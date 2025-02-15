Feather Low Power Test
======================

This test is intended to validate the low power configuration of the Feather.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### Ammeter

- Connect an ammeter (i.e. Joulescope, CurrentRanger, MoJo, etc...) inline with
the JST connector.

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather Low Power Test"). Once this message has appeared, the test is running.

Press the `USER_BTN` to toggle between **standard** and **deep sleep** running
modes.

> _**WARNING:** Once you are certain the test is running, ensure STLINK and USB
> are unplugged, as they will draw significant current._

Test Assertion
--------------

There is no assertion associated with this test.
