#include "roller.h"

/*
void gen_rolls(int amt, int sides) {
	for (; amt > 0; --amt) {
		int result = get_rand(sides);
		char resultc[1]; 
		itoa(result, resultc, 10);
		lcd_puts(resultc);
		lcd_putc(' ');
	}
}
*/

void gen_rolls(int amt, int sides) {
	char result[2];
	for (; amt > 0; --amt) {
		itoa(get_rand(sides), result, 10);
		lcd_puts(result);
		lcd_putc(' ');
	}
}
