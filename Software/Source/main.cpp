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

int getGlobalSek();
int sek_= 0;

int main(void)
{
	sei(); //global interrupt 
	
	initInterrupt();
	initTimer();

    /* Replace with your application code */
    while (1) 
    {
		//test af sekund tæller
		if(sek_ %2 == 0)
		turnOnLED(3);
		else
		turnOffLED(3);
		
		taendlys();
		
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
