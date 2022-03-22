/*
 * Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"
#include "../MCAL/DIO.h"
#include "Keypad.h"
#include <util/delay.h>

static uint8 KEYPAD_3[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
static uint8 KEYPAD_4[4][4] = { { 7, 8, 9, '/' }, { 4, 5, 6, '*' }, { 1, 2, 3,
		'-' }, { 'c', 0, '=', '+' } };

uint8 KEYPAD_READ(void) {
	uint8 key = NOT_PRESSED, r, c;
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 1, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 2, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 3, HIGH);
#if KEYPAD_TYPE== KEYPAD_3_BY_3
	for (r = 0; r < 3; r++) {
		DIO_WRITECHANNEL( KEYPAD_WRITEPORT + r, LOW);
		for (c = 0; c < 3; c++) {
			if (!DIO_READCHANNEL(KEYPAD_READPORT + c)) {
				key = KEYPAD_3[r][c];
				while (!DIO_READCHANNEL(KEYPAD_READPORT + c))
					;
			}
		}
		DIO_WRITECHANNEL(KEYPAD_WRITEPORT + r, HIGH);
	}

#elif KEYPAD_TYPE== KEYPAD_4_BY_4

	for (r = 0; r < 4; r++) {
		DIO_WRITECHANNEL( KEYPAD_WRITEPORT + r, LOW);
		for (c = 0; c < 4; c++) {
			if (!DIO_READCHANNEL(KEYPAD_READPORT + c)) {
				key = KEYPAD_4[r][c];
				while (!DIO_READCHANNEL(KEYPAD_READPORT+c))
				;
			}
		}
		DIO_WRITECHANNEL(KEYPAD_WRITEPORT+r, HIGH);
	}
#endif
	return key;
}
uint8 KEYPAD_READDEBOUNCING(void) {
	uint8 key = NOT_PRESSED, r, c;
	static uint8 PREVIOUS_KEY = NOT_PRESSED,count=0;
	uint8 CURRENT_KEY = NOT_PRESSED;

	DIO_WRITECHANNEL( KEYPAD_WRITEPORT, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 1, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 2, HIGH);
	DIO_WRITECHANNEL( KEYPAD_WRITEPORT + 3, HIGH);
#if KEYPAD_TYPE== KEYPAD_3_BY_3
	for (r = 0; r < 3; r++) {
		DIO_WRITECHANNEL( KEYPAD_WRITEPORT + r, LOW);
		for (c = 0; c < 3; c++) {
			if (!DIO_READCHANNEL(KEYPAD_READPORT + c)) {
				CURRENT_KEY = KEYPAD_3[r][c];
				if (PREVIOUS_KEY == CURRENT_KEY) {
					count++;
				} else {
					count = 0;
				}
				if (count == 5) {
					key = CURRENT_KEY;
				}
				PREVIOUS_KEY=CURRENT_KEY;
			}
		}
		DIO_WRITECHANNEL(KEYPAD_WRITEPORT + r, HIGH);
	}

#elif KEYPAD_TYPE== KEYPAD_4_BY_4

	for (r = 0; r < 4; r++) {
		DIO_WRITECHANNEL( KEYPAD_WRITEPORT + r, LOW);
		for (c = 0; c < 4; c++) {
			if (!DIO_READCHANNEL(KEYPAD_READPORT + c)) {
				CURRENT_KEY = KEYPAD_4[r][c];
				if(PREVIOUS_KEY==CURRENT_KEY) {
					count++;
				}
				else {count=0;}
				if(count==5) {
					key=CURRENT_KEY;
				}
				PREVIOUS_KEY=CURRENT_KEY;
				//TOGGLE_BIT(PORTA,0);
			}
		}
		DIO_WRITECHANNEL(KEYPAD_WRITEPORT+r, HIGH);
	}
#endif
	return key;
}
