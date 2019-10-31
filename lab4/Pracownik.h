#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include "Osoba.h"
#include "Data.h"

namespace Firma {
    class Pracownik : public Osoba
    {
    public:
        Pracownik(const std::string& _imie, const std::string& _nazwisko, const Data& _rok_ur, double _pensja);
        std::string opis() const override;
        double wyplata() const override;
        bool wczytaj(std::istream & is) override;
    protected:
        double pensja;
    };
}

#endif // PRACOWNIK_H