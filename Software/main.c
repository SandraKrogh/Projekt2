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
volatile unsigned int sek= 0; 
int times= 0;
int increaseTime = 0;
volatile unsigned int badekar_counter = 0;

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
	int RealTimeSek = 0;
	int status = 0;
	
	while(1) 
    {
		//test af sekund tæller
// 		if(sek %2 == 0)
//  		{
//  		toggleLED(5);
// 		}
		
		min = getmin();
		hour = gethour();
	
		RealTimeSek = getGlobalSek();
	 
		toggleLED(3);
		  		
 		status=compareTimeStart(min,hour,RealTimeSek);
 		 		
		if(status == 1)
		{
			taendlys();
			increaseTime = RealTimeSek;
			times=0;
		}
		
		if(RealTimeSek == increaseTime + 60  && times < 6 ) //1800 er en random værdi
		{
			increaselys();
			increaseTime += 1800; 
			times++; 
		}
// 		
// 		if(times == 6)
// 		{
// 			sluklys();
// 			times = 10;
// 		}

		if(badekar_counter > 0)
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
  
  if( sek > 86500) 
  {
	 sek=0;
  }
}

//til badekaret 
ISR(INT1_vect) 
{
	badekar_counter++;	
	toggleLED(2);
}


int getGlobalSek()
{
	return sek;
}

