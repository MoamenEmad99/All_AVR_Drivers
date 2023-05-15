/*
 * UART_Comm.h
 *
 * Created: 3/8/2023 11:50:56 PM
 *  Author: dell
 */ 


#ifndef UART_COMM_H_
#define UART_COMM_H_

#include "../../MCAL/UART/UART_Interface.h"

void UART_with_INT_init(uint32 baudRate, RXC_callback_t RXC_callback);

#endif /* UART_COMM_H_ */