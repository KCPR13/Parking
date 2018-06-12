#ifndef STREFA
#define STREFA

#include "stdafx.h"
#include <vector>
#include "Pojazd.h"

using namespace std;

static class Strefa
{
public:
	static vector<Samochod> miejscaSamochody; // wektorymiejsc dla kazdego z typow
	static vector<Ciezarowka> miejscaCiezarowki;
	static vector<Motocykl> miejscaMotocykle;
	static void WypelnienieStrefy();
	static int WszysSam, WszysCiez, WszysMot; // liczba wylosowanych miejsc danego typu

	Strefa()
	{

		miejscaCiezarowki.resize(WszysCiez=Losowanie::Losuj(10));
		miejscaMotocykle.resize(WszysMot=Losowanie::Losuj(10));
		miejscaSamochody.resize(WszysSam=Losowanie::Losuj(10));
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
};


#endif // !STREFA
