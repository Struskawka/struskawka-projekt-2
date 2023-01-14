#ifndef stol_H
#define stol_H

#include <iostream>
#include <list>
#include "karta.h"
using namespace std;


class stol {
public:
	~stol() { cout << " d stol " << endl; }
	stol() { ilosc_kart_stol = 0; }

	void doloz_na_stol(karta k) {
		karty_stol.push_back(k);
		ilosc_kart_stol++;}

	void pokaz_stol() {
		cout <<"############"<< endl;
		karty_stol.back().pokaz_karte();
		cout << "############" << endl;
	}




private:
	int ilosc_kart_stol;
	list <karta> karty_stol;


};

#endif