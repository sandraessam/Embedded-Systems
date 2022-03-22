/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"

void DIO_INIT(void) {
	uint8 i,PinValue,PortState;
	uint8* reg[8]={DDRA_ADDRESS,DDRB_ADDRESS,DDRC_ADDRESS,DDRD_ADDRESS,
			PORTA_ADDRESS,PORTB_ADDRESS,PORTC_ADDRESS,PORTD_ADDRESS};
	for(i=0;i<PIN_LIMIT;i++){
		PinValue=i%8;
		PortState=i/8;
		switch(DIO_PinConfiguration[i]){
		case INPUT_PULLUP:
			CLR_BIT(*reg[PortState],PinValue);
			SET_BIT(*reg[PortState+4],PinValue);
			break;
		case OUTPUT:
			SET_BIT(*reg[PortState],PinValue);
			break;
		case INPUT_FLOATING:
			CLR_BIT(*reg[PortState],PinValue);
			CLR_BIT(*reg[PortState+4],PinValue);
			break;
		}

	}
}

void DIO_WRITECHANNEL(uint8 CHANNEL,uint8 VALUE){
	uint8 PinValue,PortState;
	uint8* reg[4]={PORTA_ADDRESS,PORTB_ADDRESS,PORTC_ADDRESS,PORTD_ADDRESS};
		PinValue=CHANNEL%8;
		PortState=CHANNEL/8;
		switch(VALUE){
		case LOW:
			CLR_BIT(*reg[PortState],PinValue);
			break;
		case HIGH:
			SET_BIT(*reg[PortState],PinValue);
			break;
		}



}

void DIO_WRITEPORT(uint8 PORT, uint8 VALUE) {

	switch (PORT) {
	case PORT_A:
		PORTA = VALUE;
		break;
	case PORT_B:
		PORTB = VALUE;
		break;
	case PORT_C:
		PORTC = VALUE;
		break;
	case PORT_D:
		PORTD = VALUE;
		break;
	}
}


uint8 DIO_READCHANNEL(uint8 CHANNEL) {
	uint8 PinValue,PortState,value=0;
		uint8* reg[4]={PINA_ADDRESS,PINB_ADDRESS,PINC_ADDRESS,PIND_ADDRESS};
			PinValue=CHANNEL%8;
			PortState=CHANNEL/8;
			value=GET_BIT(*reg[PortState],PinValue);
	return value;
}

uint8 DIO_READPORT(uint8 PORT) {
	uint8 value = 0;
	switch (PORT) {
	case PORT_A:
		value = PINA;
		break;
	case PORT_B:
		value = PINB;
		break;
	case PORT_C:
		value = PINC;
		break;
	case PORT_D:
		value = PIND;
		break;
	}
	return value;
}
