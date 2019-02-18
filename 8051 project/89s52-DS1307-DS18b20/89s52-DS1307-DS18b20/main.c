#include <regx52.h>

#include <stdio.h>
#include <string.h>


//------------------CAU HINH I/O------------------
// PORT0 -----------------------------------------
// Cac chan du lieu cua LCD ----------------------
sbit LCD_RS=P2^2;

sbit LCD_E=P2^3;
sbit LCD_RW=P2^1;

sbit LCD_D4=P2^4;
sbit LCD_D5=P2^5;
sbit LCD_D6=P2^6;
sbit LCD_D7=P2^7;
sbit DQ=P3^3;
sbit LCD_Data=P2;

sbit SCL	=P2^1;
sbit SDA	=P2^0;

#include <DELAY\delay.c>
#include <LCD1602\lcd1602.c>
#include <DS1820\ds18b20.c>
#include <i2c\i2c.c>
#include <ds1307\ds1307.c>







float Nhiet_Do;				// DS18b20
unsigned char Lcd_Buff[30];	// LCD1602
unsigned char i;
char time, get_t;
char sec,min,hour;
void main()
{
	i2c_init();
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("8051 EASY");
	lcd1602_gotoxy(0,1);
	lcd1602_puts("TEST KI89S52V2");
	delay_ms(1000);
	//DS1307_Write(HOUR,11);
	//DS1307_Write(MIN,45); 

	while(1)
	{
	Nhiet_Do = ds18b20_readtemp();
	sec = DS1307_get(SEC);
	min = DS1307_get(MIN);	
	hour= DS1307_get(HOUR);		
	sprintf(Lcd_Buff," TEMP: %2.2f^C",Nhiet_Do);
	lcd1602_gotoxy(0,0);
	lcd1602_puts(Lcd_Buff);
	lcd1602_gotoxy(13,0);
	lcd1602_putchar(223);
	delay_ms(500);
	sprintf(Lcd_Buff,"TIME: %bu:%bu:%bu ",hour,min,sec);
	lcd1602_gotoxy(0,1);
	lcd1602_puts(Lcd_Buff);				
	delay_ms(500);
	
	
					

	}
}