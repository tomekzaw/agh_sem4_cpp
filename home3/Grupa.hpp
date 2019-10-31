#ifndef _GRUPA_HPP
#define _GRUPA_HPP

#include "Osoba.hpp"

class Grupa {
    int rozmiar;
    int licznik;
    Osoba *osoby;
public:
    // Grupa();
    Grupa(int);
    Grupa(const Grupa&); // copy constructor
    Grupa(Grupa&& v); // move constructor
    ~Grupa(); // destructor
    Grupa& operator=(const Grupa&); // copy assignment
	Grupa& operator=(Grupa&&); // move assignment
    int ile() const;
    Grupa& dodaj(const Osoba&);
};

#endif
