#include "Grupa.hpp"
#include <stdexcept>
#include <algorithm>

// Grupa::Grupa() = default;

Grupa::Grupa(int rozmiar = 20): rozmiar{rozmiar}, licznik{0}, osoby{ new Osoba[rozmiar] } {}

Grupa::Grupa(const Grupa& g) : rozmiar{g.rozmiar}, licznik{g.licznik}, osoby{ new Osoba[rozmiar] } { // copy constructor
    std::copy(g.osoby, g.osoby+licznik, osoby);
}

Grupa::Grupa(Grupa&& g): rozmiar{g.rozmiar}, licznik{g.licznik}, osoby{g.osoby} { // move constructor
    g.rozmiar = g.licznik = 0;
    g.osoby = nullptr;
}

Grupa::~Grupa() { // destructor
    delete[] osoby;
}

Grupa& Grupa::operator=(const Grupa& g) { // copy assignment
    if (this == &g) return *this;
    delete[] osoby;
    rozmiar = g.rozmiar;
    licznik = g.licznik;
    osoby = new Osoba[rozmiar];	
    std::copy(g.osoby, g.osoby+licznik, osoby);
    return *this;
}

Grupa& Grupa::operator=(Grupa&& g) { // move assignment
    if (this == &g) return *this;
    delete[] osoby;
    rozmiar = g.rozmiar;
    licznik = g.licznik;
    osoby = g.osoby;
    g.rozmiar = g.licznik = 0;
    g.osoby = nullptr;
    return *this;
}

int Grupa::ile() const {
    return licznik;
}

Grupa& Grupa::dodaj(const Osoba& osoba) {
    if (licznik >= rozmiar) throw std::overflow_error("Brak miejsca w grupie");
    osoby[licznik++] = osoba;
    return *this;
}
