#include <iostream>
#include <sstream>
#include <string>

#include "Pracownik.h"
#include "Osoba.h"

namespace Firma {
    Pracownik::Pracownik(
        const std::string& _imie,
        const std::string& _nazwisko,
        const Data& _rok_ur,
        double _pensja
    ): Osoba(_imie, _nazwisko, _rok_ur), pensja{_pensja} {}

    double Pracownik::wyplata() const {
        return pensja;
    }

    std::string Pracownik::opis() const {
        std::stringstream ss;
        ss << "Pracownik: " << imie << ' ' << nazwisko << ' ' << rok_ur << ' ' << pensja << std::endl;
        return ss.str();
    }

    bool Pracownik::wczytaj(std::istream & is) {
        if (!Osoba::wczytaj(is)) return false;
        is >> pensja;
        return (bool) is;
    }
}