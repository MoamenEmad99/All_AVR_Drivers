/*
 * I2C_Reg.h
 *
 * Created: 3/9/2023 2:20:45 PM
 *  Author: dell
 */ 


#ifndef I2C_REG_H_
#define I2C_REG_H_

#include "../../LIB/Datatypes.h"

/*--------------I2C Registers--------------*/
#define  SREG	(*(volatile uint8*)(0x5F))
#define  TWBR	(*(volatile uint8*)(0x20))
#define  TWCR	(*(volatile uint8*)(0x56))
#define  TWSR	(*(volatile uint8*)(0x21))
#define  TWDR	(*(volatile uint8*)(0x23))
#define  TWAR	(*(volatile uint8*)(0x22))

//global interrupt enable bit in SREG
#define GIE		7

/*----TWCR bits----*/
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

/*----TWSR bits----*/
#define TWPS1	1
#define TWPS0	0

/*----TWAR bits----*/
#define TWGCE	0

#endif /* I2C_REG_H_ */