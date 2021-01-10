/*
* ADC.c
*
* Created: 11/21/2020 10:24:58 PM
*  Author: karim
*/

#include "ADC.h"

void ADC_Init(void)
{
	/*Define Vref for ADC, as AVCC*/
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
	/*Right Adjust*/
	CLR_BIT(ADMUX, ADLAR);
	/*Choose channel*/
	SET_BIT(ADMUX, MUX0);
	CLR_BIT(ADMUX, MUX1);
	CLR_BIT(ADMUX, MUX2);
	CLR_BIT(ADMUX, MUX3);
	CLR_BIT(ADMUX, MUX4);
	/*Auto Trigger Mode*/
	SET_BIT(ADCSRA, ADATE);
	/*Define Prescalar*/
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
	/*Enable ADC*/
	SET_BIT(ADCSRA, ADEN);
}
Uint16t ADC_Read(void)
{
	Uint16t var = 0;
	/*Start Conversion*/
	SET_BIT(ADCSRA, ADSC);
	/*Wait and check till flag is one, Polling*/
	while(GET_BIT(ADCSRA, ADIF) != 1);
	/*Return value*/
	var = ADC_DTA;
	return var;
}