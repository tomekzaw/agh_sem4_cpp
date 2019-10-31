#ifndef ROWER_H
#define ROWER_H

#include "Pojazd.h"

class Rower : public Pojazd
{
public:
    Rower(const Osoba& _wlasciciel, int _przebieg, bool _amatorski);
    ~Rower();
    float mocKW() const;
protected:
    bool amatorski;
};

#endif // ROWER_H