#ifndef PARKING_H
#define PARKING_H
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
};

#endif // !PARKING_H

