#include <iostream>
#include "Towar.hpp"
#include "Magazyn.hpp"

using namespace std;

int main() {

    // constructor
    Towar t0, t1{"iPhone", 9999.0f}, t2{"iPad", 12999.0f}, t3{"iPod touch", 4999.0f}, t4{"iPod nano", 2999.0f};
    cout << t0 << t1 << t2 << t3;

    // constructor
    Magazyn m1;
    m1.dodaj(t0);

    // copy constructor
    Magazyn m2(m1);

    // move constructor
    Magazyn m3(std::move(m2));

    // copy assignment
    m2 = m3;

    // move assignment
    m3 = std::move(m2);

    cout << m3.ile() << endl;
    m3.dodaj(t1);
    cout << m3.ile() << endl;
    m3.dodaj(t2).dodaj(t3).dodaj(t4);
    cout << m3.ile() << endl;

    try {
        m3.dodaj(Towar());
    } catch (const std::exception &ex) {
        cerr << ex.what() << endl;
    }

    return 0;
}
