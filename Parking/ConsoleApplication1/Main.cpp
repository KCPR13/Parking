#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pojazd.h"
#include "Parking.h"

using namespace std;

int Dzialania()
{
Wybor:
	int akcja;
	cout << "Wybierz jedna z trzech opcji: [1-3]" << endl;
	cout << "1. Wypisanie stanu parkingu" << endl;
	cout << "2. Wjazd nowego pojazdu na parking" << endl;
	cout << "3. Zakonczenie programu" << endl;
	cin >> akcja;
	if (akcja == 1 || akcja == 2 || akcja == 3)
	{
		return akcja;
	}
	else
	{
		cout << "nie ma takiej opcji" << endl;
		goto Wybor;
	}
	return 0;
}

Pojazd NowyPojazd(Parking *P)
{
	Pojazd NowyPoj = P->NowyPojazd();
	return NowyPoj;
}

int main()
{
	srand(time(NULL));
	Parking *P = new Parking();
	P->Inicjalizacja();
	while (1)
	{
		int stan = Dzialania();
		switch (stan)
		{
		case 1:
			P->StanParkingu();
			break;
		case 2:
			
			if (P->Wjazd(NowyPojazd(P)))
			{
				// wprowadz pojazd na miejsce
			}
			else
			{
				cout << "Nie mozesz wjechac na parking!" << endl;
			}
			break;
		case 3:
			goto Koniec;
			break;
		default:
			break;
		}		
	}
	Koniec:
	return 0;
}



