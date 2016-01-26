CC=gcc
CFLAGS=-g -std=c89 -ansi -Wall -Werror -pedantic -D_DEBUG -I .
DEPS = calculator.h stack.h
OBJ = stack.o calculator.o calculator_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

calculator_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) -lm
