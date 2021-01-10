/*
* I2C.c
*
* Created: 12/24/2020 12:04:41 PM
*  Author: karim
*/

#include "I2C.h"
/**/
void I2C_MASTER_Init(void)
{
	TWBR = 0x0C;
	SET_BIT(TWCR, TWEN);
}
void I2C_SLAVE_Init(void)
{
	/*Assign Address*/
	TWAR =  (0x01 << 1);/*Disable General Call*/
	//TWAR =  ((0x01 << 1) | 0x01);/*Enable General Call*/
	SET_BIT(TWCR, TWEA);/*Slave enable ACK*/
	SET_BIT(TWCR, TWEN);
}
/*Frame START*/
void I2C_START_COND(void)
{
	SET_BIT(TWCR, TWSTA);
	SET_BIT(TWCR, TWINT);
	while (GET_BIT(TWCR, TWINT) == 0)
	while ((TWSR & 0xF8) != START_ACK);
}
void I2C_REPEATED_START_COND(void)
{
	/*Generate Repeated Start Condition*/
	/*
	SET_BIT(TWCR , 5);
	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);
	*/
	TWCR = (1<<7) | (1<< 5) | (1<<2);

	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) != REP_START_ACK);
}
/**/
void I2C_SLAVE_WRITE(Uint8t Address)/*Address (7BITS) and Operation(LSB)*/
{
	TWDR = (Address << 1);
	
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/
	TWCR = (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0XF8) != SLAVE_ADD_AND_WR_ACK);
}
void I2C_SLAVE_READ(Uint8t Address)/*Address (7BITS) and Operation(LSB)*/
{
	TWDR = (Address << 1) | (0x01);
	
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/
	TWCR = (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0XF8) != SLAVE_ADD_AND_RD_ACK);
}
/*Sending and receiving data*/
void I2C_TRANSMIT_DATA(Uint8t Data)
{
	TWDR  = Data;
	/*SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);*/
	TWCR = (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7) == 0);	
	while((TWSR & 0XF8) != WR_BYTE_ACK);
}
void I2C_RECEIVE_DATA(Uint8t* Data)
{
    /*
	SET_BIT(TWCR , 7);
	SET_BIT(TWCR , 2);
	*/
	TWCR = (1<<7) | (1<<2);
	while(GET_BIT(TWCR,7) == 0);	
	while((TWSR & 0XF8) != RD_BYTE_WITH_ACK);	
	*Data = TWDR;
}
/*Stop Bit*/
void I2C_STOP_COND(void)
{
	SET_BIT(TWCR, TWSTO);
}