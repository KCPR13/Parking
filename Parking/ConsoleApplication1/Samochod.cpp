#include "stdafx.h"
#include "Samochod.h"

Samochod::Samochod()
{
	typPojazdu = 1;
	oplata = 15;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju; // aby nie bylo postoju 0
																	//Wypisz(); //wypisanie wiadomosci o pojezdzie
}