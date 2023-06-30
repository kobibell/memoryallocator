###########################################################
# Makefile for CS480 Assignment #3
# Kobi Bell and Mark Duraid
###########################################################

CC = gcc
CFLAGS = -Wall -Wextra

all: memory_simulation

memory_simulation: main.o memory.o
	$(CC) $(CFLAGS) -o mot main.o memory.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c

clean:
	rm -f memory_simulation *.o

#######################[ EOF: Makefile ]###################