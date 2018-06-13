#include "stdafx.h"
#include "Pojazd.h"
#include "Strefa.h"

 void Strefa::WypelnienieStrefy()
{
	for (int i = 0; i<Strefa::WszysCiez ; i++)
	{
		int tmp=Losowanie::Losuj(2);
		if (tmp)
		{
			Ciezarowka *C=new Ciezarowka();
			Strefa::miejscaCiezarowki.push_back(*C);
		}
	}
	for (int i = 0; i<Strefa::WszysMot; i++)
	{
		int tmp = Losowanie::Losuj(2);
		if (tmp)
		{
			Motocykl *M= new Motocykl();
			Strefa::miejscaMotocykle.push_back(*M);
		}
	}
	for (int i = 0; i<Strefa::WszysSam; i++)
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
	 miejscaCiezarowki.resize(WszysCiez = Losowanie::Losuj(10));
	 miejscaMotocykle.resize(WszysMot = Losowanie::Losuj(10));
	 miejscaSamochody.resize(WszysSam = Losowanie::Losuj(10));
	 if (miejscaCiezarowki.size() == 0 && miejscaMotocykle.size() == 0 && miejscaSamochody.size() == 0) // jesli na parkingu nie bedzie zadnego miejsca
	 {
		 int jedyneWolne = Losowanie::Losuj(2);
		 if (jedyneWolne == 0)
		 {
			 miejscaCiezarowki.resize(1);
			 WszysCiez = 1;
		 }
		 else if (jedyneWolne = 1)
		 {
			 miejscaMotocykle.resize(1);
			 WszysMot = 1;
		 }
		 else
		 {
			 miejscaSamochody.resize(1);
			 WszysSam = 1;
		 }
		 WypelnienieStrefy();
	 }
 }