/*
 * Keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_CFG.h"

void KEYPAD_INIT(void);
uint8 KEYPAD_READ(void);
uint8 KEYPAD_READDEBOUNCING(void);

#endif /* KEYPAD_H_ */
