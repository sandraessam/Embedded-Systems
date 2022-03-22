/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef UART_H_
#define UART_H_
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include <util/delay.h>

#define Stop_Bits 2
#define No_Parity 0
#define Bits_8 0
#define Parity_Mode No_Parity
#define Data_Mode Bits_8
#define Baudrate 103

void UART_INIT(void);
void UART_send_char(uint8 Data);
uint8 UART_recieve_char(void);
void UART_recieve_char_with_Interrupt(void);
void UART_send_string(uint8* Data,uint8 len);
uint8* UART_recieve_string(void);
#endif /* UART_H_ */
