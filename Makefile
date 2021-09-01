CC=gcc
CFLAGS=-Wall


all: sun_translator

sun_translator: sun_translator.c
	$(CC) $(CFLAGS) -o sun_translator sun_translator.c

clean:
	rm sun_translator
