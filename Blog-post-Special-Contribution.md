# The KZG Marble Machine: My special Contribution to Ethereum’s KZG Ceremony
## Subtitle:

*A closer look at the elaborate contraption that uses marbles to generate random numbers for the Ethereum KZG Ceremony.*

<img src="/images-videos/3DRender1.png" width="576" height="324">

*The KZG Marble Machine*

## Introduction:
Cryptography is a fascinating world that thrives on creativity and innovation. In this extended blog post, I’m excited to share details about my one-of-a-kind contribution to the Ethereum KZG Ceremony using the KZG Marble Machine, an elaborate contraption designed to provide a unique source of randomness for the proceedings.

## Background:
The KZG Ceremony is a decentralized alternative to a trusted setup, which outputs public parameters for a polynomial commitment scheme. The ceremony relies on contributions from multiple participants, guaranteeing integrity as long as at least one participant acts honestly in generating their contribution and destroying the secret.

To reinforce the ceremony’s security, the Ethereum Foundation called for special contributions, including unique sources of randomness.

That’s where my KZG Marble Machine comes into play!

## The KZG Marble Machine:
The KZG Marble Machine is an intricate, custom-built contraption that uses marbles to generate random numbers. The machine features 13 obstacles, each symbolizing a milestone in Ethereum’s history. As marbles move through the machine, they interact with these obstacles and various components, creating unpredictable patterns. The result is a truly unique and random sequence of numbers that I used for my special contribution to the KZG Ceremony.

To see the machine in operation, go to this [video](https://www.youtube.com/watch?v=zKrcUxOeBF4).

## Entropy Sources:
Multiple entropy sources influence the machine’s sensors, ensuring an even higher degree of randomness. These sources include the initial position of the marbles, friction between components, air resistance, and vibrations in the machine’s structure.

Additionally, the KZG Marble Machine is equipped with ultrasonic sensors, microphones, and antennas, which incorporate environmental factors as supplementary sources of entropy. This feature allows the machine to generate even more unpredictable random numbers.

<img src="/images-videos/AnimationSD00.gif" width="576" height="324">

*Breakdown of the full KZG Marble Machine*

## The Process:
The KZG Marble Machine sent 420 random hexadecimal values (i.e. 1680 values in binary) through the serial port of an air-gapped PC via a USB cable. This air-gapped PC performed the necessary computations to generate my contribution to the KZG Ceremony. Once the calculations were completed, I transferred the resulting file to a USB stick and then to a separate computer, which sent my contribution to the sequencer.

<img src="/images-videos/setup.jpg" width="576" height="576">

*Setup beforethe contribution*

Importantly, the 420 random hexadecimal values were never recorded nor fully seen by me. After transferring the file, both the air-gapped PC and the USB stick were completely formatted to ensure no trace of the random values or my contribution remained.

## Documentation:
For more information on the KZG Marble Machine and the process, please visit the [GitHub Pages](https://github.com/ethereum/kzg-ceremony).
The machine is fully opensourced. All 3D files, programs and component list are available on Github.

## Proof of Contribution:
As proof of my contribution, here is a screenshot of the sequencer showing my Ethereum address ( xofee.eth : 0xFF141bFc450c57Ad84eBaFbD09ffa94A268a7aaE ) and contribution number (#83329) .

<img src="/images-videos/Contribution.png" width="576" height="324">

*#83329 Contribution details*

[My twitter post](https://twitter.com/Xofee3/status/1644033756066467840?s=20)

## Conclusion:
The KZG Marble Machine is a unique and innovative contribution to the KZG Ceremony. Its ability to generate random numbers using marbles and various sources of entropy makes it a valuable addition to the security of the ceremony. The machine’s intricate design and the attention to detail that went into its creation are a testament to the creativity and innovation that thrives in the world of cryptography. The fact that the machine is open-sourced further enhances its value as a contribution to the Ethereum community, and its documentation provides valuable insights into the process. Finally, we should not forget to thank all the people involved in making this possible, from the organizers of the KZG Ceremony to those who provided support and inspiration along the way.

Overall, the KZG Marble Machine is a fascinating example of how creativity and innovation can contribute to the security of decentralized systems.

*Randomly Xofee*
