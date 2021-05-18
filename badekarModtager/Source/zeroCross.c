/*
 * zeroCross.c
 *
 * Created: 18-05-2021 10:59:28
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