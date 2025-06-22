#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB5);       // seta PB5 como saída
    DDRB &= ~(1 << PB0);      // seta PB0 como entrada
    DDRB &= ~(1 << PB1);      // seta PB1 como entrada
    
    int estado=0;

    while (1)
    {
		int valorDoBotaoPB0 = (PINB & (1<<PB0));
		int valorDoBotaoPB1 = (PINB & (1<<PB1));
		
		if((valorDoBotaoPB0!=0)||(valorDoBotaoPB1==0)){
			if(estado==0)
				estado=1;
			else
				estado=0;
		}

		if (estado==0)
			PORTB &= ~(1 << PB5); // desliga LED
		else
			PORTB |= (1 << PB5);  // liga LED
			
		while( ((PINB & (1<<PB0)) != 0) ) _delay_ms(1); // tratar o pb0
		while( ((PINB & (1<<PB1)) == 0) ) _delay_ms(1); // tratar o pb1
        
        _delay_ms(1);
    }
}
