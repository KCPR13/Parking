#include "stdafx.h"
#include "Pojazd.h"
#include<iostream>
#include "defines.h"
using namespace std;

void Pojazd::Wypisz()
{
	cout << "gotowka: " << gotowka << " czas: " << czasPostoju <<" typ: ";
	if (typPojazdu == SAMOCHOD) cout << "Samochod" << endl;
	else if(typPojazdu== CIEZAROWKA)
	{
		cout << "Ciezarowka" << endl;
	}
	else if (typPojazdu == MOTOCYKL)
	{
		cout << "Motocykl" << endl;
	}
	else cout << "Error" << endl;
	cout << endl;
}




