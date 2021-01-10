/*
 * INP_OUT.h
 *
 * Created: 11/12/2020 8:40:04 PM
 *  Author: karim
 */ 


#ifndef INP_OUT_H_
#define INP_OUT_H_

#include "CPU_CONFIGURATION.h"

void Buzzer_Init(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_TGL(void);

void Relay_Init(void);
void Relay_ON(void);
void Relay_OFF(void);
void Relay_TGL(void);





#endif /* INP_OUT_H_ */