/*
 * LCD_CFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define RS PINA1
#define RW PINC1
#define E PINA2
#define LCD_WRITE_PORT 	PORT_A
#define LCD_Home 0x02
#define LCD_FunctionSet8bit 0x38
#define LCD_FunctionSet4bit 0x28
#define _4BITMODE 0
#define _8BITMODE 1
#define LCD_MODE _4BITMODE
#define LCD_DisplayOn 0x0C
#define LCD_Clear 0x01
#define LCD_EntryMode 0x06
#define LCD_FIRSTROW 0x80
#define LCD_SECONDROW 0xC0

const uint8 ExtraChar[];
#endif /* LCD_CFG_H_ */
