#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

/* rng.c */
void adc_init(void);
int get_adc(void);
int build_seed(void);
int get_rand(int);
void gen_rolls(int, int);

