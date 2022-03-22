/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef DIO_H_
#define DIO_H_
#include "DIO_CFG.h"

void DIO_INIT(void);
void DIO_WRITECHANNEL(uint8 CHANNEL,uint8 VALUE);
void DIO_WRITEPORT(uint8 PORT,uint8 VALUE);
uint8 DIO_READPORT(uint8 PORT);
uint8 DIO_READCHANNEL(uint8 CHANNEL);


#endif /* DIO_H_ */
