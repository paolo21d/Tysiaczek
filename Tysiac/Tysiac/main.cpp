#include "includes.h"
#include "classes.h"

int main()
{
	srand(time(NULL));

	Plansza plansza;
	if (plansza.sprawdz_plik()) plansza.wczytaj_gre();
	else
	{
		std::cout << "Podaj liczbe graczy (od 2 do 4): ";
		int temp;
		std::cin >> temp;
		plansza.set_ilosc_graczy(temp);
	}

	plansza.licytuj();

	
	//plansza.zapisz_gre();
	int x;
	std::cin >> x;
	return 0;
}