/*
 * seven_segment.c
 *
 * Created: 3/25/2023 12:13:39 PM
 *  Author: dell
 */ 

#include "../../MCAL/DIO/DIO_Interface.h"
#include "seven_segment.h"

void seven_segment1_init(void){
	DIO_vSetPortDirection(SS1_PORT, OUT);
	DIO_vSetPinDirection(SS1_COM_PORT, SS1_COM_PIN, OUT);
}

void seven_segment2_init(void){
	DIO_vSetPortDirection(SS2_PORT, OUT);
	DIO_vSetPinDirection(SS2_COM_PORT, SS2_COM_PIN, OUT);
}

void seven_segment1_sendNum(uint8 num){
	DIO_vWritePin(SS1_COM_PORT, SS1_COM_PIN, LOW);
	switch(num){
		case 0:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, HIGH);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, LOW);
			break;
	
		case 1:
			DIO_vWritePin(SS1_PORT, SS_A, LOW);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, LOW);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, LOW);
			DIO_vWritePin(SS1_PORT, SS_G, LOW);
			break;
			
		case 2:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, LOW);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, HIGH);
			DIO_vWritePin(SS1_PORT, SS_F, LOW);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;
			
		case 3:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, LOW);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;		
			
		case 4:
			DIO_vWritePin(SS1_PORT, SS_A, LOW);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, LOW);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;
			
		case 5:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, LOW);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;			
			
		case 6:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, LOW);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, HIGH);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;
			
		case 7:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, LOW);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, LOW);
			DIO_vWritePin(SS1_PORT, SS_G, LOW);
			break;
			
		case 8:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, HIGH);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;
			
		case 9:
			DIO_vWritePin(SS1_PORT, SS_A, HIGH);
			DIO_vWritePin(SS1_PORT, SS_B, HIGH);
			DIO_vWritePin(SS1_PORT, SS_C, HIGH);
			DIO_vWritePin(SS1_PORT, SS_D, HIGH);
			DIO_vWritePin(SS1_PORT, SS_E, LOW);
			DIO_vWritePin(SS1_PORT, SS_F, HIGH);
			DIO_vWritePin(SS1_PORT, SS_G, HIGH);
			break;
			
		default:
			break;
	}
}


void seven_segment2_sendNum(uint8 num){
	DIO_vWritePin(SS2_COM_PORT, SS2_COM_PIN, LOW);
	switch(num){
		case 0:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, HIGH);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, LOW);
		break;
		
		case 1:
		DIO_vWritePin(SS2_PORT, SS_A, LOW);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, LOW);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, LOW);
		DIO_vWritePin(SS2_PORT, SS_G, LOW);
		break;
		
		case 2:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, LOW);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, HIGH);
		DIO_vWritePin(SS2_PORT, SS_F, LOW);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 3:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, LOW);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 4:
		DIO_vWritePin(SS2_PORT, SS_A, LOW);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, LOW);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 5:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, LOW);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 6:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, LOW);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, HIGH);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 7:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, LOW);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, LOW);
		DIO_vWritePin(SS2_PORT, SS_G, LOW);
		break;
		
		case 8:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, HIGH);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		case 9:
		DIO_vWritePin(SS2_PORT, SS_A, HIGH);
		DIO_vWritePin(SS2_PORT, SS_B, HIGH);
		DIO_vWritePin(SS2_PORT, SS_C, HIGH);
		DIO_vWritePin(SS2_PORT, SS_D, HIGH);
		DIO_vWritePin(SS2_PORT, SS_E, LOW);
		DIO_vWritePin(SS2_PORT, SS_F, HIGH);
		DIO_vWritePin(SS2_PORT, SS_G, HIGH);
		break;
		
		default:
		break;
	}
}


void seven_segment1_release(void){
	DIO_vWritePin(SS1_COM_PORT, SS1_COM_PIN, HIGH);
}

void seven_segment2_release(void){
	DIO_vWritePin(SS2_COM_PORT, SS2_COM_PIN, HIGH);
}