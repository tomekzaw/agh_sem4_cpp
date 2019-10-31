#include "Magazyn.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>

Magazyn::Magazyn(int rozmiar): rozmiar{rozmiar}, licznik{0}, towary{ new Towar[rozmiar] } {
    // std::clog << "Magazyn()" << std::endl;
}

Magazyn::Magazyn(const Magazyn& m) : rozmiar{m.rozmiar}, licznik{m.licznik}, towary{ new Towar[rozmiar] } { // copy constructor
    // std::clog << "Magazyn(const Magazyn&)" << std::endl;
    std::copy(m.towary, m.towary+licznik, towary);
}

Magazyn::Magazyn(Magazyn&& m): rozmiar{m.rozmiar}, licznik{m.licznik}, towary{m.towary} { // move constructor
    // std::clog << "Magazyn(Magazyn&&)" << std::endl;
    m.rozmiar = m.licznik = 0;
    m.towary = nullptr;
}

Magazyn::~Magazyn() { // destructor
    // std::clog << "~Magazyn()" << std::endl;
    delete[] towary;
}

Magazyn& Magazyn::operator=(const Magazyn& m) { // copy assignment
    // std::clog << "operator=(const Magazyn& m)" << std::endl;
    if (this == &m) return *this;
    delete[] towary;
    rozmiar = m.rozmiar;
    licznik = m.licznik;
    towary = new Towar[rozmiar];	
    std::copy(m.towary, m.towary+licznik, towary);
    return *this;
}

Magazyn& Magazyn::operator=(Magazyn&& m) { // move assignment
    // std::clog << "operator=(Magazyn&& m)" << std::endl;
    if (this == &m) return *this;
    delete[] towary;
    rozmiar = m.rozmiar;
    licznik = m.licznik;
    towary = m.towary;
    m.rozmiar = m.licznik = 0;
    m.towary = nullptr;
    return *this;
}

int Magazyn::ile() const {
    // std::clog << "ile()" << std::endl;
    return licznik;
}

Magazyn& Magazyn::dodaj(const Towar& towar) {
    // std::clog << "dodaj(const Towar& towar)" << std::endl;
    if (licznik >= rozmiar) throw std::out_of_range("Brak miejsca w magazynie");
    towary[licznik++] = towar;
    return *this;
}
