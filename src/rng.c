#include "roller.h"

/*     The sacred register values    */
/*    Probably need notes on these   */

void adc_init(void) {
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX  |= (1 << REFS0);
	ADMUX  |= (1 << MUX2);
	ADCSRA |= (1 << ADATE);
	ADCSRA |= (1 << ADIE);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC);
}

int get_adc(void) {
	int low = ADCL;
	int high = ADCH;

	return (0x01 & low);
}

/* Builds a 16-bit int from polling the ADC's LSB */

int build_seed(void) {
	int n;
	uint16_t seed = get_adc(); // Sets the seed to ADC's LSB, then adds 15 more bits. Change this?
	for (int i = 0; i < 15; i++) {
		n = (0x01 & get_adc());
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


