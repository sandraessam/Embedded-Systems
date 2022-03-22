/*
 * ADC.c
 *
 *  Created on: ??�/??�/????
 *      Author: Copy Center
 */
#include "../STD/STD_Types.h"
#include "../STD/BIT_MATH.h"
#include "../STD/MEMMAP.h"
#include "ADC.h"

void ADC_INIT(void) {
	// Set Channel
	ADMUX = ADC_CHANNEL;
	// Reference Selection Bits
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
	// SET PRESCALER
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	// ADC Enable
	SET_BIT(ADCSRA, 7);
	// ADC Interrupt Enable
	SET_BIT(ADCSRA, 3);
	// Enable Global Interrupt
	SET_BIT(SREG, 7);

}

void ADC_START_CONVERSION(uint8 channel) {
	//Choose Channel
	ADMUX &= 0xf0;
	ADMUX |= channel;
	// ADC Start Conversion
	SET_BIT(ADCSRA, 6);
}
uint16 ADC_READ(void) {
	uint16 value;
	value = ADC;
	return value;

}
