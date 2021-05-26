/*
 * IncFile1.h
 *
 * Created: 18-11-2020 10:24:43
 *  Author: Silje
 */ 


void InitUART(unsigned long BaudRate, unsigned char DataBit);
unsigned char CharReady();
char ReadChar();
void SendChar(char Tegn);
void SendString(char* Streng);
void SendInteger(int Tal);
/****************************************/