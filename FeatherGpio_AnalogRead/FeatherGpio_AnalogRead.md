Feather GPIO Analog Read Test
=============================

This test is intended to validate the analog input interrupt behavior of the
GPIO pins.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### Breadboard

- Place a jumper wire between the `GND` header pin of the Feather and the
negative (blue/-) rail of the breadboard.
- Place a jumper wire between the `3V3` header pin of the Feather and the
positive (red/+) rail of the breadboard.
- Create a voltage divider using five identical resistors.
  - Place one leg of the first resistor in the positive (red/+) rail of the
  breadboard, and the other leg in row 1 of the breadboard.
  - Place one leg of the second resistor in row 1 of the breadboard, and the
  other leg in row 4 of the breadboard.
  - Place one leg of the third resistor in row 4 of the breadboard, and the
  other leg in row 7 of the breadboard.
  - Place one leg of the fourth resistor in row 7 of the breadboard, and the
  other leg in row 10 of the breadboard.
  - Place one leg of the fifth resistor in row 10 of the breadboard, and the
  other leg in the negative (blue/-) rail of the breadboard.
- Place the following jumper wires:
  - `A0` -> positive (red/+) rail of the breadboard
  - `A1` -> row 1 of the breadboard
  - `A2` -> row 4 of the breadboard
  - `A3` -> row 7 of the breadboard
  - `A4` -> row 10 of the breadboard
  - `A5` -> negative (blue/-) rail of the breadboard

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather GPIO Analog Read Test"). Once this message has appeared, the test
is running.

You should see output similar to the output shown below:

```
A0: 1021
A1: 818
A2: 611
A3: 408
A4: 205
A5: 0
```

Rotate the jumper wires, until all wires have visited each test point (as
described in the setup procedure). You should expecte to see a value
approximating those shown in the example output above.

Test Assertion
--------------

This test asserts that the LPUART must be functional as a serial inteface. If
LPUART is unavailable, then the onboard LED will blink rapidly indicating the
test has catastrophically failed.
