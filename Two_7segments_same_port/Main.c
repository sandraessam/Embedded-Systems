
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
#include "Seven_Segment.h"
#include <util/delay.h>

#define F_CPU 16000000

int main(void) {
	SEVEN_SEG_INIT();
	DIO_INIT_PIN_DIRECTION(PORT_C, PIN6, OUTPUT);
	DIO_INIT_PIN_DIRECTION(PORT_C, PIN7, OUTPUT);
	uint8 num1 = 0;
	uint8 num2 = 0;
	while (1) {
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, LOW);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, HIGH);
		SEVEN_SEG_DISPLAY(num2);
		_delay_ms(90);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, HIGH);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, LOW);

		SEVEN_SEG_DISPLAY(num1);
		_delay_ms(90);
		num2++;
		if (num2 == 10) {
			num2 = 0;
			num1++;
			if (num1 == 10) {
				num1 = 0;
			}
		}

	}

	return 0;
}
