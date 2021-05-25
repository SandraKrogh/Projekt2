
/************************************************
* "uart.c":                                     *
* Implementation file for Mega2560 UART driver. *
* Using UART 0.                                 *
* Henning Hargaard, 5/4 2019                    *
*************************************************/
#include <avr/io.h>
#include <stdlib.h>

// Target CPU frequency
#define XTAL 16000000

/*************************************************************************
UART 0 initialization:
    Asynchronous mode.
    Baud rate = 9600.
    Data bits = 8.
    RX and TX enabled.
    No interrupts enabled.
    Number of Stop Bits = 1.
    No Parity.
*************************************************************************/
void InitUART(unsigned long Baudrate, unsigned char Databit)
{
 if ((Baudrate>=300) && (Baudrate < 115200) && (Databit >5) && (Databit <8))
 {
	  UCSR0A = 0b00100000;
	  UCSR0B = 0b00011000;
	  UCSR0C = (Databit-5)<<1;
	  UBRR0 = (XTAL+(8*Baudrate))/(16*Baudrate)-1;
 }
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
   return UCSR0A & (1<<7);
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
  while((UCSR0A & 0b10000000)==0)
  {}
   return UDR0; //returner når det er rigtig 
}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
   while((UCSR0A & 0b00100000)==0)
   {}
	 UDR0=Tegn;
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
   while( *Streng !=0)
   {
	   SendChar(*Streng);
	   Streng++;
   }
}

/*************************************************************************
Converts the integer "Tal" to an ASCII string - and then sends this string
using the USART.
Makes use of the C standard library <stdlib.h>.
Parameter:
    Tal: The integer to be converted and sent. 
*************************************************************************/
void SendInteger(int Tal)
{
  char myarray[10];
   
   itoa(Tal, myarray,10);
   
   SendString(myarray);
}

/************************************************************************/

