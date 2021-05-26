/*
 * zeroCross.h
 *
 * Created: 18-05-2021 10:59:19
 *  Author: sandr
 */ 


#ifndef ZEROCROSS_H_
#define ZEROCROSS_H_


void zeroCrossInit();

int counter = 0;
char startArray[12] = {'1','1','1','0','0','1','1','0','1','0','1','0','/0'}; //tænd
char stopArray[12] = {'1','1','1','0','1','0','0','1','1','0','1','0','/0'}; //stop
char array[16] = {'1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0'}; //startsekvens


#endif /* ZEROCROSS_H_ */