#include <iostream>
#include <iomanip>
#include "obiekty.h"

using namespace std;

int main() {
    // Punkt(), Punkt(float, float, float)
    Punkt p0, p1(2.0f, 3.0f, 4.0f), p2(11.0f, 12.0f, 13.0f);

    // Wektor(), Wektor(float, float, float)
    Wektor w0, w1(4.0f, 5.0f, 6.0f), w2(7.0f, 8.0f, 9.0f);

    // operator<<
    cout << p0 << p1 << p2;
    cout << w0 << w1 << w2 << endl;

    // operator+, operator+=
    cout << (w1 + w2) << (w2 += w1) << endl;

    // operator*
    cout << w1 << (w1 * 3.0f) << (3.0f * w1) << endl;

    // operator+
    cout << p1 << w1 << (p1 + w1) << endl;

    // operator++, operator++(int)
    cout << p1++ << p1 << ++p1 << endl;

    // operator-
    cout << w1 << -w1 << endl;
    
    // operator>
    cout << w1 << w2 << (w2 > w1) << endl << endl;
    
    // operator[]
    cout << w1 << w1[1] << endl << w1['x'] << endl << w1[2] << endl << w1['y'] << endl << w1[3] << endl << w1['z'] << endl;
    w1[1] = 0.0f;
    w1['y'] = 3.0f;
    w1['z'] -= 2.0f;
    cout << w1 << endl;
    
    // operator float
    cout << w1 << (float) w1 << endl << endl;
   
    return 0;
}
