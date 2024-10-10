/*
  FeatherLowPower.ino - Feather Low Power Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

#include <STM32LowPower.h>

volatile static bool user_btn = false;

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

void ISR_user_btn (void) {
  user_btn = true;
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.end();

  // Initialize Built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // Initialize User Button
  pinMode(USER_BTN, INPUT);
  attachInterrupt(digitalPinToInterrupt(USER_BTN), ISR_user_btn, RISING);

  // Initialize the LPUART for logging
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);

  // Initialize the LowPower library
  LowPower.begin();

  stlinkSerial.println("Running Feather Low Power Test");
}

// the loop function runs over and over again forever
void loop() {
  if (user_btn) {
    delay(250); // Debounce (250ms)
    user_btn = false;
    deepSleep();
  }
}

void deepSleep (void) {
    stlinkSerial.println("Entering Deep Sleep...");

    // Disable the standard User Button Interrupt
    detachInterrupt(digitalPinToInterrupt(USER_BTN));

    // Power down all peripherals
    powerDownPeripherals();

    // Enable the LowPower User Button Interrupt
    LowPower.attachInterruptWakeup(digitalPinToInterrupt(USER_BTN), wake, RISING, DEEP_SLEEP_MODE);

    // Enter Low Power Mode
    LowPower.deepSleep();
}

void disable3V3Regulator() {
  digitalWrite(ENABLE_3V3, LOW);
  digitalWrite(DISCHARGE_3V3, ENABLE_DISCHARGING);
}

void disableGpio () {
  // Analog Pins
  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2,OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3,OUTPUT);
  digitalWrite(A3,LOW);
  pinMode(A4,OUTPUT);
  digitalWrite(A4,LOW);
  pinMode(A5,OUTPUT);
  digitalWrite(A5,LOW);

  // Digital Pins
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  pinMode(6,OUTPUT);
  digitalWrite(6,LOW);
  pinMode(9,OUTPUT);
  digitalWrite(9,LOW);
  pinMode(10,OUTPUT);
  digitalWrite(10,LOW);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void enable3V3Regulator() {
  digitalWrite(DISCHARGE_3V3, DISABLE_DISCHARGING);
  digitalWrite(ENABLE_3V3, HIGH);
}

void powerDownPeripherals () {
    // Turn off the LED
    digitalWrite(LED_BUILTIN, LOW);

    // Disable the 3V3 Regulator
    disable3V3Regulator();

    // Disable the GPIO
    disableGpio();

    // Disable the LPUART
    stlinkSerial.end();
}

void powerUpPeripherals () {
  // Enable the LPUART
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);

  // Enable the 3V3 Regulator
  enable3V3Regulator();

  // Turn on the LED
  digitalWrite(LED_BUILTIN, HIGH);
}

void wake (void) {
  // Power up all peripherals
  powerUpPeripherals();

  // Re-enable the standard User Button Interrupt
  attachInterrupt(digitalPinToInterrupt(USER_BTN), ISR_user_btn, RISING);

  stlinkSerial.println("Exited Deep Sleep");
}
