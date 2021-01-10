/*
* Motor.c
*
* Created: 12/12/2020 8:18:27 PM
*  Author: MM
*/
#include "Motor.h"
void MotorA_Init (void)
{
	/*ENABLE*/
	SET_BIT(DDRD,PD4);
	/*INPUT*/
	SET_BIT(DDRC,PC3);
	SET_BIT(DDRC,PC4);
}
void MotorA_DIR (Uint8t dir)
{
	if(dir == 0)
	{
		SET_BIT(PORTC,PC3);
		CLR_BIT(PORTC,PC4);
	}
	else if(dir == 1)
	{
		CLR_BIT(PORTC,PC3);
		SET_BIT(PORTC,PC4);
	}
	//SET_BIT(PORTD, PD4);
}
void MotorB_Init (void)
{
	/*ENABLE*/
	SET_BIT(DDRD,PD5);
	/*INPUT*/
	SET_BIT(DDRC,PC5);
	SET_BIT(DDRC,PC6);
}

void MotorB_DIR (Uint8t dir)
{
	#if dir == 0
	SET_BIT(PORTC,PC5);
	CLR_BIT(PORTC,PC6);
	#elif dir == 1
	CLR_BIT(PORTC,PC5);
	SET_BIT(PORTC,PC6);
	#endif
}
