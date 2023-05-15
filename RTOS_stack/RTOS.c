/*
 * RTOS.c
 *
 * Created: 3/24/2023 2:06:22 PM
 *  Author: dell
 */ 


#include "RTOS.h"
#include "../MCAL/Timer0/Timer0_Interface.h"



static task tasks[NUMBER_OF_TASKS];
static uint8 task_count = 0;

static func_ptr tasks_queue[QUEUE_SIZE];
static int8 tasks_queue_rear=-1;
static int8 tasks_queue_front=-1;

void tasks_queue_insert(func_ptr func){
	if (tasks_queue_front == -1 && tasks_queue_rear == -1) {
		tasks_queue_front = 0;
		tasks_queue_rear = 0;
	}
	else {
		tasks_queue_rear++;
	}
	tasks_queue[tasks_queue_rear] = func;
}


void tasks_queue_delete(void){
	//int y = tasks_queue[tasks_queue_front];
	if (tasks_queue_front == tasks_queue_rear) {
		tasks_queue_front = -1;
		tasks_queue_rear = -1;
	}
	else
		tasks_queue_front++;
	//return y;
}


void RTOS_init(void){
	TIMER0_SetConfig();
	TIMER0_DelayMilliSeconds_without_Blocking(RTOS_scheduler, SYSTICK);
}


void RTOS_create_task(func_ptr func, uint32 period, uint8 prior, uint8 firstDelay){
	if(task_count == 0){
		tasks[task_count].function = func;
		tasks[task_count].periodicity = period;
		tasks[task_count].priority = prior;
		tasks[task_count].firstDelay = firstDelay;
		tasks[task_count].state = RESUME;
		task_count++;		
	}

	else{
		uint8 i = task_count-1;
		while(prior<tasks[i].priority && i>=0){
			tasks[i+1].function = tasks[i].function;
			tasks[i+1].periodicity = tasks[i].periodicity;
			tasks[i+1].priority = tasks[i].priority;
			tasks[i+1].firstDelay = tasks[i].firstDelay;
			tasks[i+1].state = tasks[i].state;
			
			i--;
		}
		
		tasks[i+1].function = func;
		tasks[i+1].periodicity = period;
		tasks[i+1].priority = prior;
		tasks[i+1].firstDelay = firstDelay;
		tasks[i+1].state = RESUME;
		
		task_count++;		
	}
}


void RTOS_scheduler(void){
	for(uint8 i=0; i<task_count; i++){
		if(tasks[i].function != NULL && tasks[i].state==RESUME){
			if(tasks[i].firstDelay == 0){
				tasks[i].firstDelay = tasks[i].periodicity-1;
				tasks_queue_insert(tasks[i].function);
			}
			else 
				tasks[i].firstDelay--;
		}
	}
}


void RTOS_start(void){
	if(tasks_queue_front != -1){
		func_ptr current_task = tasks_queue[tasks_queue_front];
		tasks_queue_delete();
		current_task();
	}
}


void RTOS_suspend_task(func_ptr func){
	for(uint8 i=0; i<task_count; i++){
		if(tasks[i].function == func){
			tasks[i].state = SUSPEND;
			break;
		}
	}
}
	
void RTOS_resume_task(func_ptr func){
	for(uint8 i=0; i<task_count; i++){
		if(tasks[i].function == func){
			tasks[i].state = RESUME;
			break;
		}
	}
}
	
void RTOS_delete_task(func_ptr func){
	for(uint8 i=0; i<task_count; i++){
		if(tasks[i].function == func){
			tasks[i].function = NULL;
			break;
		}
	}
}