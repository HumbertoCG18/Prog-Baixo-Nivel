#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


// Rotina de tratamento da interrupção PCINT0
ISR(PCINT0_vect)
{
    if (PINB & (1 << PB0)) {       // lê PB0
        PORTB ^= (1 << PB5);       // toggle em PB0
        while (PINB & (1 << PB0))
            _delay_ms(1);          // debounce
    }    
    _delay_ms(1);                  // debounce
}

int main(void)
{
    DDRB |= (1 << PB5);            // seta PB5 como saída
    DDRB &= ~(1 << PB0);           // seta PB0 como entrada
    PORTB &= ~(1 << PB0);          // desabilita pull-up de PB1
   
    PCICR |= (1 << PCIE0);         // habilita vetor de interrupção para PB7 .. PB0
    PCMSK0 |= (1 << PCINT0);       // habilita interrupção para PB1
    
    sei();

    while (1) {
    }
}
