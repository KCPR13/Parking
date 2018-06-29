#include "stdafx.h"
#include "Pojazd.h"
#include "Strefa.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "Ciezarowka.h"
#include "defines.h"
#include <iostream>

using namespace std;

 void Strefa::WypelnienieStrefy()
{
	for (int i = 0; i<wszysCiez ; i++)
	{
		int tmp = Losowanie::Losuj(CZY_ZAJAC_MIEJSCE);
		if (tmp)
		{
			Ciezarowka *C= new Ciezarowka();
			miejscaCiezarowki.insert(miejscaCiezarowki.begin()+i, *C);
			ciezarowkiZajete++;
		}
	}
	for (int i = 0; i<wszysMot; i++)
	{
		int tmp = Losowanie::Losuj(CZY_ZAJAC_MIEJSCE);
		if (tmp)
		{
			Motocykl *M= new Motocykl();
			miejscaMotocykle.insert(miejscaMotocykle.begin() + i, *M);
			motocykleZajete++;
		}
	}
	for (int i = 0; i<wszysSam; i++)
	{
		int tmp = Losowanie::Losuj(CZY_ZAJAC_MIEJSCE);
		if (tmp)
		{
			Samochod *S=new Samochod();
			miejscaSamochody.insert(miejscaSamochody.begin() + i, *S);
			samochodyZajete++;
		}
	}
}
 Strefa::Strefa()
 { 
	 ciezarowkiZajete = 0;
	 motocykleZajete = 0;
	 samochodyZajete = 0;
	 LosujStrefe();
	 WypelnienieStrefy();
	 
 }
 void Strefa::LosujStrefe()
 {
	 miejscaCiezarowki.resize(wszysCiez = Losowanie::Losuj(MAX_MIEJSC));
	 miejscaMotocykle.resize(wszysMot = Losowanie::Losuj(MAX_MIEJSC));
	 miejscaSamochody.resize(wszysSam = Losowanie::Losuj(MAX_MIEJSC));
	 if (miejscaCiezarowki.size() == 0 && miejscaMotocykle.size() == 0 && miejscaSamochody.size() == 0) // jesli na parkingu nie bedzie zadnego miejsca
	 {
		 int wolne = Losowanie::Losuj(MIEJSCE_WOLNE);
		 if (wolne == 0)
		 {
			 miejscaCiezarowki.resize(1);
			 wszysCiez = 1;
		 }
		 else if (wolne == 1) // tutaj byl jeden znak rownosci
		 {
			 miejscaMotocykle.resize(1);
			 wszysMot = 1;
		 }
		 else
		 {
			 miejscaSamochody.resize(1);
			 wszysSam = 1;
		 }
	 }
 }