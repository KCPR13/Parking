#include "stdafx.h"
#include "Parking.h"
#include <vector>
#include <iostream>
#include "Strefa.h"
#include "Losowanie.h"
#include "Samochod.h"
#include "Motocykl.h"
#include "Ciezarowka.h"

using namespace std;



void Parking::Inicjalizacja()
{
	iloscStref=Losowanie::Losuj(losujStrefy)+minSterf;
	for (int i = 0; i < iloscStref; i++) //tworzenie nowych stref
	{
		Strefa *S = new Strefa();
		Strefy.push_back(*S);
	}
}
Pojazd Parking::NowyPojazd()
{
	
	int wylosowanyPojazd = Losowanie::Losuj(typyPojazdow);  //losowanie nowego pojazdu
	if (wylosowanyPojazd == 0)
	{
		Samochod *P =new Samochod();
		P->Wypisz();
		return *P;
	}
	else if (wylosowanyPojazd == 1)
	{
		Ciezarowka *C =new Ciezarowka();
		C->Wypisz();
		return *C;
	}
	else
	{
		Motocykl *M =new Motocykl();
		M->Wypisz();
		return *M;
	}
	
}
bool Parking::CzyPojazdMozeWjechac(Pojazd &P)
{
	if (Parking::WolneMiejsce(P))
	{
		cout << "Jest miejsce dla pojazdu na parkingu" << endl;
	}
	else cout << "nie ma miejsca dla pojazdu na parkingu" << endl;
	if (Parking::Oplata(P) <= P.gotowka)
	{
		cout << "Pojazd ma pieniadze na parking"<< endl;
	}
	else cout << "Pojazd nie ma pieniedzy na parking: "<< Parking::Oplata(P) << endl;
	if ((Parking::Oplata(P) <= P.gotowka) && Parking::WolneMiejsce(P)) return true;
	else return false;
}

bool Parking::Wjazd(Pojazd &P)
{
		
		P.gotowka -= Parking::Oplata(P); // pobranie oplaty
		cout << "gotowka po pobraniu: " << P.gotowka << endl;
		if (P.typPojazdu == motocykl)
		{	
			int wolneMiejsceMot = 0;
			for (int i = 0; i <Strefy[wolnaStrefaDlaMotocykla].wszysMot; i++)
			{
				if (Strefy[wolnaStrefaDlaMotocykla].miejscaMotocykle[i].czasPostoju ==0 ) // tylko w pustych miejscach wektora czas Postoju=0
				{
					wolneMiejsceMot = i;
					break;
				}
				
			} 
			Strefy[wolnaStrefaDlaMotocykla].miejscaMotocykle[wolneMiejsceMot] = P; //wpisywanie obiektu do wolnego miejsca
			Strefy[wolnaStrefaDlaMotocykla].motocykleZajete++; //zwiekszenie liczby miejsc zajetych
			cout << "Wjezdza motocykl" << endl;
			cout << endl;
			return true;
			
		}
		else if (P.typPojazdu == samochod)
		{
			for (int i = 0; i <Strefy[WolnaStrefaDlaSamochodu].wszysSam; i++)
			{
				if (Strefy[WolnaStrefaDlaSamochodu].miejscaSamochody[i].czasPostoju == 0) 
				{
					wolneMiejsceSam = i;
					break;
				}
				
			}
			Strefy[WolnaStrefaDlaSamochodu].miejscaSamochody[wolneMiejsceSam] = P;
			Strefy[WolnaStrefaDlaSamochodu].samochodyZajete++;
			cout << "Wjezdza samochod" << endl;
			cout << endl;
			return true;
		}
		else if (P.typPojazdu == ciezarowka)
		{
			for (int i = 0; i <Strefy[WolnaStrefaDlaCiezarowki].wszysCiez; i++)
			{
				if (Strefy[WolnaStrefaDlaCiezarowki].miejscaCiezarowki[i].czasPostoju == 0) 
				{
					wolneMiejsceCiez = i;
					break;
				}	
			}
			Strefy[WolnaStrefaDlaCiezarowki].miejscaCiezarowki[wolneMiejsceCiez] = P;
			Strefy[WolnaStrefaDlaCiezarowki].ciezarowkiZajete++;
			cout << "Wjezdza ciezarowka" << endl;
			cout << endl;
			return true;
		}
		else return false;
}
int Parking::Oplata(Pojazd &P)
{
	int oplata = ((P.czasPostoju / godzina)+1)*P.oplata;
	return oplata;
}

void Parking::Stan()
{
	cout << "Ilosc stref: " << iloscStref << endl;
	for (int i = 0; i < iloscStref; i++)
	{
		cout << "Strefa: " << i+1 << endl; //numerowanie od 1
		cout << "Zajetych/wszystkich miejsc dla motocykli: " << Strefy[i].motocykleZajete << "/" << Strefy[i].wszysMot << endl;
		cout << "Zajetych/wszystkich miejsc dla samochodow: " << Strefy[i].samochodyZajete << "/"<<Strefy[i].wszysSam  << endl;
		cout << "Zajetych/wszystkich miejsc dla ciezarowek: " << Strefy[i].ciezarowkiZajete << "/" << Strefy[i].wszysCiez << endl;
		cout << "Pozostaly czas dla motocykli: " << endl;
		for (int z = 0; z <Strefy[i].wszysMot; z++)
		{
			cout << z +1 << " miejsce: " << Strefy[i].miejscaMotocykle[z].czasPostoju <<" min" << endl;
		}
		cout << "Pozostaly czas dla samochodow: " << endl;
		for (int z = 0; z <Strefy[i].wszysSam; z++)
		{
			cout << z + 1 << " miejsce: " << Strefy[i].miejscaSamochody[z].czasPostoju << " min" << endl;
		}
		cout << "Pozostaly czas dla ciezarowek: " << endl;
		for (int z = 0; z <Strefy[i].wszysCiez; z++)
		{
			cout << z + 1 << " miejsce: " << Strefy[i].miejscaCiezarowki[z].czasPostoju << " min" << endl;
		}
		cout << endl;
	}
}
bool Parking::WolneMiejsce(Pojazd &P)
{
	for (int i = 0; i < iloscStref; i++)
	{
		if (P.typPojazdu == motocykl)
		{
			if (Strefy[i].motocykleZajete < Strefy[i].wszysMot)
			{
				wolnaStrefaDlaMotocykla = i;
				return true;
			}
		}
		else if (P.typPojazdu == samochod)
		{
			if (Strefy[i].samochodyZajete < Strefy[i].wszysSam)
			{
				WolnaStrefaDlaSamochodu = i;
				return true;
			}
		}
		else if (P.typPojazdu == ciezarowka)
		{
			if (Strefy[i].ciezarowkiZajete < Strefy[i].wszysCiez)
			{
				WolnaStrefaDlaCiezarowki = i;
				return true;
			}
		}	
	} 
	return false;
}
void Parking::AktualizacjaCzasuMiejscParkingowych()
{
	for (int i = 0; i < iloscStref; i++)
	{	
		for (int z = 0; z < Strefy[i].wszysCiez; z++)
		{
			if (Strefy[i].miejscaCiezarowki[z].oplata !=0 ) // aby odejmowac czas tylko od obiektow a nie od pustych miejsc
			{
				Strefy[i].miejscaCiezarowki[z].czasPostoju -= 30;
			}	
		}
		for (int z = 0; z < Strefy[i].wszysMot; z++)
		{
			if (Strefy[i].miejscaMotocykle[z].oplata != 0)
			{
				Strefy[i].miejscaMotocykle[z].czasPostoju -= 30;
			}		
		}
		for (int z = 0; z < Strefy[i].wszysSam; z++)
		{
			if (Strefy[i].miejscaSamochody[z].oplata != 0)
			{
				Strefy[i].miejscaSamochody[z].czasPostoju -= 30;
			}			
		}
	}
}

void Parking::OpuszczenieParkingu()
{
	int UsunAlboZaplac = Losowanie::Losuj(2); // 1 Usun Pojazd 0 pobierz oplate
	for (int i = 0; i < iloscStref; i++)
	{
		for (int z = 0; z < Strefy[i].wszysCiez; z++)
		{
			if (Strefy[i].miejscaCiezarowki[z].czasPostoju < 0)
			{
				if (UsunAlboZaplac)
				{
					Strefy[i].miejscaCiezarowki.erase(Strefy[i].miejscaCiezarowki.begin() + z);
					Strefy[i].ciezarowkiZajete--;
					cout << "Usuwa ciezarowke" << endl;
				}
				else
				{
					if (Strefy[i].miejscaCiezarowki[z].gotowka < Strefy[i].miejscaCiezarowki[z].oplata)
					{
						Strefy[i].miejscaCiezarowki.erase(Strefy[i].miejscaCiezarowki.begin() + z);
						Strefy[i].ciezarowkiZajete--;
						cout << "Usuwa ciezarowke" << endl;
					}
					else
					{
						Strefy[i].miejscaCiezarowki[z].gotowka -= Strefy[i].miejscaCiezarowki[z].oplata;
						Strefy[i].miejscaCiezarowki[z].czasPostoju += przedluzeniePostoju;
						cout << "Doplata ciezarowka" << endl;
					}
				}
			}		
		}

		for (int z = 0; z < Strefy[i].wszysSam; z++)
		{
			if (Strefy[i].miejscaSamochody[z].czasPostoju < 0)
			{
				if (UsunAlboZaplac)
				{
					Strefy[i].miejscaSamochody.erase(Strefy[i].miejscaSamochody.begin() + z);
					Strefy[i].samochodyZajete--;
					cout << "Usuwa samochod" << endl;
				}
				else
				{
					if (Strefy[i].miejscaSamochody[z].gotowka < Strefy[i].miejscaSamochody[z].oplata)
					{
						Strefy[i].miejscaSamochody.erase(Strefy[i].miejscaSamochody.begin() + z);
						Strefy[i].samochodyZajete--;
						cout << "Usuwa samochod" << endl;
					}
					else
					{
						Strefy[i].miejscaSamochody[z].gotowka -= Strefy[i].miejscaSamochody[z].oplata;
						Strefy[i].miejscaSamochody[z].czasPostoju += przedluzeniePostoju;
						cout << "Doplata samochod" << endl;
					}
				}
			}
		}

		for (int z = 0; z < Strefy[i].wszysMot; z++)
		{
			if (Strefy[i].miejscaMotocykle[z].czasPostoju < 0)
			{
				if (UsunAlboZaplac)
				{
					Strefy[i].miejscaMotocykle.erase(Strefy[i].miejscaMotocykle.begin() + z);
					Strefy[i].motocykleZajete--;
					cout << "Usuwa motocykl" << endl;
				}
				else
				{
					if (Strefy[i].miejscaMotocykle[z].gotowka < Strefy[i].miejscaMotocykle[z].oplata)
					{
						Strefy[i].miejscaMotocykle.erase(Strefy[i].miejscaMotocykle.begin() + z);
						Strefy[i].motocykleZajete--;
						cout << "Usuwa motocykl" << endl;
					}
					else
					{
						Strefy[i].miejscaMotocykle[z].gotowka -= Strefy[i].miejscaMotocykle[z].oplata;
						Strefy[i].miejscaMotocykle[z].czasPostoju += przedluzeniePostoju;
						cout << "Doplata motocykl" << endl;
					}
				}
			}
		}
	}	
}
