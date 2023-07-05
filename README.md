# TempReader

![v1.1.0](https://img.shields.io/badge/Version-1.1.0-green)
![Library CI](https://github.com/JoelJojoP/TempReader/workflows/Arduino%20Library%20CI/badge.svg)
[![GitHub issues](https://img.shields.io/github/issues/JoelJojoP/TempReader?color=blue&label=Issues&style=flat)](https://github.com/JoelJojoP/TempReader/issues)

## Overview:
The ATMega328P microcontroller chip used in development boards like Arduino Uno and Arduino Nano have an internal temperature sensor wired to the 8th channel of the inbuilt Analog to digital convertor (ADC) on the chip.

This library enables the user to obtain measurements from the internal temperature sensor of the chip using a single function. There are two functions that can be used:

- ```ReadTempinC()``` is used to get temperature reading in ℃
- ```ReadTempinF()``` is used to get temperature reading in ℉

## Bugs:

- Temperature readings are wrong when using ```analogRead()``` function.

## License:

This repository is licensed under the [MIT Licence](https://github.com/JoelJojoP/TempReader/blob/main/LICENSE)
