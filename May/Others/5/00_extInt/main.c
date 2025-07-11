#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Rotina de tratamento da INT0
ISR(INT0_vect)
{
    PORTB ^= (1 << PB5);
    _delay_ms(200);
}

// Rotina de tratamento da INT1
ISR(INT1_vect)
{
    PORTB ^= (1 << PB7);
    _delay_ms(200);
}

int main(void)
{
    DDRB |= (1 << PB5) | (1 << PB7);    // seta PB5 e PB7 como saídas
    DDRB |= (1 << PB1);    // seta PB1 como saídas
    
    DDRD &= ~((1 << PD2) | (1 << PD3)); // seta PD2 and PD3 como entradas
    PORTD = (1 << PD2) | (1 << PD3);    // habilita pull-ups

    EICRA = (0 << ISC01) | (1 << ISC00);  // interrupt sense control, borda de subida (rising edge) para INT0
    EICRA |= (1 << ISC11) | (0 << ISC10); // interrupt sense control, borda de descida (falling edge) para INT1

    EIMSK |= (1 << INT1) | (1 << INT0);   // enable INT1 and INT0

    sei(); // habilita interrupções

    while (1)
    {
		PORTB ^= (1 << PB1);
		_delay_ms(250);
		PORTB ^= (1 << PB1);
		_delay_ms(250);
		PORTB ^= (1 << PB1);
		_delay_ms(250);
		PORTB ^= (1 << PB1);
		_delay_ms(250);
    }
}
