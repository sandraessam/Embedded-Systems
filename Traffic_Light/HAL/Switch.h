/*
 * Switch.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef SWITCH_H_
#define SWITCH_H_
/*
 * FunName:SW_INIT
 * @brief it initializes type of a switch ( input pull-up or input pull-down)
 * @param the port used and the number of pin in it
 * @retval it doesn't return anything
 */
void SW_INIT(uint8 PORT,uint8 PIN);
/*
 * FunName:SW_READ
 * @brief it reads switch's value ( low voltage or high voltage)
 * @param the port used and the number of pin in it
 * @retval it  returns switch's value
 */
uint8 SW_READ(uint8 PORT,uint8 PIN);

#define FREE_INPUT 0
#define PULLUP_INPUT 1

#define SW_TYPE  PULLUP_INPUT

#endif /* SWITCH_H_ */
