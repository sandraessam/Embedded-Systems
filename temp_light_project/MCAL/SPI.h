/*
 * SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef SPI_H_
#define SPI_H_
#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"

void SPI_INIT_MASTER(void);
void SPI_INIT_SLAVE(void);
void SPI_SEND_DATA(uint8 data);
uint8 SPI_RECIEVE_DATA(void);

#endif /* SPI_H_ */
