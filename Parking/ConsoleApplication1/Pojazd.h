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

};

 class Samochod : public Pojazd
 {	 
 public:
	 void Wypisz();
	 Samochod();
 };
 class Ciezarowka : public Pojazd
 {
 public:
	 void Wypisz();
	 Ciezarowka();
 };
 class Motocykl : public Pojazd
 {
 public: 
	 void Wypisz();
	 Motocykl();
 };

#endif // !POJAZD_H

