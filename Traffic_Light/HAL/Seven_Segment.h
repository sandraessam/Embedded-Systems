/*
 * Seven_Segment.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

/*
 * FunName:SEVEN_SEG_INIT
 * @brief it initializes Direction of a seven segments's port ( Output) by changing DDR register in microcontroller
 * @param void
 * @retval it doesn't return anything
 */
void SEVEN_SEG_INIT(void);
/*
 * FunName:SEVEN_SEG_INIT
 * @brief it initializes Direction of a seven segments's port ( Output) by changing DDR register in microcontroller
 * @param void
 * @retval it doesn't return anything
 */
void SEVEN_SEG_DISPLAY(uint8 NUM);

#define SEG_PORT PORT_A
#define COMMON_CATHODE 0
#define COMMON_ANODE 1

#define SEG_TYPE COMMON_CATHODE


#endif /* SEVEN_SEGMENT_H_ */
