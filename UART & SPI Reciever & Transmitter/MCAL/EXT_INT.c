/*
 * EXT_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "EXT_INT.h"

void EXIT_INIT(uint8 EDGE) {
	SET_BIT(GICR, 7);
	SET_BIT(GICR, 6);
	if (EDGE == FALLING_EDGE) {
		CLR_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		CLR_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	} else if (EDGE == RISING_EDGE) {
		SET_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		SET_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
	}
	SET_BIT(SREG, 7);
}
void EXIT_DEINIT(void) {
	CLR_BIT(SREG, 7);
	CLR_BIT(GICR, 7);
	CLR_BIT(GICR, 6);
}
