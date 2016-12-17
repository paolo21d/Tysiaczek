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
		std::cout << std::endl << "Graczu " << plansza.id_grajacy + 1 << " wybierz musik (wpisz 1 albo 2): ";
		std::cin >> temp;
		std::cout << "Otrzymales: ";
		plansza.zabierz_musik(temp);
		plansza.wypisz_musik(temp);
	}

	else
	{
		std::cout << std::endl << "Graczu " << plansza.id_grajacy + 1 << " w musiku otrzymales: ";
		plansza.zabierz_musik(1);
		plansza.wypisz_musik(1);
	}

	std::cout << std::endl;
	plansza.nowa_kolejka();
	plansza.wypisz_karty_gracza(plansza.id_grajacy);
	std::cout << std::endl << "Graczu " << plansza.id_grajacy + 1 << " wybierz, ktore karty chcesz przekazac poszczegolnym Graczom (wpisz jej pozycje od lewej)" << std::endl;
	
	for(int i = 0; i < plansza.get_ilosc_graczy(); i++)
	{
		if (i != plansza.id_grajacy)
		{
			int do_oddania = 0;
			std::cout << "Dla Gracza " << i + 1 << " : ";
			std::cin >> do_oddania;
			plansza.oddaj_karte(plansza.id_grajacy, i, do_oddania);
		}
	}
	plansza.wypisz_karty_gracza(plansza.id_grajacy);
	std::cout << std::endl << "Mozesz teraz zwiekszyc wylicytowana kwote." << std::endl;
	std::cout <<"Jesli nie chcesz tego robic, wpisz ponownie ta sama kwote. " << std::endl;
	std::cout << "Jesli chcesz zagrac bombe wpisz '0'." << std::endl;
	std::cout << "Twoja decyzja (wylicytowales " << plansza.wylicytowane << "): ";
	int kwota;
	std::cin >> kwota;

	///////////////////////////////////
	
	//plansza.zapisz_gre();
	int x;
	std::cin >> x;
	return 0;
}