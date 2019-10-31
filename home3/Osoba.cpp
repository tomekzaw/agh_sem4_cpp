#include <string>
#include <ostream>
#include "Osoba.hpp"

Osoba::Osoba(std::string imie = "Tomek", int rok_ur = 1998): imie{imie}, rok_ur{rok_ur} {}

std::ostream& operator<<(std::ostream& os, const Osoba& o) {
    os << o.imie << " (" << o.rok_ur << ')' << std::endl;
    return os;
}
