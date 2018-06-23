#ifndef STREFA_H
#define STREFA_H

#define czyZajacMiejsce 2
#define miejsceWolne 2
#define maxMiejsc 10

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
	 int samochodyZajete, motocykleZajete, ciezarowkiZajete; // liczba miejsc zajetych
	 Strefa();	
};


#endif // !STREFA_H
