# KZG-Marble-machine by Xofee

Resources and documentation related to the KZG Marble machine.

## Summary

This machine was built by [Xofee](https://twitter.com/Xofee3) in order to generate randomness to participate in the KZG ceremony.
It uses chaos theory to capture entropy.

If you want more information about the KZG Ceremony, you can find it on the dedicated [GitHub Pages](https://github.com/ethereum/kzg-ceremony).
To see the machine in operation, go to this [video](https://www.youtube.com/watch?v=zKrcUxOeBF4).

## Presentation

The machine is a marble circuit. There are 13 obstacles retracing in chronological order the history of ethereum.

- White paper
- First blocks
- Attacks
- NFT madness
- Maze of the DEFI
- The Burn
- Mining area
- The Merge
- FDlow of staking
- Layers 2
- Data Blob
- Vision of the future
- Rocket lift

A complete description of each obstacle can be found in the file [Full-presentation.md](/Full-presentation.md)

## How it works

Thanks to a set of sensors, it reacts to the marble and its environment to generate random values

To contribute to the KZG ceremony, the machine will directly generate a long queue of random values which will be used as a secret.
This secret will not be recorded and will therefore be lost after participation.

## Random facts about the machine and its construction

-It took a total of more than 8 days of 3D printing to make all the pieces.
-A marble is detected by the sensor on average every 2.5s
-It takes about 25s for a ball to complete the full course.
-There are 42 marbles in the circuit in total, 30 of which are in the elevator.




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
- 2 x Strip of Neopixels LED




Some interestinng number

feedback
