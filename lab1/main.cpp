#include <iostream>
#include <iomanip>

using namespace std;

class Wektor {
    double vx, vy, vz;
    static unsigned dokladnosc;
public:
    Wektor(): vx{1.0}, vy{1.0}, vz{1.0} {};
    Wektor(const double &vx, const double &vy = 1.0, const double &vz = 1.0): vx{vx}, vy{vy}, vz{vz} {};
    double zwroc_vx() const { return vx; }
    void zmien_vx(const double &vx) { this->vx = vx; }
    double dot(const Wektor &w) const { return vx * w.vx + vy * w.vy + vz * w.vz; }
    void wypisz() const;
    static void zmien_dokladnosc(const unsigned &d) { dokladnosc = d; }
    void zapisz(ostream&) const;
    void wczytaj(istream&);
};

unsigned Wektor::dokladnosc = 3;

inline void Wektor::wypisz() const {
    cout << vx << "; " << vy << "; " << vz << endl;
}

inline void Wektor::zapisz(ostream &os) const {
    os << fixed << setprecision(dokladnosc) << '[' << vx << "; " << vy << "; " << vz << ']' << endl;
}

inline void Wektor::wczytaj(istream &is) {
    is.ignore(1);
    is >> vx;
    is.ignore(2);
    is >> vy;
    is.ignore(2);
    is >> vz;
    is.ignore(1);
}

int main() {
    Wektor w1;
    Wektor w2(2.0, 3.0);
    Wektor w3(2.0, 3.0, 4.0);
    w1.wypisz();
    w2.wypisz();
    w3.wypisz();
    cout << endl;

    cout << w1.zwroc_vx() << endl;
    w1.zmien_vx(42.0);
    w1.wypisz();
    cout << endl;

    w1.zapisz(cout);
    w2.zapisz(cout);
    w3.zapisz(cout);
    Wektor::zmien_dokladnosc(5);
    w1.zapisz(cout);
    w2.zapisz(cout);
    w3.zapisz(cout);
    cout << endl;

    cout << w2.dot(w3) << endl;
    cout << endl;

    Wektor w4;
    w4.wczytaj(cin);
    w4.zapisz(cout);    
    cout << endl;
   
    return 0;
}