/*
 * Badekar_Test.cpp
 *
 * Created: 03-05-2021 12:30:31
 *  Author: sandr
 */ 
#define F_CPU 16000000
#include <util/delay.h>



ISR(INT0_vect)
{
	badekar1.start();
	_delay_ms(3000);
	badekar1.stop();
}

tændlys()
{
	
	gethour();
	int sek = getGlobalSek();
	
}