#include <iostream>

#include "Data.h"
#include "Osoba.h"
#include "Stazysta.h"
#include "Pracownik.h"
#include "Kierownik.h"

using namespace std;

int main() {
    Firma::Data* d = new Firma::Data(1, 2, 2000);
    Firma::Osoba* ludzie[] = {
        new Firma::Stazysta("Jan", "Kowalski", *d, 1200, *d),
        new Firma::Pracownik("Jan2", "Kowalski2", *d, 1900),
        new Firma::Kierownik("Jan3", "Kowalski3", *d, 3000, 250)
    };
    for (unsigned i = 0; i < (sizeof(ludzie) / sizeof(*ludzie)); i++) {
        ludzie[i]->zapisz(cout);
        delete ludzie[i];
    }
    delete d;
    return 0;
}