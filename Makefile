CC=gcc
CFLAGS=-g -Wall
BIN=sun_translator


all:$(BIN)

sun_translator: src/sun_translator.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm sun_translator
