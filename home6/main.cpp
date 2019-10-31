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

class Drzewo {
private:
    inline static std::random_device rd{};
    inline static std::mt19937 gen{rd()};
    inline static std::uniform_int_distribution<> gatunek_dis{0, 3};
    inline static std::uniform_real_distribution<> srednica_dis{0.1, 2.0};
    inline static std::uniform_int_distribution<> wiek_dis{1, 100};
    inline static std::array<std::string, 4> gatunki{ {"dąb", "orzech", "sosna", "świerk"} };
public:
    std::string gatunek;
    double srednica;
    int wiek;
    Drzewo(): gatunek{ gatunki[gatunek_dis(gen)] }, srednica{srednica_dis(gen)}, wiek{wiek_dis(gen)} {};
    friend std::ostream& operator<<(std::ostream&, const Drzewo&);
    // bool operator<(const Drzewo &d) const { return srednica < d.srednica; }
};

std::ostream& operator<<(std::ostream& out, const Drzewo& drzewo) {
    out << "Drzewo - gatunek: " << drzewo.gatunek << ", średnica: " << drzewo.srednica << ", wiek: " << drzewo.wiek << std::endl;
    return out;
}

int main() {
    constexpr auto n = 10;
    std::vector<Drzewo> vector(n);
    std::generate(vector.begin(), vector.end(), []{ return Drzewo(); });
    /*
    std::vector<Drzewo> vector;
    vector.reserve(n);
    std::generate_n(std::back_inserter(vector), n, [] { return Drzewo(); });
    */

    for (std::vector<Drzewo>::const_iterator it = vector.begin(); it != vector.end(); ++it) std::cout << *it;
    // for (auto it = vector.begin(); it != vector.end(); ++it) std::cout << *it;
    // for (const auto& d: vector) std::cout << d;
    // std::copy(vector.begin(), vector.end(), std::ostream_iterator<Drzewo>(std::cout));
    // std::for_each(vector.begin(), vector.end(), [](const auto& d) { std::cout << d; });

    auto najciensze = std::min_element(vector.begin(), vector.end(), [](const auto& d1, const auto& d2) { return d1.srednica < d2.srednica; });
    std::cout << *najciensze;

    std::string gatunek;
    std::cin >> gatunek;
    auto ile = std::count_if(vector.begin(), vector.end(), [gatunek](const auto& d) { return d.gatunek == gatunek; });
    std::cout << ile << std::endl;

    std::for_each(vector.begin(), vector.end(), [](auto& d) { d.srednica += 0.1; });

    vector.erase(std::remove_if(vector.begin(), vector.end(), [](const auto& d) { return d.srednica > 1.0; }), vector.end());

    std::for_each(vector.begin(), vector.end(), [](const auto& d) { std::cout << d; });

    std::map<double, Drzewo> map;
    std::for_each(vector.begin(), vector.end(), [&map](const auto& d) { map[d.srednica+d.wiek] = d; });
    // for (auto const& d: vector) { map[d.srednica+d.wiek] = d; }

    for (std::map<double, Drzewo>::const_iterator it = map.begin(); it != map.end(); ++it) std::cout << it->first << ": " << it->second;
    // for (auto it = map.begin(); it != map.end(); ++it) std::cout << it->first << ": " << it->second;
    // for (const auto& pair: map) std::cout << pair.first << ": " << pair.second;
    // std::for_each(map.begin(), map.end(), [](const auto& pair) { std::cout << pair.first << ": " << pair.second; });

    return 0;
}