CFLAGS=-O3 -std=c99 -pedantic -Wall -Werror
SHELL := bash

.PHONY: clean all

all: tests cli perf

test_vectors_128.c:
	./vectors_to_tests_128.sh test_vectors.128 test_vectors_128.c

test_vectors_256.c:
	./vectors_to_tests_256.sh test_vectors.256 test_vectors_256.c

tests: unit_tests.c test_vectors_128.c test_vectors_256.c
	$(CC) $(CFLAGS) unit_tests.c -o tests

cli: salsa20.o cli.o

perf: salsa20.o perf.o

clean:
	rm -f *.o tests
