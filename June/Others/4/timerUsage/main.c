#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <time.h>

// ***********************************
// ** FUNÇÕES DE APOIO AO USO DO BOTÃO
// ***********************************
void BTN_Init() {
  DDRB &= ~(1 << PB0); // define GPIO PB0 como entrada  
}
// ************************************
// ** FUNÇÕES DE APOIO AO USO DE SERIAL
// ************************************
// VALUE = F_FPU / (16 * BAUD) - 1
#define USART_UBBR_VALUE (((unsigned long)F_CPU/(unsigned long)(16*(unsigned long)USART_BAUD))-1)

void USART_Init() {
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
void USART_putsInt(unsigned int valor){
	int tamChar=0;
	int aux=valor;
	//calcula o nro de digitos
	do{
		tamChar++;
		aux=aux/10; 
	}while(aux);
	
	char * str = malloc(sizeof(char)*(tamChar+1));
	str[tamChar]=0;
	
	aux=valor;
	int pos=tamChar-1;
	
	do{
	  int digito= aux%10;
	  str[pos]=digito+'0';
	  pos--;
	  aux=aux/10;
	}while(aux);		
	
    while(*str++)
        USART_SendByte(*str);
}

void USART_puts(char * str){
    while(*str++)
        USART_SendByte(*str);
}


// ***********************************
// ** FUNÇÕES DE APOIO AO USO DE TIMER
// ***********************************
time_t counter;
// Interrupção do timer2
ISR(TIMER2_OVF_vect){
    // toggle na porta PD5
	counter++;
	counter=(counter==(1024))?0:counter;
}

void timer_Init(){

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
}

// ************************************
// ************************************

int main(void){

	//inicializacao do timer
	timer_Init();
	USART_Init();
	DDRB &= ~(1 << PB0);
	int rodada=0;

	while(1){

		USART_putsInt(rodada++);
		USART_puts(": ");

		if(((PINB)&(1<<PB0))!=0){
		  	srand(counter);
			USART_puts(" -- ");
		}
		else
			USART_putsInt(rand());
		
		USART_SendByte('\n');
		_delay_ms(1000);

	}
}
