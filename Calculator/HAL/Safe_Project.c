#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "Keypad.h"
#include "LCD.h"
#include <util/delay.h>
#include "Safe_Project.h"
#define  ADMIN 2022
static uint8 password[4], i = 0, confirm[4], mypassword[4], x = 0, admin[4],
		count = 0;
uint8 Status;

void NEW_PASSWORD(uint8 pass) {
	LCD_VIDGOTOXY(0, 0);
	LCD_VIDSENDSTRING("New Password:", 13);
	LCD_VIDGOTOXY(1, 0);
	//pass = KEYPAD_READ();
	if (pass >= 0 && pass <= 9 && i<4) {

		password[i] = pass;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(password[i] + 48);
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR('*');
		i++;
	} else if (pass == 'c' && i > 0) {
		i--;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(' ');
	}
	if (pass == '+' && i == 4) {
		Status = Confirm_Password;
		LCD_VIDSENDCOMMAND(LCD_Clear);
		i = 0;
	} else if (pass == '+' && i != 4) {
		LCD_VIDGOTOXY(1, 0);
		LCD_VIDSENDSTRING("                           ", 16);
		LCD_VIDGOTOXY(1, 0);
		LCD_VIDSENDSTRING("PasswordSize== 4", 16);
		_delay_ms(1000);
		LCD_VIDGOTOXY(1, 0);
		LCD_VIDSENDSTRING("                           ", 16);
		LCD_VIDGOTOXY(1, 0);
		i = 0;
	}
}
void Confirm_PASSWORD(uint8 con) {

	LCD_VIDGOTOXY(0, 0);
	LCD_VIDSENDSTRING("Confirm Password", 16);
	LCD_VIDGOTOXY(1, 0);
	//con = KEYPAD_READ();
	if (con >= 0 && con <= 9 && i < 4) {
		confirm[i] = con;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(confirm[i] + 48);
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR('*');
		i++;
	} else if (con == 'c' && i > 0) {
		i--;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(' ');
	}
	if (con == '+') {
		Status = Motor_Open;
		for (i = 0; i < 4; i++) {
			if (confirm[i] != password[i]) {
				Status = New_Password;
				//DIO_WRITECHANNEL(PINC3, HIGH);
			}
		}
		if (Status == New_Password) {
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("Not Correct", 11);
			_delay_ms(1000);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
		}
		i = 0;
		LCD_VIDSENDCOMMAND(LCD_Clear);
	}

}

void OPEN_MOTOR(void) {
	if (i == 0) {
		LCD_VIDSENDCOMMAND(LCD_Clear);
		LCD_VIDGOTOXY(0, 0);
		LCD_VIDSENDSTRING("WELCOME <3", 10);
		LCD_VIDGOTOXY(1, 0);
		LCD_VIDSENDSTRING("(-)Close", 8);
		LCD_VIDGOTOXY(1, 10);
		LCD_VIDSENDSTRING("(=)Rst", 6);
		DIO_WRITEPORT(PORT_C, 0x08);
		_delay_ms(3000);
		DIO_WRITEPORT(PORT_C, 0x00);
		i = 1;
	}
}
void CLOSE_MOTOR(void) {
	DIO_WRITEPORT(PORT_C, 0x10);
	_delay_ms(3000);
	DIO_WRITEPORT(PORT_C, 0);
	Status = Enter_Password;
	LCD_VIDSENDCOMMAND(LCD_Clear);
	i = 0;
}
void ENTER_PASSWORD(uint8 pass) {
	LCD_VIDGOTOXY(0, 0);
	LCD_VIDSENDSTRING("Enter Password:", 15);
	LCD_VIDGOTOXY(1, 0);
	if (pass >= 0 && pass <= 9 && i < 4) {
		mypassword[i] = pass;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(mypassword[i] + 48);
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR('*');
		i++;
	} else if (pass == 'c' && i > 0) {
		i--;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(' ');
	}

	if (pass == '+') {
		Status = Motor_Open;
		count++;
		for (i = 0; i < 4; i++) {
			if (mypassword[i] != password[i]) {
				Status = Enter_Password;
				//DIO_WRITECHANNEL(PINC3, HIGH);
			}
		}
		if (Status == Enter_Password) {
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("Not Correct", 11);
			_delay_ms(1000);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
		} else {
			count = 0;
			LCD_VIDSENDCOMMAND(LCD_Clear);
		}
		i = 0;
	}
	if (count == 3) {
		Status = Thief;
		LCD_VIDSENDCOMMAND(LCD_Clear);
		count = 0;
	}
}
void THIEF(void) {
	LCD_WRITEEXTRACHAR(0, 6);
	DIO_WRITEPORT(PORT_C, 0x20);
	_delay_ms(3000);
	DIO_WRITEPORT(PORT_C, 0);
	Status = Admin_Password;
	LCD_VIDSENDCOMMAND(LCD_Clear);
	x = 0;
}
void ADMIN_PASSWORD(uint8 pass) {
	uint16 n1, n, n2;
	if (x == 0) {
		LCD_VIDGOTOXY(0, 0);
		LCD_VIDSENDSTRING("Admin Password:", 15);
	}
	LCD_VIDGOTOXY(1, x);
	if (pass >= 0 && pass <= 9 && i < 4) {
		admin[i] = pass;
		LCD_VIDGOTOXY(1, i + x);
		LCD_VIDSENDCHAR(admin[i] + 48);
		LCD_VIDGOTOXY(1, i + x);
		LCD_VIDSENDCHAR('*');
		i++;
	} else if (pass == 'c' && i > 0) {
		i--;
		LCD_VIDGOTOXY(1, i + x);
		LCD_VIDSENDCHAR(' ');
	}

	if (pass == '+') {
		Status = New_Password;
		n = 1000;
		n1 = ADMIN;
		for (i = 0; i < 4; i++) {
			n2 = n1 / n;
			if (admin[i] != n2) {
				Status = Call_Admin;
				//DIO_WRITECHANNEL(PINC3, HIGH);
			}
			n1 = n1 % n;
			n = n / 10;
		}
		i = 0;
		LCD_VIDSENDCOMMAND(LCD_Clear);
	}
}
void CALL_ADMIN(void) {

	LCD_VIDGOTOXY(0, 0);
	LCD_VIDSENDSTRING("Pls call admin:", 15);
	LCD_VIDGOTOXY(1, 0);
	LCD_VIDSENDSTRING("Pass:", 5);
	x = 7;
	Status = Admin_Password;
}
void ENTER_OLD_PASSWORD(uint8 pass) {
	LCD_VIDGOTOXY(0, 0);
	LCD_VIDSENDSTRING("Enter old pass:", 15);
	LCD_VIDGOTOXY(1, 0);

	if (pass >= 0 && pass <= 9 && i < 4) {
		mypassword[i] = pass;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(mypassword[i] + 48);
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR('*');
		i++;
	} else if (pass == 'c' && i > 0) {
		i--;
		LCD_VIDGOTOXY(1, i);
		LCD_VIDSENDCHAR(' ');
	}
	if (pass == '+') {
		Status = New_Password;
		count++;
		for (i = 0; i < 4; i++) {
			if (mypassword[i] != password[i]) {
				Status = Old_Password;
				//DIO_WRITECHANNEL(PINC3, HIGH);
			}
		}
		if (Status == Old_Password) {
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("Not Correct", 11);
			_delay_ms(1000);
			LCD_VIDGOTOXY(1, 0);
			LCD_VIDSENDSTRING("                           ", 16);
			LCD_VIDGOTOXY(1, 0);
		} else {
			count = 0;
			LCD_VIDSENDCOMMAND(LCD_Clear);
		}
		i = 0;
	}
	if (count == 2) {
		Status = Thief;
		LCD_VIDSENDCOMMAND(LCD_Clear);
		count = 0;
	}

}
void RESET_MOTOR(void) {
	i = 0;
	LCD_VIDSENDCOMMAND(LCD_Clear);
	Status = Old_Password;
}
