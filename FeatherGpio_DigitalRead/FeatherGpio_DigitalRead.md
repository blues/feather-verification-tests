Feather GPIO Digital Read Test
==============================

This test is intended to validate the digital input behavior of the GPIO pins.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### Breadboard

- Place a jumper wire between the `GND` header pin of the Feather and the
negative (blue/-) rail of the breadboard.
- Place a jumper wire between the `3V3` header pin of the Feather and the
positive (red/+) rail of the breadboard.
- Place jumper wires between the negative rail and each of the following pins:
`A0`, `A1`, `A2`, `A3`, `A4`, `A5`, `D5`, `D6`, `D9`, `D10`, `D11`, `D12`, `D13`

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather GPIO Digital Read Test"). Once this message has appeared, the test
is running.

First press the user button, and look for the following output.

```
USER_BTN: LOW
USER_BTN: HIGH
```

Next, move the jumpers connected to each pin between the negative (blue/-) rail
of the breadboard and the positive (red/+) rail of the breadboard. You will see
output for each pin that looks similar messages from `USER_BTN`.

> _**NOTE:** `USER_BTN` has a hardware pull-up, whereas the other pins do not.
As a result, they will be MUCH more noisy. However, the last message logged
will represent the actual logic level of the pin._

Test Assertion
--------------

This test asserts that the LPUART must be functional as a serial inteface. If
LPUART is unavailable, then the onboard LED will blink rapidly indicating the
test has catastrophically failed.
