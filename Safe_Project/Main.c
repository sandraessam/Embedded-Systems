/*
 * Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "Keypad.h"
#include "LCD.h"
#include <util/delay.h>
#include "Safe_Project.h"
int main(void) {
	DIO_INIT();
	LCD_INIT();
	Status=New_Password;
	/*while(1){
	 LCD_WRITEEXTRACHAR(0,0);
	 }*/
	uint8 key;
	while (1) {
		key=KEYPAD_READ();
		switch (Status) {
		case New_Password:
			NEW_PASSWORD(key);
			break;
		case Confirm_Password:
			//DIO_WRITECHANNEL(PINA0,HIGH);
			Confirm_PASSWORD(key);
			break;
		case  Motor_Open:
			OPEN_MOTOR();
			if(key=='-'){
				Status=Motor_Close;
			}
			if(key=='='){
				Status=Motor_Reset;
			}
			break;
		case Motor_Reset:
			RESET_MOTOR();
			break;
		case Motor_Close:
			CLOSE_MOTOR();
			break;
		case Enter_Password:
			ENTER_PASSWORD(key);
			break;
		case Thief:
			THIEF();
			break;
		case Admin_Password:
			ADMIN_PASSWORD(key);
			break;
		case Call_Admin:
			CALL_ADMIN();
			break;
		case Old_Password:
			ENTER_OLD_PASSWORD(key);
			break;

		}
	}
	return 0;
}

