/*
 * BIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CLR_BIT(Byte,Pos) (Byte&=~(1<<Pos))
#define SET_BIT(Byte,Pos) (Byte|=1<<Pos)
#define TOGGLE_BIT(Byte,Pos) (Byte^=1<<Pos)
#define GET_BIT(Byte,Pos) (((Byte>>Pos)&1))

#endif /* BIT_MATH_H_ */
