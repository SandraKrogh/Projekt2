/*
 * taendlys.c
 *
 * Created: 04-05-2021 14:40:16
 *  Author: sandr
 */ 
#include <assert.h>

#define F_CPU 16000000
#include  <util/delay.h>

void taendlys()
{
	toggleLED(5);
	
	char startArray[] = {'0','1','0','1','0','1','1','0'}; //tænd
	char adresseArray[] = {'0','1','0','1','0','1','1','0'}; 
	
	sendX10(adresseArray, startArray);
}

void sluklys()
{
	char stopArray[] = {'0','1','0','1','1','0','0','1'}; //stop
	char adresseArray[] = {'0','1','0','1','0','1','1','0'};
		
	sendX10(adresseArray, stopArray);
}

void increaselys()
{
	char increaseArray[] = {'0','1','0','1','1','0','1','0'}; //increase
	char adresseArray[] = {'0','1','0','1','0','1','1','0',};
	
	sendX10(adresseArray, increaseArray);
}



