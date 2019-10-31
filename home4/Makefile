CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic

main: main.o Osoba.o Pojazd.o PojazdSilnikowy.o PojazdOsobowy.o Rower.o
	$(CC) $(CFLAGS) -o main $^

main.o: main.cpp Osoba.h Pojazd.h PojazdOsobowy.h PojazdSilnikowy.h Rower.h
	$(CC) $(CFLAGS) -c $<

Osoba.o: Osoba.cpp Osoba.h
	$(CC) $(CFLAGS) -c $<

Pojazd.o: Pojazd.cpp Pojazd.h Osoba.h
	$(CC) $(CFLAGS) -c $<

PojazdSilnikowy.o: PojazdSilnikowy.cpp PojazdSilnikowy.h Pojazd.h Osoba.h
	$(CC) $(CFLAGS) -c $<

PojazdOsobowy.o: PojazdOsobowy.cpp PojazdOsobowy.h PojazdSilnikowy.h Pojazd.h Osoba.h
	$(CC) $(CFLAGS) -c $<

Rower.o: Rower.cpp Rower.h Pojazd.h Osoba.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
