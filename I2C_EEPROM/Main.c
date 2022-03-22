//ICU woith External Interrupt

/*
 * Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC.h"
#include "TIMER.h"
#include "EXT_INT.h"
#include "WDG.h"
#include "DIO.h"
#include "LCD.h"
#include "TWI.h"
#include "LCD.h"
#define F_CPU 16000000

uint8 d[50];
uint8 count = 0, flag = 0, temp;
uint8* D;
ISR(__vector_13) {
	temp = UDR;
	if (count == 50 || temp == '#') {
		count = 0;
		flag = 1;
		_delay_ms(1000);
		LCD_VIDSENDCOMMAND(LCD_Clear);
	} else {
		d[count] = temp;
		LCD_VIDSENDCHAR(d[count]);
		count++;
	}
}
int main(void) {

	DIO_INIT();
	//SPI_INIT_SLAVE();
	//UART_INIT();
	//UART_recieve_char_with_Interrupt();
	I2C_MASTER_INIT();
	//uint8 d = 0;
	LCD_INIT();
	//I2C_START_CONDITION(0x50, WRITE);
	while (1) {

	 I2C_START_CONDITION(0x50, WRITE);
	 TOGGLE_BIT(PORTA, 0);
	 _delay_ms(100);
	 I2C_WRITE_DATA_ACK(0x01);
	 _delay_ms(100);
	 I2C_WRITE_STRING_ACK("SANDRA");
	 I2C_STOP_CONDITION();
	 _delay_ms(1000);
	 //I2C_STOP_CONDITION();
	 I2C_START_CONDITION(0x50, WRITE);
	 I2C_WRITE_DATA_ACK(0x01);
	 I2C_REPEATED_START_CONDITION(0x50, READ);
	 _delay_ms(100);
	 D = I2C_READ_STRING_ACK();
	 I2C_STOP_CONDITION();
	 }
	/*while (1) {
		/*	if (flag == 1) {
		 UART_send_string("Done", 5);
		 flag = 0;
		 }*/
	/*	D = SPI_RECIEVE_DATA();
		LCD_VIDSENDCOMMAND(LCD_Clear);
		LCD_VIDSENDCHAR(D + 48);

	}*/
	/*	if(DIO_READCHANNEL(PINA2)==0 && DIO_READCHANNEL(PINA3)==1){
	 UART_send_char(0);
	 }
	 else if(DIO_READCHANNEL(PINA2)==1 && DIO_READCHANNEL(PINA3)==0){
	 UART_send_char(1);
	 }
	 else{

	 }*/
	/*	d=SPI_RECIEVE_DATA();
	 LCD_VIDSENDCOMMAND(LCD_Clear);
	 LCD_VIDSENDCHAR(d+48);*/

	//}
	return 0;
}
