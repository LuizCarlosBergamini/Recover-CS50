# Recovery-CS50

This program recovers JPEG files from a memory card image.

## Table of Contents

- [Project Description](#project-description)
- [Installation](#installation)
- [Usage](#usage)

## Project Description

JPEG Recovery is a C program that reads a raw and identifies and recovers JPEG files present in it. It uses file analysis techniques to locate the start and end markers of JPEG files and creates individual JPEG files from the memory card raw.

## Installation

To install and run the JPEG Recovery program, follow these steps:

1. Clone the repository or download the source code.
2. Compile the `recover.c` file using a C compiler.
3. Execute the compiled program, providing the memory card image file as a command-line argument.

Make sure you have the necessary dependencies (such as `stdio.h`, `stdlib.h`, and `stdint.h`) installed on your system.

## Usage

Once you have compiled and executed the JPEG Recovery program, follow the instructions below:

1. Run the program with the memory card raw file as a command-line argument: `./recover IMAGE`.
2. The program will read the memory card image and recover any JPEG files it finds.
3. The recovered JPEG files will be saved with names like `001.jpg`, `002.jpg`, etc.

Example usage:

```shell
$ ./recover memorycard.raw
001.jpg created
002.jpg created
003.jpg created
...
