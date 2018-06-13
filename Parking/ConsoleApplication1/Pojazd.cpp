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
Samochod::Samochod()
{
	oplata = 15;
	gotowka = Losowanie::Losuj(100);
	czasPostoju = Losowanie::Losuj(100) + 10; // aby nie bylo postoju 0
	Wypisz(); //wypisanie wiadomosci o pojezdzie
}
Ciezarowka::Ciezarowka()
{
	oplata = 20;
	gotowka = Losowanie::Losuj(100);
	czasPostoju = Losowanie::Losuj(100) + 10;
	Wypisz();
}
Motocykl::Motocykl()
{
	oplata = 10;
	gotowka = Losowanie::Losuj(100);
	czasPostoju = Losowanie::Losuj(100) + 10;
	Wypisz();
}
