/*	Partner(s) Name & E-mail: Olivia Smith: osmit003@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #2 Exercise #1
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;

    while(1)
    {
        // Read input
        tmpA = PINA & 0x03;

        // if PA1PA0 == 01, set PB0 = 1, else = 0
        if (tmpA == 0x01)
        {
            tmpB = (tmpB & 0xFE) | 0x01; // Sets tmpB to bbbbbbb1
        }
        else
        {
            tmpB = (tmpB & 0xFE);       // Sets tmpB to bbbbbbb0
        }
        PORTB = tmpB;
    }
    return 0;
}