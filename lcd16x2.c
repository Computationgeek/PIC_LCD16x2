#include <pic.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F72); // PIC16F877A config

// LCD control pins
#define RS RB0
#define EN RB1
#define DATA PORTD  // LCD data lines connected to RD0–RD7

// Pulse the enable pin
void lcd_enable() {
    EN = 1;
    __delay_us(1);
    EN = 0;
    __delay_ms(2);
}

// Send a command to LCD
void lcd_cmd(unsigned char cmd) {
    RS = 0;       // Command mode
    DATA = cmd;
    lcd_enable();
}

// Send a character to LCD
void lcd_data(unsigned char data) {
    RS = 1;       // Data mode
    DATA = data;
    lcd_enable();
}

// Initialize LCD
void lcd_init() {
    __delay_ms(20);
    lcd_cmd(0x38);  // 8-bit mode, 2 lines, 5x8 font
    lcd_cmd(0x0C);  // Display ON, cursor OFF
    lcd_cmd(0x06);  // Auto increment
    lcd_cmd(0x01);  // Clear display
    __delay_ms(2);
}

// Main function
void main() {
    TRISD = 0x00;    // All PORTD as output (D0–D7)
    TRISB0 = 0;      // RS pin output
    TRISB1 = 0;      // EN pin output

    PORTB = 0x00;
    PORTD = 0x00;

    lcd_init();

    lcd_data('H');
    lcd_data('E');
    lcd_data('L');
    lcd_data('L');
    lcd_data('O');

    while (1);  // Infinite loop
}
#include <xc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x3F72); // PIC16F877A config

// LCD control pins
#define RS RB0
#define EN RB1
#define DATA PORTD  // LCD data lines connected to RD0–RD7

// Pulse the enable pin
void lcd_enable() {
    EN = 1;
    __delay_us(1);
    EN = 0;
    __delay_ms(2);
}

// Send a command to LCD
void lcd_cmd(unsigned char cmd) {
    RS = 0;       // Command mode
    DATA = cmd;
    lcd_enable();
}

// Send a character to LCD
void lcd_data(unsigned char data) {
    RS = 1;       // Data mode
    DATA = data;
    lcd_enable();
}

// Initialize LCD
void lcd_init() {
    __delay_ms(20);
    lcd_cmd(0x38);  // 8-bit mode, 2 lines, 5x8 font
    lcd_cmd(0x0C);  // Display ON, cursor OFF
    lcd_cmd(0x06);  // Auto increment
    lcd_cmd(0x01);  // Clear display
    __delay_ms(2);
}

// Main function
void main() {
    TRISD = 0x00;    // All PORTD as output (D0–D7)
    TRISB0 = 0;      // RS pin output
    TRISB1 = 0;      // EN pin output

    PORTB = 0x00;
    PORTD = 0x00;

    lcd_init();

    lcd_data('H');
    lcd_data('E');
    lcd_data('L');
    lcd_data('L');
    lcd_data('O');

    while (1);  // Infinite loop
}
