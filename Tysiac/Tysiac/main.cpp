#include "includes.h"
#include "classes.h"

int main()
{
	srand(time(NULL));

	Plansza plansza;
	if (plansza.sprawdz_plik()) plansza.wczytaj_gre();
	else plansza.nowa_gra();

	plansza.tasuj();
	plansza.rozdaj();
	plansza.licytuj();

	/////////////////////////////////
	if (plansza.get_ilosc_graczy() == 2)
	{
		int temp;
		std::cout << std::endl << "Graczu " << plansza.grajacy + 1 << " wybierz musik (wpisz 1 albo 2): ";
		std::cin >> temp;
		std::cout << "Otrzymales: ";
		plansza.wypisz_musik(temp);
	}

	else
	{
		std::cout << std::endl << "Graczu " << plansza.grajacy + 1 << " w musiku otrzymales: ";
		plansza.wypisz_musik(1);
	}
	///////////////////////////////////
	
	//plansza.zapisz_gre();
	int x;
	std::cin >> x;
	return 0;
}