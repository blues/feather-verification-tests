/*
  FeatherVoltage.ino - Feather Voltage Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

#define BAT_VOLTAGE PA4

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize pins for GPIO Tests
  pinMode(BAT_VOLTAGE, INPUT);

  analogReadResolution(10);

  // Initialize the LPUART for logging
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);

  // Provide a visual indication a catastrophic failure has occurred
  if (!stlinkSerial) {
    pinMode(LED_BUILTIN, OUTPUT);
    while (true) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    };
  }

  stlinkSerial.println("Running Feather Voltage Test");
}

// the loop function runs over and over again forever
void loop() {
    stlinkSerial.print("V: ");
    stlinkSerial.print(analogRead(PA4));
    stlinkSerial.println(" / 1023");
    delay(1000);
}
