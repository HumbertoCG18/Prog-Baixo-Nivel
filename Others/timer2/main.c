#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define TIMER_CLK		F_CPU / 256

ISR(TIMER1_OVF_vect){
	PORTD ^= (1 << PD5);
	TCNT1  = 65536 - TIMER_CLK;
}

int main(void){
	// desabilita interrupções
	cli();
	
	// resseta contadores para TIMER1. OC2A e OC2B desconectados, modo normal
	TCCR1A = 0;
	TCCR1B = 0;
	// frequência: 1 Hz (65536 - 16MHz / 256)
	TCNT1  = 65536 - TIMER_CLK;
	// seta bit para prescaler 256
	TCCR1B |= (1 << CS12);
	// habilita máscara do timer1 para overflows
	TIMSK1 |= (1 << TOIE1);
	
	DDRD |= (1 << PD5);

	// habilita interrupções
	sei();

	while(1){
	}
}
