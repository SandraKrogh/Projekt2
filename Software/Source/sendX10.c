/*
 * sendX10.c
 *
 * Created: 18-05-2021 10:09:40
 *  Author: sandr
 */ 
#include "sendX10.h"
#include <string.h>


sendX10(char* adresse, char* data)
{	
	char buffer[17] = strcat(adresse,data);
	
	//manchester kode ind i buffer
	int counter = 0;
	int x10_counter = 0;
	
	x10_counter = g_counter
	
	while  counter < 16 //tjekker om alle tegn er sendt
	{
		PORTA &= 11111110
		
		while x10_counter == g_counter //tjekker om der er kommer zeroCross
		{
			
		}
		assert(x10_counter+1 == g_counter)
		
		x10_counter = g_counter;
		
		char c = buffer[counter];
		
		//sætte ben højt, hvis c = 1
		if(c==1)
		{
			PORTA |= 00000001;
		}
		
		counter++;
	}
}