/*
 * init.c
 *
 * Created: 27-05-2021 11:48:39
 *  Author: sandr
 */ 
#include <avr/io.h>

void initInterrupt()
{
	//enables interrupt 0
	EIMSK |= 0b00000001;
	EICRA = 0b00000011;
	
	//timer 1 
	TCCR1A = 0b10000011;
	TCCR1B = 0b00000001;
}

void initPort()
{
	//Port til indgange, x10 modtager
	DDRA = 0;
	PINA = 00000000;
	

}