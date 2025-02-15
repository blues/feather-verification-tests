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

Connect a Qwiic cable from the Feather to an Adafruit BME280. Open a serial
monitoring application, such as CoolTerm, GTKTerm, or SerialMonitor (VSCode),
and attach to the Feather at 9600 baud. The Feather will appear as an "Abstract
Control Model" device (e.g. `ttyACM0`).

### SPI

Place the jumper wires according to the following table:

| Feather | Adafruit BME280 |
|:-------:|:---------------:|
|  `3V3`  |      `VIN`      |
|  `GND`  |      `GND`      |
|  `CK`   |      `SCK`      |
|  `MO`   |      `SDI`      |
|  `MI`   |      `SDO`      |
|  `D10`  |      `CS`       |

Comment out the line:

```c++
Adafruit_BME280 bme; // I2C
```

Uncomment the following line:

```c++
// Adafruit_BME280 bme(BME_CS); // hardware SPI
```

Open a serial monitoring application, such as CoolTerm, GTKTerm, or
SerialMonitor (VSCode), and attach to the Feather at 9600 baud. The Feather
will appear as an "Abstract Control Model" device (e.g. `ttyACM0`).

Usage
-----

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

> _**NOTE:** This test is an unmodified Adafruit BME280 Library example sketch._
