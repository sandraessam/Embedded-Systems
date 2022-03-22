/*
 * DIO_CFG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */
#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"
#include "DIO_CFG.h"

uint8 DIO_PinConfiguration [PIN_LIMIT]={

		INPUT_FLOATING,   //PINA0
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
		OUTPUT,    //PINC0
		OUTPUT,   //PINC1
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
		OUTPUT,     //PIND4
		OUTPUT,    //PIND5
		OUTPUT,   //PIND6
		OUTPUT,     //PIND7

};
