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
}

ISR(INT0_vect)
{
	g_counter++;
}