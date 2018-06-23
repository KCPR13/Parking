#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pojazd.h"
#include "Parking.h"

using namespace std;

void Cennik()
{
	cout << "Oplata za kazda rozpoczeta godzine postoju:" << endl;
	cout << "Motocykl-10" << endl;
	cout << "Samochod-15" << endl;
	cout << "Ciezarowka-20" << endl;
	cout << endl;
}
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

int main()
{
	Cennik();
	srand(time(NULL));
	Parking *parking = new Parking();
	parking->Inicjalizacja();
	while (1)
	{
		switch (Dzialania())
		{
		case 1:
			parking->Stan();
			break;
		case 2:
			Pojazd nowyPojazd = parking->NowyPojazd();
			if (parking->CzyPojazdMozeWjechac(nowyPojazd))
			{
				parking->Wjazd(nowyPojazd);
			}
			else
			{
				cout << "Nie mozesz wjechac na parking!" << endl;
				cout << endl;
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



