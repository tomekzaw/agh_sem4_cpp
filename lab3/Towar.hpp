#ifndef TOWAR_HPP
#define TOWAR_HPP

#include <string>
#include <ostream>

class Towar {
private:
    std::string nazwa;
    float cena;
public:
    Towar(const std::string& = "iTowar", float = 0.01f);
    friend std::ostream& operator<<(std::ostream&, const Towar&);
};

#endif
