#include <iostream>

#include "Osoba.h"
#include "Pojazd.h"
#include "PojazdSilnikowy.h"
#include "PojazdOsobowy.h"
#include "Rower.h"

using namespace std;

int main() {
    Osoba o2222(); // this shouldn't work

    Osoba o1("Jan", "Kowalski", 1970);
    cout << o1;

    /* Pojazd p1(o1, 120000);
    cout << p1 << endl; */
    // error: cannot declare variable ‘p1’ to be of abstract type ‘Pojazd’

    PojazdSilnikowy ps1(o1, 3000, 100, 200);
    cout << ps1 << ps1.mocKW() << endl;

    PojazdOsobowy po1(o1, 3000, 100, 200, "Audi");
    cout << po1 << po1.mocKW() << endl;

    Rower r1(o1, 1000, true);
    cout << r1 << r1.mocKW() << endl;

    Rower r2(o1, 2000, false);
    cout << r2 << r2.mocKW() << endl;

    return 0;
}