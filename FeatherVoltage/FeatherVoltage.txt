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

You should see output similar to the output shown below:

```
V: 473 / 1023
```

The voltage divider used is `VMAIN` -> 10MOhm -> `PA4` -> 4.3MOhm -> `GND`,
which results in following values for common voltages:

|    Source     | Voltage | ADC Value |
|:-------------:|:-------:|:---------:|
|     `USB`     |  1.50V  |    474    |
|  LiPo (4.2V)  |  1.26V  |    390    |

Test Assertion
--------------

This test asserts that the LPUART must be functional as a serial inteface. If
LPUART is unavailable, then the onboard LED will blink rapidly indicating the
test has catastrophically failed.
