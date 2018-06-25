#include "stdafx.h"
#include "Pojazd.h"
#include "Strefa.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "Ciezarowka.h"
#include <iostream>

using namespace std;

 void Strefa::WypelnienieStrefy()
{
	for (int i = 0; i<Strefa::wszysCiez ; i++)
	{
		int tmp=Losowanie::Losuj(czyZajacMiejsce);
		if (tmp)
		{
			Ciezarowka *C= new Ciezarowka();
			miejscaCiezarowki.insert(miejscaCiezarowki.begin()+i, *C);
			ciezarowkiZajete++;
		}
	}
	for (int i = 0; i<Strefa::wszysMot; i++)
	{
		int tmp = Losowanie::Losuj(czyZajacMiejsce);
		if (tmp)
		{
			Motocykl *M= new Motocykl();
			miejscaMotocykle.insert(miejscaMotocykle.begin() + i, *M);
			motocykleZajete++;
		}
	}
	for (int i = 0; i<Strefa::wszysSam; i++)
	{
		int tmp = Losowanie::Losuj(czyZajacMiejsce);
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
	 LosujStrefe();
	 WypelnienieStrefy();
	 
 }
 void Strefa::LosujStrefe()
 {
	 miejscaCiezarowki.resize(Strefa::wszysCiez = Losowanie::Losuj(maxMiejsc));
	 miejscaMotocykle.resize(wszysMot = Losowanie::Losuj(maxMiejsc));
	 miejscaSamochody.resize(wszysSam = Losowanie::Losuj(maxMiejsc));
	 if (miejscaCiezarowki.size() == 0 && miejscaMotocykle.size() == 0 && miejscaSamochody.size() == 0) // jesli na parkingu nie bedzie zadnego miejsca
	 {
		 int wolne = Losowanie::Losuj(miejsceWolne);
		 if (wolne == 0)
		 {
			 miejscaCiezarowki.resize(1);
			 wszysCiez = 1;
		 }
		 else if (wolne = 1)
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