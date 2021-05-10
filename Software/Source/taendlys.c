/*
 * taendlys.c
 *
 * Created: 04-05-2021 14:40:16
 *  Author: sandr
 */ 
#include "computerApp.h"

void taendlys()
{
	int min = getmin();
	int hour = gethour();
	
	int RealTimeSek = getGlobalSek();
	
	bool status; 
	status=compareTimeStart(min,hour,RealTimeSek);
	
	if(status == true)
	{
		DDRC = 0xFF;
		PORTC |= 00000010;
	}
	
	wait();
	
	bool compareTimeStop(min,hour,RealTimeSek);
}

bool compareTimeStart(int min, int hour, int RealTimeSek)
{
	int RealTimeMin, WakeUpMin; 
	
	RealTimeMin = RealTimeSek/60;
	
	WakeUpMin=(hour*60+min)-30;
	
	if(WakeUpMin<0)
	{
		WakeUpMin =1440 + WakeUpMin
	}
	
	if(RealTimeMin == WakeUpMin)
	{
		return true;
	}
	else
		return false;
}

void wait()
{

}

//wait function
ISR(TIMER3_OVF_vect)
{

}

bool compareTimeStop(int min, int hour, int RealTimeSek)
{
	int RealTimeMin, WakeUpMin;
	
	RealTimeMin = RealTimeSek/60;
	
	WakeUpMin=(hour*60+min)-30;
	
	if(WakeUpMin<0)
	{
		WakeUpMin =1440 + WakeUpMin
	}
	
	if(RealTimeMin == WakeUpMin)
	{
		return true;
	}
	else
	return false;
}

