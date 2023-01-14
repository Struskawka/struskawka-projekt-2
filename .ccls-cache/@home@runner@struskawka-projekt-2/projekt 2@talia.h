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
		talia() { pozostale_karty = 52; }

		void przygotuj(){
			for(int i=0;i<4;i++){for_each(talia_kart[i], talia_kart[i]+13, [](bool &n){n=1;});}
		}

		void pokaz() {for (int i = 0; i < 4; i++) {for (int ii = 0; ii < 13; ii++)cout << talia_kart[i][ii] << " "; cout << endl;
		}}

		karta wylosuj() {
			int kolor, wartosc;
			do { kolor = rand() % 4; wartosc = rand() % 13; } while(talia_kart[kolor][wartosc] == 0);
			talia_kart[kolor][wartosc] = 0;
			pozostale_karty--;
			karta *k = new karta(kolor,wartosc); return *k; }


	private:
		bool talia_kart[4][13];
		int pozostale_karty;


    
};

#endif