#include <pic.h>                    // Include the PIC microcontroller header file
#define _XTAL_FREQ 20000000         // Tell the compiler our crystal runs at 20MHz (needed for delay functions)
__CONFIG(0x3F72);                   // Configure PIC16F877A settings (oscillator, watchdog, etc.)

// Define which pins control the LCD display
#define RS RD2                      // Register Select pin - chooses between command (0) or data (1) mode
#define EN RD3                      // Enable pin - triggers the LCD to read the data/command
#define DATA PORTB                  // Connect all 8 data lines (D0-D7) to PORTB pins

// Function to create the enable pulse that tells LCD to process the data
void lcd_enable() {
    EN = 1;                         // Pull enable pin high
    __delay_us(1);                  // Wait 1 microsecond for LCD to recognize the signal
    EN = 0;                         // Pull enable pin low (falling edge triggers LCD)
    __delay_ms(2);                  // Wait 2ms for LCD to finish processing
}

// Function to send a command to the LCD (like clear screen, cursor position, etc.)
void lcd_cmd(unsigned char cmd) {
    RS = 0;                         // Set RS to 0 to tell LCD we're sending a command
    DATA = cmd;                     // Put the command byte on the data lines
    lcd_enable();                   // Pulse the enable pin to execute the command
}

// Function to send a character to be displayed on the LCD
void lcd_data(unsigned char data) {
    RS = 1;                         // Set RS to 1 to tell LCD we're sending display data
    DATA = data;                    // Put the character byte on the data lines
    lcd_enable();                   // Pulse the enable pin to display the character
}

// Function to initialize the LCD with proper settings
void lcd_init() {
    __delay_ms(50);                 // Wait 50ms after power-on for LCD to stabilize
    lcd_cmd(0x38);                  // Configure LCD: 8-bit mode, 2 lines, 5x8 character font
    __delay_ms(5);                  // Wait 5ms for command to complete
    lcd_cmd(0x38);                  // Send the same command again (LCD initialization requirement)
    __delay_ms(1);                  // Short delay
    lcd_cmd(0x38);                  // Send it a third time to ensure proper initialization
    lcd_cmd(0x0C);                  // Turn display ON, turn cursor OFF, no blinking
    lcd_cmd(0x06);                  // Set entry mode: auto-increment cursor, no display shift
    lcd_cmd(0x01);                  // Clear the entire display and move cursor to home
    __delay_ms(2);                  // Wait for clear command to complete
}

// Main program function - starts here when PIC powers up
void main() {
    TRISB = 0x00;                   // Configure all PORTB pins as outputs (for LCD data lines)
    TRISD2 = 0;                     // Configure RD2 pin as output (for RS control)
    TRISD3 = 0;                     // Configure RD3 pin as output (for Enable control)
    PORTB = 0x00;                   // Initialize all PORTB pins to low (0V)
    PORTD = 0x00;                   // Initialize PORTD pins to low (0V)
    
    lcd_init();                     // Set up the LCD with proper configuration
    
    // Display "HELLO WORLD" one character at a time
    lcd_data('H');                  // Display the letter 'H'
    lcd_data('E');                  // Display the letter 'E'
    lcd_data('L');                  // Display the letter 'L'
    lcd_data('L');                  // Display the letter 'L'
    lcd_data('O');                  // Display the letter 'O'
    lcd_data(' ');                  // Display a space character
    lcd_data('W');                  // Display the letter 'W'
    lcd_data('O');                  // Display the letter 'O'
    lcd_data('R');                  // Display the letter 'R'
    lcd_data('L');                  // Display the letter 'L'
    lcd_data('D');                  // Display the letter 'D'
    
    while (1) {                     // Infinite loop - program stays here forever
        // Program keeps running but does nothing else
        // You could add blinking LEDs, sensor readings, or other functionality here
    }
}
