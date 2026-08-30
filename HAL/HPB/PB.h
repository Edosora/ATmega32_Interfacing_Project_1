/*
 * PB.h
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */

#ifndef HAL_HPB_PB_H_
#define HAL_HPB_PB_H_

#include "../../LIB/StdTypes.h"

#define PB_PRESSED      0
#define PB_NOT_PRESSED  1
void HPB_voidInit       (u8 A_u8PortName , u8 A_u8PinNumber) ;
u8   HPB_u8GetPbStatues (u8 A_u8PortName , u8 A_u8PinNumber) ;

#endif // HAL_HPB_PB_H_
