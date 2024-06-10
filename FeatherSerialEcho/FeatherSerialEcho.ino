/*
  FeatherSerialEcho.ino - Feather Serial Inteface Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

#define txRxPinsSerial Serial1
#define usbSerial Serial

static bool stlinkSerialAvailable = false;
static bool txRxPinsSerialAvailable = false;
static bool usbSerialAvailable = false;

HardwareSerial stlinkSerial(PIN_VCP_RX, PIN_VCP_TX);

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize the LPUART for testing
  stlinkSerial.begin(115200);
  const size_t stlinkSerial_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !stlinkSerial && (millis() - start_ms) < stlinkSerial_timeout_ms;);
  if (stlinkSerial) {
    stlinkSerialAvailable = true;
  }

  // Initialize the UART for testing
  txRxPinsSerial.begin(9600);
  const size_t txRxPins_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !txRxPinsSerial && (millis() - start_ms) < txRxPins_timeout_ms;);
  if (txRxPinsSerial) {
    txRxPinsSerialAvailable = true;
  }

  // Initialize the USB for testing
  usbSerial.begin(9600);
  const size_t usb_timeout_ms = 3000;
  for (const size_t start_ms = millis(); !usbSerial && (millis() - start_ms) < usb_timeout_ms;);
  if (usbSerial) {
    usbSerialAvailable = true;
  }

  // Provide a visual indication a catastrophic failure has occurred
  if (!stlinkSerialAvailable && !txRxPinsSerialAvailable && !usbSerialAvailable) {
    pinMode(LED_BUILTIN, OUTPUT);
    while (1) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
  }

  if (stlinkSerialAvailable) {
    printSerialInterfaceStatus(stlinkSerial);
    stlinkSerial.println("Running Feather Serial Echo Test (LPUART)");
  }
  if (txRxPinsSerialAvailable) {
    printSerialInterfaceStatus(txRxPinsSerial);
    txRxPinsSerial.println("Running Feather Serial Echo Test (UART)");
  }
  if (usbSerialAvailable) {
    printSerialInterfaceStatus(usbSerial);
    usbSerial.println("Running Feather Serial Test Echo (USB)");
  }
}

// the loop function runs over and over again forever
void loop() {
  if (stlinkSerialAvailable) {
    while (stlinkSerial.available()) {
      stlinkSerial.write(stlinkSerial.read());
    }
  }
  if (txRxPinsSerialAvailable) {
    while (txRxPinsSerial.available()) {
      txRxPinsSerial.write(txRxPinsSerial.read());
    }
  }
  if (usbSerialAvailable) {
    while (usbSerial.available()) {
      usbSerial.write(usbSerial.read());
    }
  }
}

void printSerialInterfaceStatus (Stream & serial_) {
  serial_.println("Serial interface status:");
  serial_.print("\t- LPUART: ");
  serial_.println(stlinkSerialAvailable ? "OK" : "N/A");
  serial_.print("\t- UART:   ");
  serial_.println(txRxPinsSerialAvailable ? "OK" : "N/A");
  serial_.print("\t- USB:    ");
  serial_.println(usbSerialAvailable ? "OK" : "N/A");
  serial_.println();
}
