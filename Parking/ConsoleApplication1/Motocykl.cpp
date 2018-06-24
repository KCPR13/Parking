#include "stdafx.h"
#include "Motocykl.h"

Motocykl::Motocykl()
{
	typPojazdu = 3;
	oplata = 10;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju;
	//Wypisz();
}