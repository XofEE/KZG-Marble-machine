# KZG-Marble-machine by xoffe

Resources and documentation related to the KZG Marble machine.

## Summary

This machine was built by [Xofee](https://twitter.com/Xofee3) in order to generate randomness to participate in the KZG ceremony.
It uses chaos theory to capture entropy.


## Source of entropy

The machine draws its entropy mainly from the measurement of the time between the passage of two marbles.
Indeed during its course, each marble will follow a slightly different path which will make it encounter greatly different obstacles.
In addition, the obstacles move to add even more randomness.

The accumulation of these parameters as well as their chaotic characteristic mean that the machine can be considered capable of generating pseudo_random values.

Secondary entropy sources such as noise, temperature are also captured by sensors to be added as well.

### Primary

| Description  | Sensor | Range |
| - | - | - |
|Time interval between two balls| LJ12A3-4-Z/BX|~2 500 000 μs - ~12 000 000 µs|

### Secondary

| Description  | Sensor | Range |
| - | - | - |
| Sound | Adafruit MAX4466 | 0 - 1023 |
| Brightness | Iduino 1485310 | 0 - 1023 |
| Distance | Ultrasonic 28015 REV C | 0mm - 500mm |
| Electrostatic noise | Antenna length 40 cm | 0 - 1023 |
| Electrostatic noise | Antenna length 40 cm | 0 - 1023 |
| Electrostatic noise | 6 x ADC | 6 x 0 - 1023 |
| Temperature | 4 x Robotis Dynamixel MX-28AR | 4 x 0 - 255 |
| Load | 4 x Robotis Dynamixel MX-28AR |  4 x 0 - 2047 |
| Position | 4 x Robotis Dynamixel MX-28AR | 4 x 0 - 4095|

## Output

The machine aggregates all the parameters of its sensors.

It can then output this value directly* or convert it to hexadecimal or binary simply performing a modulo 16 or 2 respectively.

The order of magnitude of the sum of the outputs of all the sensors being greater than 10^5, a modulo 16 can loop enough times for this value to be unpredictable.

In other words, a modulo 10 will come down to looking at the last value of a sensor outputting a 6-digit result. However, the latter is mainly influenced by the noise and not by the measured variable.

**be careful with this raw value the distribution is not homogeneous because there are more balls that finish in 2.5s than in 10s for example.*

## List of materials:

- White and gray PLA 3D printed parts
- Back board 45x66cm
- 4 x Robotis Dynamixel MX-28AR
- 1 x OpenCM 9.04 board
- 1 x OpenCM EXP 485 power board
- 1 x 12v 3A powersupply
- 1 x LJ12A3-4-Z/BX inductive proximity sensor
- 1 x Mic Adafruit MAX4466
- 1 x Brightness sensor Iduino 1485310
- 1 x Ultrasonic sensor 28015 REV C




Some interestinng number

feedback
