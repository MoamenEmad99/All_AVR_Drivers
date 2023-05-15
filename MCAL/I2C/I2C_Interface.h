/*
 * I2C_Interface.h
 *
 * Created: 3/9/2023 2:21:05 PM
 *  Author: dell
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../../LIB/Datatypes.h"



#define SCL_CLK			(400000UL)
#define I2C_PRESCALER	PRESC_1
#define I2C_STATE		(TWSR & 0xF8)
#define I2C_INT			I2C_EN


#define READ			(0)
#define WRITE			(1)

#define ACK				(0)
#define NACK			(1)

#define PRESC_1			(0)
#define PRESC_4			(1)
#define PRESC_16		(2)
#define PRESC_64		(3)


#define I2C_DIS			(0)
#define I2C_EN			(1)


/*----------MASTER MODE STATES----------*/
#define START_STATE				(0x08)
#define REPEATED_START_STATE	(0x10)
#define MASTER_SLA_W_ACK		(0x18)
#define MASTER_SLA_W_NACK		(0x20)
#define MASTER_DATA_W_ACK		(0x28)
#define MASTER_DATA_W_NACK		(0x30)
#define MASTER_SLA_R_ACK		(0x40)
#define MASTER_SLA_R_NACK		(0x48)
#define MASTER_DATA_R_ACK		(0x50)
#define MASTER_DATA_R_NACK		(0x58)
#define MASTER_ARBIT_LOST		(0x38)

/*----------MASTER MODE RETURNS----------*/
#define EVENT_OK					(0)
#define	START_FAILED				(1)
#define	REPEATED_START_FAILED		(2)
#define SLA_W_ACK_SENT				(3)
#define SLA_W_NACK_SENT				(4)
#define DATA_W_ACK_SENT				(5)
#define DATA_W_NACK_SENT			(6)
#define DATA_W_FAILED				(7)
#define SLA_R_ACK_SENT				(8)
#define SLA_R_NACK_SENT				(9)
#define SLA_RW_FAILED				(10)
#define DATA_R_ACK_SENT				(11)
#define DATA_R_NACK_SENT			(12)
#define DATA_R_FAILED				(13)

/*----------SLAVE MODE STATES----------*/
#define SLAVE_SLA_W_ACK			(0x60)
#define SLAVE_DATA_W_ACK		(0x80)
#define SLAVE_DATA_W_NACK		(0x88)

#define SLAVE_SLA_R_ACK			(0xA8)
#define SLAVE_DATA_R_ACK		(0xB8)
#define SLAVE_DATA_R_NACK		(0xC0)

#define SLAVE_GC_ACK			(0x70)
#define SLAVE_GC_DATA_W_ACK		(0x90)
#define SLAVE_GC_DATA_W_NACK	(0x98)

#define SLAVE_STOP_SR			(0xA0)



//pointer to function typedef (for isr callback)
typedef void (*I2C_callback_t) (uint8 I2C_data);

//UART I2C interrupt request
#define I2C_INT_vector __vector_19

//ISR macro
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)



void I2C_master_init(void);
uint8 I2C_start(void);
uint8 I2C_repeated_start(void);
uint8 I2C_address_select(uint8 address, uint8 rw);
uint8 I2C_data_RW(uint8 *data, uint8 rw, uint8 ack);
void I2C_stop(void);
void I2C_master_transmit_byte(uint8 data, uint8 address);
uint8 I2C_master_receive_byte(uint8 address, uint8 ack);
void I2C_slave_init(uint8 address);
uint8 I2C_slave_receive_byte(void);
void I2C_set_callback(I2C_callback_t I2C_callback);
#endif /* I2C_INTERFACE_H_ */