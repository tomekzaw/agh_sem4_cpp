#include <iostream>
#include "Osoba.hpp"
#include "Grupa.hpp"

using namespace std;

int main() {
    Osoba o1, o2("Kemot", 1889);

    cout << o1 << o2;

    return 0;
}
