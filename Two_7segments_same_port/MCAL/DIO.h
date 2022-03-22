/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef DIO_H_
#define DIO_H_
/*
 * FunName:DIO_INIT_PORT_DIRECTION
 * @brief it changes Direction of a port (Input or Output) by changing registers in microcontroller
 * @param Port,Direction
 * @retval it doesn't return anything
 */
void DIO_INIT_PORT_DIRECTION(uint8 PORT,uint8 DIRECTION);
/*
 * FunName:DIO_WRITE_PORT_VALUE
 * @brief it writes in one port value to make some bits zero (0V) and others one (5V)
 * @param Port,value
 * @retval it doesn't return anything
 */
void DIO_WRITE_PORT_VALUE(uint8 PORT,uint8 VALUE);
/*
 * FunName:DIO_READ_PORT_VALUE
 * @brief it read one port's value to read some bits zero (0V) and others one (5V)
 * @param Port
 * @retval it returns port's value
 */
uint8 DIO_READ_PORT_VALUE(uint8 PORT);
/*
 * FunName:DIO_INIT_PIN_DIRECTION
 * @brief it changes Direction of a pin (Input or Output) by changing registers in microcontroller
 * @param Port,number of pin,Direction
 * @retval it doesn't return anything
 */
void DIO_INIT_PIN_DIRECTION(uint8 PORT,uint8 PINno,uint8 DIRECTION);
/*
 * FunName:DIO_WRITE_PIN_VALUE
 * @brief it writes in one pin's value zero (0V) or  one (5V)
 * @param Port,Number of Pin,value
 * @retval it doesn't return anything
 */
void DIO_WRITE_PIN_VALUE(uint8 PORT,uint8 PINno,uint8 VALUE);
/*
 * FunName:DIO_READ_PIN_VALUE
 * @brief it read one pin's value to zero (0V) or one (5V)
 * @param Port,Number of pin
 * @retval it returns pin's value
 */
uint8 DIO_READ_PIN_VALUE(uint8 PORT,uint8 PINno);

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define INPUT 0
#define OUTPUT 1

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define HIGH 1
#define LOW 0


#endif /* DIO_H_ */
