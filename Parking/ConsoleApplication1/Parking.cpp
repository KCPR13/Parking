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
	iloscStref=Losowanie::Losuj(5)+2;
	for (int i = 0; i < iloscStref; i++) //tworzenie nowych stref
	{
		Strefy.push_back(Strefa());
	}
}
Pojazd Parking::NowyPojazd()
{
	Pojazd P;
	int wylosowanyPojazd = Losowanie::Losuj(3);  //losowanie nowego pojazdu
	if (wylosowanyPojazd == 0) P = Samochod();
	else if (wylosowanyPojazd == 1) P = Ciezarowka();
	else Pojazd P = Motocykl();
	return P;
}
bool Parking::Wjazd(Pojazd &P)
{
	if ((P.czasPostoju % 60)*P.oplata >= P.gotowka)//tutaj jeszcze sprawdzenie czy jest wolne miejsce dla danego pojazdu
	{
		P.gotowka -= (P.czasPostoju % 60)*P.oplata; // pobranie oplaty
		return true; // wprowadzenie na miejsce 
	}
	else return false;
	return false;
}
void Parking::StanParkingu()
{
	cout << "Ilosc stref: " << iloscStref << endl;
	for (int i = 0; i < iloscStref; i++)
	{
		cout << "Strefa: " << i << endl;
		cout << "Wszystkich/wolnych miejsc dla motocykli: " << endl; //tutaj dla kazdego do wypisania liczbe miejsc
		cout << "Wszystkich/wolnych miejsc dla samochodow: " << endl;
		cout << "Wszystkich/wolnych miejsc dla ciezarowek: " << endl;
	}
}