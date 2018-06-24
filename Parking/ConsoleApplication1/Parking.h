#ifndef PARKING_H
#define PARKING_H

#define losujStrefy 5
#define minSterf 2
#define godzina 60
#define typyPojazdow 3
#define motocykl 3
#define samochod 1
#define ciezarowka 2
#define przedluzeniePostoju 60

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

