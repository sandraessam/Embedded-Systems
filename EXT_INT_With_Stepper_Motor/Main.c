/*
 * Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "EXT_INT.h"
#include "Stepper_Motor.h"

#define F_CPU 16000000

ISR (INT0_vect) {
	TOGGLE_BIT(PORTB, 0);
}
ISR (INT1_vect) {
	TOGGLE_BIT(PORTB, 1);
}

uint8 i=0;
int main(void) {
	DIO_INIT();
	EXIT_INIT(FALLING_EDGE);
	while (1) {
		for(i=0;i<128;i++){
		 MOTOR_CWFULL();}
		 }




	return 0;
}
