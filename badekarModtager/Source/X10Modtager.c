/*
 * X10Modtager.c
 *
 * Created: 18-05-2021 10:56:22
 *  Author: sandr
 */

#include "X10Modtager.h"
#include "zeroCross.h"

char* X10MODTAGER()
{
	char buffer[8];
	
	//manchester kode ind i buffer
	int counter = 0;
	int x10_counter = 0;
	
	x10_counter = g_counter
	
	while  counter < 8 //tjekker om alle tegn er modtaget
	{
		
		while x10_counter == g_counter //tjekker om der er kommet zeroCross
		{
			
		}
		assert(x10_counter+1 == g_counter)
		
		x10_counter = g_counter;
		
		if(PINA &= 00000001)
		{
			buffer[counter]='1';
		} 
		else 
		{
			buffer[counter]='1';
		}		
		counter++;
	}
	
	return buffer
}
