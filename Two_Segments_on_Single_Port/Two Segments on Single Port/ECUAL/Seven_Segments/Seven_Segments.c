/*
 * _7_Segments.c
 *
 * Created: 4/13/2023 11:18:08 PM
 *  Author: IBRAHIM
 */ 

#include "Seven_Segments.h"
#include "util/delay.h"
#define F_CPU 1000000

u8 count=0;

u16 internal_count = 0;

u8 numbers[10]={zero,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
nine};

void Segment7_VidInit(u8 u8PortCopy, u8 u8ComPortCopy, u8 u8ComPinCopy, u8 u8ComPinTypeCopy)
{
	DIO_SetPortDirection(u8PortCopy, PORT_OUTPUT);
	DIO_SetPinDirection(u8ComPortCopy, u8ComPinCopy, PIN_OUTPUT);
	switch(u8ComPinTypeCopy)
	{
		case comCathode:
		DIO_SetPinValue(u8ComPortCopy, u8ComPinCopy, PIN_LOW);
		break;
		case comAnode:
		DIO_SetPinValue(u8ComPortCopy, u8ComPinCopy, PIN_HIGH);
		break;
	}
	Port7Segment = u8PortCopy;
	comPort = u8ComPortCopy;
	comPin = u8ComPinCopy;
	comType = u8ComPinTypeCopy;
}

void Segment7_VidSetDisplay(u8 u8SignalCopy)
{
	DIO_SetPortValue(Port7Segment,u8SignalCopy);
}

void Segment7_VidClearDisplay()
{
	DIO_SetPortValue(Port7Segment, PORT_LOW);
}

void Segment7_VidEnableDisplay(u8 comPort,u8 comPin,u8 comType)
{
	switch(comType)
	{
		case comAnode:
		DIO_SetPinValue(comPort, comPin, PIN_HIGH);
		break;
		case comCathode:
		DIO_SetPinValue(comPort, comPin, PIN_LOW);
		break;
	}
}

void Segment7_VidDisableDisplay(u8 comPort,u8 comPin,u8 comType)
{
	switch(comType)
	{
		case comCathode:
		DIO_SetPinValue(comPort, comPin, PIN_HIGH);
		break;
		case comAnode:
		DIO_SetPinValue(comPort, comPin, PIN_LOW);
		break;
	}
}

void AppInit (void)
{
	Segment7_VidInit(PORTA, PORTC, PIN0, comCathode);
	Segment7_VidInit(PORTA, PORTC, PIN1, comCathode);
	Segment7_VidClearDisplay();
	Segment7_VidEnableDisplay(PORTC, PIN0, comCathode);
	Segment7_VidDisableDisplay(PORTC, PIN1, comCathode);
}

void App_Start (void)
{
					
					
					Segment7_VidEnableDisplay(PORTC, PIN0, comCathode);
					Segment7_VidDisableDisplay(PORTC, PIN1, comCathode);


					Segment7_VidSetDisplay(numbers[(count%10)]);

					_delay_ms(10);

					Segment7_VidEnableDisplay(PORTC, PIN1, comCathode);
					Segment7_VidDisableDisplay(PORTC, PIN0, comCathode);

					Segment7_VidSetDisplay(numbers[(count/10)]);

					_delay_ms(10);

					internal_count++;

					if(internal_count==50){
						internal_count=0;
						count++;
					}

					if(count==100){
						count=0;
					}
}