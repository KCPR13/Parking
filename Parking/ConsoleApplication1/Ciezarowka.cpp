#include "stdafx.h"
#include "Ciezarowka.h"
#include "defines.h"

Ciezarowka::Ciezarowka()
{
	typPojazdu = CIEZAROWKA;
	oplata = OPLATA_CIEZAROWKA;
	gotowka = Losowanie::Losuj(ILOSC_GOTOWKI);
	czasPostoju = Losowanie::Losuj(MINUTY_POSTOJU) + MIN_CZAS_POSTOJU;
	//Wypisz();
}