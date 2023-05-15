/*
 * RFID_Interface.h
 *
 * Created: 3/15/2023 3:23:18 PM
 *  Author: dell
 */ 


#ifndef RFID_INTERFACE_H_
#define RFID_INTERFACE_H_

#include "../../LIB/Datatypes.h"


#define RFID_SS					PORT_B, PIN3

// chip commands
#define CMD_Idle				(0x00)
#define CMD_Mem					(0x01)
#define CMD_GenerateRandomID	(0x02)
#define CMD_CalcCRC				(0x03)
#define CMD_Transmit			(0x04)
#define CMD_NoCmdChange			(0x07)
#define CMD_Receive				(0x08)
#define CMD_Transceive			(0x0C)
#define CMD_MFAuthent			(0x0E)
#define CMD_SoftReset			(0x0F)

// MIFARE card commands
#define APDU_REQA				(0x26)
#define APDU_WUPA				(0x52)
#define APDU_CT					(0x88)
#define APDU_SEL_CL1			(0x93)
#define APDU_SEL_CL2			(0x95)
#define APDU_SEL_CL3			(0x97)
#define APDU_HLTA				(0x50)
#define APDU_MF_AUTH_KEY_A		(0x60)
#define APDU_MF_AUTH_KEY_B		(0x61)
#define APDU_MF_READ			(0x30)
#define APDU_MF_WRITE			(0xA0)
#define APDU_MF_DECREMENT		(0xC0)
#define APDU_MF_INCREMENT		(0xC1)
#define APDU_MF_RESTORE			(0xC2)
#define APDU_MF_TRANSFER		(0xB0)
#define APDU_UL_WRITE			(0xA2)


#define CARD_FOUND		1
#define CARD_NOT_FOUND	2
#define ERROR			3

#define MAX_LEN			16

//Card types
#define Mifare_UltraLight 	0x4400
#define Mifare_One_S50		0x0400
#define Mifare_One_S70		0x0200
#define Mifare_Pro_X		0x0800
#define Mifare_DESFire		0x4403

// Mifare_One card command word
# define PICC_REQIDL          0x26               // find the antenna area does not enter hibernation
# define PICC_REQALL          0x52               // find all the cards antenna area
# define PICC_ANTICOLL        0x93               // anti-collision
# define PICC_SElECTTAG       0x93               // election card
# define PICC_AUTHENT1A       0x60               // authentication key A
# define PICC_AUTHENT1B       0x61               // authentication key B
# define PICC_READ            0x30               // Read Block
# define PICC_WRITE           0xA0               // write block
# define PICC_DECREMENT       0xC0               // debit
# define PICC_INCREMENT       0xC1               // recharge
# define PICC_RESTORE         0xC2               // transfer block data to the buffer
# define PICC_TRANSFER        0xB0               // save the data in the buffer
# define PICC_HALT            0x50               // Sleep



uint8 RFID_readReg(uint8 reg);
void RFID_writeReg(uint8 reg, uint8 value);
void RFID_clearBitMask(uint8 reg, uint8 mask);
void RFID_setBitMask(uint8 reg, uint8 mask);
void RFID_reset(void);
uint8 RFID_getFirmwareVersion(void);
uint8 RFID_communicate(uint8 command,
uint8 *sendData,
uint8 sendLen,
uint8 *backData,
uint8 *backLen,
uint8 *validBits);
void RFID_init(void);
uint8 RFID_detectCard(void);
uint8 RFID_getCardId(uint8 *uid);

#endif /* RFID_INTERFACE_H_ */