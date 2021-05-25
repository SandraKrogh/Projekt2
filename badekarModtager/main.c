/*
 * badekarModtager.c
 *
 * Created: 10-05-2021 13:17:10
 * Author : sandr
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "Header/init.h"


int main(void)
{
 
 initInterrupt();
 initPort();
 
 sei();
 
//  char modtagetdata[9];
//  char startArray[] = {'0','1','1','0','1','0','1','0','/0'}; //tænd
//  char stopArray[] = {'1','0','0','1','1','0','1','0','/0'}; //stop
	 
}


