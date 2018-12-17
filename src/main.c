#include "roller.h"

int main(void) {
	adc_init();
	lcd_io_init();
	lcd_init();

	gen_rolls(8, 6);

	while (1) {

	}

	return 0;
}
