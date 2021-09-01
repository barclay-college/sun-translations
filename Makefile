CC=gcc
CFLAGS=-Wall


all: sun_translator

sun_translator: sun_translator.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm sun_translator
