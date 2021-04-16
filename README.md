# Face-mask vending system

## Introduction

The project involves coming up with a mask dispensing system that alerts a person when they exit their home. With an added function of alerting the person when the number of masks runs low.

## Components

1 Arduino MEGA 2560 board,
2 HC-SRO4 ultrasonic sensors,
1 LCD display,
1 Potentiometer,
1 Membrane Keypad,
1 Active Buzzer,
1 Breadboard,
2 LEDs (green and red),
2 220Ω resistors,
Several jumper-wires

## Specifications

### HC-SR04 Ultrasonic Sensor
Working Voltage: DC 5V,
Working Current: 15mA,
Working Frequency: 40Hz,
Min Range: 2cm,
Max Range: 4m,
Measuring Angle: 15°.

**Pin-out**

VCC: Power GND: Ground TRIG: trigger output ECHO: echo input

### Active buzzer
Rated Voltage:	5V DC,
Operating Voltage:	4~8V,
Max Rated Current:	≤32 mA,
Min. Sound Output: at 10cm	85 dB,
Resonant Frequency:	2300 ±300 Hz,
Operating Temperature:	-20°C to 45°C

**Pin-out**

Longer pin is the positive pin, GND

### Matrix Membrane Keypad
Number of Keys:	16, 
Layout:	4x4,
Current Rating:	30 mA,
Voltage Rating:	12V DC
Lifetime:	1 million clicks or more,
Reclosing time:	≤5ms

**Pin-out**

8-pin access to the matrix

### LCD 
Operating voltage:	5±0.3V DC,
Operating current: 1mA (without backlight),
Controller:	Hitachi HD44780 LCD controller,
Screen resolution:	2 lines x 16 characters,
Character resolution:	5 x 8 pixels

**Pin-out**
 Pin no. | Label | Connection	| Function 
---|---|---|---
 1 | VSS | GND | Signal ground 
2 | VDD | 5V | Logic power for LCD 
3	| V0 | 10 kΩ potentiometer |	Contrast adjustment
4	| RS	| Pin 7 | Register select signal
5	| R/W	| GND |	Read/write select signal (grounded to write)
6	| E	| Pin 8 | Operation enable signal
7–14 | D0 – D7 |	| Data bus lines used for 8-bit mode
11-14 |	D4 – D7	| Pin 9-12 |	Data bus lines used for 4-bit mode
15 | A (LED+) |	5V | Anode for LCD backlight
16 | K (LED-)	| GND | Cathode for LCD backlight

## Breadboard Layout
![Breadboard layout](Fritzing/Method%20B_bb.jpg)
