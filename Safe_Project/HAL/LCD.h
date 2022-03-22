/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef LCD_H_
#define LCD_H_
#include "LCD_CFG.h"

extern void LCD_INIT(void);
extern void LCD_VIDSENDCOMMAND(uint8 Command);
extern void LCD_VIDSENDCHAR(uint8 DATA);
extern void LCD_VIDGOTOXY(uint8 x,uint8 y);
extern void LCD_VIDSENDSTRING(uint8* STRING,uint8 MAX);
extern void LCD_WRITEEXTRACHAR(uint8 Row,uint8 Col);


#endif /* LCD_H_ */
