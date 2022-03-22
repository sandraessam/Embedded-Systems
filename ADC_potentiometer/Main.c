/*
 * Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD/STD_Types.h"
#include "STD/BIT_MATH.h"
#include "STD/MEMMAP.h"
#include "MCAL/DIO.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MCAL/ADC.h"

#define F_CPU 16000000


uint16 Value = 1025;
uint16 Analog = 3;

ISR(ADC_vect) {
	Value = ADC_READ();
}
int main(void) {
	DIO_INIT();
	ADC_INIT();
	while (1) {

		ADC_START_CONVERSION(ADC_CHANNEL) ;
		Analog = (1000 * (uint32) (Value * Vref)) / (1024);

		if (Analog >= 0 && Analog <= 1500) {
			DIO_WRITECHANNEL(PINA1, HIGH);
			DIO_WRITECHANNEL(PINA2, LOW);
			DIO_WRITECHANNEL(PINA3, LOW);
		} else if (Analog >= 1500 && Analog <= 3000) {
			DIO_WRITECHANNEL(PINA1, LOW);
			DIO_WRITECHANNEL(PINA2, HIGH);
			DIO_WRITECHANNEL(PINA3, LOW);
		} else if (Analog >= 3000 && Analog <= 5000) {
			DIO_WRITECHANNEL(PINA1, LOW);
			DIO_WRITECHANNEL(PINA2, LOW);
			DIO_WRITECHANNEL(PINA3, HIGH);
		}
		DIO_WRITEPORT(PORT_B, Value);
		DIO_WRITECHANNEL(PINA6,GET_BIT(Value,8));
		DIO_WRITECHANNEL(PINA7,GET_BIT(Value,9));

	}

	return 0;
}
