/*
 * PB.c
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/StdTypes.h"
#include "../../MCAL/MDIO/DIO.h"
#include "PB.h"
#include <util/delay.h>

void HPB_voidInit       (u8 A_u8PortName , u8 A_u8PinNumber)
{
	MDIO_voidInitPin(A_u8PortName, A_u8PinNumber, DIO_INPUT) ;
	MDIO_voidSetPinValue(A_u8PortName, A_u8PinNumber, DIO_HIGH) ;
}
u8   HPB_u8GetPbStatues (u8 A_u8PortName , u8 A_u8PinNumber)
{
	if (MDIO_u8GetPinValue(A_u8PortName, A_u8PinNumber) == PB_PRESSED)
	{
		_delay_ms(20) ;
		if (MDIO_u8GetPinValue(A_u8PortName, A_u8PinNumber) == PB_PRESSED)
		{
			while (MDIO_u8GetPinValue(A_u8PortName, A_u8PinNumber) == PB_PRESSED) ;
			_delay_ms(20) ;
			return PB_PRESSED ;
		}
		else
		{
			return PB_NOT_PRESSED ;
		}
	}
	else
	{
		return PB_NOT_PRESSED ;
	}
}
