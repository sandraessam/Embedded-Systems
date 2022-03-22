/*
 * TWI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef TWI_H_
#define TWI_H_

#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"

#define READ 1
#define WRITE 0
#define TWINT 7
#define TWEN 2
#define TWSTA 5
#define TWEA 6
#define TWSTO 4

void I2C_MASTER_INIT(void);
void I2C_SLAVE_INIT(uint8 Slave_Address);
void I2C_START_CONDITION(uint8 Slave_Address, uint8 R_W);
void I2C_STOP_CONDITION(void);
void I2C_REPEATED_START_CONDITION(uint8 Slave_Address, uint8 R_W);
uint8 I2C_READ_DATA_ACK(void);
uint8 I2C_READ_DATA_NO_ACK(void);
void I2C_WRITE_DATA_ACK(uint8 Data);
void I2C_WRITE_DATA_NO_ACK(uint8 Data);
void I2C_WRITE_STRING_ACK(uint8* Data);
uint8* I2C_READ_STRING_ACK(void);
uint8 GET_STATUS(void);

#endif /* TWI_H_ */
