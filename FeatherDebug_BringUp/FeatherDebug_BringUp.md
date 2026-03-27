Feather Debug Bring-Up Test
===========================

This test is intended to validate the ability to debug the Feather.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

This is a simple sketch designed to allow you to validate the BSP has been
successfully loaded (i.e. `setup()` and `loop()` run normally) and that it is
possible to connect a debugger. The built-in LED is operated by the USER button.
The LED should be on when the USER button is not pressed, and the LED should go
out when the USER button is pressed.

Test Assertion
--------------

There is no assertion associated with this test.
