#include <iostream>
#include <iomanip>
#include "obiekty.h"

using namespace std;

int main() {
    Punkt p0, p1(2.0, 3.0);
    cout << p0 << p1;

    Macierz m0, m1(4.0, 5.0, 6.0), m2(7.0, 8.0, 9.0);
    cout << m0 << m1 << m2;

    cout << m2 - m1 << (m2 -= m1);

    cout << m1 * 3.0 << 3.0 * m1;

    cout << p1 * m1;

    cout << m1-- << m1 << --m1;

    cout << p1 << -p1;

    cout << m1 << (double) m1 << endl << m2 << (double) m2 << endl << (m1 < m2) << endl;

    cout << p1 << p1[1] << endl << p1['x'] << endl << p1[2] << endl << p1['y'] << endl;
    p1[1] = 5.0;
    p1['y'] += 3.0;
    cout << p1;
    
    return 0;
}
