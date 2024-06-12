/*
  FeatherGpio_DigitalRead.ino - Feather GPIO Digital Read Test

  Used to test the configuration of new boards added to the STM32 core.

  modified 31 May 2024
  by Zachary J. Fields
*/

static bool a0 = false;
static bool a1 = false;
static bool a2 = false;
static bool a3 = false;
static bool a4 = false;
static bool a5 = false;
static bool d5 = false;
static bool d6 = false;
static bool d9 = false;
static bool d10 = false;
static bool d11 = false;
static bool d12 = false;
static bool d13 = false;
static bool user_btn = false;

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
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  pinMode(D11, INPUT);
  pinMode(D12, INPUT);
  pinMode(D13, INPUT);
  pinMode(USER_BTN, INPUT);

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

  stlinkSerial.println("Running Feather GPIO Digital Read Test");
}

// the loop function runs over and over again forever
void loop() {
  // Read pin A0
  if (a0 != digitalRead(A0)) {
    delay(100);
    a0 = !a0;
    stlinkSerial.print("A0: ");
    stlinkSerial.println(a0 ? "HIGH" : "LOW");
  }

  // Read pin A1
  if (a1 != digitalRead(A1)) {
    delay(100);
    a1 = !a1;
    stlinkSerial.print("A1: ");
    stlinkSerial.println(a1 ? "HIGH" : "LOW");
  }

  // Read pin A2
  if (a2 != digitalRead(A2)) {
    delay(100);
    a2 = !a2;
    stlinkSerial.print("A2: ");
    stlinkSerial.println(a2 ? "HIGH" : "LOW");
  }

  // Read pin A3
  if (a3 != digitalRead(A3)) {
    delay(100);
    a3 = !a3;
    stlinkSerial.print("A3: ");
    stlinkSerial.println(a3 ? "HIGH" : "LOW");
  }

  // Read pin A4
  if (a4 != digitalRead(A4)) {
    delay(100);
    a4 = !a4;
    stlinkSerial.print("A4: ");
    stlinkSerial.println(a4 ? "HIGH" : "LOW");
  }

  // Read pin A5
  if (a5 != digitalRead(A5)) {
    delay(100);
    a5 = !a5;
    stlinkSerial.print("A5: ");
    stlinkSerial.println(a5 ? "HIGH" : "LOW");
  }

  // Read pin D5
  if (d5 != digitalRead(D5)) {
    delay(100);
    d5 = !d5;
    stlinkSerial.print("D5: ");
    stlinkSerial.println(d5 ? "HIGH" : "LOW");
  }

  // Read pin D6
  if (d6 != digitalRead(D6)) {
    delay(100);
    d6 = !d6;
    stlinkSerial.print("D6: ");
    stlinkSerial.println(d6 ? "HIGH" : "LOW");
  }

  // Read pin D9
  if (d9 != digitalRead(D9)) {
    delay(100);
    d9 = !d9;
    stlinkSerial.print("D9: ");
    stlinkSerial.println(d9 ? "HIGH" : "LOW");
  }

  // Read pin D10
  if (d10 != digitalRead(D10)) {
    delay(100);
    d10 = !d10;
    stlinkSerial.print("D10: ");
    stlinkSerial.println(d10 ? "HIGH" : "LOW");
  }

  // Read pin D11
  if (d11 != digitalRead(D11)) {
    delay(100);
    d11 = !d11;
    stlinkSerial.print("D11: ");
    stlinkSerial.println(d11 ? "HIGH" : "LOW");
  }

  // Read pin D12
  if (d12 != digitalRead(D12)) {
    delay(100);
    d12 = !d12;
    stlinkSerial.print("D12: ");
    stlinkSerial.println(d12 ? "HIGH" : "LOW");
  }

  // Read pin D13
  if (d13 != digitalRead(D13)) {
    delay(100);
    d13 = !d13;
    stlinkSerial.print("D13: ");
    stlinkSerial.println(d13 ? "HIGH" : "LOW");
  }

  // Read pin USER_BTN
  if (user_btn != digitalRead(USER_BTN)) {
    delay(100);
    user_btn = !user_btn;
    stlinkSerial.print("USER_BTN: ");
    stlinkSerial.println(user_btn ? "HIGH" : "LOW");
  }
}
