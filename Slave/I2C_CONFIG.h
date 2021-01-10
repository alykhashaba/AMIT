/*
 * I2C_CONFIG.h
 *
 * Created: 12/24/2020 12:04:19 PM
 *  Author: karim
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

/*Register for two wire interface*/
/*
#define TWCR (*((volatile uint8*)0x56))
#define TWDR (*((volatile uint8*)0x23))
#define TWAR (*((volatile uint8*)0x22))
#define TWBR (*((volatile uint8*)0x20))
#define TWSR (*((volatile uint8*)0x21))
*/

#include "CPU_CONFIGURATION.h"

#define I2C_MASTER  1

#define I2C_SLAVE   0
 
#define I2C_MODE    I2C_MASTER

#define START_ACK                0x08 // start has been sent
#define REP_START_ACK            0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK              0x28 // Master transmit data ACK
#define RD_BYTE_WITH_NACK        0x58// Master received data with not NACK
#define RD_BYTE_WITH_ACK         0x50// Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 // means that slave address is received with write request
#define SLAVE_ADD_RCVD_WR_REQ    0x60 // means that slave address is received with read request
#define SLAVE_DATA_RECEIVED      0x80 // means that read byte request is received
#define SLAVE_BYTE_TRANSMITTED   0xC0 // means that write byte request is received


#endif /* I2C_CONFIG_H_ */