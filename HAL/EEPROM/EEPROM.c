/*
 * EEPROM.c
 *
 * Created: 3/16/2023 2:41:48 PM
 *  Author: dell
 */ 


#include "../../MCAL/I2C/I2C_Interface.h"
#include "EEPROM.h"


void EEPROM_init(void){
	I2C_master_init();
}


void EEPROM_write_byte(uint8 page, uint8 byteAddress, uint8 dataByte){
	uint8 EEPROM_address = (EEPROM_ADDRESS | (page<<1));
	if(I2C_start() == EVENT_OK){
		if(I2C_address_select(EEPROM_address, WRITE) == SLA_W_ACK_SENT){
			if(I2C_data_RW(&byteAddress, WRITE, ACK) == DATA_W_ACK_SENT){
				if(I2C_data_RW(&dataByte, WRITE, ACK) == DATA_W_ACK_SENT){
					I2C_stop();
				}
			}
		}
	}
	
}


void EEPROM_write_page(uint8 page, uint8 startByte, uint8 dataSize, uint8 *data){}


uint8 EEPROM_read_current(uint8 page){
	uint8 EEPROM_address = (EEPROM_ADDRESS | (page<<1));
	uint8 data;
	if(I2C_start() == EVENT_OK){
		if(I2C_address_select(EEPROM_address, READ) == SLA_R_ACK_SENT){
			if(I2C_data_RW(&data, READ, NACK) == DATA_R_NACK_SENT){
				I2C_stop();
			}
		}
	}
	return data;
}


uint8 EEPROM_read_address(uint8 page, uint8 byteAddress){
	uint8 EEPROM_address = (EEPROM_ADDRESS | (page<<1));
	uint8 data;
	if(I2C_start() == EVENT_OK){
		if(I2C_address_select(EEPROM_address, WRITE) == SLA_W_ACK_SENT){
			if(I2C_data_RW(&byteAddress, WRITE, ACK) == DATA_W_ACK_SENT){
				if(I2C_repeated_start() == EVENT_OK){
					if(I2C_address_select(EEPROM_address, READ) == SLA_W_ACK_SENT){
						if(I2C_data_RW(&data, READ, NACK) == DATA_R_NACK_SENT){
							I2C_stop();
						}
					}
				}
			}
		}
	}
	return data;	
}
	
	
void EEPROM_read_page(uint8 page, uint8 startByte, uint8 dataSize, uint8 *data){}