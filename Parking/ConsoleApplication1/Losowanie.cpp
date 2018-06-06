#include "stdafx.h"
#include "Losowanie.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Losowanie::Losuj()
{
	 int wylosowanaLiczba;
	 srand(time(NULL));
	 wylosowanaLiczba = rand()%50 + 1;
	 return wylosowanaLiczba;
}
