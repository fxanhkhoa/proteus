#include "ds1307.h"

unsigned char DS1307_get(unsigned char addr) 
{
   unsigned int temp,ret; 
   bit AckTemp=1;
   I2C_Start(); /* Start i2c bus */
   i2c_write(DS1307_ID); /* Connect to DS1307 */
   AckTemp=i2c_checkack();
   i2c_write(addr);    /* Request RAM address on DS1307 */  
   AckTemp=i2c_checkack();
   I2C_Start();    /* Start i2c bus */
   i2c_write(DS1307_ID+1);   /* Connect to DS1307 for Read */
   AckTemp=i2c_checkack();
   ret = i2c_read();    /* Receive data */
   AckTemp=i2c_checkack();
   I2C_Stop();
//*********************************************
   temp = ret;    /*BCD to HEX*/
   ret = (((ret/16)*10)+ (temp & 0x0f));    /*for Led 7seg*/
//*********************************************   
   return ret;   
}


void DS1307_Write(unsigned char addr,unsigned char dat)
{
   unsigned int temp;
   bit AckTemp=1;
//**********************************************    /*HEX to BCD*/
   temp = dat ;    /*for Led 7seg*/
   dat = (((dat/10)*16)|(temp %10));
//**********************************************   
   I2C_Start(); /* Start i2c bus */
   i2c_write(DS1307_ID); /* Connect to DS1307 */
   AckTemp=i2c_checkack();
   i2c_write(addr);    /* Request RAM address on DS1307 */ 
   AckTemp=i2c_checkack();
   i2c_write(dat);   /* Connect to DS1307 for Read */
   AckTemp=i2c_checkack();
   I2C_Stop();
}
/************************************************** *********************/


