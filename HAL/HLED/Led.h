/*
 * Led.h
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */

#ifndef HAL_HLED_LED_H_
#define HAL_HLED_LED_H_

#include "../../LIB/StdTypes.h"

void HLED_voidLedInit  (u8 A_u8PortName , u8 A_u8PinNumber) ;
void HLED_voidLedOn    (u8 A_u8PortName , u8 A_u8PinNumber) ;
void HLED_voidLedOff   (u8 A_u8PortName , u8 A_u8PinNumber) ;
void HLED_voidLedTog   (u8 A_u8PortName , u8 A_u8PinNumber) ;

#endif // HAL_HLED_LED_H_
