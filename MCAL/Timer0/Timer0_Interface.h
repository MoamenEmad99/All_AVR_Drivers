/*
 * Timer0_Interface.h
 *
 * Created: 2/24/2023 1:36:10 PM
 *  Author: dell
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "Timer0_Reg.h"
#include "../../LIB/Calcbit.h"
#include "../../LIB/Datatypes.h"

//Timer0 operating modes
#define NORMAL_MODE (0)
#define PWM_PHASE_CORRECT (1)
#define CTC_MODE (2)
#define FAST_PWM (3)

//prescaler masks
#define PRESCALER_CLEAR (0xF8)
#define PRESCALER_1 (0x01)
#define PRESCALER_8 (0x02)
#define PRESCALER_64 (0x03)
#define PRESCALER_256 (0x04)
#define PRESCALER_1024 (0x05)
#define EXT_CLK_FALLING_EDGE (0x06)
#define EXT_CLK_RISING_EDGE (0x07)

//Timer0 interrupt state
#define TIMER0_INT_DISABLE (0)
#define TIMER0_INT_ENABLE (1)


//pointer to function typedef (for isr callback)typedef void (*CTC_callback_t) (void);
typedef void (*OV_callback_t) (void);


//Timer configs struct
typedef struct
{
	uint8 Mode;
	uint8 Enable_Interrupt;	
}Timer_Config;


//Timer0 configs object
static Timer_Config Config = {
	NORMAL_MODE,
	TIMER0_INT_ENABLE,
	};

//TIMER0 overflow interrupt request
#define TIMER0_OV_INT __vector_11
//TIMER0 compare match interrupt request
#define TIMER0_COMP_INT __vector_10

//ISR macro
#define TIMER0_ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)



/*** Timer0 APIs***/
void TIMER0_SetConfig(void);void TIMER0_DelayMilliSeconds_with_Blocking(uint16 Milli_Seconds);void TIMER0_DelayMicroSeconds_with_Blocking(uint16 Micro_Seconds);void TIMER0_DelayMilliSeconds_without_Blocking(CTC_callback_t CTC_callback, uint16 Milliseconds);
void TIMER0_start(void);void TIMER0_stop(void);uint64 getTime_microSecond(void);
#endif /* TIMER0_INTERFACE_H_ */