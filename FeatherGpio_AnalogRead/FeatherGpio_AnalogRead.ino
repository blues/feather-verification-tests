/*
  FeatherGpio_AnalogRead.ino - Feather GPIO Analog Read Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

static uint8_t gpio_pin = 0;

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize pins for GPIO Tests
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

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

  stlinkSerial.println("Running Feather GPIO Analog Read Test");
}

// the loop function runs over and over again forever
void loop() {
  uint16_t active_pin = (gpio_pin++ % 6);
  if (!active_pin) {
    stlinkSerial.println();
    delay(1000);
  }
  roll_gpio(active_pin);
}

void roll_gpio (uint16_t gpio_pin_) {
  switch (1 << gpio_pin_) {
    case 0x0001:
      stlinkSerial.print("A0: ");
      stlinkSerial.println(analogRead(A0));
      break;
    case 0x0002:
      stlinkSerial.print("A1: ");
      stlinkSerial.println(analogRead(A1));
      break;
    case 0x0004:
      stlinkSerial.print("A2: ");
      stlinkSerial.println(analogRead(A2));
      break;
    case 0x0008:
      stlinkSerial.print("A3: ");
      stlinkSerial.println(analogRead(A3));
      break;
    case 0x0010:
      stlinkSerial.print("A4: ");
      stlinkSerial.println(analogRead(A4));
      break;
    case 0x0020:
      stlinkSerial.print("A5: ");
      stlinkSerial.println(analogRead(A5));
      break;
  }
}
