#include "stdafx.h"
#include "Losowanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Losowanie::Losuj(int przedzial)
{
	 int wylosowanaLiczba;
	 wylosowanaLiczba = rand()%przedzial ;
	 return wylosowanaLiczba;
}
