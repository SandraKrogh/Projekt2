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

int getGlobalSek();

//global variable declaration 
volatile int sek= 0; 
int times= 0;
int increaseTime = 0;

//til test delay
#define F_CPU 16000000
#include  <util/delay.h>

int main(void)
{	
	initLEDport();
	initInterrupt();
	initTimer();
	initPort();
	
	sei();//enable global interrupt 

    /* Replace with your application code */
	
	while(1) 
    {
		//test af sekund tæller
 		if(sek %2 == 0)
 		{
 		turnOnLED(3);
 		_delay_ms(100);
 		}
		else
 		turnOffLED(3);
		
// 		int min = getmin();
// 		int hour = gethour();
// 		
// 		int RealTimeSek = getGlobalSek();
// 			
// 		bool status;
// 		
// 		status=compareTimeStart(min,hour,RealTimeSek);
// 			
// 		if(status == true)
// 		{
// 			taendlys();
// 			int increaseTime = RealTimeSek;
// 			times=0;
// 		}
// 		
// 		if(RealTimeSek == increaseTime + 1800  && times < 6 ) //1800 er en random værdi
// 		{
// 			increase();
// 			increaseTime += 1800; 
// 			times++; 
// 		}
// 		
// 		if(times == 6)
// 		{
// 			sluklys();
// 			times = 10;
// 		}
	}
}

//real time
ISR(TIMER1_OVF_vect)
{ 
  sek++;
  
  if( sek > 86500) 
  {
	 toggleLED(3);
	 sek=0;
  }
}

//til badekaret 
ISR(INT2_vect) 
{
	fyldbadekar();
}


int getGlobalSek()
{
	return sek;
}
