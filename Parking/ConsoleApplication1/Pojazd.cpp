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




