#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void adc_init()
{
	// habilita ADC
	ADCSRA = (1 << ADEN);
	// AVcc com capacitor externo no pino AREF
	ADMUX |= (1 << REFS0);
	// seleciona prescaler 128, habilita ADC
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
}

void adc_set_channel(uint8_t ch)
{
	// seleciona o canal ADC
	ADMUX &= ~0xf;
	ADMUX |= ch;
	_delay_us(300);
}

uint16_t adc_read()
{
	// inicia a conversão
	ADCSRA |= (1 << ADSC);
    // enquanto não terminar...
	while (!(ADCSRA & (1 << ADSC)));
    // indica o fim da conversão
	ADCSRA |= (1 << ADIF);

	return ADC;
}

