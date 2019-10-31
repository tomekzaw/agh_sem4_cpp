#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iterator>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

class Samochod {
private:
    inline static std::random_device rd{};
    inline static std::mt19937 gen{rd()};
    inline static std::array<std::string, 5> marki{ {"Opel", "Ford", "Audi", "Mercedes", "BMW"} };
    inline static std::uniform_int_distribution<> marka_dis{0, marki.size()-1};
    inline static std::uniform_int_distribution<> rok_produkcji_dis{2000, 2014};
    inline static std::array<double, 8> pojemnosci{ {1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.2, 2.4} };
    inline static std::uniform_int_distribution<> pojemnosc_dis{0, pojemnosci.size()-1};
public:
    std::string marka;
    int rok_produkcji;
    double pojemnosc;
    Samochod(int _rok_produkcji): marka{ marki[marka_dis(gen)] }, rok_produkcji{ _rok_produkcji }, pojemnosc{ pojemnosci[pojemnosc_dis(gen)] } {};
    Samochod(): Samochod(rok_produkcji_dis(gen)) {};
    std::string key() const { return marka + std::to_string(rok_produkcji); }
    bool operator<(const Samochod& other) const { return key() < other.key(); };
    bool operator==(const int _rok) const { return rok_produkcji == _rok; };
    friend std::ostream& operator<<(std::ostream&, const Samochod&);
    // bool operator<(const Drzewo &d) const { return srednica < d.srednica; }
};

std::ostream& operator<<(std::ostream& out, const Samochod& samochod) {
    out << "Samochód - marka: " << samochod.marka << ", rok produkcji: " << samochod.rok_produkcji << ", pojemność: " << samochod.pojemnosc << std::endl;
    return out;
}

int main() {

    // stwórz kolekcję (vector) wygenerowanych losowo obiektów tej klasy i wypisz zawartość listy korzystając z iteratora
    // generate - stworzyć 10 losowych pojazdów, w których rok produkcji będzie przyjmować kolejne wartości od 2001 do 2010
    constexpr auto n = 10;
    std::vector<Samochod> vector(n);
    auto rok = 2001;
    std::generate(vector.begin(), vector.end(), [&rok]{ return Samochod(rok++); });
    /*
    std::vector<Samochod> vector;
    vector.reserve(n);
    auto rok = 2001;
    std::generate_n(std::back_inserter(vector), n, [&rok]{ return Samochod(rok++); });
    */

    // for (std::vector<Samochod>::const_iterator it = vector.begin(); it != vector.end(); ++it) std::cout << *it;
    // for (auto it = vector.begin(); it != vector.end(); ++it) std::cout << *it;
    for (const auto& d: vector) std::cout << d;
    // std::copy(vector.begin(), vector.end(), std::ostream_iterator<Samochod>(std::cout));
    // std::for_each(vector.begin(), vector.end(), [](const auto& d) { std::cout << d; });

    // stwórz zbiór (set) obiektów z wcześniejszej kolekcji, wypisując obiekty, które się powtórzyły,
    std::set<Samochod> set;
    vector.insert(vector.end(), *vector.begin()); // duplicate first car
    std::for_each(vector.begin(), vector.end(), [&set](const auto& s) {     
        if (!set.insert(s).second) std::cout << "*** " << s;
    });

    // stwórz mapę (map) wygenerowanych losowo obiektów tej klasy, z zadanym kluczem i wypisz jej zawartość
    std::map<std::string, Samochod> map;
    // std::for_each(vector.begin(), vector.end(), [&map](const auto& s) { map[s.key()] = s; });
    for (auto const& s: vector) { map[s.key()] = s; }

    // for (std::map<std::string, Samochod>::const_iterator it = map.begin(); it != map.end(); ++it) std::cout << it->first << ": " << it->second;
    // for (auto it = map.begin(); it != map.end(); ++it) std::cout << it->first << ": " << it->second;
    for (const auto& pair: map) std::cout << pair.first << ": " << pair.second;
    // std::for_each(map.begin(), map.end(), [](const auto& pair) { std::cout << pair.first << ": " << pair.second; });

    // find - znaleźć (i wypisać) samochód wyprodukowany w 2005 roku
    // auto from2005 = std::find_if(vector.begin(), vector.end(), [](const auto& s) { return s.rok_produkcji == 2005; });
    auto from2005 = std::find(vector.begin(), vector.end(), 2005);
    std::cout << *from2005;

    // count_if - podać liczbę pojazdów zadanej marki (wczytanej z klawiatury)
    std::string marka;
    std::cin >> marka;
    auto ile = std::count_if(vector.begin(), vector.end(), [marka](const auto& s) { return s.marka == marka; });
    std::cout << ile << std::endl;

    // sort - uporządkować kolekcję według roku produkcji, potem pojemności
    std::sort(vector.begin(), vector.end(), [](const auto& s1, const auto& s2) {
        if (s1.rok_produkcji < s2.rok_produkcji) return true;
        if (s1.rok_produkcji > s2.rok_produkcji) return false;
        return s1.pojemnosc < s2.pojemnosc;
    });

    // unique - pozostawić w kolekcji tylko po jednym pojeździe danej marki
    std::sort(vector.begin(), vector.end(), [](const auto& s1, const auto& s2) { return s1.marka < s2.marka; });
    vector.erase(std::unique(vector.begin(), vector.end(), [](const auto& s1, const auto& s2) { return s1.marka == s2.marka; }), vector.end());
   
    return 0;
}