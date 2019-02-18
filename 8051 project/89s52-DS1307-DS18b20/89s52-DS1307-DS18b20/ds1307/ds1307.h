#ifndef __DS1307_H__
#define __DS1307_H__

#include "ds1307/ds1307.h"

#define     DS1307_ID 0xD0   
#define     SEC 0x00
#define     MIN 0x01   
#define     HOUR 0x02

unsigned char DS1307_get(unsigned char addr) ;
void DS1307_Write(unsigned char addr,unsigned char dat);

#endif
