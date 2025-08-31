PIC_LCD16x2

A simple bare-metal C program to interface a 16x2 character LCD with a PIC microcontroller (PIC16F877A) using the MPLAB IDE. The code initializes the LCD in 8-bit mode and displays text without using external libraries.

This educational project demonstrates how we can interface LCD 16x2 Display with timing function based on LCD controller used in the display mostly HD44780

Outcome of This Project:

-> Not depending on libraries only baremetal C and Simple delay-based timing

-> We can understand how this display works in hardware Level which is not possible with libraries and function calls

Hardware Needed:

-> PIC16F877A Microcontroller

-> LCD 16x2 Display(HD44780 Based)

-> Contrast control potentiometer - 10K

-> 20MHz Crystal Oscillator

-> 5V Power Supply

Pin Configuration:

-> LCD RS pin → PIC RD2

-> LCD EN pin → PIC RD3

-> LCD Data pins (D0-D7) → PIC PORTB (RB0-RB7)


Software Requirements:

-> MPLAB IDE or MPLAB X IDE

-> HI-TECH C Compiler

Note: You can also simulate this project in Proteus circuit simulation software by building the project to generate a HEX file, then loading this HEX file into the PIC16F877A component in Proteus simulation.

