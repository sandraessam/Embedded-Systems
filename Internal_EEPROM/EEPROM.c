/* EEPROM.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "EEPROM.h"


void EEPROM_write(uint16 Address, uint8 Data){
	/* Wait for completion of previous write */
	while(GET_BIT(EECR,EEMWE));
	while(GET_BIT(SPMCR,SPMEN));
	/* Set up address and data registers */
	EEAR = Address;
	EEDR = Data;
	/* Write logical one to EEMWE */
	/* Start eeprom write by setting EEWE */
	EECR |=(1<<EEMWE) |(1<<EEWE);

}

uint8 EEPROM_read(uint16 Address){
	/* Wait for completion of previous write */
	while(GET_BIT(EECR,EEMWE));
	TOGGLE_BIT(PORTB,0);
	/* Set up address register */
	EEAR = Address;
	/* Start eeprom read by writing EERE */

	SET_BIT(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}
