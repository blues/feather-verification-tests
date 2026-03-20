/*
  Feather3V3Regulator.ino - Feather 3V3 Regulator Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

// the setup function runs once when you press reset or power the board
void setup() {

  // The 3V3 Regulator is initialized as analog during `initVariant()`
  // Equivalent Instruction(s):
  // pinMode(ENABLE_3V3, OUTPUT);
  // pinMode(DISCHARGE_3V3, OUTPUT);
  // digitalWrite(DISCHARGE_3V3, DISABLE_DISCHARGING);
  // digitalWrite(ENABLE_3V3, HIGH);

  // Initialize the LPUART for logging
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);

  stlinkSerial.println("Running Feather 3V3 Regulator Test");
}

// the loop function runs over and over again forever
void loop() {
  // Toggle the regulator at 0.5Hz
  disable3V3Regulator();
  delay(2000);
  enable3V3Regulator();
  delay(2000);
}

void disable3V3Regulator() {
  digitalWrite(ENABLE_3V3, LOW);
  digitalWrite(DISCHARGE_3V3, ENABLE_DISCHARGING);
  delay(1);
  digitalWrite(DISCHARGE_3V3, DISABLE_DISCHARGING);
}

void enable3V3Regulator() {
  digitalWrite(DISCHARGE_3V3, DISABLE_DISCHARGING);
  digitalWrite(ENABLE_3V3, HIGH);
}
