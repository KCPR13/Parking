#ifndef STREFA_H
#define STREFA_H

#include "stdafx.h"
#include <vector>
#include "Pojazd.h"
using namespace std;

 class Strefa
{
public:
	 vector<Samochod> miejscaSamochody; // wektorymiejsc dla kazdego z typow
	 vector<Ciezarowka> miejscaCiezarowki;
	 vector<Motocykl> miejscaMotocykle;
	 void WypelnienieStrefy();
	 void LosujStrefe();
	 int wszysSam, wszysCiez, wszysMot; // liczba wszystkich wylosowanych miejsc danego typu
	Strefa();
	
};


#endif // !STREFA_H
