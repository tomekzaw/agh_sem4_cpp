#ifndef POJAZDSILNIKOWY_H
#define POJAZDSILNIKOWY_H

#include "Pojazd.h"

class PojazdSilnikowy : public Pojazd
{
public:
    PojazdSilnikowy(const Osoba& _wlasciciel, int _przebieg, float _pojemnosc, int _moc_km);
    virtual ~PojazdSilnikowy();
    float mocKW() const;
protected:
    float pojemnosc;
    int moc_km;
};

#endif // POJAZDSILNIKOWY_H