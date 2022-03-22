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
		OUTPUT,    //PINB0
		OUTPUT,   //PINB1
		OUTPUT,   //PINB2
		OUTPUT,   //PINB3
		OUTPUT,     //PINB4
		OUTPUT,    //PINB5
		OUTPUT,    //PINB6
		OUTPUT,   //PINB7
		INPUT_FLOATING,    //PINC0
		INPUT_FLOATING,   //PINC1
		OUTPUT,    //PINC2
		OUTPUT,    //PINC3
		OUTPUT,    //PINC4
		OUTPUT,    //PINC5
		OUTPUT,   //PINC6
		INPUT_FLOATING,     //PINC7
		INPUT_FLOATING,   //PIND0
		OUTPUT,    //PIND1
		INPUT_PULLUP,     //PIND2
		INPUT_PULLUP,   //PIND3
		INPUT_PULLUP,     //PIND4
		INPUT_PULLUP,    //PIND5
		OUTPUT,   //PIND6
		OUTPUT,     //PIND7

};
