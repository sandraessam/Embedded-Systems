/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "UART.h"

void UART_INIT(void) {

//Set BaudRate
	UBRRL = Baudrate;
//Set Frame
#if Data_Mode==Bits_8
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);

#endif
//set Stop Bit
#if Stop_Bits==2
	SET_BIT(UCSRC, 3);
#endif
//set Parity
#if Parity_Mode==No_Parity
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);
#endif
//set Asynchronous Mode
	CLR_BIT(UCSRC, 6);
}

void UART_send_char(uint8 Data) {

	//Enable Transmitter
	SET_BIT(UCSRB, 3);
	//Wait
	while (!(GET_BIT(UCSRA, 5)))
		;
	//put Data
	UDR = Data;

}

uint8 UART_recieve_char(void) {
	//Enable Reciever
	SET_BIT(UCSRB, 4);
	//Wait
	while (!(GET_BIT(UCSRA, 7)))
		;
	//put Data
	return UDR;
}
void UART_recieve_char_with_Interrupt(void) {
	//Enable Reciever
	SET_BIT(UCSRB, 4);
	//Enable RX Interrupt complete
	SET_BIT(UCSRB, 7);
	SET_BIT(SREG, 7);

}
void UART_send_string(uint8* Data, uint8 len) {
	uint8 i;
	for (i = 0; i < len; i++) {
		UART_send_char(Data[i]);
		_delay_ms(10);
	}
}
uint8* UART_recieve_string(void) {
	static uint8 data[50];
	uint8 count=0;
	data[count]=UART_recieve_char();
	while(count!=50 || data[count]!='\0'){
		(count)++;
		data[count]=UART_recieve_char();
	}
	return data;
}
