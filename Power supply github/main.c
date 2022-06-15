#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "lcdlib.h"
#include "battery.h"

int main()
{
	double batt;
	char buffer[10];

	// initialize adc and lcd
	battery_init();
	LCD_init(); //CURSOR
	
	_delay_ms(50);
	
	while(1)
	{
		batt= battery_percentage();   // finding the battery value
		
		if(batt>0)
		{
		dtostrf(batt, 2, 2, buffer);		LCD_write_string("Battery=", 1, 1);   //display battery percentage		LCD_write_string(buffer, 9, 1);
		}
		else
		LCD_write_string("Battery Dead", 1, 1); 
		
		_delay_ms(200);
	}
	
	return 0;
}