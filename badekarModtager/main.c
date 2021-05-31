#include <avr/io.h>
#include <stdio.h>
#include <String.h>
#include <avr/interrupt.h>
#include "Header/LED.h"
#include "Header/init.h"
#define F_CPU 16000000
#include  <util/delay.h>

volatile unsigned int counter = 0;
volatile int intensityCounter = 0;
volatile int increase = 100;


char buffer[20] = {0};
//char buffer[] = {"11100101100101101010"};
char startArray[] = {"01101010"};
char stopArray[] = {"10011010"}; //stop
char adresse[] = {"01011001"};//adresse
char array[] = {"1110"}; //startsekvens

//funktion
int compare(char*, char*,int, int);

int main(void)
{
	initLEDport();
	initInterrupt();
	initPort();
	
	sei();
	
	while(1)
	{
		
		int startcompare;
		int stopcompare;
		
		startcompare = compare(buffer,startArray,12, 8);
		stopcompare = compare(buffer,stopArray, 12, 8);
		
		if(startcompare == 1)
		{
			turnOnLED(7);
			OCR1A = 200; //duty cycle på 50%
		}
		
		if(stopcompare == 1)
		{
			turnOffLED(7);
			OCR1A = 0; //duty cycle på 50%
		}
		
	}
	
}

int compare(char* buffer, char* konstant, int startc, int slutc)
{
	for(int i = 0; i < slutc;i++)
	{
		if(buffer[i+startc]==konstant[i])
		{
			
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
}


ISR(INT0_vect)
{
	toggleLED(4);
	
	if(PINA == 00000001) //hvis 1
	{
		buffer[counter] = '1';
		toggleLED(6);
	}
	
	if(PINA == 00000000) // hvis 0
	{
		buffer[counter] = '0';
	}
	
	counter++;
	
	if( compare(buffer, array,0,4)!= 1 && counter == 4)
	{
		for(int i = 0; i < 4; i++)
		{
			buffer[i] = buffer[i+1];
		}
		counter--;
	}
	
	if( counter == 11)
	{
		if(compare(buffer,adresse,4,8)==0)
		
		counter = 0;
	}
	
	if (counter > 19)
	{
		counter = 0;
	}
}


