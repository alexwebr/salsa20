CFLAGS=-std=c99 -pedantic -Wall -Werror

tests: unit_tests.o
	$(CC) unit_tests.o -o tests

cli: salsa20.o cli.o
	$(CC) salsa20.o cli.o -o salsa20

clean:
	rm -f *.o tests
