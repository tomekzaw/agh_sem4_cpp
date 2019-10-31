#include <iostream>
#include <sstream>

#include "Osoba.h"
#include "Data.h"

namespace Firma {
    Osoba::Osoba(const std::string& _imie, const std::string& _nazwisko, const Data& _rok_ur): imie{_imie}, nazwisko{_nazwisko}, rok_ur{_rok_ur} {}

    bool Osoba::zapisz(std::ostream & os) const {
        os << opis();
        return (bool) os;
    }

    bool Osoba::wczytaj(std::istream & is) {
        is >> imie >> nazwisko;
        rok_ur.wczytaj(is);
        return (bool) is;
    }
}