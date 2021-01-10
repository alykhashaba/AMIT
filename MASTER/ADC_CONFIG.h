/*
 * ADC_CONFIG.h
 *
 * Created: 12/20/2020 9:56:00 AM
 *  Author: karim
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "CPU_CONFIGURATION.h"

/************************************** ADC-Registers *******************************************/
/*
#define ADMUX   (*(volatile Uint8t*) (0x27))
#define ADCSRA  (*(volatile Uint8t*) (0x26))
#define ADCH    (*(volatile Uint8t*) (0x25))
#define ADCL    (*(volatile Uint8t*) (0x24))
*/
#define ADC_DTA (*(volatile Uint16t*)(0x24))



#endif /* ADC_CONFIG_H_ */