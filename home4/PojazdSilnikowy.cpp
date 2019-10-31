#include "PojazdSilnikowy.h"

PojazdSilnikowy::PojazdSilnikowy(const Osoba& _wlasciciel, int _przebieg, float _pojemnosc, int _moc_km): Pojazd(_wlasciciel, _przebieg), pojemnosc{_pojemnosc}, moc_km{_moc_km} {}

float PojazdSilnikowy::mocKW() const {
    return 1.4f * moc_km;
}

PojazdSilnikowy::~PojazdSilnikowy() {
    std::cout << "~PojazdSilnikowy()" << std::endl;
}