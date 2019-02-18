#include "avr/io.h"
#define F_CPU 1000000UL // 1 MHz
//#define F_CPU 14.7456E6
#include <util/delay.h>

#define ledxanh PORTB.0
#define leddo PORTB.1



int main(void)
{
	PORTB=0b00000011;
	DDRB=0XFF;
	while (1)
	{
		ledxanh=1;
		leddo=0;
		PORTB=PORTB | ledxanh;
		PORTB=PORTB | leddo;
		_delay_ms(100);
		leddo=1;
		ledxanh=0;
		PORTB=PORTB | ledxanh;
		PORTB=PORTB | leddo;
		_delay_ms(100);
	}
	return(0);
}

