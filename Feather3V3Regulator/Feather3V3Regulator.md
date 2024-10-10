Feather 3V3 Regulator Test
==========================

This test is intended to validate the 3V3 regulator.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### Breadboard

- Place an LED with the positive leg on the row with the `3V3` pin of the
Feather, and the negative leg in row 1 of the breadboard.
- Place one leg of a resistor in row 1 of the breadboard, and place the other
leg of the resistor in the row with the `GND` pin of the Feather.

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather 3V3 Regulator Test"). Once this message has appeared, the test
is running.

The LED should toggle on an off in one second intervals.

Test Assertion
--------------

There is no assertion associated with this test.
