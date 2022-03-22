/*
 * LCD.C
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

void LCD_VIDSENDCOMMAND(uint8 Command) {
#if LCD_MODE==_8BITMODE
	DIO_WRITECHANNEL(PINA6,HIGH);
	/* SET RS to LOW */
	DIO_WRITECHANNEL(RS, LOW);
	/* SET R/W to LOW */
	DIO_WRITECHANNEL( RW, LOW);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	/* WRITE COMMAND */
	DIO_WRITEPORT( LCD_WRITE_PORT, Command);
	/* SET E to LOW */
	DIO_WRITECHANNEL( E, LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	_delay_ms(5);
#elif LCD_MODE==_4BITMODE
	uint8 c=0;
	/* SET RS to LOW */
	DIO_WRITECHANNEL(RS,LOW);
	/* SET R/W to LOW */
	DIO_WRITECHANNEL( RW ,LOW);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E ,HIGH);
	/* WRITE COMMAND */
	c=(((Command >>1)& 0x78)| 0x04)| DIO_READCHANNEL(PINA0);
	DIO_WRITEPORT( LCD_WRITE_PORT ,c);
	/* SET E to LOW */
	DIO_WRITECHANNEL( E ,LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E ,HIGH);
	_delay_ms(1);
	/* WRITE COMMAND */
	//c=(Command & 0x0F);
	c=(((Command<<3)& 0x78)| 0x04)| DIO_READCHANNEL(PINA0);
	DIO_WRITEPORT( LCD_WRITE_PORT ,c);
	/* SET E to LOW */
	DIO_WRITECHANNEL( E ,LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E ,HIGH);
	_delay_ms(5);
#endif
}

void LCD_INIT(void) {
	_delay_ms(30);
	/* RETURN_HOME */
	LCD_VIDSENDCOMMAND(LCD_Home);
	_delay_ms(1);
	/* FUNCTION SET */
#if LCD_MODE==_8BITMODE
	LCD_VIDSENDCOMMAND(LCD_FunctionSet8bit);
#elif LCD_MODE==_4BITMODE
	LCD_VIDSENDCOMMAND(LCD_FunctionSet4bit);
#endif
	_delay_ms(1);
	/* DISPLAY ON/OFF CONTROL */
	LCD_VIDSENDCOMMAND(LCD_DisplayOn);
	/* CLEAR DISPLAY */
	LCD_VIDSENDCOMMAND(LCD_Clear);
	/* ENTRY MODE SET */
	LCD_VIDSENDCOMMAND(LCD_EntryMode);
	_delay_ms(1);

}
extern void LCD_VIDSENDCHAR(uint8 DATA) {
#if LCD_MODE==_8BITMODE
	/* SET RS to HIGH */
	DIO_WRITECHANNEL(RS, HIGH);
	/* SET R/W to LOW */
	DIO_WRITECHANNEL( RW, LOW);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	/* WRITE COMMAND */
	DIO_WRITEPORT( LCD_WRITE_PORT, DATA);
	/* SET E to LOW */
	DIO_WRITECHANNEL( E, LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	_delay_ms(5);
#elif LCD_MODE==_4BITMODE
	/* SET RS to HIGH */
	DIO_WRITECHANNEL(RS, HIGH);
	/* SET R/W to LOW */
	DIO_WRITECHANNEL( RW, LOW);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	/* WRITE COMMAND */
	DIO_WRITEPORT( LCD_WRITE_PORT, (((DATA >>1)& 0x78)|0x06)| DIO_READCHANNEL(PINA0));
	/* SET E to LOW */
	DIO_WRITECHANNEL( E, LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	_delay_ms(1);
	/* WRITE COMMAND */
	DIO_WRITEPORT( LCD_WRITE_PORT, (((DATA <<3)& 0x78)| 0x06)| DIO_READCHANNEL(PINA0));
	/* SET E to LOW */
	DIO_WRITECHANNEL( E, LOW);
	/* wait for E to settle */
	_delay_ms(2);
	/* SET E to HIGH */
	DIO_WRITECHANNEL( E, HIGH);
	_delay_ms(5);
#endif
}

void LCD_VIDGOTOXY(uint8 x, uint8 y) {
	if (y >= 0 && y < 16) {
		switch (x) {
		case 0:
			LCD_VIDSENDCOMMAND(y + LCD_FIRSTROW);
			break;
		case 1:
			LCD_VIDSENDCOMMAND(y + LCD_SECONDROW);
			break;
		}
	}
}

void LCD_VIDSENDSTRING(uint8* STRING, uint8 MAX) {
	uint8 i = 0;
	for (i = 0; i < MAX; i++) {
		LCD_VIDSENDCHAR(STRING[i]);
	}
	_delay_ms(2);
}
void LCD_WRITEEXTRACHAR(uint8 Row,uint8 Col){
uint8 iteration1,iteration2;
if((Col>=0 && Col<16)&& ((Row==0 || Row==1))){
	//DIO_WRITECHANNEL(PINC0,HIGH);
	LCD_VIDSENDCOMMAND(0x40);
	for(iteration1=0;iteration1<64;iteration1++){
		LCD_VIDSENDCHAR(ExtraChar[iteration1]);
	}
LCD_VIDSENDCOMMAND(0x80);
LCD_VIDGOTOXY(Row,Col);
for(iteration2=0;iteration2<8;iteration2++){

		LCD_VIDSENDCHAR(iteration2);}

}

}
