#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"



/*     The sacred register values    */
/*    Probably need notes on these   */

void adc_init(void) {
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX  |= (1 << REFS0);
	ADMUX  |= (1 << ADLAR);
	ADMUX  |= (1 << MUX2);
	ADCSRA |= (1 << ADATE);
	ADCSRA |= (1 << ADIE);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC);
}

int get_ldr(void) {
	int low = ADCL;
	int high = ADCH;

	return ((high << 2) | (low >> 6)); // Don't need all 10 bits here?
}

/* Builds a 16-bit int from polling the ADC's LSB */

int build_seed(void) {
	uint16_t seed = 0;
	int n;
	for (int i = 0; i < 16; i++) {
		n = (0x01 & get_ldr());
		seed = (seed << 1) | n;
		_delay_ms(50);
	}
	return seed;
}

int get_rand(int max) {
	int seed = build_seed();
	srand(seed);
	int n = rand();
		
	return (n % max) + 1; // Better way to this? Modulo is very big
}

int main(void) {
	adc_init();
	lcd_io_init();
	lcd_init();

	char result[5];
	int line = 0;
		
	while(1) {
		/* Temporary output for debugging */
		for(int i = 0; i < 16; i++) {
			itoa(get_rand(6), result, 10);
			lcd_puts(result);
			_delay_ms(50);
		}
		if(!line) lcd_cmd(LCD_LINE_2);                /* This is really bad      */
		else{ lcd_cmd(0x01); lcd_cmd(LCD_LINE_1); }   /* Please change this soon */
		line = !line;
	}

	return 1;
}
