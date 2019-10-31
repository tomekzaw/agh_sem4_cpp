#include <iostream>
#include <iomanip>

using namespace std;

class Data {
    int d, m, r;
    static int lata;
public:
    Data(): d{1}, m{1}, r{2000} { lata += r; };
    Data(const int &d, const int &m, const int &r = 2000): d{d}, m{m}, r{r} {
        if (m < 1 || m > 12) this->d = this->m = 1, this->r = 2000;
        lata += this->r;
    }
    int rok() const { return r; }
    void dodaj_rok() { r++; }
    bool czy_wczesniej_niz(const Data &other) const { return r < other.r || m < other.m || d < other.d; }
    void wypisz() const;
    static int ile_lat() { return lata; }
    void zapisz(ostream&) const;
    void wczytaj(istream&);
};

int Data::lata = 0;

inline void Data::wypisz() const {
    cout << setfill('0') << setw(2) << d << '.' << setw(2) << m << '.' << r << endl;
}

inline void Data::zapisz(ostream &os) const {
    os << setfill('0') << setw(4) << r << '-' << setw(2) << m << '-' << setw(2) << d << endl;
}

inline void Data::wczytaj(istream &is) {
    is >> setw(4) >> r;
    is.ignore(1, '-');
    is >> setw(2) >> m;
    is.ignore(1, '-');
    is >> setw(2) >> d;
}

int main() {
    Data data1 = Data();
    Data data2 = Data(2, 3);
    Data data3 = Data(4, 5, 2001);
    Data data4 = Data(6, 78, 2002);
    data1.wypisz(); // 01.01.2000
    data2.wypisz(); // 02.03.2000
    data3.wypisz(); // 04.05.2001
    data4.wypisz(); // 01.01.2000
    cout << data1.czy_wczesniej_niz(data2) << endl; // 1
    cout << data2.czy_wczesniej_niz(data1) << endl; // 0
    cout << data3.czy_wczesniej_niz(data4) << endl; // 0
    cout << Data::ile_lat() << endl; // 8001
    data1.zapisz(cout);
    data2.zapisz(cout);
    data3.zapisz(cout);
    data4.zapisz(cout);
    Data data5;
    data5.wczytaj(cin); // YYYY-MM-DD
    data5.zapisz(cout); // YYYY-MM-DD
    return 0;
}