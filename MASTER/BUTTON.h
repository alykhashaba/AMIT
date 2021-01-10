/*
 * BUTTON.h
 *
 * Created: 11/13/2020 8:15:41 PM
 *  Author: karim
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "CPU_CONFIGURATION.h"

#define PRESSED 1
#define NOT_PRESSED 0


void BTN_Init(void);
Uint8t BTN_Read(void);

#endif /* BUTTON_H_ */