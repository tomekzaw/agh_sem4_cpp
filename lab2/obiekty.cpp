#include <cmath>
#include <ostream>
#include <stdexcept>
#include "obiekty.h"

using namespace std;

Punkt::Punkt(): x{0.0}, y{0.0}, z{0.0} {}

Punkt::Punkt(float x, float y, float z): x{x}, y{y}, z{z} {}

ostream& operator<<(ostream& os, const Punkt& p) {
    os << '(' << p.x << ", " << p.y << ", " << p.z << ')' << endl;
    return os;
}

Punkt Punkt::operator+(const Wektor& w) const {
    return Punkt(x + w.x, y + w.y, z + w.z);
}

Punkt& Punkt::operator++() { // prefix
    ++x;
    ++y;
    ++z;
    return *this;
}

Punkt Punkt::operator++(int) { // postfix
    Punkt p(*this);
    ++(*this);
    return p;
}

Wektor::Wektor(): x{0.0}, y{0.0}, z{0.0} {}

Wektor::Wektor(float x, float y, float z): x{x}, y{y}, z{z} {}
  
ostream& operator<<(ostream &os, const Wektor &w) {
    os << '[' << w.x << ", " << w.y << ", " << w.z << ']' << endl;
    return os;
}

Wektor& Wektor::operator+=(const Wektor &w) {
    x += w.x;
    y += w.y;
    z += w.z;
    return *this;
}

Wektor Wektor::operator+(const Wektor &other) const {
    return Wektor(*this) += other;
}

Wektor& Wektor::operator*=(float f) {
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

Wektor operator*(const Wektor &w, float f) {
    return Wektor(w) *= f;
}

Wektor operator*(float f, const Wektor &w) {
    return w * f;
}

Wektor Wektor::operator-() const {
    return Wektor(-x, -y, -z);
}

bool Wektor::operator>(const Wektor &other) const {
    return (float) *this > (float) other;
}

float& Wektor::operator[] (int i) { // for non-const objects: can be used for assignment
    switch (i) {
        case 1: case 'x': return x;
        case 2: case 'y': return y;
        case 3: case 'z': return z;
    }
    throw std::out_of_range("Invalid index");
}
 
const float& Wektor::operator[] (int i) const { // for const objects: can only be used for access
    switch (i) {
        case 1: case 'x': return x;
        case 2: case 'y': return y;
        case 3: case 'z': return z;
    }
    throw std::out_of_range("Invalid index");
}

Wektor::operator float() const {
    return sqrt(x*x + y*y + z*z);
}
