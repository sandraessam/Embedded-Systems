/*
 * Keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*
 * FunName:KEYPAD_INIT
 * @brief it initializes Direction of a Keypad's port (first four pins  High Output  and the other four PullUpInput) by changing registers in microcontroller
 * @param void
 * @retval it doesn't return anything
 */
void KEYPAD_INIT(void);
/*
 * FunName:KEYPAD_READ
 * @brief it reads one Keypad's switch (by reading one of first four pins Output (Low) and one of the other four PullUpInput (Low))
 * @param void
 * @retval it returns keypad's value
 */
uint8 KEYPAD_READ(void);


#define KEYPAD_WRITEPORT PORT_B
#define KEYPAD_READPORT PORT_B
#define KEYPAD_3_BY_3  0
#define KEYPAD_4_BY_4 1

#define KEYPAD_TYPE KEYPAD_4_BY_4

#endif /* KEYPAD_H_ */
