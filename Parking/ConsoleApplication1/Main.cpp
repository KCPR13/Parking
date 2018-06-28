
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pojazd.h"
#include "Parking.h"
#include "defines.h"
#include "Motocykl.h"
#include "Samochod.h"
#include "Ciezarowka.h"

using namespace std;

int koniec;

void Cennik()
{
	cout << "Oplata za kazda rozpoczeta godzine postoju:" << endl;
	cout << "Motocykl-" <<OPLATA_MOTOCYKL << endl;
	cout << "Samochod-" <<OPLATA_SAMOCHOD << endl;
	cout << "Ciezarowka-"<<OPLATA_CIEZAROWKA << endl;
	cout << endl;
}

int Dzialania()
{
	int akcja;
	cout << "Wybierz jedna z trzech opcji: [1-3]" << endl;
	cout << "1. Wypisanie stanu parkingu" << endl;
	cout << "2. Wjazd nowego pojazdu na parking" << endl;
	cout << "3. Zakonczenie programu" << endl;
	cin >> akcja;
	if (akcja == STAN_PARKINGU || akcja == NOWY_POJAZD || akcja ==KONIEC )
	{
		return akcja;
	}
	else
	{
		cout << "nie ma takiej opcji" << endl;
		koniec = 1;
	}
	return 0;
}

int main()
{
	int czas = 0;
	Cennik();
	srand(time(NULL));
	Parking *parking = new Parking();
	parking->Inicjalizacja();
	while (1)
	{
		parking->OpuszczenieParkingu();
		Pojazd nowyPojazd = parking->NowyPojazd();
		cout << "Czas: " << czas << " min" << endl;
		switch (Dzialania())
		{
		case STAN_PARKINGU:
			parking->Stan();
			break;
		case NOWY_POJAZD:
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
		case KONIEC:
			koniec = 1;
			break;
		default:
			break;		
		}	
		czas += ITERACJA_CZASU;
		parking->AktualizacjaCzasuMiejscParkingowych();
		if (koniec) break;
	}
	return 0;
}



