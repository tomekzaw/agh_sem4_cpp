#include "Rower.h"

Rower::Rower(const Osoba& _wlasciciel, int _przebieg, bool _amatorski): Pojazd(_wlasciciel, _przebieg), amatorski{_amatorski} {}

float Rower::mocKW() const {
    return amatorski ? 0.3f : 0.4f;
}

Rower::~Rower() {
    std::cout << "~Rower()" << std::endl;
}