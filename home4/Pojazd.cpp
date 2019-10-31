#include <sstream>

#include "Pojazd.h"

Pojazd::Pojazd(const Osoba& _wlasciciel, int _przebieg): wlasciciel{_wlasciciel}, przebieg{_przebieg} {}

Pojazd::~Pojazd() {
    std::cout << "~Pojazd()" << std::endl;
}

std::string Pojazd::opis() const {
    std::stringstream ss;
    ss << "właściciel: " << wlasciciel.opis() << ", przebieg: " << przebieg;
    return ss.str();
}

bool Pojazd::zapisz(std::ostream & os) const {
    os << opis() << std::endl;
    return true;
}

bool Pojazd::wczytaj(std::istream & is) {
    wlasciciel.wczytaj(is);
    is >> przebieg;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Pojazd& p) {
    p.zapisz(os);
    return os;
}