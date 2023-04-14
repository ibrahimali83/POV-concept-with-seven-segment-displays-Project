/*
 * _7_Segments.h
 *
 * Created: 4/13/2023 11:17:47 PM
 *  Author: IBRAHIM
 */ 

#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_

#include "../../MCAL/GPIO/GPIO.h"

#define comCathode 0
#define comAnode 1

#define zero    0x3f
#define one     0x06
#define two     0x5b
#define three   0x4f
#define four    0x66
#define five    0x6d
#define six     0x7d
#define seven   0x07
#define eight   0x7f
#define nine    0x6f

void Segment7_VidInit(u8 u8PortCopy, u8 u8ComPortCopy, u8 u8ComPinCopy, u8 u8ComPinTypeCopy);
void Segment7_VidSetDisplay(u8 u8SignalCopy);
void Segment7_VidClearDisplay();
void Segment7_VidEnableDisplay(u8 comPort,u8 comPin,u8 comType);
void Segment7_VidDisableDisplay(u8 comPort,u8 comPin,u8 comType);
void AppInit (void);
void App_Start (void); 

u8 Port7Segment;
u8 comPort;
u8 comPin;
u8 comType;

#endif /* 7_SEGMENTS_H_ */