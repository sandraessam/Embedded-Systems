/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"

#define EEMWE 2
#define EEWE 1
#define EERE 0
#define SPMEN 0

void EEPROM_write(uint16 Address, uint8 Data);
uint8 EEPROM_read(uint16 Address);



#endif /* EEPROM_H_ */
