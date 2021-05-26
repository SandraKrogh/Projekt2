/*
 * sendX10.c
 *
 * Created: 18-05-2021 10:09:40
 *  Author: sandr
 */ 
#include <string.h>
#include <stdio.h>
#include <avr/io.h>
#include <assert.h>
#include <avr/interrupt.h>

//til test delay
#define F_CPU 16000000
#include  <util/delay.h>

volatile unsigned int g_counter = 0;

sendX10(char* adresse, char* data)
{	
	//send startsekvens 
	char buffer2[16] = {0};
	
	strcpy(buffer2,adresse); 
	
	strcat(buffer2,data);
	
	//manchester kode ind i buffer
	int counter = 0;
	int x10_counter = 0;
	g_counter = 0;
	
	while  (counter < 16) //tjekker om alle tegn er sendt
	{
		PORTA &= 11111110;
		
		while (x10_counter == g_counter) //tjekker om der er kommet zeroCross
		{
		}
		//assert(x10_counter+1 == g_counter);
		
 		x10_counter = g_counter;
		
		char c;
		
		c = buffer2[counter];
		
		//s�tte ben h�jt, hvis c = 1
		if(c==1)
		{
			PORTA |= 00000001;
		}

		//s�tte ben h�jt, hvis c = 0
		if(c==0)
		{
			PORTA &= 11111110;
		}
		
		SendChar(c);

		counter++;
	}
}

//zero cross
ISR(INT0_vect)
{
	toggleLED(2);
	g_counter++;
}

