CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic

main: main.o Data.o Osoba.o Stazysta.o Pracownik.o Kierownik.o
	$(CC) $(CFLAGS) -o main $^

main.o: main.cpp Data.h
	$(CC) $(CFLAGS) -c $<

Data.o: Data.cpp Data.h
	$(CC) $(CFLAGS) -c $<

Osoba.o: Osoba.cpp Osoba.h Data.h
	$(CC) $(CFLAGS) -c $<

Stazysta.o: Stazysta.cpp Stazysta.h Osoba.h Data.h
	$(CC) $(CFLAGS) -c $<

Pracownik.o: Pracownik.cpp Pracownik.h Osoba.h Data.h
	$(CC) $(CFLAGS) -c $<

Kierownik.o: Kierownik.cpp Kierownik.h Pracownik.h Osoba.h Data.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
