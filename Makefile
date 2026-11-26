CC = gcc
CFLAGS = -Wall -Wextra -std=c11

crashTech: main.o year.o
	$(CC) $(CFLAGS) -o crashTech main.o year.o

main.o: main.c year.h
year.o: year.c year.h

.PHONY: clean
clean:
	rm -f main.o year.o crashTech
