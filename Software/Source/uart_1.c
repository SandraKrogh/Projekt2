/*
 * Uart.c
 *
 * Created: 18-11-2020 10:23:12
 *  Author: Silje
 */ 

#include <avr/io.h>
#include <stdlib.h>

// Target CPU frequency
#define XTAL 16000000

//Obs her tælles fra bit 0-7 (dvs bit 2 er det 3. bit)

/*************************************************************************
UART 0 initialization:
    Asynchronous mode.
    Baud rate = 9600.
    Data bits = 8.
    RX and TX enabled.
    No interrupts enabled.
    Number of Stop Bits = 1.
    No Parity.
    Data bits = 8.
*************************************************************************/
void InitUART(unsigned long BaudRate, unsigned char DataBit)
{
	
	if(BaudRate>=300 && BaudRate<=115200 && DataBit>=5 && DataBit<=8)
	{
		UCSR0A = 0b00100000; //default clock
	
   //Asynkron mode: Bit 6 & 7 =0
   //Ingen paritet: bit 4 & 5 =0
   //1 stop bit: bit bit 3 =0
   
   //if-loop, der bestemmer antal databits (5-8 - plads 1 og 0):
   if(DataBit == 5)
   {
	   UCSR0C = 0b00000000;
   }
   
   if(DataBit == 6)
   {
	   UCSR0C = 0b00000010;
   }
   
   if(DataBit == 7)
   {
	   UCSR0C = 0b00000100;
   }
   
   if(DataBit == 8)
   {
	   UCSR0C = 0b00000110;
   }
  
   
   //Ingen interrupts: bit 5, 6 & 7 =0
   //RX enable - tænder for modtager: bit 4 =1
   //TX enable - tænder for sender: bit 3 =1
   //Uanset hvilket antal databits der vælges er bit 2 =0
   UCSR0B = 0b00011000;
   
   //Opsætning af Baud Rate (benytter formlen):
   UBRR0 = (16000000/(16*BaudRate))-1;
	}
   
}

/*************************************************************************
  Returns 0 (FALSE), if the UART has NOT received a new character.
  Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/
unsigned char CharReady()
{
   //Tjekker om der er kommet ny data
   //Bit 7 i register UCSRnA er 1 når der er ny data
   return UCSR0A & (1<<7);
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/
char ReadChar()
{
	
	//Afvent ny data:
   while((UCSR0A & (1<<7)) == 0)
   {
	   
   }
   //Ny data er kommet, så returner dataen
   return UDR0;
   
}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
	Tegn : Character for sending. 
*************************************************************************/
void SendChar(char Tegn)
{
   //Afvent fri bane
   //Når bit 5 i UCSR0A er 1 er der fri bane
   while((UCSR0A & 0b00100000) == 0)
   {
	   
   }
   //Skriver tegnet i vores sende-register:
   UDR0 = Tegn;
   
}

/*************************************************************************
Sends 0 terminated string.
Parameter:
   Streng: Pointer to the string. 
*************************************************************************/
void SendString(char* Streng)
{
   
   int i = 0;
   //Når strengen ikke er 0
   while(Streng[i] != 0)
   {
	   //Udskriv det som pointeren peger på
	   SendChar(Streng[i]);
	   i++;
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
   // <---- Skriv din kode her
   
   char myArray[10] = {0};
	   
	   
	itoa(Tal,myArray,10);
	
	SendString(myArray);
	
	
	   
}

/************************************************************************/