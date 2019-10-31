#ifndef POJAZDOSOBOWY_H
#define POJAZDOSOBOWY_H

#include <string>

#include "PojazdSilnikowy.h"

class PojazdOsobowy : public PojazdSilnikowy
{
public:
    PojazdOsobowy(const Osoba& _wlasciciel, int _przebieg, float _pojemnosc, int _moc_km, const std::string& _marka);
    ~PojazdOsobowy();
protected:
    std::string marka;
};

#endif // POJAZDOSOBOWY_H