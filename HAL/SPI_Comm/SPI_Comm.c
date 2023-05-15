/*
 * SPI_Comm.c
 *
 * Created: 3/8/2023 11:46:13 PM
 *  Author: dell
 */ 
#include "SPI_Comm.h"



void SPI_with_INT_init(SPI_callback_t SPI_callback){
	SPI_set_callback(SPI_callback);
	SPI_init();
}
