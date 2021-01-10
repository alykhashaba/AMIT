/*
* TIMER1_CONFIG.h
*
* Created: 12/5/2020 12:16:31 PM
*  Author: karim
*/


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/************************************** TIMER1-Registers *********************************************/
/*
#define TCCR1A (*(volatile Uint8t* )(0x4F))
#define TCCR1B (*(volatile Uint8t* )(0x4E))
#define OCR1A  (*(volatile Uint16t*)(0x4A))
#define ICR1   (*(volatile Uint16t*)(0x46))
*/
void TIMER1_PWM_Init(void);
void TIMER1_PWM_SETDUTY(Uint8t Duty);
void TIMER1_PWM_Start(void);

#endif /* TIMER1_CONFIG_H_ */