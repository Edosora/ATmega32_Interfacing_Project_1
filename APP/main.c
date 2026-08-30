/*
 * main.c
 *
 *  Created on: Aug 29, 2026
 *      Author: Mohammed
 */
#include "../LIB/BitMath.h"
#include "../LIB/StdTypes.h"

#include "../MCAL/MDIO/DIO.h"

#include "../HAL/HKP/KP.h"
#include "../HAL/H7SEG/7Seg.h"
#include "../HAL/HLCD/LCD.h"
#include "../HAL/HBuzzer/Buzzer.h"

#include <util/delay.h>

// Arabic letters: م ح م د
u8 G_u8Char_M [8] = { 0x00, 0x00, 0x0E, 0x0A, 0x1F, 0x00, 0x00, 0x00 } ;
u8 G_u8Char_H [8] = { 0x00, 0x00, 0x0E, 0x01, 0x1F, 0x00, 0x00, 0x00 } ;
u8 G_u8Char_D [8] = { 0x00, 0x00, 0x01, 0x01, 0x07, 0x00, 0x00, 0x00 } ;

static u16 G_u16KeypressCounter = 0 ;

void main (void)
{
	u8 L_u8Key = KP_NOT_PRESSED ;
	u8 L_u8Beep = 0 ;

	// 7-seg wiring
	Seg_t SEG1 =
	{
			.Data_Port = DIO_PORTC  ,
			.Comm_Port = DIO_PORTB  ,
			.Comm_Pin  = DIO_PIN4   ,
			.Type      = COMM_CATHODE
	} ;

	HKP_voidInit(DIO_PORTD) ;
	H7SEG_voidInit(SEG1) ;
	H7SEG_voidOff(SEG1) ;
	HLCD_voidInit() ;
	HBuzzer_voidBuzzerInit(DIO_PORTB , DIO_PIN5) ;

	while (1)
	{
		L_u8Key = HKP_u8GetPressedValue(DIO_PORTD) ;

		if (L_u8Key != KP_NOT_PRESSED)
		{
			G_u16KeypressCounter ++ ;

			// digit -> 7-seg
			if ( (L_u8Key >= '0') && (L_u8Key <= '9') )
			{
				H7SEG_voidWriteNumber(SEG1 , L_u8Key - '0') ;
			}
			// slash -> english name
			else if (L_u8Key == '/')
			{
				HLCD_voidClrScreen() ;
				HLCD_voidMoveCursor(LCD_ROW0 , LCD_COL0) ;
				HLCD_voidDisplayStr((u8*)"MOHAMMED") ;
			}
			// asterisk -> arabic name
			else if (L_u8Key == '*')
			{
				HLCD_voidClrScreen() ;
				HLCD_voidDisplayCustomChar(G_u8Char_M , LCD_BLOCK0 , LCD_ROW0 , LCD_COL9) ;
				HLCD_voidDisplayCustomChar(G_u8Char_H , LCD_BLOCK1 , LCD_ROW0 , LCD_COL8) ;
				HLCD_voidDisplayCustomChar(G_u8Char_M , LCD_BLOCK2 , LCD_ROW0 , LCD_COL7) ;
				HLCD_voidDisplayCustomChar(G_u8Char_D , LCD_BLOCK3 , LCD_ROW0 , LCD_COL6) ;
			}

			// beep every 10 presses
			if ( (G_u16KeypressCounter % 10 == 0) && (G_u16KeypressCounter > 0) )
			{
				HBuzzer_voidBuzzerOn(DIO_PORTB , DIO_PIN5) ;
				for (L_u8Beep = 0 ; L_u8Beep < 4 ; L_u8Beep ++)
				{
					_delay_ms(50) ;
				}
				HBuzzer_voidBuzzerOff(DIO_PORTB , DIO_PIN5) ;
			}
			else
			{
				HBuzzer_voidBuzzerOff(DIO_PORTB , DIO_PIN5) ;
			}

			_delay_ms(50) ;
		}
	}
}
