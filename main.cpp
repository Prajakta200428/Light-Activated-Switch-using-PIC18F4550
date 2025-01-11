#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

// Configuration bits
#pragma config FOSC = HS        // High-speed oscillator
#pragma config WDT = OFF        // Watchdog Timer disabled
#pragma config LVP = OFF        // Low Voltage Programming disabled
#pragma config MCLRE = ON       // MCLR pin enabled

#define _XTAL_FREQ 20000000     // 20MHz oscillator frequency

void init_ADC() {
    ADCON1 = 0x0E;              // Configure AN0 as analog input
    ADCON2 = 0xA9;              // Right justified, 20 TAD, Fosc/8
    ADCON0 = 0x01;              // Enable ADC and select AN0
}

unsigned int read_ADC() {
    ADCON0bits.GO = 1;          // Start conversion
    while (ADCON0bits.GO);      // Wait for conversion to complete
    return ((ADRESH << 8) + ADRESL); // Return result
}

void main() {
    TRISA = 0x01;               // Set RA0 as input
    TRISD = 0x00;               // Set PORTD as output
    PORTD = 0x00;               // Initialize PORTD to 0

    init_ADC();                 // Initialize ADC

    while (1) {
        unsigned int adc_value = read_ADC(); // Read ADC value

        if (adc_value > 48) {  // Adjust threshold as needed
            LATDbits.LATD0 = 0; // 
        } else {
            LATDbits.LATD0 = 1;
        }

        __delay_ms(1);        // Delay for stability
    }
}