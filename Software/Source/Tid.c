/*
 * Tid.c
 *
 * Created: 20-05-2021 12:32:48
 *  Author: sandr
 */ 

int compareTimeStart(int min, int hour, int RealTimeSek)
{
	int RealTimeMin, WakeUpMin;
	
	RealTimeMin = RealTimeSek/60; //den faktiske tid i min 
	
	WakeUpMin=(hour*60+min)-30; //vækketidspunktet 
	
	if(WakeUpMin<0) 
	{
		WakeUpMin =1440 + WakeUpMin; //1440 = 24h og WakeUpMin er minus
	}
	
	if(RealTimeMin == WakeUpMin)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

