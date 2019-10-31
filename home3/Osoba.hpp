#ifndef _OSOBA_HPP
#define _OSOBA_HPP

#include <string>
#include <ostream>

class Osoba {
    std::string imie;
    int rok_ur;
public:
    Osoba(std::string, int);
    friend std::ostream& operator<<(std::ostream&, const Osoba&);
};

#endif
