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
		sendX10(int, int);
		
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

sendX10(int adresse, int data)
{
	char buffer[16];
	//manchester kode ind i buffer 
	int counter = 0;
	int np_counter = g_counter //skal erklæres 
	
	while  counter < 16
	{
		while np_counter == g_counter 
		{
			
		}
		assert(np_counter+1 == g_counter)
		
		np_counter = g_counter;
		// kan sende noget ud 
		
		char c = buffer[counter++];
		//sætte ben højt, hvis c = 1
		 
		
	}  
	
}
