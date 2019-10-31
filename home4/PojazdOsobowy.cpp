#include "PojazdOsobowy.h"

PojazdOsobowy::PojazdOsobowy(const Osoba& _wlasciciel, int _przebieg, float _pojemnosc, int _moc_km, const std::string& _marka): PojazdSilnikowy(_wlasciciel, _przebieg, _pojemnosc, _moc_km), marka{_marka} {}

PojazdOsobowy::~PojazdOsobowy() {
    std::cout << "~PojazdOsobowy()" << std::endl;
}