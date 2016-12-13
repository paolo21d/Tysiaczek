#include "includes.h"
#include "classes.h"

int main()
{
	srand(time(NULL));

	Plansza plansza;
	if (plansza.sprawdz_plik()) plansza.wczytaj_gre();
	
	
	//plansza.zapisz_gre();
	int x;
	std::cin >> x;
	return 0;
}