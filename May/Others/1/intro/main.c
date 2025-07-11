#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main (void) 
{
  DDRB |= (1 << PB0); // define GPIO PB0 como saída 
  while(1)
  {
    PORTB |= 1 << PB0;     // liga o led
    _delay_ms(500);
    PORTB &= ~(1 << PB0);  // desliga o led
    _delay_ms(500);
  }
}