/*
 * Led.c
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/StdTypes.h"
#include "../../MCAL/MDIO/DIO.h"
#include "Led.h"

void HLED_voidLedInit  (u8 A_u8PortName , u8 A_u8PinNumber)
{
	MDIO_voidInitPin(A_u8PortName, A_u8PinNumber, DIO_OUTPUT) ;
}
void HLED_voidLedOn    (u8 A_u8PortName , u8 A_u8PinNumber)
{
	MDIO_voidSetPinValue(A_u8PortName, A_u8PinNumber, DIO_HIGH) ;
}
void HLED_voidLedOff   (u8 A_u8PortName , u8 A_u8PinNumber)
{
	MDIO_voidSetPinValue(A_u8PortName, A_u8PinNumber, DIO_LOW) ;
}
void HLED_voidLedTog   (u8 A_u8PortName , u8 A_u8PinNumber)
{
	MDIO_voidTogPinValue(A_u8PortName , A_u8PinNumber) ;
}
