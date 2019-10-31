CC=g++
CFLAGS=-Wall -Wextra -pedantic

main: main.o Towar.o Magazyn.o
	g++ $(CFLAGS) -o main main.o Towar.o Magazyn.o

main.o: main.cpp Towar.hpp Magazyn.hpp
	gcc $(CFLAGS) -c main.cpp

Towar.o: Towar.cpp Towar.hpp
	g++ $(CFLAGS) -c Towar.cpp

Magazyn.o: Magazyn.cpp Magazyn.hpp Towar.hpp
	g++ $(CFLAGS) -c Magazyn.cpp

clean:
	rm -f *.o main
