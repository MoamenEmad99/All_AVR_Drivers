/*
 * UART_Comm.c
 *
 * Created: 3/8/2023 11:51:06 PM
 *  Author: dell
 */ 

#include "UART_Comm.h"

void UART_with_INT_init(uint32 baudRate, RXC_callback_t RXC_callback){
	UART_init(baudRate);
	UART_Set_RXC_callback(RXC_callback);
}
