#ifndef PARKING_H
#define PARKING_H

#define losujStrefy 5
#define minSterf 2
#define godzina 60
#define typyPojazdow 3

#include "stdafx.h"
#include <vector>
#include "Strefa.h"

class Parking
{
public:
	vector<Strefa> Strefy;
	void Inicjalizacja();
	Pojazd NowyPojazd();
	bool Wjazd(Pojazd &P);
	void StanParkingu();
	static int Oplata(Pojazd &P);
	bool WolneMiejsce();
};

#endif // !PARKING_H

