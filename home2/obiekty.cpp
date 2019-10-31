#include <ostream>
#include <stdexcept>
#include "obiekty.h"

using namespace std;

Punkt::Punkt(): x{0.0}, y{0.0} {}

Punkt::Punkt(const double &x, const double &y): x{x}, y{y} {}

ostream& operator<<(ostream& os, const Punkt& p) {
    os << '(' << p.x << ", " << p.y << ')' << endl;
    return os;
}

const Macierz Punkt::operator*(const Macierz& m) const {
    return Macierz(x * m.mxx, x * m.mxy, y * m.myy);
}

const Punkt Punkt::operator-() {
    return Punkt(-x, -y);
}

double& Punkt::operator[] (const int i) { // for non-const objects: can be used for assignment
    switch (i) {
        case 1: case 'x': return x;
        case 2: case 'y': return y;
    }
    throw std::out_of_range("Invalid index");
}
 
const double& Punkt::operator[] (const int i) const { // for const objects: can only be used for access
    switch (i) {
        case 1: case 'x': return x;
        case 2: case 'y': return y;
    }
    throw std::out_of_range("Invalid index");
}

Macierz::Macierz(): mxx{0.0}, mxy{0.0}, myy{0.0} {}

Macierz::Macierz(const double &mxx, const double &mxy, const double &myy): mxx{mxx}, mxy{mxy}, myy{myy} {}
  
ostream& operator<<(ostream& os, const Macierz& m) {
    // os << "⌈ " << m.mxx << ", " << m.mxy << " ⌉" << endl << "⌊ " << m.mxy << ", " << m.myy << " ⌋" << endl;
    os << "[[" << m.mxx << ", " << m.mxy << "], [" << m.mxy << ", " << m.myy << "]]" << endl;
    return os;
}

Macierz& Macierz::operator-=(const Macierz &m) {
    mxx -= m.mxx;
    mxy -= m.mxy;
    myy -= m.myy;
    return *this;
}

Macierz& Macierz::operator*=(const double &d) {
    mxx *= d;
    mxy *= d;
    myy *= d;
    return *this;
}

const Macierz Macierz::operator-(const Macierz &other) const {
    return Macierz(*this) -= other;
}

const Macierz operator*(const double &d, const Macierz &m) {
    return Macierz(m) *= d;
}

const Macierz operator*(const Macierz &m, const double &d) {
    return d * m;
}

const Macierz& Macierz::operator--() { // prefix --
    --mxx;
    --mxy;
    --myy;
    return *this;
}

const Macierz Macierz::operator--(int) { // postfix --
    Macierz m(*this);
    --(*this);
    return m;
}

Macierz::operator double() const {
    return mxx * myy - mxy * mxy;
}

bool Macierz::operator<(const Macierz& m) const {
    return (double) *this < (double) m;
}