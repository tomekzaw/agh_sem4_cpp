#include <iostream>
#include <sstream>

#include "Osoba.h"

Osoba::Osoba(const std::string& _imie, const std::string& _nazwisko, int _rok_ur): imie{_imie}, nazwisko{_nazwisko}, rok_ur{_rok_ur} {}

Osoba::~Osoba() {
    std::cout << "~Osoba()" << std::endl;
}

void Osoba::ustawImie(const std::string& im) {
    imie = im;
}

std::string Osoba::pobierzImie() const {
    return imie;
}

std::string Osoba::opis() const {
    std::stringstream ss;
    ss << imie << ' ' << nazwisko << ' ' << rok_ur;
    return ss.str();
}

bool Osoba::zapisz(std::ostream & os) const {
    os << imie << ' ' << nazwisko << ' ' << rok_ur << std::endl;
    return true; // ???
}

bool Osoba::wczytaj(std::istream & is) {
    is >> imie >> nazwisko >> rok_ur;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Osoba& o) {
    o.zapisz(os);
    return os;
}