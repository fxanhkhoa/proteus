#ifndef __I2C_H
#define __I2C_H
#include "i2c/i2c.h"
 
#define I2C_DELAY      2


void I2C_Delay(unsigned int time);
void i2c_init();
void I2C_Start();
void I2C_Stop();
unsigned char i2c_checkack(void);
void i2c_write(unsigned char Data);
unsigned char i2c_read(void);
#endif
