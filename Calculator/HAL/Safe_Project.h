/*
 * Safe_Project.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef SAFE_PROJECT_H_
#define SAFE_PROJECT_H_

#define New_Password 0
#define Confirm_Password 1
#define Motor_Open 2
#define Motor_Close 3
#define Motor_Reset 4
#define Enter_Password 5
#define Thief 6
#define Admin_Password 7
#define Call_Admin 8
#define Old_Password 9

void NEW_PASSWORD(uint8 key);
void Confirm_PASSWORD(uint8 con);
void OPEN_MOTOR(void);
void CLOSE_MOTOR(void);
void ENTER_PASSWORD(uint8 pass);
void THIEF(void);
void ADMIN_PASSWORD(uint8 pass);
void CALL_ADMIN(void);
void ENTER_OLD_PASSWORD(uint8 pass);
void RESET_MOTOR(void);
extern uint8 Status;

#endif /* SAFE_PROJECT_H_ */
