/*
 * I2C.c
 *
 * Created: 3/9/2023 2:15:21 PM
 *  Author: dell
 */ 

#include "I2C_Interface.h"
#include "I2C_Reg.h"
#include "../../LIB/Calcbit.h"
#include <math.h>

static uint8 I2C_R_data;
I2C_callback_t I2C_callback_ptr = NULL;

void I2C_master_init(void){
	TWSR = I2C_PRESCALER;
	TWBR = ((F_CPU/SCL_CLK - 16)/(2*pow(4,I2C_PRESCALER)));
}

uint8 I2C_start(void){
	//clear interrupt flag, enable start bit, enable I2C
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN)); 
		
	while(getbit(TWCR,TWINT) == 0); //wait for start bit transmission
	
	if(I2C_STATE != START_STATE)	//check start bit state
		return START_FAILED;
		
	else 
		return EVENT_OK;
}

uint8 I2C_repeated_start(void){
	//clear interrupt flag, enable start bit, enable I2C
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1<<TWEN));
	
	while(getbit(TWCR,TWINT) == 0); //wait for repeated start bit transmission
	
	if(I2C_STATE != REPEATED_START_STATE)	//check repeated start bit state
		return REPEATED_START_FAILED;
	
	else
		return EVENT_OK;	
}

uint8 I2C_address_select(uint8 address, uint8 rw){
	if(rw == WRITE)
		TWDR = address + 0;
		
	else if(rw == READ)
		TWDR = address + 1;
		
	else
		return SLA_RW_FAILED;
		
	TWCR = ((1<<TWINT) | (1<<TWEN)); //clear interrupt, flag enable I2C
	
	while(getbit(TWCR,TWINT) == 0); //wait for address transmission
	
	if(I2C_STATE == MASTER_SLA_W_ACK)	//check SLA+W with ACK state
		return SLA_W_ACK_SENT;
		
	else if(I2C_STATE == MASTER_SLA_W_NACK)	//check SLA+W with NACK state
		return SLA_W_NACK_SENT;
		
	else if(I2C_STATE == MASTER_SLA_R_ACK)	//check SLA+R with ACK state
		return SLA_R_ACK_SENT;
		
	else if(I2C_STATE == MASTER_SLA_R_NACK)	//check SLA+R with NACK state
		return SLA_R_NACK_SENT;
		
	else
		return SLA_RW_FAILED;
}

uint8 I2C_data_RW(uint8 *data, uint8 rw, uint8 ack){
	if(rw == WRITE){
		TWDR = *data;			//write data
		
		TWCR = ((1<<TWINT) | (1<<TWEN)); //clear interrupt flag, enable I2C	
		
		while(getbit(TWCR,TWINT) == 0);		//wait for data transmission
		
		if(I2C_STATE == MASTER_DATA_W_ACK)	//check data write with ACK state
			return DATA_W_ACK_SENT;
			
		else if(I2C_STATE == MASTER_DATA_W_NACK)	//check data write with NACK state
			return DATA_W_NACK_SENT;
			
		else
			return DATA_W_FAILED;
	}
	
	if(rw == READ){
		if(ack == ACK){
			//enable ack, clear interrupt flag, enable I2C
			TWCR = ((1<<TWEA) | (1<<TWINT) | (1<<TWEN));
		}
		else if(ack == NACK){
			//clear interrupt flag, enable I2C
			TWCR = ((1<<TWINT) | (1<<TWEN));
		}
		
		while(getbit(TWCR,TWINT) == 0);		//wait for data reception
		
		*data = TWDR;						//read data	
		
		if(I2C_STATE == MASTER_DATA_R_ACK)	//check data read with ACK state
			return DATA_R_ACK_SENT;
		
		else if(I2C_STATE == MASTER_DATA_R_NACK)	//check data read with NACK state
			return DATA_R_NACK_SENT;
		
		else
			return DATA_R_FAILED;
	}
}

void I2C_stop(void){
	//enable stop bit, clear interrupt flag, enable I2C
	TWCR = ((1<<TWSTO) | (1<<TWINT) | (1<<TWEN));
	
	while(getbit(TWCR,TWSTO) == 1);		//wait for stop bit	
}


void I2C_master_transmit_byte(uint8 data, uint8 address){
	if(I2C_start() == EVENT_OK){
		if(I2C_address_select(address, WRITE) == SLA_W_ACK_SENT){
			if(I2C_data_RW(&data, WRITE, ACK) == DATA_W_ACK_SENT){
				I2C_stop();
			}
		}
	}
}

uint8 I2C_master_receive_byte(uint8 address, uint8 ack){
	uint8 data;
	if(I2C_start() == EVENT_OK){
		if(I2C_address_select(address, READ) == SLA_R_ACK_SENT){
			if(ack == NACK){
				if(I2C_data_RW(&data, READ, NACK) == DATA_R_NACK_SENT){
					I2C_stop();
				}
			}
			else{
				if(I2C_data_RW(&data, READ, ACK) == DATA_R_ACK_SENT){
					I2C_stop();
				}
			}
		}
	}
	return data;
}

void I2C_slave_init(uint8 address){
	TWBR = 0x00;
	TWSR = 0x00;
	TWAR = address;

	if(I2C_INT == I2C_EN){
		setbit(SREG,GIE);
		TWCR = ((1<<TWEA) | (1<<TWIE) | (1<<TWEN));
	}
	
	else if(I2C_INT == I2C_DIS){
		TWCR = ((1<<TWEA) | (1<<TWEN));
	}
}

//uint8 I2C_slave_listen(uint8 address)

uint8 I2C_slave_receive_byte(void){
	uint8 data;
	while(getbit(TWCR,TWINT) == 0);
	if(I2C_STATE == SLAVE_SLA_W_ACK){
		setbit(TWCR,TWINT);
		while(getbit(TWCR,TWINT) == 0);
		if(I2C_STATE == SLAVE_DATA_W_ACK){
			data =  TWDR;
			setbit(TWCR,TWINT);
			while(getbit(TWCR,TWINT) == 0);
			if(I2C_STATE == SLAVE_STOP_SR){
				setbit(TWCR,TWINT);
				return data;
			}
		}
	}
}

void I2C_set_callback(I2C_callback_t I2C_callback){
	if(I2C_callback != NULL) 
		I2C_callback_ptr = I2C_callback;
}

ISR(I2C_INT_vector){	
	if(I2C_STATE == SLAVE_SLA_W_ACK)
		setbit(TWCR,TWINT);
		
	else if(I2C_STATE == SLAVE_DATA_W_ACK){
		I2C_R_data =  TWDR;
		setbit(TWCR,TWINT);
	}

	else if(I2C_STATE == SLAVE_STOP_SR){
		setbit(TWCR,TWINT);
		I2C_callback_ptr(I2C_R_data);
	}
	
	else
		setbit(TWCR,TWINT); 
}