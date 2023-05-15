

#include "FreeRTOS/Source/include/FreeRTOS.h"
#include "FreeRTOS/Source/include/task.h"
#include "FreeRTOS/Source/include/semphr.h"

#include "HAL/LCD/LCD.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "util/delay.h"

xSemaphoreHandle task_smphr;
uint64 task_time=0;
uint8 task_time_str[20]; 
void sysTick_task(void){	
	TIMER0_start();
	vTaskDelay(1);
	TIMER0_stop();
	
	task_time = getTime_microSecond();
	uint8 i=0;
	while(task_time){
		task_time_str[i] = (task_time%10 + '0');
		task_time/=10;
		i++;
	}
	for(uint8 i=0; task_time_str[i] != '\0'; i++){
		UART_Transmit(task_time_str[i]);
	}
	
	while(1){

	}
}

void task1(void){
	TIMER0_start();
	while(1){
		vTaskDelay(1);
	}
}

void task2(void){
	TIMER0_stop();
	task_time = getTime_microSecond();
	uint8 i=0;
	while(task_time){
		task_time_str[i] = (task_time%10 + '0');
		task_time/=10;
		i++;
	}
	//sprintf(task_time_str, "%d", task_time);
	for(i=0; task_time_str[i] != '\0'; i++){
		UART_Transmit(task_time_str[i]);
	}	
	
	while(1){
		vTaskDelay(1);
	}
}

void task3(void){
	xSemaphoreGive(task_smphr);
	TIMER0_start();
	while(1){
		vTaskDelay(1);
	}
}

void task4(void){
	if(xSemaphoreTake(task_smphr,0)==pdPASS){
		TIMER0_stop();
		task_time = getTime_microSecond();
		uint8 i=0;
		while(task_time){
			task_time_str[i] = (task_time%10 + '0');
			task_time/=10;
			i++;
		}
		//sprintf(task_time_str, "%d", task_time);
		for(i=0; task_time_str[i] != '\0'; i++){
			UART_Transmit(task_time_str[i]);
		}
	}
	while(1){
		vTaskDelay(1);
	}
}

int main(void)
{
	TIMER0_SetConfig();
	UART_init(9600);
	//task_smphr = xSemaphoreCreateCounting(1,0);
	//xTaskCreate(task3, "T3", 100, NULL, 2, NULL);
	//xTaskCreate(task4, "T4", 200, NULL, 1, NULL);
	
	xTaskCreate(sysTick_task, "T1", 150, NULL, 1, NULL);
	

	/*
	xTaskCreate(task1, "T1", 100, NULL, 2, NULL);
	xTaskCreate(task2, "T2", 200, NULL, 1, NULL);
	*/
	
	vTaskStartScheduler();

		
	
	while(1){		

	}
}
