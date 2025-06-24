#ifndef USART_H
#define USART_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

void USART_Init(void);
void USART_SendByte(uint8_t u8Data);
uint8_t USART_ReceiveByte(void);
void USART_puts(char* str);

#endif