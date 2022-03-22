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

#endif /* MEMMAP_H_ */
