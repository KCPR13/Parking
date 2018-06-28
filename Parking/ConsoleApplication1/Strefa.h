#ifndef STREFA_H
#define STREFA_H

#include "stdafx.h"
#include <vector>
#include "Pojazd.h"
using namespace std;

 class Strefa
{
public:
	 vector<Pojazd> miejscaSamochody; // wektory miejsc dla kazdego z typow
	 vector<Pojazd> miejscaCiezarowki;
	 vector<Pojazd> miejscaMotocykle;
	 void WypelnienieStrefy();
	 void LosujStrefe();
	 int wszysSam, wszysCiez, wszysMot; // liczba wszystkich wylosowanych miejsc danego typu
	 int samochodyZajete, motocykleZajete, ciezarowkiZajete; // liczba miejsc zajetych
	 Strefa();	
};


#endif // !STREFA_H
