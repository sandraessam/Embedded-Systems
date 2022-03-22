/*
 * DIO_CFG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define INPUT_PULLUP 0
#define OUTPUT 1
#define INPUT_FLOATING 3

#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7
#define PINB0 8
#define PINB1 9
#define PINB2 10
#define PINB3 11
#define PINB4 12
#define PINB5 13
#define PINB6 14
#define PINB7 15
#define PINC0 16
#define PINC1 17
#define PINC2 18
#define PINC3 19
#define PINC4 20
#define PINC5 21
#define PINC6 22
#define PINC7 23
#define PIND0 24
#define PIND1 25
#define PIND2 26
#define PIND3 27
#define PIND4 28
#define PIND5 29
#define PIND6 30
#define PIND7 31
#define PIN_LIMIT 32
#define HIGH 1
#define LOW 0

uint8 DIO_PinConfiguration [PIN_LIMIT];
#endif /* DIO_CFG_H_ */
