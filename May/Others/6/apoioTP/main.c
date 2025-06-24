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

    char ultimaAcao = 'L'; // com pullup, liberado é qdo o botão tem valor 1;
                    //'P'; // com pullup, pressionado é qdo o botão está em 1;

    char estado = 'A'; // estado inicial
             //   'B'; // estado de configuração (alcançado qdo botão fica pressionado por mais de 3 segundo)
	
    int tempo=0;

    // Inicializa USART
    USART_Init();

    USART_SendByte(estado);
    for(;;){
        if((PINB & (1 << PB0))==1){  // ao perceber que o botão está liberado
            if(ultimaAcao=='P'){     // se antes ele estava pressionado
              USART_SendByte('L');
            }
            ultimaAcao = 'L';
            
        }
		else{                        // ao perceber que o botão está pressionado
            if(ultimaAcao=='L'){     // se antes ele estava liberado
              USART_SendByte('P');
              tempo=0;
            }
            else
              if(tempo>300){ // estamos num clique longo                
                estado=(estado=='A')?'B':'A';              
                USART_SendByte(estado);
                while((PINB & (1 << PB0))!=1) _delay_ms(5);
              }              
            ultimaAcao = 'P';
        }        
		_delay_ms(10); // ocorre 100x por segundo ==> 1segundo = 1000ms ==> 1000ms/10ms = 100 intervalos de 10ms
        tempo++;
    }
}
