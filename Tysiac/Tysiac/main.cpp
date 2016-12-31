#include "includes.h"
#include "classes.h"

int main()
{
	srand(time(NULL));

	Plansza plansza;
	if (plansza.sprawdz_plik()) plansza.wczytaj_gre();
	else plansza.nowa_gra();

	while (true)
	{
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

		std::vector <int> id_oddane;
		for (int i = 0; i < plansza.get_ilosc_graczy(); i++)
		{
			if (i != plansza.id_grajacy)
			{
				if (plansza.get_ilosc_graczy() == 4 && i == plansza.get_id_rozdajacy()) continue;
				else
				{
					int do_oddania = 0;
					std::cout << "Dla Gracza " << i + 1 << " : ";
					std::cin >> do_oddania;
					for (int j = 0; j < id_oddane.size(); j++)
					{
						if (do_oddania > id_oddane[j]) do_oddania++;
					}
					id_oddane.push_back(do_oddania);
					plansza.oddaj_karte(plansza.id_grajacy, i, do_oddania);
				}
			}
		}
		plansza.wypisz_karty_gracza(plansza.id_grajacy);
		std::cout << std::endl << "Mozesz teraz zwiekszyc wylicytowana kwote." << std::endl;
		std::cout << "Jesli nie chcesz tego robic, wpisz ponownie ta sama kwote. " << std::endl;
		std::cout << "Jesli chcesz zagrac bombe wpisz '0'." << std::endl;
		std::cout << "Twoja decyzja (wylicytowales " << plansza.wylicytowane << "): ";
		int kwota;
		std::cin >> kwota;
		if (kwota != 0) plansza.wylicytowane = kwota;
		//else bomba
		system("cls");
		plansza.rozegraj_partie();

		if (plansza.get_id_rozdajacy() < plansza.get_ilosc_graczy() - 1) plansza.set_id_rozdajacy(plansza.get_id_rozdajacy ()+ 1);
		else (plansza.set_id_rozdajacy(0));
		plansza.zapisz_gre();
		plansza.nowa_kolejka(plansza.get_id_rozdajacy());

		std::cout << "WYNIKI" << std::endl;
		std::cout << "------------------" << std::endl;

		int id_prowadzacy;
		int punkty_prowadzacego = -1;

		for (int i = 0; i < plansza.get_ilosc_graczy(); i++)
		{
			std::cout << "Gracz " << i + 1 << " : " << plansza.punkty_gracza[i] << std::endl;
			if (plansza.punkty_gracza[i] > punkty_prowadzacego)
			{
				punkty_prowadzacego = plansza.punkty_gracza[i];
				id_prowadzacy = i;
			}
		}
		std::cout << std::endl;
		if (punkty_prowadzacego >= 1000)
		{
			std::cout << "Gratulacje Graczu " << id_prowadzacy + 1 << "!!!" << std::endl;
			std::cout << "Wygralas/les zdobywajac " << punkty_prowadzacego << " punktow!!!" << std::endl;
			std::cout << std::endl << "Dziekujemy za gre.";
			system("pause");
			break;
		}
	}
	///////////////////////////////////
	
	//plansza.zapisz_gre();
	//int x;
	//std::cin >> x;
	return 0;
}