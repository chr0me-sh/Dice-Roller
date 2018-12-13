#include "roller.h"

int gen_rolls(int amt, int sides) {
	for (amt; amt > 0; --amt) {
		int res = get_rand();
		lcd_putc(res);
		lcd_putc(' ');
	}
}
