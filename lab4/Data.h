#ifndef DATA_H
#define DATA_H

#include <iostream>

namespace Firma {
	class Data
	{
	public:
		Data(int _dzien, int _miesiac, int _rok);
		void setDzien(int d);
		int getDzien();
		bool zapisz(std::ostream & os) const; /// zapisuje atrybuty do strumienia
		bool wczytaj(std::istream & is); /// wczytuje atrybuty ze strumienia
	private:
		int dzien, miesiac, rok;
	};

	std::ostream& operator<<(std::ostream& os, const Data& d);
}

#endif // DATA_H