#ifndef karta_H
#define karta_H

#include <iostream>
using namespace std;


class karta {
public:
	~karta() { cout << " d karta " << endl; }
	karta(int k,int w) { kolor = k; wartosc = w; }
	karta() { kolor = 0; wartosc = 0; }

	void pokaz_karte() {
		cout << "kolor: " << kolor << " wartosc: " << wartosc << endl;
	}




private:
	int kolor;
	int wartosc;


};

#endif