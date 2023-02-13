# KZG-Marble-machine by xoffe

Resources and documentation related to the KZG Marble machine.

## Summary

This mpachine was built by xofee in order to generate randomness to participate in the KZG ceremony.

###Source of entropy
#Primary

The machine draws its entropy mainly from the measurement of the time between the passage of two balls.

| Description  | Sensor | Range |
| - | - | - |
|Time interval between two balls| LJ12A3-4-Z/BX|~2 500 000 μs - ~12 000 000 µs|

#Secondary

| Description  | Sensor | Range |
| - | - | - |
| Sound | Adafruit MAX4466 | 0 - 1023 |
| Brightness | Iduino 1485310 | 0 - 1023 |
| Distance | Ultrasonic 28015 REV C | 0mm - 500mm |
| Electrostatic noise | Antenna length 40 cm | 0 - 1023 |
| Electrostatic noise | Antenna length 40 cm | 0 - 1023 |
| Electrostatic noise | 6 x ADC | 6 x 0 - 1023 |
| Temperature | 4 x Robotis Dynamixel MX-28AR | 4 x 0-255 |
| Load | 4 x Robotis Dynamixel MX-28AR |  4 x 0-2047 |
| Position | 4 x Robotis Dynamixel MX-28AR | 4 x 0-4095|

Some interestinng number

feedback
