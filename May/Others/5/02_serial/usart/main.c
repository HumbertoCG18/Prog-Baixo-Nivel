#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// VALUE = F_FPU / (16 * BAUD) - 1
#define USART_UBBR_VALUE (((unsigned long)F_CPU/(unsigned long)(16*(unsigned long)USART_BAUD))-1)

void USART_Init(void) {
    // Seta taxa de transmissão/recepção (baud rate)
    UBRR0H = (uint8_t) (USART_UBBR_VALUE >> 8);
    UBRR0L = (uint8_t) USART_UBBR_VALUE;
    // Seta formato do frame de transmissão: 8 bits de dados, sem paridade, 1 stop bit
    UCSR0C = (0 << USBS0) | (3 << UCSZ00);
    // Habilita receptor e transmissor
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void USART_SendByte(uint8_t u8Data) {
    // Espera se um byte estiver sendo transmitido
    while ((UCSR0A & (1 << UDRE0)) == 0);
    // Transmite o byte
    UDR0 = u8Data;
}

uint8_t USART_ReceiveByte(void) {
    // Espera até um byte ter sido recebido
    while ((UCSR0A & (1 << RXC0)) == 0);
    return UDR0;
}

int main(void) {
	
	DDRB  = ~(1 << PB0);
	PORTB = (1 << PB0);
	
    uint8_t c;

    // Inicializa USART
    USART_Init();

    USART_SendByte('O');
    USART_SendByte('i');
    USART_SendByte('!');
    USART_SendByte('\n');
    // Implementar função abaixo!
    //USART_puts("\nHello World!\n");

    for(;;){
        // Faz "eco" de qualquer caractere recebido
        //c = USART_ReceiveByte();
        if((PINB & (1 << PB0))==1)
			USART_SendByte('1');
		else
			USART_SendByte('0');
		_delay_ms(500);
    }
}
