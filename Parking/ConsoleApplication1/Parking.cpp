#include "stdafx.h"
#include "Parking.h"
#include <vector>
#include <iostream>
#include "Strefa.h"
#include "Losowanie.h"

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
	else cout << "Pojazd nie ma pieniedzy na parking"<< Parking::Oplata(P) << endl;
	if ((Parking::Oplata(P) <= P.gotowka) && Parking::WolneMiejsce(P)) return true;
	else return false;
}

bool Parking::Wjazd(Pojazd &P)
{
		P.gotowka -= Parking::Oplata(P); // pobranie oplaty
		cout << "gotowka po pobraniu: " << P.gotowka << endl;
		if (P.typPojazdu == motocykl)
		{	
			Strefy[wolnaStrefaDlaMotocykla].miejscaMotocykle.push_back(P);
			Strefy[wolnaStrefaDlaMotocykla].motocykleZajete++;
			cout << "Wjezdza motocykl" << endl;
			cout << endl;
			return true;
			
		}
		else if (P.typPojazdu == samochod)
		{
			Strefy[WolnaStrefaDlaSamochodu].miejscaSamochody.push_back(P);
			Strefy[WolnaStrefaDlaSamochodu].samochodyZajete++;
			cout << "Wjezdza samochod" << endl;
			cout << endl;
			return true;
		}
		else if (P.typPojazdu == ciezarowka)
		{
			Strefy[WolnaStrefaDlaCiezarowki].miejscaCiezarowki.push_back(P);
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
		cout << "Strefa: " << i << endl; //numerowanie od 1
		cout << "Zajetych/wszystkich miejsc dla motocykli: " << Strefy[i].motocykleZajete << "/" << Strefy[i].wszysMot << endl;
		cout << "Zajetych/wszystkich miejsc dla samochodow: " << Strefy[i].samochodyZajete << "/"<<Strefy[i].wszysSam  << endl;
		cout << "Zajetych/wszystkich miejsc dla ciezarowek: " << Strefy[i].ciezarowkiZajete << "/" << Strefy[i].wszysCiez << endl;
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
