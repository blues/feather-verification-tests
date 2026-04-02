/*
  FeatherVoltage.ino - Feather Voltage Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 26 March 2026
  by Zachary J. Fields
*/

volatile static bool changeDetectNotCharge = false;
volatile static bool changeDetectUsb = false;

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

void ISR_detectNotCharge (void) {
  changeDetectNotCharge = true;
}

void ISR_detectUsb (void) {
  changeDetectUsb = true;
}

static const uint32_t MV_REPORT_MS = 3000;
uint32_t mv_last_report = static_cast<uint32_t>(-MV_REPORT_MS);

// the setup function runs once when you press reset or power the board
void setup() {

  // `VMAIN_ADC` pin is initialized as analog during `initVariant()`
  // Equivalent Instruction(s):
  // pinMode(VMAIN_ADC, ANALOG_INPUT);

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

  // Configure pins to listen for signals
#ifndef ARDUINO_SWAN_R5
  pinMode(CHARGE_DETECT, INPUT_PULLUP);
#endif
  pinMode(USB_DETECT, INPUT_PULLDOWN);

  // Connect to signals
#ifndef ARDUINO_SWAN_R5
  attachInterrupt(digitalPinToInterrupt(CHARGE_DETECT), ISR_detectNotCharge, CHANGE);
#endif
  attachInterrupt(digitalPinToInterrupt(USB_DETECT),    ISR_detectUsb,       CHANGE);

  stlinkSerial.println("Running Feather Voltage Test");
}

// the loop function runs over and over again forever
void loop() {
  if (changeDetectUsb) {
    stlinkSerial.print("USB ");
    stlinkSerial.println(digitalRead(USB_DETECT) ? "connected" : "disconnected");
    delay(100); // debounce
    changeDetectUsb = false;
  }

#ifndef ARDUINO_SWAN_R5
  if (changeDetectNotCharge) {
    stlinkSerial.print("Battery ");
    stlinkSerial.print(digitalRead(CHARGE_DETECT) ? "not " : "");
    stlinkSerial.println("charging");
    delay(500); // debounce
    changeDetectNotCharge = false;
  }
#endif

  uint32_t now_ms = millis();
  if ((now_ms - mv_last_report) > MV_REPORT_MS) {
    mv_last_report = now_ms;
    stlinkSerial.print(VMAIN_MV());
    stlinkSerial.println("mV");
  }
}
