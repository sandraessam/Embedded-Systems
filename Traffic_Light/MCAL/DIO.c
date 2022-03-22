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


void DIO_INIT_PORT_DIRECTION(uint8 PORT, uint8 DIRECTION) {
	switch (PORT) {
	case PORT_A:
		if (DIRECTION == INPUT) {
			DDRA = 0x00;
		} else if (DIRECTION == OUTPUT) {
			DDRA = 0xff;
		}
		break;
	case PORT_B:
		if (DIRECTION == INPUT) {
			DDRB = 0x00;
		} else if (DIRECTION == OUTPUT) {
			DDRB = 0xff;
		}
		break;
	case PORT_C:
		if (DIRECTION == INPUT) {
			DDRC = 0x00;
		} else if (DIRECTION == OUTPUT) {
			DDRC = 0xff;
		}
		break;
	case PORT_D:
		if (DIRECTION == INPUT) {
			DDRD = 0x00;
		} else if (DIRECTION == OUTPUT) {
			DDRD = 0xff;
		}
		break;
	}
}

void DIO_WRITE_PORT_VALUE(uint8 PORT, uint8 VALUE) {

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
uint8 DIO_READ_PORT_VALUE(uint8 PORT) {
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

void DIO_INIT_PIN_DIRECTION(uint8 PORT, uint8 PINno, uint8 DIRECTION) {
	switch (PORT) {
	case PORT_A:
		if (DIRECTION == INPUT) {
			CLR_BIT(DDRA, PINno);
		} else if (DIRECTION == OUTPUT) {
			SET_BIT(DDRA, PINno);
		}
		break;
	case PORT_B:
		if (DIRECTION == INPUT) {
			CLR_BIT(DDRB, PINno);
		} else if (DIRECTION == OUTPUT) {
			SET_BIT(DDRB, PINno);
		}
		break;
	case PORT_C:
		if (DIRECTION == INPUT) {
			CLR_BIT(DDRC, PINno);
		} else if (DIRECTION == OUTPUT) {
			SET_BIT(DDRC, PINno);
		}
		break;
	case PORT_D:
		if (DIRECTION == INPUT) {
			CLR_BIT(DDRD, PINno);
		} else if (DIRECTION == OUTPUT) {
			SET_BIT(DDRD, PINno);
		}
		break;
	}
}

void DIO_WRITE_PIN_VALUE(uint8 PORT, uint8 PINno, uint8 VALUE) {
	switch (PORT) {
	case PORT_A:
		if (VALUE == LOW) {
			CLR_BIT(PORTA, PINno);
		} else if (VALUE == HIGH) {
			SET_BIT(PORTA, PINno);
		}
		break;
	case PORT_B:
		if (VALUE == LOW) {
			CLR_BIT(PORTB, PINno);
		} else if (VALUE == HIGH) {
			SET_BIT(PORTB, PINno);
		}
		break;
	case PORT_C:
		if (VALUE == LOW) {
			CLR_BIT(PORTC, PINno);
		} else if (VALUE == HIGH) {
			SET_BIT(PORTC, PINno);
		}
		break;
	case PORT_D:
		if (VALUE == LOW) {
			CLR_BIT(PORTD, PINno);
		} else if (VALUE == HIGH) {
			SET_BIT(PORTD, PINno);
		}
		break;
	}
}
uint8 DIO_READ_PIN_VALUE(uint8 PORT, uint8 PINno) {
	uint8 value = 0;
	switch (PORT) {
	case PORT_A:
		value = GET_BIT(PINA, PINno);
		break;
	case PORT_B:
		value = GET_BIT(PINB, PINno);
		break;
	case PORT_C:
		value = GET_BIT(PINC, PINno);
		break;
	case PORT_D:
		value = GET_BIT(PIND, PINno);
		break;
	}
	return value;
}
