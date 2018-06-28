#include "stdafx.h"
#include "Motocykl.h"
#include "defines.h"

Motocykl::Motocykl()
{
	typPojazdu = MOTOCYKL;
	oplata = OPLATA_MOTOCYKL;
	gotowka = Losowanie::Losuj(ILOSC_GOTOWKI);
	czasPostoju = Losowanie::Losuj(MINUTY_POSTOJU) + MIN_CZAS_POSTOJU;
	//Wypisz();
}