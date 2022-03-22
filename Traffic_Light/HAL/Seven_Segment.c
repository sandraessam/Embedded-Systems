/*
 * Seven_Segment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Copy Center
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MEMMAP.h"
#include "DIO.h"
#include "Seven_Segment.h"

static int num_common_cathode[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
static int num_common_anode[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

void SEVEN_SEG_INIT(void){
	DIO_INIT_PORT_DIRECTION(SEG_PORT,OUTPUT);
}

void SEVEN_SEG_DISPLAY(uint8 NUM){
#if SEG_TYPE == COMMON_CATHODE
	DIO_WRITE_PORT_VALUE(SEG_PORT,num_common_cathode[NUM]);
#elif SEG_TYPE == COMMON_ANODE
	DIO_WRITE_PORT_VALUE(SEG_PORT,num_common_anode[NUM]);
#endif

}

