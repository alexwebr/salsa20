CFLAGS=-std=c99 -pedantic -Wall -Werror

tests: unit_tests.o
	$(CC) unit_tests.o -o tests

cli: salsa20.o cli.o

clean:
	rm -f *.o tests
