#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int ligado=0;
int tempo=0;
int estado=0; // 0 não pisca; 1 pisca (botão é o mecanismo de troca de estado)

int main(void)
{
    DDRB  |=  (1 << PB5);            // seta PB5 como saída
    PORTB &= ~(1 << PB5);

    DDRB  &=  ~(1 << PB0);            // seta PB0 como entrada
    
   
    while (1) {
		
		if((PINB & (1<<PB0))!=0){ // o botão foi pressionado
			estado=(estado==0)?1:0;
			while((PINB & (1<<PB0))!=0) _delay_ms(1);
		}		
		
		if(estado==0)
			PORTB |= (1 << PB5);
		else{		
			if(tempo>=500){
				PORTB ^= (1 << PB5);
				tempo=0;
			}
			tempo++;
		}
		
		_delay_ms(1);
    }
}
