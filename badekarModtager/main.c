/*
 * badekarModtager.c
 *
 * Created: 10-05-2021 13:17:10
 * Author : sandr
 */ 

#include <avr/io.h>
#include "X10Modtager.h"


int main(void)
{
 sei()
 initInterrupt();
 initPort();
 
 char modtagetdata[9];
 char startArray[] = {'0','1','1','0','1','0','1','0','/0'}; //tænd
 char stopArray[] = {'1','0','0','1','1','0','1','0','/0'}; //stop
 
    /* Replace with your application code */
    while (1) 
    {
		 modtagetdata = X10MODTAGER();
    }
}


