/*
 * 7Seg.c
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/StdTypes.h"
#include "../../MCAL/MDIO/DIO.h"
#include "7Seg.h"

static u8 G_u8SegNumbers [] =
{
		0x3F ,
		0x06 ,
		0x5B ,
		0x4F ,
		0x66 ,
		0x6D ,
		0x7D ,
		0x07 ,
		0x7F ,
		0x6F
};
void H7SEG_voidInit        (Seg_t A_xSeg                )
{
	MDIO_voidInitPort(A_xSeg.Data_Port, 0xff) ;
	MDIO_voidInitPin(A_xSeg.Comm_Port, A_xSeg.Comm_Pin, DIO_OUTPUT) ;
}
void H7SEG_voidOff         (Seg_t A_xSeg                )
{
	switch (A_xSeg.Type)
	{
	case COMM_ANODE :
		MDIO_voidSetPinValue(A_xSeg.Comm_Port, A_xSeg.Comm_Pin, DIO_LOW) ;
		break ;
	case COMM_CATHODE :
		MDIO_voidSetPinValue(A_xSeg.Comm_Port, A_xSeg.Comm_Pin, DIO_HIGH) ;
		break ;
	}
}
void H7SEG_voidWriteNumber (Seg_t A_xSeg , u8 A_u8Number)
{
	if (A_u8Number > 9)
	{
		return ;
	}
	switch (A_xSeg.Type)
	{
	case COMM_ANODE :
		MDIO_voidSetPinValue(A_xSeg.Comm_Port, A_xSeg.Comm_Pin, DIO_HIGH) ;
		MDIO_voidSetPortValue(A_xSeg.Data_Port, ~G_u8SegNumbers [A_u8Number]) ;
		break ;
	case COMM_CATHODE :
		MDIO_voidSetPinValue(A_xSeg.Comm_Port, A_xSeg.Comm_Pin, DIO_LOW) ;
		MDIO_voidSetPortValue(A_xSeg.Data_Port, G_u8SegNumbers [A_u8Number]) ;
		break ;
	}
}
