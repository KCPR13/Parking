#ifndef POJAZD_H
#define POJAZD_H

#define samochod 1
#define ciezarowka 2
#define motocykl 3
#define iloscGotowki 100
#define minutyPostoju 100
#define minCzasPostoju 10

#include "stdafx.h"
#include "Losowanie.h"

 class Pojazd
{
public:
int oplata;
int gotowka;
int czasPostoju;
int typPojazdu;
void Wypisz();
};

#endif // !POJAZD_H

