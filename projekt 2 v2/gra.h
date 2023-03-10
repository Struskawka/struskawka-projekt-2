#ifndef gra_H
#define gra_H

#include "talia.h"
#include "gracz.h"
#include "karta.h"
#include "stol.h"
#include <iostream>
using namespace std;


class gra {
public:
	~gra() { cout << " d gra " << endl; }
	gra() { tura = 0; ilosc_graczy = 0; }

	void graj() {
//---------przygotowanie talii i stolu------------
		talia* ta = new talia();
		ta->przygotuj();
		stol* st = new stol();

//---------przygotowanie graczy------------
		cout << "ilu graczy: "; cin >> ilosc_graczy;
		vector<gracz> gracze_tab;
		for(int i = 0; i < ilosc_graczy; i++) {gracze_tab.push_back(gracz(i,0));}
		for(int i = 0; i < ilosc_graczy; i++) {gracze_tab[i].dobierz(5, ta); }
		/*for_each(gracze_tab.begin(), gracze_tab.end(), [](gracz &n) {n.pokaz_karty_gracza(); });
		for_each(gracze_tab.begin(), gracze_tab.end(), [](gracz &n) {n.posortuj_karty_gracza(); });
		for_each(gracze_tab.begin(), gracze_tab.end(), [](gracz &n) {n.pokaz_karty_gracza(); });*/


//---------rozgrywka------------
		st->doloz_na_stol(ta->wylosuj());

		do {cout << endl;
			tura++; if(tura == ilosc_graczy)tura = 0;
		
		st->pokaz_stol();
		gracze_tab[tura].posortuj_karty_gracza();
		gracze_tab[tura].pokaz_karty_gracza();
		
		int opcja;
		int nr_karty;
		
		cout << "1. wyloz karte"<<endl<<"2. dobierz karte"<<endl; cin >> opcja;
		while(opcja != 1 && opcja != 2) { cout << "niepoprawny numer, podaj poprawny  "; cin >> opcja; }

		if(opcja == 1) {
			cout << "ktora karte wybrac: "; cin >> nr_karty;

			while(st->czy_mozna_dolozyc(gracze_tab[tura].czy_mozna_dolozyc_gracz(nr_karty))==0) 
			{ cout << "nie mozesz dolozyc tej karty, jesli chcesz dobrac karte wpisz -1"; cin >> nr_karty;
			if(nr_karty == -1)break;
			}
			
			if(nr_karty != -1) {
				st->doloz_na_stol(gracze_tab[tura].wyloz(nr_karty));
				gracze_tab[tura].wyloz_2(nr_karty);}}

		if(opcja == 2||nr_karty==-1) {gracze_tab[tura].dobierz(1, ta);}
		
		} while(gracze_tab[tura].pokaz_ilosc_kart_gracz() > 0);

		cout << endl << endl << "wygrywa gracz " << tura << endl << endl;


//---------czyszczenie------------
		for_each(gracze_tab.begin(), gracze_tab.end(), [](gracz &n) {n.~gracz(); });
		delete ta;
		delete st;
	}

private:
	int tura;
	int ilosc_graczy;


};

#endif