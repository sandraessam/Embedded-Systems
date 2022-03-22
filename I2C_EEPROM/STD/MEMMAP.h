/*
 * MEMMAP.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

/********************************* DIO*******************************************/

#define DDRA (*(volatile uint8*)0x3A)
#define PINA (*(volatile uint8*)0x39)
#define PORTA (*(volatile uint8*)0x3B)

#define DDRB (*(volatile uint8*)0x37)
#define PORTB (*(volatile uint8*)0x38)
#define PINB (*(volatile uint8*)0x36)

#define DDRC (*(volatile uint8*)0x34)
#define PORTC (*(volatile uint8*)0x35)
#define PINC (*(volatile uint8*)0x33)

#define DDRD (*(volatile uint8*)0x31)
#define PORTD (*(volatile uint8*)0x32)
#define PIND (*(volatile uint8*)0x30)

#define DDRA_ADDRESS ((volatile uint8*)0x3A)
#define PINA_ADDRESS ((volatile uint8*)0x39)
#define PORTA_ADDRESS ((volatile uint8*)0x3B)

#define DDRB_ADDRESS ((volatile uint8*)0x37)
#define PORTB_ADDRESS ((volatile uint8*)0x38)
#define PINB_ADDRESS ((volatile uint8*)0x36)

#define DDRC_ADDRESS ((volatile uint8*)0x34)
#define PORTC_ADDRESS ((volatile uint8*)0x35)
#define PINC_ADDRESS ((volatile uint8*)0x33)

#define DDRD_ADDRESS ((volatile uint8*)0x31)
#define PORTD_ADDRESS ((volatile uint8*)0x32)
#define PIND_ADDRESS ((volatile uint8*)0x30)
/**********************************************************************************/

/******************************************INTERRUPTS*****************************/

#define SREG (*(volatile uint8*)0x5F)
#define GICR (*(volatile uint8*)0x5B)
#define MCUCR (*(volatile uint8*)0x55)
/*********************************************************************************/

/*************************************ADC****************************************/

#define ADMUX (*(volatile uint8*)0x27)
#define ADC  (*(volatile uint16*)0x24)
#define ADCSRA (*(volatile uint8*)0x26)


#endif /* MEMMAP_H_ */
/*********************************************************************************/

/*******************************TIMER0*******************************************/

#define TCCR0 (*(volatile uint8*)0x53)
#define TCNT0 (*(volatile uint8*)0x52)
#define OCR0 (*(volatile uint8*)0x5C)
#define TIMSK (*(volatile uint8*)0x59)
/*********************************************************************************/

/*******************************WGD TIMER****************************************/

#define WDTCR (*(volatile uint8*)0x41)
/********************************************************************************/

/********************************TIMER1******************************************/
#define TCCR1A  (*(volatile uint8*)0x4F)
#define TCCR1B  (*(volatile uint8*)0x4E)
#define TCNT1   (*(volatile uint16*)0x4C)
/********************************************************************************/

/*****************************UART***********************************************/
#define UDR (*(volatile uint8*)0x2C)
#define UCSRA (*(volatile uint8*)0x2B)
#define UCSRB (*(volatile uint8*)0x2A)
#define UCSRC (*(volatile uint8*)0x40)
#define UBRRL (*(volatile uint8*)0x29)

/********************************************************************************/

/*************************************SPI*****************************************/
#define SPCR (*(volatile uint8*)0x2D)
#define SPSR (*(volatile uint8*)0x2E)
#define SPDR (*(volatile uint8*)0x2F)
/**********************************************************************************/

/***********************************TWI*******************************************/

#define TWBR (*(volatile uint8*)0x20)
#define TWCR (*(volatile uint8*)0x56)
#define TWAR (*(volatile uint8*)0x22)
#define TWDR (*(volatile uint8*)0x23)
#define TWSR (*(volatile uint8*)0x21)
/*********************************************************************************/

