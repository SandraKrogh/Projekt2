/*
 * init.c
 *
 * Created: 10-05-2021 13:21:49
 *  Author: sandr
 */ 
#include <avr/io.h>

void initInterrupt()
{
	 //enables interrupt 0
	 EIMSK |= 0b00000001;
	 EICRA = 0b00000011; 
}

void initPort()
{
	//Port til indgange, x10 modtager
	DDRA = 0;
	PINA = 00000000;
	
}
