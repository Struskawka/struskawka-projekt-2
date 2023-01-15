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
		cout <<"####stol####"<< endl;
		karty_stol.back().pokaz_karte();
		cout << "############" << endl;
	}

	bool czy_mozna_dolozyc(karta k) {
		bool bo;
		if(k.pokaz_kolor() == karty_stol.back().pokaz_kolor())bo = 1;
		else if(k.pokaz_wartosc() == karty_stol.back().pokaz_wartosc())bo = 1;
		else bo = 0;
		return bo;
	}




private:
	int ilosc_kart_stol;
	list <karta> karty_stol;


};

#endif