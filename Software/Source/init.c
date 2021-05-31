/*
 * init.c
 *
 * Created: 10-05-2021 13:07:57
 *  Author: sandr
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

void initTimer()
{
	//Lys Timer1 initiering
		//normal mode 
		TCCR1A = 0b00000000;
		TCCR1B = 0b00000100; //prescale 1024
		TCNT1 = 3037; //49912
		
	//Lys timer 3 initiering
		TCNT3 = 0;
		TCCR3A = 0b00000000;
		TCCR3B = 0b00000101; //prescale 1024
		
	//Lys CTS timer 
	//timer 1
	TCCR4A = 0b10000011;
	TCCR4B = 0b00000001;//ingen prescale 
}

void initInterrupt()
{
	//Lys interrupt(int2) + zeroCross(int0) + badekar(int3)
	EICRA = 0b10100011;
	EIMSK |= 0b00001101; //INT0 + INT2 enable + INT3
	
	//enables timer 1 interrupt 
	TIMSK1 |= 0b00000001;  //interrupt på overflow 
}

void initPort()
 {
	 //Port til udgang, pwm
	 DDRH = 0xFF;
	 PORTH = 00000000; 
	 
	 	 //Port til udgang, pwm
	  DDRA = 0xFF;
	 PORTA = 00000000;
	 
	 //zerocross
	 DDRD = 0; //laver til indgang 
 }