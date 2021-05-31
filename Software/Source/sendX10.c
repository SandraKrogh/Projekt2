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
volatile unsigned int counter = 0;
volatile unsigned int x10_counter = 0;

void sendX10(char* adresse, char* data)
{	
	SendString("\rsend x10  ");
	//send startsekvens 
	char buffer2[] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	
	int for_counter=0;
	
	for( int i =4 ; i < 12; i++)
	{
		buffer2[i]=adresse[for_counter];
		for_counter++;	
	}
	
	for_counter = 0;
	
	for( int i = 12 ; i < 20; i++)
	{
		buffer2[i]=data[for_counter];
		for_counter++;
	}

	//manchester kode ind i buffer
	g_counter = 0;
	char c;
	
	while  (counter < 20) //tjekker om alle tegn er sendt
	{
		PORTA &= 11111110;
		
		while (x10_counter == g_counter) //tjekker om der er kommet zeroCross
		{
		}
		
 		x10_counter = g_counter;
		
		c = buffer2[counter];
		
		//sætte ben højt, hvis c = 1
		if(c=='1')
		{
			turnOnLED(4);
// 			OCR4A = 512;
// 			_delay_us(10000);
// 			OCR4A = 0;
			PORTA |= 0b00000001;
		}
		
		if(c=='0')
		{
					
					// 			OCR4A = 512;
					// 			_delay_us(10000);
					// 			OCR4A = 0;

			PORTA &= 0b11111110;
		}
		
		SendChar(c);

		counter++;
	}
	
	counter = 0;

}

//zero cross
ISR(INT0_vect)
{
	toggleLED(2);
	g_counter++;
}


