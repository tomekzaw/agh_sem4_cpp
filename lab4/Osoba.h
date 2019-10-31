#ifndef OSOBA_H
#define OSOBA_H

#include "Data.h"

namespace Firma {
    class Osoba
    {
    public:
        Osoba(const std::string& _imie, const std::string& _nazwisko, const Data& _rok_ur);
        virtual ~Osoba() = default;
        virtual std::string opis() const = 0;
        virtual double wyplata() const = 0;
        bool zapisz(std::ostream & os) const;
        virtual bool wczytaj(std::istream & is);
    protected:
        std::string imie, nazwisko;
        Data rok_ur;
    };
}

#endif // OSOBA_H