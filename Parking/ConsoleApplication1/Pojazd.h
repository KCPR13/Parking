#ifndef POJAZD_H
#define POJAZD_H
#include "stdafx.h"
#include "Losowanie.h"

 class Pojazd
{
public:
 int oplata;
int gotowka;
int czasPostoju;
Pojazd() {};
};

 class Samochod : public Pojazd
 {	 
 public:
	 void Wypisz();
	 Samochod()
	 {
		 oplata = 15;
		 gotowka = Losowanie::Losuj(100);
		 czasPostoju = Losowanie::Losuj(100)+10; // aby nie bylo postoju 0
		 Wypisz(); //wypisanie wiadomosci o pojezdzie
	 }
 };
 class Ciezarowka : public Pojazd
 {
 public:
	 void Wypisz();
	 Ciezarowka()
	 {
		 oplata = 20;
		 gotowka = Losowanie::Losuj(100);
		 czasPostoju = Losowanie::Losuj(100)+10;
		 Wypisz();
	 }
 };
 class Motocykl : public Pojazd
 {
 public: 
	 void Wypisz();
	 Motocykl()
	 {
		 oplata = 10;
		 gotowka = Losowanie::Losuj(100);
		 czasPostoju = Losowanie::Losuj(100)+10;
		 Wypisz();
	 }
 };

#endif // !POJAZD_H

