/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef ADC_H_
#define ADC_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define Vref 5

void ADC_INIT(void);
void ADC_START_CONVERSION(uint8 channel);
uint16 ADC_READ(void);
#define ADC_CHANNEL ADC1

#endif /* ADC_H_ */
