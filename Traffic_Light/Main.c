/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include <util/delay.h>
#include "Seven_Segment.h"
#include "Keypad.h"
#include "DIO.h"

#define F_CPU 16000000

int main(void) {
	SEVEN_SEG_INIT();
	KEYPAD_INIT();
	DIO_INIT_PORT_DIRECTION(PORT_C, OUTPUT);
	uint8  Max_num = 40,num1 = Max_num/10, num2 = Max_num%10, count = 0,value, pin = PIN0, key,
			flag = 0;
	while (1) {


		DIO_WRITE_PIN_VALUE(PORT_C, pin, HIGH);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, LOW);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, HIGH);
		SEVEN_SEG_DISPLAY(num2);
		_delay_ms(100);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN7, HIGH);
		DIO_WRITE_PIN_VALUE(PORT_C, PIN6, LOW);
		SEVEN_SEG_DISPLAY(num1);
		_delay_ms(100);
		key = KEYPAD_READ();
		switch (key) {
		case '+':
			flag ^= 1;
			break;
		case '-':
			num2 = Max_num%10;
			num1 = Max_num/10;
			count = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
			pin=PIN0;
			break;
		case '*':
			Max_num = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, PIN7, LOW);
			DIO_WRITE_PIN_VALUE(PORT_C, PIN6, LOW);
			do {
				key=KEYPAD_READ();
				value=HIGH;
				if(key>=0 && key<=9){
				Max_num = (Max_num * 10) + key;
				DIO_WRITE_PIN_VALUE(PORT_C, PIN7, value);
				DIO_WRITE_PIN_VALUE(PORT_C, PIN6, value^1);
				SEVEN_SEG_DISPLAY(Max_num%10);
				value^=value;}
			} while ((Max_num < 10 || Max_num > 99));
			num2 = Max_num%10;
			num1 = Max_num/10;
			count = 0;
			DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
			pin=PIN0;
			break;
		default:
			if (flag == 0) {
				count++;
				if (count == Max_num) {
					num2 = Max_num%10;
					num1 = Max_num/10;
					count = 0;
					DIO_WRITE_PIN_VALUE(PORT_C, PIN2, LOW);
					DIO_WRITE_PIN_VALUE(PORT_C, pin, LOW);
					pin++;
					if (pin == PIN2) {
						pin= PIN0;
					}
				} else {
					if(count>=Max_num-10){
					 TOGGLE_BIT(PORTC, PIN2);
					 }
					if (num2 == 0) {
						num2 = 9;
						if (num1 == 0) {
							num1 = Max_num/10;;
						}
						else{
						num1--;}
					}
					else{
						num2--;
					}

				}

			}

		}


	}

	return 0;
}

