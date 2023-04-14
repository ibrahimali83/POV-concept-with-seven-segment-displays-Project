/*
 * Bit_Manipulate.h
 *
 * Created: 4/13/2023 11:21:28 PM
 *  Author: IBRAHIM
 */ 

#ifndef BIT_MANIPULATE_H_
#define BIT_MANIPULATE_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* BIT_MANIPULATE_H_ */