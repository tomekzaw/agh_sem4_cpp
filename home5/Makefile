CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp NodeBST.h TreeBST.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o main
