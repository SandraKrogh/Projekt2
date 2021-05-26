/*
 * zeroCross.c
 *
 * Created: 18-05-2021 10:59:28
 *  Author: sandr
 */ 
#include <avr/io.h>
#include <string.h>

int counter = 0;
char startArray[12] = {'1','1','1','0','0','1','1','0','1','0','1','0','/0'}; //tænd
char stopArray[12] = {'1','1','1','0','1','0','0','1','1','0','1','0','/0'}; //stop
char array[16] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0'}; //startsekvens
char buffer[12]; 

ISR(INT0_vect)
{
	
	if(PINA == 00000001) //hvis 1
	{
		buffer[counter] = 1;
	}
	
	if(PINA == 00000000) // hvis 0
	{
		buffer[counter] = 0;
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

	if(strcmp(buffer,startArray))
	{
		turnOnLED(2);
	}
	
	if(strcmp(buffer,stopArray))
	{
		turnOffLED(2);
	}
}