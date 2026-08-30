/*
 * 7Seg.h
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */

#ifndef HAL_H7SEG_7SEG_H_
#define HAL_H7SEG_7SEG_H_

#include "../../LIB/StdTypes.h"

typedef struct
{
	u8 Data_Port ;
	u8 Comm_Port ;
	u8 Comm_Pin  ;
	u8 Type      ;
}Seg_t;

#define COMM_ANODE    1
#define COMM_CATHODE  2

void H7SEG_voidInit        (Seg_t A_xSeg                ) ;
void H7SEG_voidOff         (Seg_t A_xSeg                ) ;
void H7SEG_voidWriteNumber (Seg_t A_xSeg , u8 A_u8Number) ;

#endif // HAL_H7SEG_7SEG_H_
