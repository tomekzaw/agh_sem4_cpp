#include <string>
#include <iostream>
#include <iomanip>
#include "Towar.hpp"

Towar::Towar(const std::string& nazwa, float cena): nazwa{nazwa}, cena{cena} {}

std::ostream& operator<<(std::ostream& os, const Towar& t) {
    os << t.nazwa << " (" << std::fixed << std::setprecision(2) << std::setfill('0') << t.cena << " zł)" << std::endl;
    return os;
}
