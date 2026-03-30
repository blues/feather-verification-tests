Feather I2C/SPI Test
====================

This test is intended to validate the following peripherals:

- I2C
- SPI

Setup
-----

### IDE

Compile and flash using the Arduino IDE v2.x

### I2C

#### Qwiic

```cpp
#define TEST_I2C 1
#define TEST_QWIIC 1
```

Connect a Qwiic cable from the Feather to an Adafruit BME280.

#### Feather Pins

```cpp
#define TEST_I2C 1
#define TEST_QWIIC 0
```

Place the jumper wires according to the following table:

| Feather | Adafruit BME280 |
|:-------:|:---------------:|
|  `3V3`  |      `VIN`      |
|  `GND`  |      `GND`      |
|  `SCL`  |      `SCK`      |
|  `SDA`  |      `SDI`      |

### SPI

```cpp
#define TEST_I2C 0
#define TEST_QWIIC 0  // Doesn't matter
```

Place the jumper wires according to the following table:

| Feather | Adafruit BME280 |
|:-------:|:---------------:|
|  `3V3`  |      `VIN`      |
|  `GND`  |      `GND`      |
|  `CK`   |      `SCK`      |
|  `MO`   |      `SDI`      |
|  `MI`   |      `SDO`      |
|  `D11`  |      `CS`       |

Usage
-----

Open a serial monitoring application, such as CoolTerm, GTKTerm, or
SerialMonitor (VSCode), and attach to the Feather at 9600 baud. The Feather
will appear as an "Abstract Control Model" device (e.g. `ttyACM0`).

On boot, you should see a "ready message" in the serial monitor (e.g. "BME280
test"). Once this message has appeared, the test is running.

You should see output similar to the output shown below:

```
Temperature = 22.38 °C
Pressure = 969.66 hPa
Approx. Altitude = 369.44 m
Humidity = 58.14 %
```

Test Assertion
--------------

There is no assertion associated with this test.

> _**NOTE:** This test has been minimally modified from the Adafruit BME280 Library example sketch._
