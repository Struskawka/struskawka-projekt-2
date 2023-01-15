#ifndef karta_H
#define karta_H

#include <iostream>
using namespace std;


class karta {
public:
	~karta() { /*cout << " dkarta "; */}
	karta(int k,int w) { kolor = k; wartosc = w; }
	karta() { kolor = 0; wartosc = 0; }

	void pokaz_karte() {
		//cout << "kolor: " << kolor << " wartosc: " << wartosc << endl;
		if(wartosc <= 8)cout << "  " << wartosc + 2;
		else if(wartosc==9)cout << "  J";
		else if(wartosc == 10)cout << "  Q";
		else if(wartosc == 11)cout << "  K";
		else if(wartosc == 12)cout << "  A";

		printf("%c", kolor+3);
		cout << endl;
	}

	int pokaz_wartosc() {return wartosc;}
	int pokaz_kolor() { return kolor; }




private:
	int kolor;
	int wartosc;


};

#endif