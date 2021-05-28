/*
 * LysApp.c
 *
 * Created: 10-05-2021 13:24:18
 * Author : sandr
 */ 

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
char buffer[] = {"11100101011001101010"};
char startArray[] = {"01101010"};
char stopArray[] = {"10011010"}; //stop
char increaseArray[] = {"01011010"}; //increase
char adresse[] = {"01010110"};//adresse
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
	int increasecompare;
	
	startcompare = compare(buffer,startArray,12, 8);
	stopcompare = compare(buffer,stopArray, 12, 8);
	increasecompare = compare(buffer,increaseArray, 12, 8);
	
	if(startcompare == 1) 
	 {
		turnOnLED(7);
		OCR1A = 200; //duty cycle på 50%
	 }
	 
	 if(increasecompare == 1)
	  {
		 OCR1A += 100;
	  }
	 
	 if(stopcompare == 1)
	 {
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

