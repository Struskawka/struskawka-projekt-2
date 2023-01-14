#ifndef gra_H
#define gra_H

#include "talia.h"
#include "gracz.h"
#include "karta.h"
#include <iostream>
using namespace std;


class gra {
    public:
		~gra() {cout << " d gra " << endl;}
		gra() {tura = 1; ilosc_graczy=0;} 

		void graj() {
//---------przygotowanie talii------------
			talia* ta = new talia(); 
			ta->przygotuj();
//---------przygotowanie graczy------------
			cout << "ilu graczy: "; cin >> ilosc_graczy;
			gracz* gracze_tab;
			gracze_tab = (gracz*)malloc(ilosc_graczy * sizeof(gracz));
			for_each(gracze_tab, gracze_tab + ilosc_graczy, [](gracz &n) {n = gracz(); });

			gracze_tab[0].dobierz(5, ta2);
			//for_each(gracze_tab, gracze_tab + ilosc_graczy, [](gracz &n,) {n.dobierz(5, ta); });



//---------czyszczenie------------
			for_each(gracze_tab, gracze_tab + ilosc_graczy, [](gracz &n) {n.~gracz(); });
			free(gracze_tab);
			delete ta;
		}

	private:
		int tura;
		int ilosc_graczy;

    
};

#endif