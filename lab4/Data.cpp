#include <iostream>
#include <iomanip>

#include "Data.h"

namespace Firma {
    Data::Data(int _dzien, int _miesiac, int _rok): dzien{_dzien}, miesiac{_miesiac}, rok{_rok} {}

    void Data::setDzien(int d) {
        dzien = d;
    }

    int Data::getDzien() {
        return dzien;
    }

    bool Data::zapisz(std::ostream & os) const {
        os << std::setfill('0') << std::setw(2) << dzien << '.' << std::setw(2) << miesiac << '.' << std::setw(4) << rok << " r.";
        return (bool) os;
    }

    bool Data::wczytaj(std::istream & is) {
        is >> dzien >> miesiac >> rok;
        return (bool) is;
    }

    std::ostream& operator<<(std::ostream& os, const Data& d) {
        d.zapisz(os);
        return os;
    }
}