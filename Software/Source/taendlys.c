/*
 * taendlys.c
 *
 * Created: 04-05-2021 14:40:16
 *  Author: sandr
 */ 
#include "computerApp.h"
#include "taendlys.h"
#include "zeroCross.h"
#include <assert.h>

#define F_CPU 16000000;
#include  <util/delay.h>


void taendlys()
{
	char startArray[] = {'0','1','0','1','0','1','1','0','/0'}; //tænd
	char stopArray[] = {'0','1','0','1','1','0','0','1','/0'}; //stop
	char adresseArray[] = {'0','1','0','1','0','1','1','0','/0'}; //stop
	
	int min = getmin();
	int hour = gethour();
	
	int RealTimeSek = getGlobalSek();
	
	bool status,status2; 
	status=compareTimeStart(min,hour,RealTimeSek);
	
	if(status == true)
	{
		sendX10(adresseArray, startArray);
	}
	
	
	status2 = compareTimeStop(min,hour,RealTimeSek);
	
	if(status2 == true)
	{
		sendX10(adresseArray, stopArray);
	}
	
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

bool compareTimeStop(int min, int hour, int RealTimeSek)
{
	int RealTimeMin, stopWakeUpMin = 30;
	
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



