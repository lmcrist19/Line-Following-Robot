# Line Following Robot

## Overview

This Arduino-based Line Following Robot is designed to follow a predefined path marked by a contrasting line. It uses a set of five infrared sensors to detect the line and make decisions on how to adjust its movement to stay on the line.

## Author

- **Author:** Lauren Crist
- **Date:** Spring 2021

## Table of Contents

- [Line Following Robot](#line-following-robot)
  - [Overview](#overview)
  - [Author](#author)
  - [Table of Contents](#table-of-contents)
  - [Components](#components)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Code Explanation](#code-explanation)

## Components

- Arduino board
- 5 Infrared line sensors (sens1 to sens5)
- 2 DC motors with motor drivers
- Wheels and chassis
- Breadboard and jumper wires

## Installation

1. **Connect the Hardware**: Assemble the robot. Ensure that the line sensors are properly aligned to detect the line.

2. **Upload the Code**: Use the Arduino IDE to upload the provided Arduino sketch (`LineFollowingRobot.ino`) to your Arduino board.

## Usage

1. **Calibration**: Before running the robot, it's essential to calibrate it for the specific line you want it to follow. Adjust sensor thresholds in the code to match the line's reflectivity.

2. **Run the Robot**: Place the robot on the line you want it to follow and power it on. The robot will use the infrared sensors to detect the line and adjust its motor movements to stay on the path.

3. **Monitor the Serial Output**: Connect the Arduino to your computer, open the Serial Monitor, and observe the sensor values and robot's decisions as it follows the line.

## Code Explanation

- The code reads values from the five infrared sensors and uses these values to determine the robot's course of action.
- Based on the sensor readings, the robot can either move straight, turn left, or turn right to stay on the line.
- The motor control functions (`straight`, `left`, and `right`) adjust the motor speeds and directions to achieve the desired movements.
