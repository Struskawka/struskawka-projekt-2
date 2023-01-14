#ifndef karta_H
#define karta_H

#include <iostream>
using namespace std;


class karta {
public:
	~karta() { cout << " dkarta "; }
	karta(int k,int w) { kolor = k; wartosc = w; }
	karta() { kolor = 0; wartosc = 0; }

	void pokaz_karte() {
		cout << "kolor: " << kolor << " wartosc: " << wartosc << endl;
	}

	int pokaz_wartosc() {return wartosc;}
	int pokaz_kolor() { return kolor; }




private:
	int kolor;
	int wartosc;


};

#endif