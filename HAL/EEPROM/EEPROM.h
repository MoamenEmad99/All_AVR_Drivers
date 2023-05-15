/*
 * EEPROM.h
 *
 * Created: 3/16/2023 2:42:06 PM
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../LIB/Datatypes.h"

#define EEPROM_ADDRESS		(0xA0)

void EEPROM_init(void);
void EEPROM_write_byte(uint8 page, uint8 byteAddress, uint8 dataByte);
void EEPROM_write_page(uint8 page, uint8 startByte, uint8 dataSize, uint8 *data);
uint8 EEPROM_read_current(uint8 page);
uint8 EEPROM_read_address(uint8 page, uint8 byteAddress);
void EEPROM_read_page(uint8 page, uint8 startByte, uint8 dataSize, uint8 *data);



#endif /* EEPROM_H_ */