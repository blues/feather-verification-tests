/*
  FeatherGpio_DigitalRead_Interrupt.ino - Feather GPIO Digital Read
  Interrupt Test

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

void ISR_a0 (void) {
  a0 = true;
}

void ISR_a1 (void) {
  a1 = true;
}

void ISR_a2 (void) {
  a2 = true;
}

void ISR_a3 (void) {
  a3 = true;
}

void ISR_a4 (void) {
  a4 = true;
}

void ISR_a5 (void) {
  a5 = true;
}

void ISR_d5 (void) {
  d5 = true;
}

void ISR_d6 (void) {
  d6 = true;
}

void ISR_d9 (void) {
  d9 = true;
}

void ISR_d10 (void) {
  d10 = true;
}

void ISR_d11 (void) {
  d11 = true;
}

void ISR_d12 (void) {
  d12 = true;
}

void ISR_d13 (void) {
  d13 = true;
}

void ISR_user_btn (void) {
  user_btn = true;
}

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize pins for GPIO Tests
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLUP);
  pinMode(D6, INPUT_PULLUP);
  pinMode(D9, INPUT_PULLUP);
  pinMode(D10, INPUT_PULLUP);
  pinMode(D11, INPUT_PULLUP);
  pinMode(D12, INPUT_PULLUP);
  pinMode(D13, INPUT_PULLUP);
  pinMode(USER_BTN, INPUT_PULLUP);

  // Attach Interrupts
  attachInterrupt(digitalPinToInterrupt(A0),       ISR_a0,       RISING);
  attachInterrupt(digitalPinToInterrupt(A1),       ISR_a1,       RISING);
  attachInterrupt(digitalPinToInterrupt(A2),       ISR_a2,       RISING);
  attachInterrupt(digitalPinToInterrupt(A3),       ISR_a3,       RISING);
  attachInterrupt(digitalPinToInterrupt(A4),       ISR_a4,       RISING);
  attachInterrupt(digitalPinToInterrupt(A5),       ISR_a5,       RISING);
  attachInterrupt(digitalPinToInterrupt(D5),       ISR_d5,       RISING);
  attachInterrupt(digitalPinToInterrupt(D6),       ISR_d6,       RISING);
  attachInterrupt(digitalPinToInterrupt(D9),       ISR_d9,       RISING);
  attachInterrupt(digitalPinToInterrupt(D10),      ISR_d10,      RISING);
  attachInterrupt(digitalPinToInterrupt(D11),      ISR_d11,      RISING);
  attachInterrupt(digitalPinToInterrupt(D12),      ISR_d12,      RISING);
  attachInterrupt(digitalPinToInterrupt(D13),      ISR_d13,      RISING);
  attachInterrupt(digitalPinToInterrupt(USER_BTN), ISR_user_btn, RISING);

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

  stlinkSerial.println("Running Feather GPIO Digital Read Interrupt Test");
}

// the loop function runs over and over again forever
void loop() {
  // Check for pin A0 interrupt
  if (a0) {
    delay(100);
    a0 = false;
    stlinkSerial.println("A0: Interrupt");
  }

  // Check for pin A1 interrupt
  if (a1) {
    delay(100);
    a1 = false;
    stlinkSerial.println("A1: Interrupt");
  }

  // Check for pin A2 interrupt
  if (a2) {
    delay(100);
    a2 = false;
    stlinkSerial.println("A2: Interrupt");
  }

  // Check for pin A3 interrupt
  if (a3) {
    delay(100);
    a3 = false;
    stlinkSerial.println("A3: Interrupt");
  }

  // Check for pin A4 interrupt
  if (a4) {
    delay(100);
    a4 = false;
    stlinkSerial.println("A4: Interrupt");
  }

  // Check for pin A5 interrupt
  if (a5) {
    delay(100);
    a5 = false;
    stlinkSerial.println("A5: Interrupt");
  }

  // Check for pin D5 interrupt
  if (d5) {
    delay(100);
    d5 = false;
    stlinkSerial.println("D5: Interrupt");
  }

  // Check for pin D6 interrupt
  if (d6) {
    delay(100);
    d6 = false;
    stlinkSerial.println("D6: Interrupt");
  }

  // Check for pin D9 interrupt
  if (d9) {
    delay(100);
    d9 = false;
    stlinkSerial.println("D9: Interrupt");
  }

  // Check for pin D10 interrupt
  if (d10) {
    delay(100);
    d10 = false;
    stlinkSerial.println("D10: Interrupt");
  }

  // Check for pin D11 interrupt
  if (d11) {
    delay(100);
    d11 = false;
    stlinkSerial.println("D11: Interrupt");
  }

  // Check for pin D12 interrupt
  if (d12) {
    delay(100);
    d12 = false;
    stlinkSerial.println("D12: Interrupt");
  }

  // Check for pin D13 interrupt
  if (d13) {
    delay(100);
    d13 = false;
    stlinkSerial.println("D13: Interrupt");
  }

  // Check for USER_BTN interrupt
  if (user_btn) {
    delay(100);
    user_btn = false;
    stlinkSerial.println("USER_BTN: Interrupt");
  }
}
