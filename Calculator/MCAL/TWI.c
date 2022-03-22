/*
 * TWI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "LCD.h"
#include "TWI.h"
#include <util/delay.h>

void I2C_MASTER_INIT(void) {
	//Bit Rate (SCL Frequency)
	TWBR = 3;
	//Prescaler 1
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);
	//Enable I2C
	SET_BIT(TWCR, 2);
}

void I2C_SLAVE_INIT(uint8 Slave_Address) {
	//SET slave Address
	TWAR = Slave_Address << 1;
	CLR_BIT(TWAR, 0);
	//Bit Rate (SCL Frequency)
	TWBR = 3;
	//Prescaler zero
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);
	//Enable Acknowledge
	SET_BIT(TWCR, 6);
	//Enable I2C
	SET_BIT(TWCR, 2);
	while (!GET_BIT(TWCR, 7))
		;

}
void I2C_START_CONDITION(uint8 Slave_Address, uint8 R_W) {
	//Enable Start Condition
	SET_BIT(TWCR, 5);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
	//Send Slave Address
	TWDR = (Slave_Address << 1) | R_W;
	//CLEAR Start Condition
	CLR_BIT(TWCR, 5);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
}

void I2C_STOP_CONDITION(void) {
	//Enable Stop Condition
	SET_BIT(TWCR, 4);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	//while (!GET_BIT(TWCR, 7))
	;
	//CLEAR Stop Condition
	//CLR_BIT(TWCR, 4);
}
void I2C_REPEATED_START_CONDITION(uint8 Slave_Address, uint8 R_W) {
	//Enable Start Condition
	SET_BIT(TWCR, 5);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
	/*LCD_VIDSENDCOMMAND(LCD_Clear);
	 LCD_VIDSENDCHAR((GET_STATUS() / 100) + 48);
	 LCD_VIDSENDCHAR(((GET_STATUS() % 100) / 10) + 48);
	 LCD_VIDSENDCHAR(((GET_STATUS() % 100) % 10) + 48);*/
	//Send Slave Address
	TWDR = (Slave_Address << 1) | R_W;
	//CLEAR Start Condition
	CLR_BIT(TWCR, 5);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
}
uint8 I2C_READ_DATA_ACK(void) {
	//Enable Acknowledge
	SET_BIT(TWCR, 6);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	while (!(GET_BIT(TWCR, 7)))
		;
	TOGGLE_BIT(PORTB, 0);
	return TWDR;
}

uint8 I2C_READ_DATA_NO_ACK(void) {
	//Enable NoAcknowledge
	CLR_BIT(TWCR, 6);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
	return TWDR;
}

void I2C_WRITE_DATA_ACK(uint8 Data) {
	//Load Data
	TWDR = Data;
	//Enable Acknowledge
	SET_BIT(TWCR, 6);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
	SET_BIT(TWCR, 7);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
}
void I2C_WRITE_DATA_NO_ACK(uint8 Data) {
	//Load Data
	TWDR = Data;
	//Enable NoAcknowledge
	CLR_BIT(TWCR, 6);
	//Enable I2C
	SET_BIT(TWCR, 2);
	// Clear TWIN Flag
		SET_BIT(TWCR, 7);
	// Wait
	while (!GET_BIT(TWCR, 7))
		;
}

uint8 GET_STATUS(void) {
	return TWSR;
}
void I2C_WRITE_STRING_ACK(uint8* Data) {
	uint8 i = 0;
	while (Data[i] != '\0') {
		I2C_WRITE_DATA_ACK(Data[i]);
		i++;
		_delay_ms(100);
	}
	I2C_WRITE_DATA_ACK(Data[i]);
}

uint8* I2C_READ_STRING_ACK(void) {
	static uint8 Data[50], flag = 0;
	uint8 count = 0, d = 0, i = 0;
	d = I2C_READ_DATA_ACK();
	while (d != '\0' && count != 50) {
		_delay_ms(100);
		Data[i] = d;
		LCD_VIDSENDCHAR(Data[i]);
		d = I2C_READ_DATA_ACK();
		count++;
		i++;
	}
	return Data;
}

