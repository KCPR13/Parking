#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pojazd.h"
#include "Parking.h"

using namespace std;

int Dzialania();
int main()
{
	Parking *P = new Parking();
	P->Inicjalizacja();
	while (1)
	{
		int stan = Dzialania();
		if (stan == 1)
		{
			P->StanParkingu();				// funkcja do wypisania stanu parkingu
		}
		else if (stan == 2)
		{
			Pojazd NowyPoj = P->NowyPojazd();
			if (P->Wjazd(NowyPoj))
			{
				// wprowadz pojazd na miejsce
			}
			else cout << "Nie mozesz wjechac na parking!" << endl;
		}
		else if (stan == 3) break;
	} 
	return 0;
}

int Dzialania()
{
	int akcja;
	Wybor:
	cout << "Wybierz jedna z trzech opcji: [1-3]"<< endl;
	cin >> akcja;
	if (akcja != 1 || akcja != 2 || akcja != 3)
	{
		cout << "Nie ma takiej opcji" << endl;
		goto Wybor;
	}
	cout << "1. Wypisanie stanu parkingu" << endl;
	cout << "2. Wjazd nowego pojazdu na parking" << endl;
	cout << "3.zakonczenie programu" << endl;
	return akcja;
}