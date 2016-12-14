#include "includes.h"
#include "classes.h"
Plansza::Plansza()
{
	rozdajacy = 0;
	inicjalizuj_karty(); ////// inicjalizuje karty w talii
}


Plansza::~Plansza()
{
	//zamkniecie pliku
	plik.close();
}


int Plansza::get_ilosc_graczy()
{
	return ile_graczy;
}

void Plansza::set_ilosc_graczy(int ilosc)
{
	ile_graczy = ilosc;
}

int Plansza::get_rozdajacy()
{
	return rozdajacy;
}

void Plansza::set_rozdajacy(int id)
{
	rozdajacy = id;
}


int Plansza::get_meldunek()
{
	return meldunek;
}

void Plansza::set_meldunek(int meld)
{
	meldunek = meld;
}


void Plansza::inicjalizuj_karty()
{
	/***
	Karta.id - wskazuje id karty (indexowane od 0)
	Karta.figura - wskazuje na figure karty (od 9 do 14-asa)
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[øo≥πdü], 4-pik[wino] )
	***/
	talia.clear();
	int id = 0;
	Karta kar;
	for (int i = 9; i <= 14; i++)
	{
		kar.id = id;
		kar.figura = i;
		for (int j = 1; j <= 4; j++, id++)
		{
			kar.id = id;
			kar.figura = i;
			kar.kolor = j;
			talia.push_back(kar);
		}
	}
}


void Plansza::tasuj()
{
	int k;
	for (int i = 0; i < talia.size(); i++)
	{
		k = rand() % talia.size();
		std::swap(talia[i], talia[k]);
	}
}


void Plansza::rozdaj()
{
	musik.clear();
	musik_dodatkowy.clear();
	if (ile_graczy >= 3) // na ponad 3 graczy
	{
		for (int i = 0; i <= 2; i++) // rozdanie musika
		{
			musik.push_back(talia[i]);
		}
		for (int i = 3; i < talia.size(); i += 3)
		{
			gracze[0]->karty_w_rece.push_back(talia[i]);
			gracze[1]->karty_w_rece.push_back(talia[i+1]);
			gracze[2]->karty_w_rece.push_back(talia[i + 2]);
		}
	}
	else if (ile_graczy == 2)
	{
		musik.push_back(talia[0]);
		musik.push_back(talia[1]);
		musik_dodatkowy.push_back(talia[2]);
		musik_dodatkowy.push_back(talia[3]);
		for (int i = 4; i < talia.size(); i += 2)
		{
			gracze[0]->karty_w_rece.push_back(talia[i]);
			gracze[1]->karty_w_rece.push_back(talia[i + 1]);
		}
	}
}

bool Plansza::sprawdz_plik()
{
	plik.open("dane_gry.txt", std::ios::in | std::ios::_Nocreate);

	if (!plik.good())
	{
		plik.close();
		return 0;
	}
	else
	{
		plik.close();
		return 1;
	}
}


void Plansza::zapisz_gre() //ustalic na jakiej zasadzie beda zapisy, czy nastepne, czy nadpisujemy
{
	plik.open("dane_gry.txt", std::ios::out);

	if (!plik.good()) //nie udalo sie otworzyc pliku
	{
		std::cout << "NIE UDALO SIE OTWORZYC PLIKU" << std::endl;
	}

	else
	{
		std::cout << "UDALO SIE OTWORZYC PLIK" << std::endl;
	}
	
	
	/************************
	Struktura pliku od zapisu
	1. Data (mm/dd/rr GG:MM:SS)
	2. liczba graczy
	3. opis graczy - id, Typ(0-komputer, 1-czlowiek), nazwa, wynik- w nastpenych wierszach
	4. id gracza rozpoczynajacego nastpene rozdanie (rozdajacy)
	************************/

	/*Ad 1. DATA*/
	char buffer[64];
	time_t my_time;
	tm my_timeTM;

	time(&my_time); //pobranie obecnego czasu
	localtime_s(&my_timeTM, &my_time); //konwersja i zamiana na strefe lokalna
	strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", &my_timeTM); //zapis do stringa
	plik << buffer << std::endl;
	//std::cout << "Save gry z: " << buffer << std::endl; //wypisanie
	
	/*Ad 2,3. LICZBA I OPIS GRACZY*/
	plik<<ile_graczy<<std::endl;
	for (int i = 0; i < ile_graczy; i++)
	{
		if (gracze[i]->typ_gracza == 0) //komputer 
		{
			plik << gracze[i]->id_gracza <<" 0 " << gracze[i]->nazwa << gracze[i]->wynik << std::endl;
		}
		else if (gracze[i]->typ_gracza == 1) //uzytkownik
		{
			plik << gracze[i]->id_gracza << " 1 " << gracze[i]->nazwa << gracze[i]->wynik << std::endl;
		}
	}

	/*Ad 4. ROZDAJACY!*/

	plik.close();
}


void Plansza::wczytaj_gre()
{
	plik.open("dane_gry.txt", std::ios::in );

	if (!plik.good()) //nie udalo sie otworzyc pliku
	{
		std::cout << "NIE UDALO SIE OTWORZYC PLIKU" << std::endl;

	}
	else
	{
		std::cout << "UDALO SIE OTWORZYC PLIK" << std::endl;
	}

	/************************
	Struktura pliku od zapisu
	1. Data (mm/dd/rr GG:MM:SS)
	2. liczba graczy
	3. opis graczy - id, Typ(0-komputer, 1-czlowiek), nazwa - w nastpenych wierszach
	4. id gracza rozpoczynajacego nastpene rozdanie (rozdajacy)
	************************/

	/*Ad 1. DATA*/
	std::string data, godzina;
	plik >> data;
	plik >> godzina;
	data = data + " " + godzina;  // data ostatniego zapisu

	std::cout << "Znaleziono plik zapisu gry z dnia: " << data << std::endl;
	std::cout << "Czy chcesz go wczytac (T/N): ";
	char wybor;
	std::cin >> wybor;

	if (wybor == 'T')
	{
		/*Ad 2. LICZBA GRACZY*/
		std::string ile; // ilosc graczy
		plik >> ile;
		ile_graczy = atoi(ile.c_str());

		/*Ad 3. OPIS GRACZY*/
		std::string id, t, n, w;
		for (int i = 0; i < ile_graczy; i++)
		{
			plik >> id >> t >> n >> w;
			gracze[i]->id_gracza = atoi(id.c_str());
			gracze[i]->typ_gracza = atoi(t.c_str());
			gracze[i]->nazwa = atoi(n.c_str());
			gracze[i]->wynik = atoi(w.c_str());
		}

		/*Ad 4. ROZDAJACY!*/
		std::string r;
		plik >> r; 
		rozdajacy = atoi(r.c_str());
	}

	plik.close();
}

void Plansza::nowa_gra()
{
	std::cout << "Podaj liczbe graczy (od 2 do 4): ";
	std::cin >> ile_graczy;
	std::cout << "Dla kazdego gracza podaj czy ma byc sterowany przez uzytkownika czy komputer (wpisz 'U' lub 'K')" << std::endl;
	char wybor;

	for (int i = 0; i < ile_graczy; i++)
	{
		std::cout << "Gracz " << i + 1 << " : ";
		std::cin >> wybor;

		switch (wybor)
		{
		/*case 'K':
			gracze[i] = &komp[i];
			break;*/

		case 'U':
			gracze[i] = &uzyt[i];
			break;
		}
	}


}

void Plansza::licytuj()
{
	std::cout << std::endl << "LICYTACJA" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "Rozdawal Gracz " << rozdajacy+1 << std::endl;
	int ile_licytuje = ile_graczy;
	int licytowane = 100;

	for (int i = 0; i < ile_graczy; i++) gracze[i]->wylicytowane = 100;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < ile_graczy; j++)
		{
			if (gracze[j]->wylicytowane == 0) continue;

			if (i == 0 && j == 0) j = rozdajacy + 1;

			std::cout << "Gracz " << j + 1 << " : ";
			if (i == 0 && j == rozdajacy + 1) std::cout << "100" << std::endl << std::endl;
			
			else
			{
				std::cout << std::endl;
				gracze[j]->wypisz_talie();
				std::cout << std::endl;
				std::cout << "Twoja kwota: ";
				std::cin >> licytowane;
				std::cout << std::endl;
			}

			gracze[j]->wylicytowane = licytowane;

			if (licytowane == 0) ile_licytuje--;

			if (ile_licytuje == 1)
			{
				for (int k = 0; k < ile_graczy; k++)
				{
					if (gracze[k]->wylicytowane == 0) continue;
					else
					{
						std::cout << "Licytacje wygral Gracz " << k+1 << std::endl;
						std::cout << "Wylicytowal on " << gracze[k]->wylicytowane;
						grajacy = k;
						return;
					}
				}
			}	
		}
	}
}

void Plansza::wypisz_musik(int lp)
{
	switch (lp)
	{
	case 1:
		for (int i = 0; i<musik.size(); i++)
		{
			musik[i].wypisz();
			std::cout << " | ";
		}
		break;

	case 2:
		for (int i = 0; i<musik_dodatkowy.size(); i++)
		{
			musik_dodatkowy[i].wypisz();
			std::cout << " | ";
		}
	}
}