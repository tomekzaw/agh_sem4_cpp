CC=g++
CFLAGS=-Wall -Wextra -pedantic

main: main.o Osoba.o Grupa.o
	g++ $(CFLAGS) -o main main.o Osoba.o Grupa.o

main.o: main.cpp Osoba.hpp Grupa.hpp
	gcc $(CFLAGS) -c main.cpp

Osoba.o: Osoba.cpp Osoba.hpp
	g++ $(CFLAGS) -c Osoba.cpp

Grupa.o: Grupa.cpp Grupa.hpp
	g++ $(CFLAGS) -c Grupa.cpp

clean:
	rm -f *.o main
