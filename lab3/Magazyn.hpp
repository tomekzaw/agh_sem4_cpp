#ifndef MAGAZYN_HPP
#define MAGAZYN_HPP

#include "Towar.hpp"

class Magazyn {
private:
    int rozmiar;
    int licznik;
    Towar *towary;
public:
    // Magazyn();
    Magazyn(int = 5);
    Magazyn(const Magazyn&); // copy constructor
    Magazyn(Magazyn&& v); // move constructor
    ~Magazyn(); // destructor
    Magazyn& operator=(const Magazyn&); // copy assignment
	Magazyn& operator=(Magazyn&&); // move assignment
    int ile() const;
    Magazyn& dodaj(const Towar&);
};

#endif
