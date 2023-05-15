/*
 * I2C_comm.h
 *
 * Created: 3/9/2023 9:24:13 PM
 *  Author: dell
 */ 


#ifndef I2C_COMM_H_
#define I2C_COMM_H_

#include "../../MCAL/I2C/I2C_Interface.h"

void I2C_comm_slave_init(uint8 address);
uint8 I2C_comm_slave_receive_byte(void);
void I2C_comm_master_init(void);
uint8 I2C_comm_master_receive_byte(uint8 address, uint8 ack);
void I2C_comm_master_transmit_byte(uint8 data, uint8 address);

#endif /* I2C_COMM_H_ */