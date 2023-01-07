#ifndef gracz_H
#define gracz_H

#include <iostream>
#include <vector>
#include "karta.h"
#include "talia.h"
using namespace std;


class gracz {
public:
	~gracz() { cout << " d gracz " << endl; }
	gracz() { ilosc_kart = 0; }

	void dobierz(int n, talia t) {for(int i = 0; i < n; i++){
		karty_gracza.push_back(t.wylosuj());
		ilosc_kart++;
	}}
	


	int pokaz_ilosc_kart() {return ilosc_kart;}



private:
	int ilosc_kart;
	vector<karta> karty_gracza;


};

#endif