/*
 * GPIO.h
 *
 * Created: 4/13/2023 11:17:25 PM
 *  Author: IBRAHIM
 */ 

#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilities/Registers.h"
#include "../../Utilities/Bit_Manipulate.h"
#include "../../Utilities/STD_Types.h"

/* Port Defines */
#define PORTA    0
#define PORTC    2
/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PORT Directions */
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xff
/* PORT Value Options */
#define PORT_LOW  0x00
#define PORT_HIGH 0xff
/* PIN Directions */
#define PIN_INPUT  0
#define PIN_OUTPUT 1
/* PIN Value Options */
#define PIN_LOW  0
#define PIN_HIGH 1

/* IO Pins */
void DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy);
u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy);
void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);

/* IO Ports */
void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy);
void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy);
void DIO_TogglePortValue(u8 u8PortIdCopy);
u8 DIO_GetPortValue(u8 u8PortIdCopy);

#endif /* GPIO_H_ */