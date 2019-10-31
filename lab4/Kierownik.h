#ifndef KIEROWNIK_H
#define KIEROWNIK_H

#include "Pracownik.h"
#include "Osoba.h"
#include "Data.h"

namespace Firma {
    class Kierownik : public Pracownik
    {
    public:
        Kierownik(const std::string& _imie, const std::string& _nazwisko, const Data& _rok_ur, double _pensja, double _dodatek);
        std::string opis() const override;
        double wyplata() const override;
        bool wczytaj(std::istream & is) override;
    protected:
        double dodatek;
    };
}

#endif // KIEROWNIK_H