/*
 * uasrt.h
 *
 * Created: 25-11-2020 08:44:16
 *  Author: sandr
 */ 


#ifndef UASRT_H_
#define UASRT_H_

/****************************************
* "uart.h":                             *
* Header file for Mega2560 UART driver. *
* Using UART 0.                         *
* Henning Hargaard, 5/4 2019            *
*****************************************/
void InitUART();
unsigned char CharReady();
char ReadChar();
void SendChar(char Tegn);
void SendString(char* Streng);
void SendInteger(int Tal);
/****************************************/

#endif /* UASRT_H_ */