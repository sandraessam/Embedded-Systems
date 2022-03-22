/*
 * DIO_CFG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO_CFG.h"

uint8 DIO_PinConfiguration [PIN_LIMIT]={

		OUTPUT,   //PINA0
		OUTPUT,    //PINA1
		OUTPUT,     //PINA2
		OUTPUT,   //PINA3
		OUTPUT,   //PINA4
		OUTPUT,   //PINA5
		OUTPUT,   //PINA6
		OUTPUT,    //PINA7
		INPUT_PULLUP,    //PINB0
		INPUT_PULLUP,   //PINB1
		INPUT_PULLUP,   //PINB2
		INPUT_PULLUP,   //PINB3
		OUTPUT,     //PINB4
		OUTPUT,    //PINB5
		OUTPUT,    //PINB6
		OUTPUT,   //PINB7
		OUTPUT,    //PINC0
		OUTPUT,   //PINC1
		OUTPUT,    //PINC2
		OUTPUT,    //PINC3
		OUTPUT,    //PINC4
		OUTPUT,    //PINC5
		OUTPUT,   //PINC6
		INPUT_FLOATING,     //PINC7
		OUTPUT,   //PIND0
		INPUT_PULLUP,    //PIND1
		INPUT_PULLUP,     //PIND2
		INPUT_PULLUP,   //PIND3
		INPUT_PULLUP,     //PIND4
		INPUT_PULLUP,    //PIND5
		OUTPUT,   //PIND6
		OUTPUT,     //PIND7

};
