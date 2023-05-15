/*
 * DELAY.c
 *
 * Created: 3/9/2023 1:17:39 AM
 *  Author: dell
 */ 

#include "../../MCAL/Timer0/Timer0_Interface.h"

void delayMilliSeconds(uint16 Milliseconds){
	TIMER0_DelayMilliSeconds_with_Blocking(Milliseconds);
}

void delayMicroSeconds(uint16 Microseconds){
	TIMER0_DelayMilliSeconds_with_Blocking(Microseconds);
}