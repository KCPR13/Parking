#include "stdafx.h"
#include "Samochod.h"
#include "defines.h"

Samochod::Samochod()
{
	typPojazdu = SAMOCHOD;
	oplata = OPLATA_SAMOCHOD;
	gotowka = Losowanie::Losuj(ILOSC_GOTOWKI);
	czasPostoju = Losowanie::Losuj(MINUTY_POSTOJU) + MIN_CZAS_POSTOJU; // aby nie bylo postoju 0
	//Wypisz(); //wypisanie wiadomosci o pojezdzie
}