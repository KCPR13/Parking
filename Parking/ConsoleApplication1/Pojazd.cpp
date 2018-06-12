#include "stdafx.h"
#include "Pojazd.h"
#include<iostream>
using namespace std;

void Samochod::Wypisz()
{
	cout <<"Typ pojazdu: Samochod "<< "czas postoju: " << czasPostoju << " gotowka: " << gotowka << endl;
}
void Motocykl::Wypisz()
{
	cout << "Typ pojazdu: Motocykl " << "czas postoju: " << czasPostoju << " gotowka: " << gotowka << endl;
}
void Ciezarowka::Wypisz()
{
	cout << "Typ pojazdu: Ciezarowka " << "czas postoju: " << czasPostoju << " gotowka: " << gotowka << endl;
}