/*
 * WDG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include <util/delay.h>
#include"WDG.h"

void WDG_ENABLE(void) {
	//Timer Prescale Select
	SET_BIT(WDTCR, 0);
	SET_BIT(WDTCR, 1);
	SET_BIT(WDTCR, 2);
	//Timer Enable
	SET_BIT(WDTCR, 3);
}

void WDG_DISABLE(void) {
	//Timer Enable Select
	SET_BIT(WDTCR, 3);
	SET_BIT(WDTCR, 4);
	//_delay_ms(1000);
	//Timer Disable Select
	CLR_BIT(WDTCR, 3);
}

void WDG_REFRESH(void){
	asm volatile("wdr");
}
