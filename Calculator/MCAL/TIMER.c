/*
 * TIMER.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include"TIMER.h"

void TIMER0_INIT(void) {
	//Select Mode
	if (T0_MODE == NORMAL) {
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		CLR_BIT(TCCR0, 4);
		CLR_BIT(TCCR0, 5);
		//Enable OVERFLOW INTERRUPT
		SET_BIT(TIMSK, 0);
		//Enable Global Interrupt
		SET_BIT(SREG, 7);
	} else if (T0_MODE == CTC) {
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		//Toggle OCR0
		SET_BIT(TCCR0, 4);
		CLR_BIT(TCCR0, 5);
		//Enable Compare Match INTERRUPT
		SET_BIT(TIMSK, 1);
		//Enable Global Interrupt
		SET_BIT(SREG, 7);
	} else if (T0_MODE == FAST_PWM) {
		SET_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
		//Toggle OCR0 (Non_Inverting)
		CLR_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		//Enable Compare Match INTERRUPT
		SET_BIT(TIMSK, 1);
		//Enable Global Interrupt
		SET_BIT(SREG, 7);
	}
	//SET PRESCALER at 1024
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);

}

void TIMER1_INIT(void) {
	//Select Mode
	if (T1_MODE == NORMAL) {
		CLR_BIT(TCCR1A, 0);
		CLR_BIT(TCCR1A, 1);
		CLR_BIT(TCCR1B,3);
		CLR_BIT(TCCR1B,4);
		CLR_BIT(TCCR1A, 4);
		CLR_BIT(TCCR1A, 5);
		CLR_BIT(TCCR1A, 6);
		CLR_BIT(TCCR1A, 7);
		//Enable OVERFLOW INTERRUPT
		SET_BIT(TIMSK, 2);
		//Enable Global Interrupt
		SET_BIT(SREG, 7);
	}
	//SET PRESCALER at 1024
	SET_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 1);
	SET_BIT(TCCR1B, 2);

}

