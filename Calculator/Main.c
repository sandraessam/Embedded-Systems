//ICU with External Interrupt

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
#include "Keypad.h"
#include "TWI.h"
#include "LCD.h"
#define F_CPU 16000000

#define FIRST_STATE 1
#define SECOND_STATE 2
#define THIRD_STATE 3
#define FOURTH_STATE 4

int main(void) {

	DIO_INIT();
	uint8 num[10];
	uint8 d = 0, state = FIRST_STATE;
	uint8 num1 = 0, num2 = 0, op = '=', i, count = 0, re = 0;
	uint64 res = 0, div = 0;
	LCD_INIT();
	LCD_VIDGOTOXY(0, 0);
	while (1) {

		d = KEYPAD_READ();
		if (d != NOT_PRESSED) {
			switch (state) {
			case FIRST_STATE:
				if (d == '+' || d == '-' || d == '*' || d == '/') {
					state = SECOND_STATE;
					LCD_VIDSENDCHAR(d);
					op = d;
				} else if (d == '=') {
					state = FOURTH_STATE;
					LCD_VIDSENDCHAR(d);
				} else if (d == 'c') {
					num1 = 0;
					num2 = 0;
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
				} else {
					num1 = num1 * 10 + d;
					LCD_VIDSENDCHAR(d + 48);
				}
				break;
			case SECOND_STATE:
				if (d == 'c') {
					num1 = 0;
					num2 = 0;
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
				} else if (d >= 0 && d <= 9) {
					num2 = num2 * 10 + d;
					LCD_VIDSENDCHAR(d + 48);
					state = THIRD_STATE;
				} else {
					LCD_VIDSENDCOMMAND(LCD_Clear);
					LCD_VIDSENDSTRING("ERROR", 5);
					_delay_ms(500);
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
					num1 = 0;
					num2 = 0;
				}
				break;
			case THIRD_STATE:
				if (d == '+' || d == '-' || d == '*' || d == '/') {
					LCD_VIDSENDCOMMAND(LCD_Clear);
					LCD_VIDSENDSTRING("ERROR", 5);
					_delay_ms(500);
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
					num1 = 0;
					num2 = 0;
				} else if (d == '=') {
					state = FOURTH_STATE;
					LCD_VIDSENDCHAR(d);
				} else if (d == 'c') {
					num1 = 0;
					num2 = 0;
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
				} else {
					num2 = num2 * 10 + d;
					LCD_VIDSENDCHAR(d + 48);
				}
				break;
			case FOURTH_STATE:
				if (d == '+' || d == '-' || d == '*' || d == '/') {
					LCD_VIDSENDCOMMAND(LCD_Clear);
					LCD_VIDSENDSTRING("ERROR", 5);
					_delay_ms(500);
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
					num1 = 0;
					num2 = 0;
				} else if (d == 'c') {
					num1 = 0;
					num2 = 0;
					LCD_VIDSENDCOMMAND(LCD_Clear);
					state = FIRST_STATE;
				} else if (d >= 0 && d <= 9) {
					LCD_VIDSENDCOMMAND(LCD_Clear);
					num1 = d;
					num2 = 0;
					LCD_VIDSENDCHAR(d + 48);
					state = FIRST_STATE;

				} else {
					switch (op) {
					case '+':
						res = num1 + num2;
						break;
					case '-':
						res = num1 - num2;
						break;
					case '/':
						res = num1 / num2;
						break;
					case '*':
						res = num1 * num2;
						break;
					}
					div = res;
					LCD_VIDGOTOXY(1, 5);
					LCD_VIDSENDSTRING("                                 ", 16);
					LCD_VIDGOTOXY(1, 8);
					do {
						re = div % 10;
						div = div / 10;
						num[count] = re;
						count++;

					} while (re != 0 || div != 0);
					for (i = count; i > 0; i--) {
						LCD_VIDSENDCHAR(num[i] + 48);
					}
					LCD_VIDSENDCHAR(num[i] + 48);
					count = 0;
				}
				break;
			}
		}
	}
	return 0;
}
