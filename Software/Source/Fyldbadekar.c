/*
 * Fyldbadekar.c
 *
 * Created: 18-05-2021 10:13:31
 *  Author: sandr
 */ 

#define F_CPU 16000000
#include  <util/delay.h>

void fyldbadekar()
{
	toggleLED(7);
	char Adresse[] = {'0','1','0','1','1','0','0','1'};
	char startFunktion[] = {'0','1','0','1','0','1','1','0'};
	char stopFunktion[] = {'0','1','0','1','1','0','0','1'};
	
	sendX10(Adresse,startFunktion); //tænd 
	
// 	_delay_ms(5000);
// 	
// 	sendX10(Adresse,stopFunktion); //sluk
}