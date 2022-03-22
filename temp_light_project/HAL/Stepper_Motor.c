/*
 * Stepper_Motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"
#include "../MCAL/DIO.h"
#include <util/delay.h>
#include "Stepper_Motor.h"

void MOTOR_INIT(void) {
	DIO_WRITECHANNEL(BLUE, LOW);
	DIO_WRITECHANNEL(PINK, LOW);
	DIO_WRITECHANNEL(YELLOW, LOW);
	DIO_WRITECHANNEL(ORANGE, LOW);
}

void MOTOR_CWFULL(void) {
	uint8 i;
	const uint8 Colour[4] = { BLUE, PINK, YELLOW, ORANGE };
	for (i = 0; i < 4; i++) {
		DIO_WRITECHANNEL(Colour[i], HIGH);
		_delay_ms(10);
		DIO_WRITECHANNEL(Colour[i], LOW);
	}
}

void MOTOR_CWHALF(void) {
	uint8 i;
	const uint8 CW_HM[8]={9,1,3,2,6,4,12,8};
	for (i = 0; i < 8; i++) {
		DIO_WRITECHANNEL(BLUE, (CW_HM[i]>>0)&1);
		DIO_WRITECHANNEL(PINK, (CW_HM[i]>>1)&1);
		DIO_WRITECHANNEL(YELLOW,(CW_HM[i]>>2)&1);
		DIO_WRITECHANNEL(ORANGE, (CW_HM[i]>>3)&1);
		_delay_ms(10);
	}
}
