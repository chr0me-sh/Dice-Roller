VPATH = src
TGT = roller

MMC = atmega328p
F_CPU = 16000000L
PRG = usbasp
DEV = usb

INC = -Iinclude/
LD = -Llib/ -llcd

CC = avr-gcc
CFLAGS = $(INC) $(LD) -mmcu=$(MMC) -Wall -Os
CPPFLAGS = -D F_CPU=$(F_CPU)

OC = avr-objcopy
OFLAGS = -j .data -j .text -O ihex

FL = avrdude
FFLAGS = -c $(PRG) -p $(MMC) -P $(DEV) -e

.PHONY: clean flash compile all
.INTERMEDIATE: $(TGT).hex

all: flash

compile: $(TGT).hex

flash: $(TGT).hex
	sudo $(FL) $(FFLAGS) -U flash:w:$<:i
	
%.hex: %.elf
	$(OC) $(OFLAGS) $< $@

%.elf: %.c
	$(CC) $< $(CFLAGS) $(CPPFLAGS) -o $@
