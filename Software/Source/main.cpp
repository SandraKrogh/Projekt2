/*
 * Software.cpp
 *
 * Created: 29-04-2021 13:24:26
 * Author : sandr
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "taendlys.h"
#include "Init.h"
#include "Fyldbadekar.h"
#include "Tid.h"

int getGlobalSek();
int sek_= 0; //global variabel til sekund tæller
int times = 10;
int increaseTime=0;

int main(void)
{
	sei(); //enable global interrupt 
	
	initInterrupt();
	initTimer();
	initPort();

    /* Replace with your application code */
	
	while (1) 
    {
		//test af sekund tæller
		if(sek_ %2 == 0)
		turnOnLED(3);
		else
		turnOffLED(3);
		
		int min = getmin();
		int hour = gethour();
		
		int RealTimeSek = getGlobalSek();
			
		bool status;
		
		status=compareTimeStart(min,hour,RealTimeSek);
			
		if(status == true)
		{
			taendlys();
			int increaseTime = RealTimeSek;
			times=0;
		}
		
		if(RealTimeSek == increaseTime + 1800  && times < 6 ) //1800 er en random værdi
		{
			increase();
			increaseTime += 1800; 
			times++; 
		}
		
		if(times == 6)
		{
			sluklys();
			times = 10;
		}
    }
}

//real time
ISR(TIMER1_OVF_vect)
{ 
  sek_++;
  
  if( sek_ > 86400)
  {
	  sek_=0;
  }
}

//til badekaret 
ISR(INT2_vect) 
{
	fyldbadekar();
}

int getGlobalSek()
{
	return sek_;
}
