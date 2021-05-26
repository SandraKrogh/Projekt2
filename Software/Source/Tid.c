/*
 * Tid.c
 *
 * Created: 20-05-2021 12:32:48
 *  Author: sandr
 */ 
#include <stdbool.h>

int compareTimeStart(int min, int hour, int RealTimeSek)
{
	int RealTimeMin, WakeUpMin;
	
	RealTimeMin = RealTimeSek/60;
	
	WakeUpMin=(hour*60+min)-30; 
	
	if(WakeUpMin<0) 
	{
		WakeUpMin =1440 + WakeUpMin; //1440 = 24h og WakeUpMin er minus
	}
	
	if(RealTimeMin == WakeUpMin)
	{
		return 1;
	}
	else
	
	return 0;
}

