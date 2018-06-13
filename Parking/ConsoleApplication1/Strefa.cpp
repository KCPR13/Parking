#include "stdafx.h"
#include "Pojazd.h"
#include "Strefa.h"

 void Strefa::WypelnienieStrefy()
{
	for (int i = 0; i<Strefa::wszysCiez ; i++)
	{
		int tmp=Losowanie::Losuj(2);
		if (tmp)
		{
			Ciezarowka *C=new Ciezarowka();
			Strefa::miejscaCiezarowki.push_back(*C);
		}
	}
	for (int i = 0; i<Strefa::wszysMot; i++)
	{
		int tmp = Losowanie::Losuj(2);
		if (tmp)
		{
			Motocykl *M= new Motocykl();
			Strefa::miejscaMotocykle.push_back(*M);
		}
	}
	for (int i = 0; i<Strefa::wszysSam; i++)
	{
		int tmp = Losowanie::Losuj(2);
		if (tmp)
		{
			Samochod *S=new Samochod();
			Strefa::miejscaSamochody.push_back(*S);
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
	 miejscaCiezarowki.resize(Strefa::wszysCiez = Losowanie::Losuj(10));
	 miejscaMotocykle.resize(wszysMot = Losowanie::Losuj(10));
	 miejscaSamochody.resize(wszysSam = Losowanie::Losuj(10));
	 if (miejscaCiezarowki.size() == 0 && miejscaMotocykle.size() == 0 && miejscaSamochody.size() == 0) // jesli na parkingu nie bedzie zadnego miejsca
	 {
		 int wolne = Losowanie::Losuj(2);
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