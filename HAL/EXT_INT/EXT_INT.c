/*
 * EXT_INT.c
 *
 * Created: 3/8/2023 11:57:41 PM
 *  Author: dell
 */ 

#include "EXT_INT.h"
#include "../../MCAL/DIO/DIO_Interface.h"

void EXT_INT_INIT(interrupt_callback_t ISR0, interrupt_callback_t ISR1, interrupt_callback_t ISR2){
	EXT_INT_Init();
	if(ISR0 != NULL) DIO_vWritePin(PORT_D, Pin_Int0, HIGH);
	if(ISR1 != NULL) DIO_vWritePin(PORT_D, Pin_Int1, HIGH);
	if(ISR2 != NULL) DIO_vWritePin(PORT_B, Pin_Int2, HIGH);
	
	external_interrupt_register_callback(ISR0, ISR1, ISR2);
	EXT_INT_SET_CONFIG();
}