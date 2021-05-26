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
	TCNT1 = 49912; //har før haft 49912
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000101; //prescale 1024
	
	//Lys timer 3 initiering
	TCNT3 = 0;
	TCCR3A = 0b00000000;
	TCCR3B = 0b00000101; //prescale 1024
}

void initInterrupt()
{
	//Badekar interupt 2 
	EIMSK |= 0b00000100;
	EICRA = 0b00100000;
	
	//Lys interrupt 0 zeroCross
	EICRA = 0b00000011;
	EIMSK |= 0b00000001;
	
	//Lys interrupt 3 wait funktion
	EICRA = 0b00000011;
	EIMSK |= 0b00001000;
	
	//enables timer 3 interrupt wait funktion
	TIMSK3 = 0b00001000;
	
	//enables timer 1 interrupt 
	TIMSK1 = 0b00000001;  //interrupt på overflow 
}

void initPort()
 {
	 //Port til udgang, x10 sender
	 DDRA = 0xFF;
	 PORTA = 00000000; 
	 
	 //zerocross
	 DDRD = 0; //laver til indgang 
 }