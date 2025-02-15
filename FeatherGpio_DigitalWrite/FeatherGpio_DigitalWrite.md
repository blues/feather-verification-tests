Feather GPIO Digital Write Test
===============================

This test is intended to validate the digital output behavior of the GPIO pins.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### Breadboard

- Place 13 LEDs in a breadboard with the negative leg of each LED in the
positive (red/+) rail of the breadbaord.
- Place a 100Ohm resistor between the positive (red/+) rail and the negative
(blue/-) rail.
- Place a jumper wire between the GND header pin of the Feather and the
negative (blue/-) rail of the breadboard.
- Place jumper wires between the positive leg of an LED and one of the following
pins: `A0`, `A1`, `A2`, `A3`, `A4`, `A5`, `D5`, `D6`, `D9`, `D10`, `D11`,
`D12`, `D13`.

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather GPIO Digital Write Test"). Once this message has appeared, the test
is running.

Each LEDs will light up sequentially, as the code loops through the GPIO pins
and turns on and off each one (including the Onboard LED).

Test Assertion
--------------

There is no assertion associated with this test.
