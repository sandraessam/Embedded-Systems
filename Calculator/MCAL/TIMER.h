/*
 * TIMER.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef enum{
	NORMAL=0,
	CTC,
	PWM,
	FAST_PWM
}TIMER_MODES;

#define T0_MODE FAST_PWM
#define T1_MODE NORMAL

void TIMER0_INIT(void);
void TIMER1_INIT(void);

#endif /* TIMER_H_ */
