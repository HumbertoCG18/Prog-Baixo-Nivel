#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int counter;
// Interrupção do timer2
ISR(TIMER2_OVF_vect){
    // toggle na porta PD5
	counter++;
	counter=(counter==32)?0:counter;
	if(counter==0)
    	PORTD ^= (1 << PD5);
}

int main(void){
	// desabilita interrupções
	cli();
	counter=0;
	
	// inicializa timer em modo normal
	TCCR2A = 0x00;
	// prescaler é 1024
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20);

	// gera interrupção quando ocorre overflow em TCNT2
    // 16MHz / 1024 (prescaler) / 256 (registrador de 8 bits)
	TIMSK2 = (1 << TOIE2);

    // seta PD5 como saída    
	DDRD |= (1 << PD5);

	// habilita interrupções
	sei();

	while(1){
	}
}
