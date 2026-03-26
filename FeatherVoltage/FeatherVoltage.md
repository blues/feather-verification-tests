Feather Voltage Test
====================

This test is intended to validate the analog input used to test the voltage
supplied to the Feather.

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### STLINK

- Connect the STLINK to the STDC14 connector (a.k.a. JTAG) on the Feather. This
will be used to collect logs.

Usage
-----

On boot, you should see a "ready message" on the serial monitor (e.g. "Running
Feather Voltage Test"). Once this message has appeared, the test is running.

You should see recurring output similar to the output shown below:

```
4100.44mV
```

The value being displayed, is the product of a MACRO function, `VMAIN_MV()`, which
has been provided to calculate the voltage of `VMAIN` in millivolts (mV).

The test validates the voltage divider built in to the device:

`VMAIN` -> `VMAIN_ADC_DIV_TOP_R` -> `VMAIN_ADC` -> `VMAIN_ADC_DIV_BOT_R` -> `GND`

> _**NOTE:** `VMAIN_ADC` can be sampled directly._

The test will also output interrupt-based messages indicating the presence, or absense,
of USB, as well as whether or not the attached battery is charging.

```
USB connected
Battery charging
USB disconnected
Battery not charging
```

Test Assertion
--------------

This test asserts that the VCP must be functional as a serial inteface. If
VCP is unavailable, then the onboard LED will blink rapidly indicating the
test has catastrophically failed.
