/*
 * coding.c
 *
 * Created: 7/15/2023 2:31:33 AM
 * Author : kamar
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "FreeRTOS.H"
#include "task.h"

void task1 (void *vp);
void task2 (void *vp);


int main(void)
{
	
	char x=7;
	char y=6;
	
	/* cteation tasks */
	xTaskCreate(task1,"kamar",100,&x,1,NULL);
	xTaskCreate(task2,"salah",100,&y,2,NULL);
	
	/*start OS */
	vTaskStartScheduler();
    
}

void task1 (void *vp)
{
	/* intialization */
	DDRD|=(1<< *((char*)vp));                                                    //pin in PORTD is output
	while(1)
	{
		PORTD^=(1<< *((char*)vp));                                               // toggle 
		_delay_ms(1000);
	}
}

void task2 (void *vp)
{
	
	vTaskDelay(4000);                                                           // remain in wating state for 4 sec
	/* intialization */
	DDRD|=(1<< *((char*)vp));                                                    //pin in PORTD is output
	while(1)
	{
		PORTD^=(1<< *((char*)vp));                                               // toggle 
		_delay_ms(1000);
	}
}