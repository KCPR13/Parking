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
	void Stan();
	int Oplata(Pojazd &P);
	bool WolneMiejsce(Pojazd &P);
	bool CzyPojazdMozeWjechac(Pojazd &P);
	void AktualizacjaCzasuMiejscParkingowych();
	void OpuszczenieParkingu();
	int iloscStref;
	int wolnaStrefaDlaMotocykla, WolnaStrefaDlaCiezarowki, WolnaStrefaDlaSamochodu;
	int wolneMiejsceMot,wolneMiejsceSam,wolneMiejsceCiez;
};

#endif // !PARKING_H

