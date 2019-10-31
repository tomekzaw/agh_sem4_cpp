CC=g++
CFLAGS=-Wall -Wextra -pedantic

main: main.o obiekty.o
	g++ $(CFLAGS) -o main main.o obiekty.o

main.o: main.cpp obiekty.h
	gcc $(CFLAGS) -c main.cpp

obiekty.o: obiekty.cpp obiekty.h
	g++ $(CFLAGS) -c obiekty.cpp

clean:
	rm -f *.o main obiekty