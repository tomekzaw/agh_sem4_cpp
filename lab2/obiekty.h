#ifndef _OBIEKTY_H
#define _OBIEKTY_H

#include <iostream>

using namespace std;

class Wektor;

class Punkt {
    float x, y, z;
public:
    Punkt();
    Punkt(float, float, float);
    friend ostream& operator<<(ostream&, const Punkt&);
    Punkt operator+(const Wektor&) const;
    Punkt& operator++();
    Punkt operator++(int);
};

class Wektor {
    float x, y, z;
public:
    Wektor();
    Wektor(float, float, float);
    friend ostream& operator<<(ostream&, const Wektor&);
    Wektor& operator+=(const Wektor&);
    Wektor operator+(const Wektor&) const;
    Wektor& operator*=(float);
    friend Wektor operator*(const Wektor&, float);
    friend Wektor operator*(float, const Wektor&);
    friend Punkt Punkt::operator+(const Wektor&) const;
    Wektor operator-() const;
    bool operator>(const Wektor&) const;
    float& operator[](int);
    const float& operator[](int) const;
    operator float() const;
};

#endif