/*
 * LysApp.c
 *
 * Created: 10-05-2021 13:24:18
 * Author : sandr
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include "Header/LED.h"
#include "Header/zeroCross.h"
#define F_CPU 16000000
#include  <util/delay.h>

int counter = 0;
char buffer[13];
char startArray[] = {'1','1','1','0','0','1','1','0','1','0','1','0', '/0'}; //tænd
char stopArray[12] = {'1','1','1','0','1','0','0','1','1','0','1','0','/0'}; //stop
char increaseArray[12] = {'1','1','1','0','0','1','0','1','1','0','1','0','/0'}; //increase
char array[16] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0'}; //startsekvens

int main(void)
{
	int intensityCounter = 0;
	int increase = 100;
	
	initLEDport();
	
	while(1)
	{

	if(strcmp(buffer,startArray)==0) 
	 {
		intensityCounter = 1; 
	 }
	 
	 if(intensityCounter == 1)
	 {
		 toggleLED(2);
		 wait(increase);
	 }
	 
	 if(strcmp(buffer,stopArray)==0)
	 {
		 turnOffLED(2);
		 intensityCounter = 0;
	 }
	 
	 if(strcmp(buffer,increaseArray)==0)
	 {
		 increase -= 10;
	 }
	}
   	
   	return 0;
}

void wait(int increase)
{
	for(unsigned int i=0; i < increase; i++)
	{
		_delay_ms(1); 
		
	}
}

ISR(INT0_vect)
{
	if(PINA == 00000001) //hvis 1
	{
		buffer[counter] = '1';
	}
	
	if(PINA == 00000000) // hvis 0
	{
		buffer[counter] = '0';
	}
	
	counter++;
	
	if( strcmp(array,buffer)!= 0 && counter == 4)
	{
		for(int i = 0; i < 4; i++)
		{
			buffer[i] = buffer[i+1];
		}
		counter--;
	}
}

