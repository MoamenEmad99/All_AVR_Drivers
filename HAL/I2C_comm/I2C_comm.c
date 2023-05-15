/*
 * I2C_comm.c
 *
 * Created: 3/9/2023 9:24:26 PM
 *  Author: dell
 */ 

#include "I2C_comm.h"

void I2C_comm_slave_init(uint8 address){
	I2C_slave_init(address);
}

uint8 I2C_comm_slave_receive_byte(void){
	I2C_comm_slave_receive_byte();
}

void I2C_comm_master_init(void){
	I2C_master_init();
}

uint8 I2C_comm_master_receive_byte(uint8 address, uint8 ack){
	I2C_master_receive_byte(address, ack);
}

void I2C_comm_master_transmit_byte(uint8 data, uint8 address){
	I2C_comm_master_transmit_byte(data, address);
}