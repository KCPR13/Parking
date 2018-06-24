#include "stdafx.h"
#include "Ciezarowka.h"

Ciezarowka::Ciezarowka()
{
	typPojazdu = 2;
	oplata = 20;
	gotowka = Losowanie::Losuj(iloscGotowki);
	czasPostoju = Losowanie::Losuj(minutyPostoju) + minCzasPostoju;
	//Wypisz();
}