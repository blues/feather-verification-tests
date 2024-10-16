Feather Serial Echo Test
========================

This test is intended to validate the following Serial ports:

- USB
- UART (RX/TX)
- LPUART

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### USB

Connect a standard USB cable from your PC to the Feather. Open a serial
monitoring application, such as CoolTerm, GTKTerm, or SerialMonitor (VSCode),
and attach to the Feather at 9600 baud. The Feather will appear as an "Abstract
Control Model" device (e.g. `ttyACM0`).

### UART (RX/TX)

Connect an FTDI cable from your PC to the Feather (black - ground, orange - rx,
yellow - tx). Open a serial monitoring application, such as CoolTerm, GTKTerm,
or SerialMonitor (VSCode), and attach to the FTDI controller at 9600 baud. The
FTDI controller will appear as a "USB Serial" device (e.g. `ttyUSB0`).

### LPUART

Connect a standard USB cable from your PC to the STLINK, then a 14-pin ribbon
cable to the STDC14 connector (a.k.a. JTAG) on the Feather. Open a serial
monitoring application, such as CoolTerm, GTKTerm, or SerialMonitor (VSCode),
and attach to the STLINK at 115200 baud. The STLINK will appear as an "Abstract
Control Model" device (e.g. `ttyACM0`).

Usage
-----

On boot, you should see a "status message", followed by a "ready message" in the
serial monitor for each of the serial interfaces (e.g. "Running Feather Serial
Test (UART)"). Once this message has appeared, the test is ready.

Enter any text into each of the terminals, and you should see that text echoed
back in the respective terminal.

Test Assertion
--------------

This test asserts there must be at least one functional serial inteface. If
there are no serial interfaces available, then the onboard LED will blink
rapidly indicating the test has catastrophically failed.
