/*
 * LysApp.c
 *
 * Created: 10-05-2021 13:24:18
 * Author : sandr
 */ 

#include <avr/io.h>
#include "LysApp.h"

#define F_CPU 16000000;
#include  <util/delay.h>


int main(void)
{
	int intensityCounter = 0;
	int increase = 100;
	
	initLEDport();
	
	while(1)
	{
	 
	if(strcmp(buffer == startArray))
	 {
		intensityCounter = 1; 
	 }
	 
	 if(intensityCounter == 1)
	 {
		 toggleLED(2);
		 _delay_ms(increase);
	 }
	 
	 if(strcmp(buffer == stopArray))
	 {
		 turnOffLED(2);
		 intensityCounter = 0;
	 }
	 
	 if(strcmp(buffer == increaseArray))
	 {
		 increase -= 10;
	 }
	}
   	
   	return 0;
}

