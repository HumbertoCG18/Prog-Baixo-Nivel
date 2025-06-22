#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB5);       // seta PB5 como saída

    while (1)
    {
        PORTB |= (1 << PB5);  // liga LED
        _delay_ms(500);
        PORTB &= ~(1 << PB5); // desliga LED
        _delay_ms(500);
    }
}
