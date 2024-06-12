/*
  FeatherGpio_AnalogWrite.ino - Feather GPIO Analog Write Test

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

  stlinkSerial.println("Running Feather GPIO Analog Write Test");
}

// the loop function runs over and over again forever
void loop() {
  roll_gpio(gpio_pin++%14);
}

void led_glow (uint8_t pin_) {
  analogWrite(pin_, 0);
  for (size_t i = 1; i < 256; i++) {
    analogWrite(pin_, i);
    delay(2);
  }
  for (size_t i = 255; i > 0; i--) {
    analogWrite(pin_, i);
    delay(2);
  }
  analogWrite(pin_, 0);
}

void roll_gpio (uint16_t gpio_pin_) {
  switch (1 << gpio_pin_) {
    case 0x0001:
      led_glow(A0);
      break;
    case 0x0002:
      led_glow(A1);
      break;
    case 0x0004:
      led_glow(A2);
      break;
    case 0x0008:
      led_glow(A3);
      break;
    case 0x0010:
      led_glow(A4);
      break;
    case 0x0020:
      led_glow(A5);
      break;
    case 0x0040:
      led_glow(D5);
      break;
    case 0x0080:
      led_glow(D6);
      break;
    case 0x0100:
      led_glow(D9);
      break;
    case 0x0200:
      led_glow(D10);
      break;
    case 0x0400:
      led_glow(D11);
      break;
    case 0x0800:
      led_glow(D12);
      break;
    case 0x1000:
      led_glow(D13);
      break;
    case 0x2000:
      led_glow(LED_BUILTIN);
      break;
  }
}
