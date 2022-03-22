/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "LCD.h"
#include "EEPROM.h"

#include <util/delay.h>

#define F_CPU 16000000

//int __attribute__ ((section(".Sandra"))) Sandravar;


/*int __attribute__ ((section(".SandraFunctions"))) add(int x,int y){
	return x+y;
};*/
int main(void){
	//Sandravar=3;
	DIO_INIT();
	LCD_INIT();
    uint8 data='m';
    uint8 address=0x05;
    int f;
	while(1){

		EEPROM_write(address,'S');
		data=EEPROM_read(address);
		//f = add(5,6)
		if(data=='S')
			TOGGLE_BIT(PORTC,2);
		_delay_ms(100);
	}



	return 0;
}
