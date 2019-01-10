/*	Partner(s) Name & E-mail: Olivia Smith: osmit003@ucr.edu
 *	Lab Section: 022
 *	Assignment: Lab #2 Exercise #2
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char cntavail = 0x00;

    while(1)
    {
        tmpA = PINA & 0x0F;

        if (tmpA == 0x00)
        {
            cntavail = 4;
        }
        else if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08)
        {
            cntavail = 3;
        }
        else if (tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 ||
                    tmpA == 0x0A || tmpA == 0x0C)
        {
            cntavail = 2;
        }
        else
        {
            cntavail = 1;
        }
        PORTC = cntavail;
    }
    return 0;
}