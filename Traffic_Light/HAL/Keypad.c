/*
 * Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "Switch.h"
#include "Keypad.h"
#include <util/delay.h>
#include "DIO.h"

static uint8 KEYPAD_3[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
static uint8 KEYPAD_4[4][4] = { { 7, 8, 9, '/' }, { 4, 5, 6, '*' }, { 1, 2, 3,
		'-' }, { 'c', 0, '=', '+' } };

void KEYPAD_INIT(void) {
	uint8 i;
	for (i = PIN0; i <= PIN7; i++) {
		if (i < PIN4) {
			DIO_INIT_PIN_DIRECTION(KEYPAD_WRITEPORT, i, OUTPUT);
			DIO_WRITE_PIN_VALUE(KEYPAD_WRITEPORT, i, HIGH);
		} else {
			SW_INIT(KEYPAD_READPORT, i);
		}
	}
}

uint8 KEYPAD_READ(void) {
	uint8 key = 'm', r, c;

#if KEYPAD_TYPE== KEYPAD_3_BY_3
		for (r = PIN0; r < PIN3; r++) {
			DIO_WRITE_PIN_VALUE(KEYPAD_WRITEPORT, r, LOW);
			for (c = PIN4; c < PIN7; c++) {
				if (!SW_READ(KEYPAD_READPORT, c)) {
					key = KEYPAD_3[r][c - PIN4];
					while (!SW_READ(KEYPAD_READPORT, c));
				}
			}
			DIO_WRITE_PIN_VALUE(KEYPAD_WRITEPORT, r, HIGH);
		}

#elif KEYPAD_TYPE== KEYPAD_4_BY_4

		for (r = PIN0; r < PIN4; r++) {
				DIO_WRITE_PIN_VALUE(KEYPAD_WRITEPORT, r, LOW);
				for (c = PIN4; c <= PIN7; c++) {
					if (!SW_READ(KEYPAD_READPORT, c)) {
						key = KEYPAD_4[r][c - PIN4];
						while (!SW_READ(KEYPAD_READPORT, c));
					}
				}
				DIO_WRITE_PIN_VALUE(KEYPAD_WRITEPORT, r, HIGH);
			}
#endif
	return key;
}
