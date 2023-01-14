#ifndef talia_H
#define talia_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include "karta.h"
using namespace std;


class talia {
    public:
		~talia() {cout << " d talia " << endl;}
		talia() { ilosc_kart_talia = 52; }

		void przygotuj(){
			for(int i=0;i<4;i++){for_each(talia_kart[i], talia_kart[i]+13, [](bool &n){n=1;});}}

		void pokaz_talia(){
			for (int i = 0; i < 4; i++) {for (int ii = 0; ii < 13; ii++)cout << talia_kart[i][ii] << " "; cout << endl;}}

		karta wylosuj() {
			int kolor, wartosc;
			do { kolor = rand() % 4; wartosc = rand() % 13; } while(talia_kart[kolor][wartosc] == 0);
			talia_kart[kolor][wartosc] = 0;
			ilosc_kart_talia--;
			karta k(kolor,wartosc); return k; }


	private:
		bool talia_kart[4][13];
		int ilosc_kart_talia;


    
};

#endif