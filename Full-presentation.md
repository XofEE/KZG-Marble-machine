# Full presentation of The KZG Marble Machine by Xofee

## Summary 

This presentation aims to supplement the information found in the [Readme file](/README.md).

If you want more information about the KZG Ceremony, you can find it on the dedicated [GitHub Pages](https://github.com/ethereum/kzg-ceremony).

To see the machine in operation, go to this [video](https://www.youtube.com/watch?v=zKrcUxOeBF4).

## Obstacles 

We will deconstruct each obstacle of the KZG Marble Machine to understand its functioning.

<img src="/images-videos/AnimationSD00.gif" width="576" height="324">


The best place to start is with the title: ETHEREUM. We'll take a look at some of its major milestones.

<img src="/images-videos/AnimationSD01.gif" width="576" height="324">


In 2014, Vitalik published the Ethereum White Paper 📝, which marked the beginning of the project. This obstacle is powered by the logo rotating randomly 🔄, deflecting the marbles.

<img src="/images-videos/AnimationSD02.gif" width="576" height="324">


In 2015, 🏁 the first blocks of Ethereum were mine and worked smoothly until...

<img src="/images-videos/AnimationSD03.gif" width="576" height="324">


In 2016, there was a setback with the hack of The DAO and the Shanghai attack. Here we see a funnel that sucks all the marbles 🌪️.

<img src="/images-videos/AnimationSD04.gif" width="576" height="324">


In 2017, the NFT craze is depicted with a CryptoKitty (#634995) congesting the marble flow with its paws. 🐾

<img src="/images-videos/AnimationSD05.gif" width="576" height="324">


We delve into the complexities of decentralized finance with the 2020 DEFI Summer.

<img src="/images-videos/AnimationSD06.gif" width="576" height="324">


We find the 🔥 Burn mechanism of the EIP1559 with a switch that diverts some of the marbles. This update was implemented during the London fork in August 2021.

<img src="/images-videos/AnimationSD07.gif" width="576" height="324">


Next, we come to the moment of the merge symbolized by a panda 🐼. Upstream, we have the miners' pickaxes ⛏️ representing the Proof of Work era.

<img src="/images-videos/AnimationSD08.gif" width="576" height="324">


In September 2022, we move to proof of stake with the marbles flowing between the ETH staked 🪙.

<img src="/images-videos/AnimationSD09.gif" width="576" height="324">


We then reach the layer 2, which operates in parallel ⛓️ with Ethereum to improve scalability.

<img src="/images-videos/AnimationSD10.gif" width="576" height="324">


We arrive at a blob that absorbs data to make more room for the layer 2s. The KZG ceremony 🕯️ with the EIP 4844 will enable the deployment of this new data type.

<img src="/images-videos/AnimationSD11.gif" width="576" height="324">



The end of the course features a sensor measuring the final interval between two marbles to generate entropy 🎲. Then we discover a vision of a future built on Ethereum 🏙️.

<img src="/images-videos/AnimationSD12.gif" width="576" height="324">


Finally, we come to a rocket 🚀 (familiar to some in the community) which uses an elevator to raise the marbles to the top of the course. ⏫

<img src="/images-videos/AnimationSD13.gif" width="576" height="324">


## Source of entropy

The machine draws its entropy mainly from the measurement of the time between the passage of two marbles.
Indeed, during its course, each marble will follow a slightly different path which will make it encounter greatly different obstacles.
In addition, the obstacles move to add even more randomness.

The accumulation of these parameters as well as their chaotic characteristic means that the machine can be considered capable of generating pseudo random values.

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
| Load | 4 x Robotis Dynamixel MX-28AR | 4 x 0 - 2047 |
| Position | 4 x Robotis Dynamixel MX-28AR | 4 x 0 - 4095|

## Output

The machine aggregates all the parameters of its sensors.

It can then output this value directly* or convert it to hexadecimal or binary simply performing a modulo 16 or 2 respectively.

The order of magnitude of the sum of the outputs of all the sensors being greater than 10<sub>5</sub>, a modulo 16 can loop enough times for this value to be unpredictable.

In other words, a modulo 10 will come down to looking at the last value of a sensor outputting a 6-digit result. However, the latter is mainly influenced by the noise and not by the measured variable.

**be careful with this raw value the distribution is not homogeneous because there are more balls that finish in 2.5s than in 10s for example.*

## Control of obstacles

### Motorized obstacle

4 obstacles are controlled by servomotors:

- White paper
- NFT madness
- Mining area
- Rocket lift

These servos change speed and position randomly according to the last generated random value.
This change happens every time a marble completes the circuit or every 5s (whichever comes first).

### Mechanical obstacle

The burn is a special obstacle since it is a switch that separates half of the marbles. The burnt balls are sent on a faster path towards the end of the course.

## List of materials:

If you want to build this machine yourself, you will find below a non-exhaustive list of the necessary materials:

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

[Files](/3D%20files) and [code](/program) are available in opensource on this github.

If you have any questions, don't hesitate to contact me on twitter at [Xofee](https://twitter.com/Xofee3).

*Randomly Xofee*
