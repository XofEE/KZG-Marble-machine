# KZG-Marble-machine by Xofee

Resources and documentation related to the KZG Marble machine.

## Summary

This machine was built by [Xofee](https://twitter.com/Xofee3) in order to generate randomness to participate in the KZG ceremony.
It uses chaos theory to capture entropy.

If you want more information about the KZG Ceremony, you can find it on the dedicated [GitHub Pages](https://github.com/ethereum/kzg-ceremony).
To see the machine in operation, go to this [video](https://www.youtube.com/watch?v=zKrcUxOeBF4).

## Presentation

The machine is a marble circuit. There are 13 obstacles retracing in chronological order the history of Ethereum:

- White paper
- First blocks
- Attacks
- NFT madness
- Maze of the DEFI
- The Burn
- Mining area
- The Merge
- Flow of staking
- Layers 2
- Data Blob
- Vision of the future
- Rocket lift

A complete description of each obstacle can be found in the file [Full-presentation.md](/Full-presentation.md)

## How it works

Thanks to a set of sensors, it measures the time between marbles, and it is also sensitive to its external environment.

Each time a ball completes the course, it is detected by a sensor. This causes a measurement on all the other sensors and also some light animations.
These values are aggregated and then output in one random number via USB.

Some obstacles are mechanical or motorized with servomotors. The latter also serves as a sensor to add entropy.
The course is embellished with animated LEDs to make it more entertaining.
The public present in front of the machine also participates in the entropy thanks to the microphone, light sensor and the ultrasonic sensor which measures the distance of the public from the machine.

To contribute to the KZG ceremony, the machine will directly generate a long string of random values which will be used as a secret.
**This secret will not be recorded and will therefore be lost after participation.**

This special contribution for the KZG ceremony will take place after mid-March.

## Random facts about the machine and its construction

- It took a total of more than 8 days of 3D printing to make all the pieces.
- A marble is detected by the sensor on average every 2.5s
- It takes about 25s for a ball to complete the full course.
- There are 42 marbles in the circuit in total, 30 of which are in the elevator.
- The course measures more than 4m in total.
- The longest obstacle is the DEFI maze which alone represents a quarter of the course.

## More info


You can find more info about the machine in the file [Full-presentation.md](/Full-presentation.md).

A data set of more than 16,000 values (CSV file available in raw, hexadecimal or binary) in the folder.
You can use them as random values in your projects or analyze them to check that the machine is not biased.

If you have any questions, don't hesitate to contact me on twitter at [Xofee](https://twitter.com/Xofee3).




*Randomly Xofee*



