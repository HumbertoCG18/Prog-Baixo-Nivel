#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

char keypadChar[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};

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

void configKeypad(){
    // definir os pinos de entrada do keypad
    // estimulos pelos pinos de coluna do keypad
    DDRB |= (1 << PB5);
    DDRB |= (1 << PB6);
    DDRB |= (1 << PB7);

    // seta PD0 como entrada
    DDRB &= ~(1 << PB0);  
    DDRB &= ~(1 << PB1);  
    DDRB &= ~(1 << PB2);  
    DDRB &= ~(1 << PB3);  
}

char scanKeypad(){
    PORTB = 0;
    int row=-1;
    int col=-1;
    for(int c=0; c<3; c++)// passar por cada uma das coluna
    {
        // gero estímulo na entrada (1)
        PORTB |= (1<< (PB5+c));
        
        //scanner das linhas
        for(int l=0; l<4; l++)
        {
            if((PINB & (1<<(PB0+l)))!=0){
                row=l;
                col=c;
                while((PINB & (1<<(PB0+l)))) _delay_ms(2);
            }
        }
        // retiro o estimulo da entrada (0)
        PORTB &= ~(1<< (PB5+c));
    }
    if((row==-1)||(col==-1))
        return 0;
    else
        return keypadChar[row][col];
}

int main(void)
{
    configKeypad();
    USART_Init();

    char ultimo=-1;
    while(1){
        char valor=scanKeypad();
        if(valor!=ultimo){
            if(valor==0)
                USART_SendByte('-');
            else
                USART_SendByte(valor);
        }
        ultimo=valor;
        _delay_ms(10);
    }
    
}
