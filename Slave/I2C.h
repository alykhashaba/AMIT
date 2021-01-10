/*
* I2C.h
*
* Created: 12/24/2020 12:04:30 PM
*  Author: karim
*/


#ifndef I2C_H_
#define I2C_H_

#include "I2C_CONFIG.h"

/**/
void I2C_MASTER_Init(void);
void I2C_SLAVE_Init(void);
/*Frame START*/
void I2C_START_COND(void);
void I2C_REPEATED_START_COND(void);
/**/
void I2C_SLAVE_WRITE(Uint8t Address);/*Address (7BITS) and Operation(LSB)*/
void I2C_SLAVE_READ(Uint8t Address);/*Address (7BITS) and Operation(LSB)*/
/**/
void I2C_TRANSMIT_DATA(Uint8t Data);
void I2C_RECEIVE_DATA(Uint8t* Data);
/**/
void I2C_STOP_COND(void);
/*Frame END*/
#endif /* I2C_H_ */