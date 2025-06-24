#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

char estadoAnterior=0;

int main (void) 
{
  DDRB |=  (1 << PB5); // define GPIO PB5 como saída 
  DDRB &= ~(1 << PB0); // zera o pino PB0 do DDRB, definindo como entrada
  
  while(1)
  {
	/*
	if(((PINB)&(1<<PB0))!=0)
      PORTB |= (1 << PB5);
    else
      PORTB &= ~(1 << PB5);
    */
    
    /*
	if( ((PINB)&(1<<PB0))!=0){
	  PORTB ^= (1<<PB5);
	  while( ((PINB)&(1<<PB0))!=0 ) _delay_ms(5);
	}
	*/
      
	if(((PINB)&(1<<PB0))!=0){
	  if(estadoAnterior==0)
	    PORTB ^= (1<<PB5);	  
	  estadoAnterior=1;
	}
	else
	  estadoAnterior=0;
	  
    _delay_ms(10);
  }
}
