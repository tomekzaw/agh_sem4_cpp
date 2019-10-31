#include <iostream>
#include <sstream>
#include <string>

#include "Kierownik.h"
#include "Pracownik.h"
#include "Osoba.h"

namespace Firma {
    Kierownik::Kierownik(
        const std::string& _imie,
        const std::string& _nazwisko,
        const Data& _rok_ur,
        double _pensja,
        double _dodatek
    ): Pracownik(_imie, _nazwisko, _rok_ur, _pensja), dodatek{_dodatek} {}

    double Kierownik::wyplata() const {
        return Pracownik::wyplata() + pensja;
    }

    std::string Kierownik::opis() const {
        std::stringstream ss;
        ss << "Kierownik: " << imie << ' ' << nazwisko << ' ' << rok_ur << ' ' << pensja << ' ' << dodatek << std::endl;
        return ss.str();
    }

    bool Kierownik::wczytaj(std::istream & is) {
        if (!Pracownik::wczytaj(is)) return false;
        is >> dodatek;
        return (bool) is;
    }
}