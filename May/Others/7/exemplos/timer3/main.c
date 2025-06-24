#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define TIMER_CLK		F_CPU / 1024
// Freq. de interrupção: 10 Hz
#define IRQ_FREQ		10

ISR(TIMER1_COMPA_vect){
	PORTD ^= (1 << PD5);
}

int main(void){
	// desabilita interrupções
	cli();
	
	// resseta contadores para TIMER1
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	// seta o registrador output compare
	OCR1A = (TIMER_CLK / IRQ_FREQ) - 1;
	// liga modo CTC
	TCCR1B |= (1 << WGM12);
	// seta CS10 e CS12 para prescaler 1024
	TCCR1B |= (1 << CS12) | (1 << CS10);  
	// habilita máscara do timer1
	TIMSK1 |= (1 << OCIE1A);
	
	DDRD |= (1 << PD5);

	// habilita interrupções
	sei();

	while(1){
	}
}
