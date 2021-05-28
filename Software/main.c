/*
 * main1.c
 *
 * Created: 22-05-2021 21:08:57
 *  Author: sandr
 */ 

/*
 * Software.cpp
 *
 * Created: 29-04-2021 13:24:26
 * Author : sandr
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

#include "Header/Fyldbadekar.h"
#include "Header/LED.h" 
#include "Header/sendX10.h"
#include "Header/Tid.h"
#include "Header/lys.h"
#include "Header/Init1.h"
#include "Header/computerApp.h"
#include "Header/uart_1.h"

//til test delay
#define F_CPU 16000000
#include  <util/delay.h>

int getGlobalSek();

//global variable declaration 
volatile unsigned int sek= 10; 
int times= 0;
volatile unsigned int increaseTime = 0;
volatile unsigned int badekar_counter = 0;
volatile unsigned int RealTimeSek = 0;
volatile unsigned int status = 0;

int main(void)
{	
	InitUART(9600, 8);
	initLEDport();
    initInterrupt();
 	initTimer();
	initPort();
	
	sei();

    /* Replace with your application code */
	
	int min = 0;
	int hour = 0;
	int alarmcounter=0;
	
	min = getmin();
	hour = gethour();
	
	while(1) 
    {
		RealTimeSek = getGlobalSek();
		  		
 		status=compareTimeStart(min,hour,RealTimeSek);
		  		
// 		if(status == 1 && alarmcounter == 0)
// 		{
// 			SendString("tandlys\r");
// 			taendlys();
// 			SendString("i main\r");
// 			increaseTime = RealTimeSek;
// 			times=0;
// 			alarmcounter++;	
// 		}
// 		
// 		if((RealTimeSek == (increaseTime + 120))  && times < 6 ) 
// 		{
// 			SendString("increase");
// 			SendString("\r");
// 			increaselys();
// 			increaseTime += 1800; 
// 			times++; 
// 			alarmcounter = 0;
// 		}
// 		
// 		if(times == 6)
// 		{
// 			sluklys();
// 			times = 10;
// 		}

		if(badekar_counter == 1)
		{
			fyldbadekar();
			badekar_counter = 0;
		}
	}
}

//real time
ISR(TIMER1_OVF_vect)
{ 
  sek++;
  
  if( sek > 86500)  //24 timer
  {
	 sek=0;
  }
}

//til badekaret 
ISR(INT3_vect) 
{
	badekar_counter++;	
}


int getGlobalSek()
{
	return sek;
}

