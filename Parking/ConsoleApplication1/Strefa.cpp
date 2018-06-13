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