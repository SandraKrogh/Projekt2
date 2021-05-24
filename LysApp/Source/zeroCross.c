/*
 * zeroCross.c
 *
 * Created: 21-05-2021 08:55:19
 *  Author: sandr
 */ 

#include "zeroCross.h"
#include <string.h>

int counter = 0;
char buffer[12];
char startArray[12] = {'1','1','1','0','0','1','1','0','1','0','1','0','/0'}; //t�nd
char stopArray[12] = {'1','1','1','0','1','0','0','1','1','0','1','0','/0'}; //stop
char increaseArray[12] = {'1','1','1','0','0','1','0','1','1','0','1','0','/0'}; //increase
char array[16] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0'}; //startsekvens

ISR(INT0_vect)
{
	char buffer[12];
	
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
}