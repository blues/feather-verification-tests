/*
  FeatherGpio_DigitalWrite.ino - Feather GPIO Digital Write Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

static uint8_t gpio_pin = 0;

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize pins for GPIO Tests
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D11, OUTPUT);
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialize the LPUART for logging
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);

  stlinkSerial.println("Running Feather GPIO Digital Write Test");
}

// the loop function runs over and over again forever
void loop() {
  roll_gpio(gpio_pin++%14);
  delay(250);
}

void roll_gpio (uint16_t gpio_pin_) {
  switch (1 << gpio_pin_) {
    case 0x0001:
      digitalWrite(A0, HIGH);
      digitalWrite(LED_BUILTIN, LOW);
      break;
    case 0x0002:
      digitalWrite(A1, HIGH);
      digitalWrite(A0, LOW);
      break;
    case 0x0004:
      digitalWrite(A2, HIGH);
      digitalWrite(A1, LOW);
      break;
    case 0x0008:
      digitalWrite(A3, HIGH);
      digitalWrite(A2, LOW);
      break;
    case 0x0010:
      digitalWrite(A4, HIGH);
      digitalWrite(A3, LOW);
      break;
    case 0x0020:
      digitalWrite(A5, HIGH);
      digitalWrite(A4, LOW);
      break;
    case 0x0040:
      digitalWrite(D5, HIGH);
      digitalWrite(A5, LOW);
      break;
    case 0x0080:
      digitalWrite(D6, HIGH);
      digitalWrite(D5, LOW);
      break;
    case 0x0100:
      digitalWrite(D9, HIGH);
      digitalWrite(D6, LOW);
      break;
    case 0x0200:
      digitalWrite(D10, HIGH);
      digitalWrite(D9, LOW);
      break;
    case 0x0400:
      digitalWrite(D11, HIGH);
      digitalWrite(D10, LOW);
      break;
    case 0x0800:
      digitalWrite(D12, HIGH);
      digitalWrite(D11, LOW);
      break;
    case 0x1000:
      digitalWrite(D13, HIGH);
      digitalWrite(D12, LOW);
      break;
    case 0x2000:
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(D13, LOW);
      break;
  }
}
