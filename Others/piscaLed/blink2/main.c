#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB0);       // seta PB0 como saída
    DDRB |= (1 << PB1);       // seta PB1 como saída
    DDRD |= (1 << PD4);       // seta PD4 como saída

    while (1) {
        PORTB |= 1 << PB0;    // liga LED
        PORTB &= ~(1 << PB1); // desliga LED
        _delay_ms(500);
        PORTB &= ~(1 << PB0); // desliga LED
        PORTB |= 1 << PB1;    // liga LED
        _delay_ms(500);
        PORTD ^= 1 << PD4;    // inverte LED (toggle)
        _delay_ms(500);
    }
}
