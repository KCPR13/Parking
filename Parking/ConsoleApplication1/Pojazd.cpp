#include "stdafx.h"
#include "Pojazd.h"
#include<iostream>
using namespace std;

void Pojazd::Wypisz()
{
	cout << "gotowka: " << gotowka << " czas: " << czasPostoju <<" typ: ";
	if (typPojazdu == samochod) cout << "Samochod" << endl;
	else if(typPojazdu== ciezarowka)
	{
		cout << "Ciezarowka" << endl;
	}
	else if (typPojazdu == motocykl)
	{
		cout << "Motocykl" << endl;
	}
	else cout << "Error" << endl;
	cout << endl;
}

Samochod::Samochod()
{
	typPojazdu = 1;
	oplata = 15;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju; // aby nie bylo postoju 0
	//Wypisz(); //wypisanie wiadomosci o pojezdzie
}
Ciezarowka::Ciezarowka()
{
	typPojazdu = 2;
	oplata = 20;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju;
	//Wypisz();
}
Motocykl::Motocykl()
{
	typPojazdu = 3;
	oplata = 10;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju;
	//Wypisz();
}
