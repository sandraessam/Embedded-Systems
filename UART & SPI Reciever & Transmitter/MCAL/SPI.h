/*
 * SPI.h
 *
 *  Created on: ??�/??�/????
 *      Author: Copy Center
 */

#ifndef SPI_H_
#define SPI_H_
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"

void SPI_INIT_MASTER(void);
void SPI_INIT_SLAVE(void);
void SPI_SEND_DATA(uint8 data);
uint8 SPI_RECIEVE_DATA(void);

#endif /* SPI_H_ */
