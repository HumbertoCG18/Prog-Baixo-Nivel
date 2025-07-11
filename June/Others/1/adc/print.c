#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usart.h"
#include "print.h"

// Converte inteiro para string, inclusive gerando hexadecimal se desejado (base=16)
static int8_t *itoa(int32_t i, int8_t *s, int32_t base)
{
	int8_t c;
	int8_t *p = s;
	int8_t *q = s;
	uint32_t h;

	if (base == 16) {
		h = (uint32_t)i;
		do {
			*q++ = '0' + (h % base);
		} while (h /= base);
		if ((i >= 0) && (i < 16)) *q++ = '0';
		for (*q = 0; p <= --q; p++){
			(*p > '9')?(c = *p + 39):(c = *p);
			(*q > '9')?(*p = *q + 39):(*p = *q);
			*q = c;
		}
	} else {
		if (i >= 0) {
			do {
				*q++ = '0' + (i % base);
			} while (i /= base);
		} else {
			*q++ = '-';
			p++;
			do{
				*q++ = '0' - (i % base);
			} while (i /= base);
		}
		for (*q = 0; p <= --q; p++) {
			c = *p;
			*p = *q;
			*q = c;
		}
	}
	return s;
}

// Escreve um inteiro na serial
void printint(uint32_t n)
{
	int8_t buf[30];
	uint16_t i;

	itoa(n, buf, 10);
	i = 0;
	while (buf[i]) USART_SendByte(buf[i++]);
}

// Escreve um hexadecimal na serial
void printhex(uint32_t n)
{
	int8_t buf[30];
	uint16_t i;

	itoa(n, buf, 16);
	i = 0;
	while (buf[i]) USART_SendByte(buf[i++]);
}

// Escreve um float na serial
void printfloat(float n)
{
	uint32_t v1, v2;
	
	v1 = (uint32_t)n;
	printint(v1);
	print(".");
	v2 = ((n - (float)v1) * 1000.0);
	if (v2 < 100) print("0");
	if (v2 < 10) print("0");
	printint(v2);
}

// Escreve uma string na serial
void print(char *s)
{
	while (*s) {
		USART_SendByte(*s);
		s++;
	}
}
