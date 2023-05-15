/*
 * EXT_INT.h
 *
 * Created: 3/8/2023 11:57:28 PM
 *  Author: dell
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "../../MCAL/EXTI/External_INT_Interface.h"

void EXT_INT_INIT(interrupt_callback_t ISR0, interrupt_callback_t ISR1, interrupt_callback_t ISR2);


#endif /* EXT_INT_H_ */