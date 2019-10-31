#ifndef STAZYSTA_H
#define STAZYSTA_H

#include "Osoba.h"
#include "Data.h"

namespace Firma {
    class Stazysta : public Osoba
    {
    public:
        Stazysta(const std::string& _imie, const std::string& _nazwisko, const Data& _rok_ur, double _stypendium, const Data& _koniec_stazu);
        void zmienKoniecStazu(const Data& d);
        std::string opis() const override;
        double wyplata() const override;
        bool wczytaj(std::istream & is) override;
    protected:
        double stypendium;
        Data koniec_stazu;
    };
}

#endif // STAZYSTA_H