/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"
#include "DIO.h"
#include "SPI.h"

void SPI_INIT_MASTER(void) {

	/*choose prescaler*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	SET_BIT(SPSR, 0);

	/*CHOOSE LSB */
	SET_BIT(SPCR, 5);
	/*choose polarity*/
	CLR_BIT(SPCR, 3);
	/*choose PHASE*/

	CLR_BIT(SPCR, 2);

	/* ENABLE MASTER*/
	SET_BIT(SPCR, 4);
	/*ENABLE SPI*/
	SET_BIT(SPCR, 6);

}
void SPI_INIT_SLAVE(void) {

	/*choose prescaler*/
	SET_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	SET_BIT(SPSR, 0);

	/*CHOOSE LSB */
	SET_BIT(SPCR, 5);
	/*choose polarity*/
	CLR_BIT(SPCR, 3);
	/*choose PHASE*/

	CLR_BIT(SPCR, 2);

	/* ENABLE SLAVE*/
	CLR_BIT(SPCR, 4);
	/*ENABLE SPI*/
	SET_BIT(SPCR, 6);

}

void SPI_SEND_DATA(uint8 data) {
	SPDR = data;
	while (!(GET_BIT(SPSR, 7)))
		;
}

uint8 SPI_RECIEVE_DATA(void) {
	while (!(GET_BIT(SPSR, 7)))
		;
	return SPDR;

}
