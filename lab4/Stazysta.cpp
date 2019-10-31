#include <iostream>
#include <sstream>
#include <string>

#include "Stazysta.h"
#include "Data.h"

namespace Firma {
    Stazysta::Stazysta(
        const std::string& _imie,
        const std::string& _nazwisko,
        const Data& _rok_ur,
        double _stypendium,
        const Data& _koniec_stazu
    ): Osoba(_imie, _nazwisko, _rok_ur), stypendium{_stypendium}, koniec_stazu{_koniec_stazu} {}

    double Stazysta::wyplata() const {
        return stypendium;
    }

    std::string Stazysta::opis() const {
        std::stringstream ss;
        ss << "Stażysta: " << imie << ' ' << nazwisko << ' ' << rok_ur << ' ' << stypendium << ' ' << koniec_stazu << std::endl;
        return ss.str();
    }

    bool Stazysta::wczytaj(std::istream & is) {
        if (!Osoba::wczytaj(is)) return false;
        is >> stypendium;
        koniec_stazu.wczytaj(is);
        return (bool) is;
    }
}