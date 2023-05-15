/*
 * RTOS.h
 *
 * Created: 3/24/2023 2:06:10 PM
 *  Author: dell
 */ 


#ifndef RTOS_H_
#define RTOS_H_

#include "../LIB/Datatypes.h"

#define SYSTICK					(25)
#define NUMBER_OF_TASKS			(10)
#define QUEUE_SIZE				(20)
//#define MAX_PERIODICITY			(2000)

#define SUSPEND					(0)
#define RESUME					(1)

typedef void (*func_ptr) (void);

typedef struct {
	func_ptr function;
	uint32 periodicity;
	uint8 priority;
	uint8 firstDelay;
	uint8 state;
} task;

void tasks_queue_insert(func_ptr func);
void tasks_queue_delete(void);
void RTOS_init(void);
void RTOS_create_task(func_ptr func, uint32 period, uint8 prior, uint8 firstDelay);
void RTOS_suspend_task(func_ptr func);
void RTOS_resume_task(func_ptr func);
void RTOS_delete_task(func_ptr func);
void RTOS_scheduler(void);
void RTOS_start(void);
#endif /* RTOS_H_ */