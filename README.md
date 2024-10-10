Feather Verification Tests
==========================

The tests provided here are used to verify the Blues Feather compatible
hardware; currently the Swan and Cygnet.

The Arduino sketches provided in this repository will validate the board
definitions provided by the
[`stm32duino` BSP](https://github.com/stm32duino/Arduino_Core_STM32).

Communication Protocols
-----------------------

- [I2C](bme280test/bme280test.md)
- [SPI](bme280test/bme280test.md)
- [LPUART](FeatherSerialEcho/FeatherSerialEcho.md)
- [UART](FeatherSerialEcho/FeatherSerialEcho.md)
- [USB](FeatherSerialEcho/FeatherSerialEcho.md)

GPIO Functionality
------------------

- Digital I/O
    - [Input](FeatherGpio_DigitalRead/FeatherGpio_DigitalRead.md)
    - [Output](FeatherGpio_DigitalWrite/FeatherGpio_DigitalWrite.md)
- Analog I/O
    - [Input](FeatherGpio_AnalogRead/FeatherGpio_AnalogRead.md)
    - [Output](FeatherGpio_AnalogWrite/FeatherGpio_AnalogWrite.md)
- [PWM](FeatherGpio_AnalogWrite/FeatherGpio_AnalogWrite.md)
- [Interrupts](FeatherGpio_DigitalRead_Interrupts/FeatherGpio_DigitalRead_Interrupts.md)

Power Management
----------------

- [3V3 Regulator](Feather3V3Regulator/Feather3V3Regulator.md)
- [Detect Battery Voltage](FeatherVoltage/FeatherVoltage.md)
- [Low-Power Mode](FeatherLowPower/FeatherLowPower.md)
