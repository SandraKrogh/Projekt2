/* 
* LysApp.cpp
*
* Created: 29-04-2021 14:13:12
* Author: sandr
*/


#include "LysApp.h"


void start()
{
	DDRB = 0xFF;
	PORTB = 0;
	TCCR5A = 0b10000011;
	TCCR5B = 0b00000001;
	OCR5A = 102; //10% duty cycle 
}

void increase()
{
	
}


void stop(){
	
	
}