#include "stdafx.h"
#include "Parking.h"
#include <vector>
#include <iostream>
#include "Strefa.h"
#include "Losowanie.h"

using namespace std;
int iloscStref;

void Parking::Inicjalizacja()
{
	iloscStref=Losowanie::Losuj(losujStrefy)+minSterf;
	for (int i = 0; i < iloscStref; i++) //tworzenie nowych stref
	{
		Strefa *S = new Strefa();
		Strefy.push_back(*S);
	}
}
Pojazd Parking::NowyPojazd()
{
	Pojazd P;
	int wylosowanyPojazd = Losowanie::Losuj(typyPojazdow);  //losowanie nowego pojazdu
	if (wylosowanyPojazd == 0) P = Samochod();
	else if (wylosowanyPojazd == 1) P = Ciezarowka();
	else Pojazd P = Motocykl();
	return P;
}
bool Parking::Wjazd(Pojazd &P)
{
		// co 60 minut dodanie oplaty za parking
	if ((Parking::Oplata(P) >= P.gotowka) && P.czasPostoju!=0)//tutaj jeszcze sprawdzenie czy jest wolne miejsce dla danego pojazdu
	{
		P.gotowka -= Parking::Oplata(P); // pobranie oplaty
		return true; // wprowadzenie na miejsce 
	}
	else return false;
}
int Parking::Oplata(Pojazd &P)
{
	int oplata = (P.czasPostoju / godzina)*P.oplata;
	return oplata;
}

void Parking::StanParkingu()
{
	cout << "Ilosc stref: " << iloscStref << endl;
	for (int i = 0; i < iloscStref; i++)
	{
		cout << "Strefa: " << i+1 << endl;
		cout << "Zajetych/wszystkich miejsc dla motocykli: " << Strefy[i].motocykleZajete << "/" << Strefy[i].wszysMot << endl; //tutaj dla kazdego do wypisania liczbe miejsc
		cout << "Zajetych/wszystkich miejsc dla samochodow: " << Strefy[i].samochodyZajete << "/"<<Strefy[i].wszysSam  << endl;
		cout << "Zajetych/wszystkich miejsc dla ciezarowek: " << Strefy[i].ciezarowkiZajete << "/" << Strefy[i].wszysCiez << endl;
	}
}
bool Parking::WolneMiejsce()
{
	return false;
}
