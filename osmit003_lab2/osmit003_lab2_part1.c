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
            tmpB = (tmpB & 0xFD) | 0x01; // Sets tmpB to bbbbbbb1
        }
        else
        {
            tmpB = (tmpB & 0xFD);       // Sets tmpB to bbbbbbb0
        }
        PORTB = tmpB;
    }
    return 0;
}