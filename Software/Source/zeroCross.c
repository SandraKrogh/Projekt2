/*
 * zeroCross.c
 *
 * Created: 10-05-2021 12:59:23
 *  Author: sandr
 */ 
#include "zeroCross.h"

int g_counter = 0;

void zeroCrossInit()
{
	DDRD = 0; //laver til indgang 
	
	//interrupt initering
	EICRA = 0b00000011; 
	EIMSK |= 0b00000001;
	
	if(PIND &= 0b00000001)
	{
		g_counter++;
	}
}

ISR
{
	
}