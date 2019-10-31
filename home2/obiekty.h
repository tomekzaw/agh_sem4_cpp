#ifndef _OBIEKTY_H
#define _OBIEKTY_H

#include <iostream>

using namespace std;

class Macierz;

class Punkt {
    double x, y;
public:
    Punkt();
    Punkt(const double&, const double&);
    friend ostream& operator<<(ostream&, const Punkt&);
    const Macierz operator*(const Macierz& m) const;
    const Punkt operator-();
    double& operator[] (const int i);
    const double& operator[] (const int i) const;
};

class Macierz {
    double mxx, mxy, myy;
    Macierz& operator*=(const double&); // used by operator*()
public:
    Macierz();
    Macierz(const double&, const double&, const double&);
    friend ostream& operator<<(ostream&, const Macierz&);
    Macierz& operator-=(const Macierz&);
    const Macierz operator-(const Macierz&) const;
    friend const Macierz operator*(const double&, const Macierz&);
    friend const Macierz operator*(const Macierz&, const double&);
    friend const Macierz Punkt::operator*(const Macierz&) const;
    const Macierz& operator--();
    const Macierz operator--(int);
    operator double() const;
    bool operator<(const Macierz&) const;
};

#endif