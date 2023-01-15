#ifndef gracz_H
#define gracz_H

#include <iostream>
#include <vector>
#include "karta.h"
#include "talia.h"
using namespace std;


class gracz {
public:
	~gracz() { /*cout << " d gracz " << endl;*/ }
	gracz(int nr, int ikg) { numer_gracza = nr; ilosc_kart_gracz = ikg;}

	void dobierz(int n, talia *t) {
		for(int i = 0; i < n; i++) {
			karty_gracza.push_back(t->wylosuj());
			ilosc_kart_gracz++;}}
	
	karta wyloz(int i) {
		cout<< "gracz " << numer_gracza << " kladzie karte ";
		karty_gracza[i].pokaz_karte();
		ilosc_kart_gracz--;
		cout << "zostalo mu " << ilosc_kart_gracz << " kart"<<endl<<endl;
		return karty_gracza[i];
	}

	karta czy_mozna_dolozyc_gracz(int i) {return karty_gracza[i];}

	void wyloz_2(int i) {karty_gracza.erase(karty_gracza.begin() + i);}

	void posortuj_karty_gracza() {
		sort(karty_gracza.begin(), karty_gracza.end(), 
			[](karta & a, karta & b) -> bool { return a.pokaz_wartosc() < b.pokaz_wartosc(); });
		sort(karty_gracza.begin(), karty_gracza.end(),
			[](karta & a, karta & b) -> bool { return a.pokaz_kolor() < b.pokaz_kolor(); });
	}


	void pokaz_karty_gracza() { 
		cout << endl << "karty gracza nr " << numer_gracza << endl;
		//for_each(karty_gracza.begin(), karty_gracza.end(), [](karta& ii) {ii.pokaz_karte(); }); 
		for(int i = 0; i < ilosc_kart_gracz; i++) { cout << " " << i << " "; karty_gracza[i].pokaz_karte(); }
	}



	int pokaz_ilosc_kart_gracz() { return ilosc_kart_gracz; }



private:
	int ilosc_kart_gracz;
	int numer_gracza;
	vector<karta> karty_gracza;


};

#endif