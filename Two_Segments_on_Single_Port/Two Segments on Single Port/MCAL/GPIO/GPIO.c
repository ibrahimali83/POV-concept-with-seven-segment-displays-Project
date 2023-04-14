/*
 * GPIO.c
 *
 * Created: 4/13/2023 11:16:38 PM
 *  Author: IBRAHIM
 */ 

#include "GPIO.h"

void DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy)
{

		if ( u8PinValCopy == PIN_HIGH )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: SET_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTC: SET_BIT(PORTC_Register,u8PinIdCopy); break;
				default : break;
			}
		}

		else if ( u8PinValCopy == PIN_LOW )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: CLR_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTC: CLR_BIT(PORTC_Register,u8PinIdCopy); break;
				default : break;
			}
		}


	}


u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	u8 u8Valuecopy;


		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORTA: u8Valuecopy = GET_BIT(PINA_Register,u8PinIdCopy); break;
			case PORTC: u8Valuecopy = GET_BIT(PINC_Register,u8PinIdCopy); break;
			default : break;
		}


	return u8Valuecopy;

}
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy)
{

		if ( u8PinDirCopy == PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: SET_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTC: SET_BIT(DDRC_Register,u8PinIdCopy); break;
				default : break;
			}
		}

		else if ( u8PinDirCopy == PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: CLR_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTC: CLR_BIT(DDRC_Register,u8PinIdCopy); break;
				default : break;
			}
		}


	}


void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{

		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORTA: TOG_BIT(PORTA_Register,u8PinIdCopy); break;
			case PORTC: TOG_BIT(PORTC_Register,u8PinIdCopy); break;
			default : break;
		}
	}



/* IO Ports */
void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy)
{
	switch(u8PortIdCopy)
	{
		case PORTA : DDRA_Register = u8PortDirCopy; break;
		case PORTC : DDRC_Register = u8PortDirCopy; break;
		default: break;
	}

}
void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy)
{
	switch(u8PortIdCopy)
	{
		case PORTA : PORTA_Register = u8PortValCopy; break;
		case PORTC : PORTC_Register = u8PortValCopy; break;
		default: break;
	}


}
void DIO_TogglePortValue(u8 u8PortIdCopy)
{
	switch(u8PortIdCopy)
	{
		case PORTA : PORTA_Register ^= 0xFF; break;
		case PORTC : PORTC_Register ^= 0xFF; break;
		default: break;
	}

}
u8 DIO_GetPortValue(u8 u8PortIdCopy)
{
	u8 u8Valuecopy;

	switch(u8PortIdCopy)
	{
		case PORTA :u8Valuecopy = PINA_Register; break;
		case PORTC :u8Valuecopy = PINC_Register; break;
		default: break;
	}

	return u8Valuecopy;

}