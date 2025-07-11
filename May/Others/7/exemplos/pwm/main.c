#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void){
	// desabilita interrupções
	cli();
	
	// inicializa timer no modo 7, fast PWM
    // seta OC2B para bottom, limpa OC2B em compare match
	TCCR2A = (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);

	// prescaler é 256
	TCCR2B = (1 << CS22) | (1 << CS21) | (1 << WGM22);
	
	OCR2A = 100;
	OCR2B = 25;  // 25% duty cycle
	
	// habilita interrupções - PWM no PD3
	DDRD |= (1 << PD3);
	sei();

    uint8_t duty = 10;

	while (1) {
        OCR2B = duty;
        _delay_ms(20);
        if(duty++>100) duty = 10;
	}
}
