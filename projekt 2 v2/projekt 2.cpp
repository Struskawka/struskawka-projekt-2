#include <iostream>
#include <algorithm>
#include "gra.h"

using namespace std;

int main()
{

	gra *g = new gra();
	g->graj();
	delete g;

	system("pause");
	return(0);
}
