#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main (void) 
{
  DDRB |= (1 << PB5); // define GPIO PB5 como saída 
  DDRB |= (1 << PB3);
  DDRB |= (1 << PB1);
  //DDRB |= (1 << PB5) | (1 << PB3) | (1 << PB1);
  
  while(1)
  {
    PORTB |= (1 << PB5);
    _delay_ms(200);
    PORTB |= (1 << PB3);
    _delay_ms(200);
    PORTB |= (1 << PB1);
    _delay_ms(200);
    PORTB &= ~(1 << PB5);
    _delay_ms(200);
    PORTB &= ~(1 << PB3);
    _delay_ms(200);
    PORTB &= ~(1 << PB1);
    _delay_ms(200);
  }
}
