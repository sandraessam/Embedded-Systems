
/*
 * Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD/STD_Types.h"
#include "STD/BIT_MATH.h"
#include "STD/MEMMAP.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MCAL/ADC.h"
#include "MCAL/DIO.h"

#define F_CPU 16000000


uint16 Value = 1025;
uint16 Value1 = 1025;
uint16 Analog = 3;
uint8 channel = ADC0;

ISR(ADC_vect) {
	if (channel == ADC0) {
		Value = ADC_READ();
	} else if (channel == ADC1) {
		Value1 = ADC_READ();
	}
}
int main(void) {
	uint8 Temp;
	DIO_INIT();
	ADC_INIT();
	while (1) {
		ADC_START_CONVERSION(channel);
		Analog = (1000 * (uint32) (Value * Vref)) / (1024);
		Temp = (Analog / 10);
		PORTB=Temp;
		if (Temp < 20) {
			DIO_WRITECHANNEL(PINC0, HIGH);
			DIO_WRITECHANNEL(PINC1, LOW);
			DIO_WRITECHANNEL(PINC2, LOW);
		} else if (Temp >= 20 && Temp <= 40) {
			DIO_WRITECHANNEL(PINC0, LOW);
			DIO_WRITECHANNEL(PINC1, HIGH);
			DIO_WRITECHANNEL(PINC2, LOW);
		} else {
			DIO_WRITECHANNEL(PINC0, LOW);
			DIO_WRITECHANNEL(PINC1, LOW);
			DIO_WRITECHANNEL(PINC2, HIGH);
		}
		Analog = (1000 * (uint32) (Value1 * Vref)) / (1024);
		if (Analog < 2500) {
			DIO_WRITECHANNEL(PINC3, HIGH);
		} else {
			DIO_WRITECHANNEL(PINC3, LOW);
		}
	channel++;
	if (channel == 2) {
		channel = ADC0;
	}
}

return 0;
}
