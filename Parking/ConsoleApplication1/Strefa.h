#ifndef STREFA_H
#define STREFA_H

#include "stdafx.h"
#include <vector>
#include "Pojazd.h"
using namespace std;

static class Strefa
{
public:
	static vector<Samochod> miejscaSamochody; // wektorymiejsc dla kazdego z typow
	static vector<Ciezarowka> miejscaCiezarowki;
	static vector<Motocykl> miejscaMotocykle;
	static void WypelnienieStrefy();
	static void LosujStrefe();
	static int wszysSam, wszysCiez, wszysMot; // liczba wszystkich wylosowanych miejsc danego typu
	Strefa();
	
};


#endif // !STREFA_H
