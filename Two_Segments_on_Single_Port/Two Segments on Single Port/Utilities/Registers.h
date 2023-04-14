/*
 * Registers.h
 *
 * Created: 4/13/2023 11:19:15 PM
 *  Author: IBRAHIM
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_


/********************************************************/
/*                 GPIO Registers                       */
/********************************************************/

/* Port-A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Port-C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

#endif /* REGISTERS_H_ */