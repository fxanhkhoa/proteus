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
		//ledxanh=l;
		//leddo=0;
		PORTB=0b00000011;
		_delay_ms(500);
		//leddo=1;
		//ledxanh=0;
		PORTB=0b00000000;
		_delay_ms(500);
	}
	return(0);
}

