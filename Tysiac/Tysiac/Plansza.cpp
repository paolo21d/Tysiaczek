#include "includes.h"
#include "classes.h"
Plansza::Plansza()
{
	id_rozdajacy = 0;
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

int Plansza::get_id_rozdajacy()
{
	return id_rozdajacy;
}

void Plansza::set_id_rozdajacy(int id)
{
	id_rozdajacy = id;
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
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[�o��d�], 4-pik[wino] )
	***/
	talia.clear();
	int id = 0;
	Karta kar;
	for (int i = 9; i <= 13; i++) // nadanie 9, J, D, K
	{
		if (i == 10) continue;
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
	for (int j = 1; j <= 4; j++, id++) // nadanie 10
	{
		kar.id = id;
		kar.figura = 10;
		kar.kolor = j;
		talia.push_back(kar);
	}
	for (int j = 1; j <= 4; j++, id++) // nadanie Asa
	{
		kar.id = id;
		kar.figura = 14;
		kar.kolor = j;
		talia.push_back(kar);
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
	if (ile_graczy == 4) //4 graczy
	{
		for (int i = 0; i <= 2; i++) // rozdanie musika
		{
			musik.push_back(talia[i]);
		}
		if (id_rozdajacy == 0) // nie dostaje gracz 0
		{
			for (int i = 3; i < talia.size(); i += 3)
			{
				gracze[1]->karty_w_rece.push_back(talia[i]);
				gracze[2]->karty_w_rece.push_back(talia[i + 1]);
				gracze[3]->karty_w_rece.push_back(talia[i + 2]);
			}
			gracze[1]->sortuj_karty();
			gracze[2]->sortuj_karty();
			gracze[3]->sortuj_karty();
		}
		if (id_rozdajacy == 1) // nie dostaje gracz 1
		{
			for (int i = 3; i < talia.size(); i += 3)
			{
				gracze[0]->karty_w_rece.push_back(talia[i]);
				gracze[2]->karty_w_rece.push_back(talia[i + 1]);
				gracze[3]->karty_w_rece.push_back(talia[i + 2]);
			}
			gracze[0]->sortuj_karty();
			gracze[2]->sortuj_karty();
			gracze[3]->sortuj_karty();
		}
		if (id_rozdajacy == 2) // nie dostaje gracz 2
		{
			for (int i = 3; i < talia.size(); i += 3)
			{
				gracze[0]->karty_w_rece.push_back(talia[i]);
				gracze[1]->karty_w_rece.push_back(talia[i + 1]);
				gracze[3]->karty_w_rece.push_back(talia[i + 2]);
			}
			gracze[0]->sortuj_karty();
			gracze[1]->sortuj_karty();
			gracze[3]->sortuj_karty();
		}
		if (id_rozdajacy == 3) // nie dostaje gracz 3
		{
			for (int i = 3; i < talia.size(); i += 3)
			{
				gracze[0]->karty_w_rece.push_back(talia[i]);
				gracze[1]->karty_w_rece.push_back(talia[i + 1]);
				gracze[2]->karty_w_rece.push_back(talia[i + 2]);
			}
			gracze[0]->sortuj_karty();
			gracze[1]->sortuj_karty();
			gracze[2]->sortuj_karty();
		}
		
	}
	if (ile_graczy == 3) //3 graczy
	{
		for (int i = 0; i <= 2; i++) // rozdanie musika
		{
			musik.push_back(talia[i]);
		}
		for (int i = 3; i < talia.size(); i += 3)
		{
			gracze[0]->karty_w_rece.push_back(talia[i]);
			gracze[1]->karty_w_rece.push_back(talia[i + 1]);
			gracze[2]->karty_w_rece.push_back(talia[i + 2]);
		}
		gracze[0]->sortuj_karty();
		gracze[1]->sortuj_karty();
		gracze[2]->sortuj_karty();
	}
	else if (ile_graczy == 2) //2 graczy
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
		gracze[0]->sortuj_karty();
		gracze[1]->sortuj_karty();
	}
	///////////////////////////psuje tutaj!!!!!
	//gracze[0]->sortuj_karty();
	//gracze[1]->sortuj_karty();
	//gracze[2]->sortuj_karty();
	//gracze[3]->sortuj_karty();
}

void Plansza::wypisz_karty(std::vector <Karta> karty)
{
	for (int i = 0; i < karty.size(); i++)
	{
		karty[i].wypisz();
		std::cout << " | ";
		if (i == 0)
		{
			HANDLE hOut;
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hOut, 0x0007);
		}
	}
}

void Plansza::sprawdz_meldunek(int id_gracza, int pozycja_karty)
{
	for (int i = 0; i < gracze[id_gracza]->karty_w_rece.size(); i++)
	{
		if (gracze[id_gracza]->karty_w_rece[pozycja_karty-1].figura == 12)
		{
			if (gracze[id_gracza]->karty_w_rece[i].id == gracze[id_gracza]->karty_w_rece[pozycja_karty - 1].id + 1)
			{
				set_meldunek(gracze[id_gracza]->karty_w_rece[pozycja_karty - 1].kolor);
				gracze[id_gracza]->punkty_w_partii += 120 - 20 * meldunek;
				return;
			}
		}
		else return;
	}
}

int Plansza::podlicz_punkty(std::vector<Karta> karty)
{
	int punkty = 0;

	for (int i = 0; i < karty.size(); i++)
	{
		switch (karty[i].figura)
		{
		case 9:
			break;
		case 10:
			punkty += 10;
			break;
		case 11:
			punkty += 2;
			break;
		case 12:
			punkty += 3;
			break;
		case 13:
			punkty += 4;
			break;
		case 14:
			punkty += 11;
			break;
		}
	}

	return punkty;
}


void Plansza::nowa_kolejka()
{
	for (int k = 0; k < 2; k++)
	{
		std::cout << "Graczu, odejdz od komputera, za " << 10 - k * 2 << " sekund zacznie sie kolejka Gracza " << id_grajacy + 1 << "!";
		Sleep(2000 + k * 8000);
		system("cls");
	}
}

void Plansza::nowa_kolejka(int id_gracza)
{
	for (int k = 0; k < 2; k++)
	{
		std::cout << "Graczu, odejdz od komputera, za " << 10 - k * 2 << " sekund zacznie sie kolejka Gracza "<<id_gracza+1<<"!";
		Sleep(2000 + k * 8000);
		system("cls");
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
	4. id gracza rozpoczynajacego nastpene rozdanie (id_rozdajacy)
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

	/*Ad 4. id_rozdajacy!*/

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
	4. id gracza rozpoczynajacego nastpene rozdanie (id_rozdajacy)
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

		/*Ad 4. id_rozdajacy!*/
		std::string r;
		plik >> r; 
		id_rozdajacy = atoi(r.c_str());
	}

	plik.close();
}

void Plansza::nowa_gra()
{
	std::cout << "Podaj liczbe graczy (od 2 do 4): ";
	std::cin >> ile_graczy;
	for (int i = 0; i < ile_graczy; i++) punkty_gracza.push_back(0);

	std::cout << "Dla kazdego gracza podaj czy ma byc sterowany przez uzytkownika czy komputer (wpisz 'U' lub 'K')" << std::endl;
	char wybor;

	for (int i = 0; i < ile_graczy; i++)
	{
		std::cout << "Gracz " << i + 1 << " : ";
		std::cin >> wybor;
		wybor = toupper(wybor);
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
	/*std::cout << std::endl << "LICYTACJA" << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "Rozdawal Gracz " << id_rozdajacy + 1 << std::endl << std::endl;
	*/
	int ile_licytuje = ile_graczy;
	int licytowane = 100;
	int prog = 100;

	for (int i = 0; i < ile_graczy; i++) gracze[i]->wylicytowane = 100;

	if (ile_graczy == 4)
	{
		ile_licytuje--;
		gracze[id_rozdajacy]->wylicytowane = 0;
		gracze[id_rozdajacy]->licytowal = true;
	}

	std::cout << std::endl;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < ile_graczy; j++)
		{
			
			if (gracze[j]->wylicytowane != 0)
			{
				std::cout << "LICYTACJA" << std::endl;
				std::cout << "------------------" << std::endl;
				std::cout << "Rozdawal Gracz " << id_rozdajacy + 1 << std::endl;
				for (int k = 0; k < ile_graczy; k++)
				{
					std::cout << "Gracz " << k + 1 << " : ";
					if (!gracze[k]->licytowal) std::cout << "-" << std::endl;
					else if (ile_graczy == 4 && k == id_rozdajacy) std::cout << "-" << std::endl;
					else
					{
						std::cout << gracze[k]->wylicytowane;
						if (gracze[k]->wylicytowane == 0) std::cout << " (pas)";
						std::cout << std::endl;
					}
				}
			}


			if (gracze[j]->wylicytowane == 0) continue;

			if (i == 0 && j == 0) j = id_rozdajacy + 1;


			std::cout << std::endl << "Gracz " << j + 1 << " : " << std::endl;
			
			
			//if (i == 0 && j == id_rozdajacy + 1) std::cout << "100" << std::endl << std::endl;
			if (i != 0 || j != id_rozdajacy + 1)
			{
				gracze[j]->wypisz_talie();
				std::cout << std::endl;
				std::cout << "Twoja kwota (min " << prog + 10 << "):";
				std::cin >> licytowane;
				std::cout << std::endl;
			}

			if (licytowane >= prog) prog = licytowane;
			gracze[j]->wylicytowane = licytowane;
			gracze[j]->licytowal = true;
			if (licytowane == 0) ile_licytuje--;		
			
			if (ile_licytuje == 1)
			{
				for (int k = 0; k < ile_graczy; k++)
				{
					if (gracze[k]->wylicytowane == 0) continue;
					else
					{
						system("cls");
						std::cout << "Licytacje wygral Gracz " << k+1 << std::endl;
						std::cout << "Wylicytowal on " << gracze[k]->wylicytowane;
						id_grajacy = k;
						wylicytowane = gracze[k]->wylicytowane;
						return;
					}
				}
			}


			int id_nastepny = j + 1;
			while (id_nastepny >= ile_graczy || gracze[id_nastepny]->wylicytowane == 0)
			{
					if (id_nastepny >= ile_graczy) id_nastepny = 0;
					else if (gracze[id_nastepny]->licytowal == false) break;
					else id_nastepny++;
			}
			nowa_kolejka(id_nastepny);
		}
	}
}


void Plansza::rozegraj_partie()
{
	int ile_kolejek;
	if (ile_graczy == 2) ile_kolejek = 11;
	else ile_kolejek = 8;

	int ile_gra = ile_graczy;
	if (ile_graczy == 4)
	{
		ile_gra--;
		for (int i = 0; i < musik.size(); i++)
		{
			if (musik[i].figura == 14) gracze[id_rozdajacy]->wynik += 50;
			if (musik[i].figura == 12)
			{
				for (int j = 0; j < musik.size(); j++)
				{
					if (musik[j].id == musik[i].id + 1) gracze[id_rozdajacy]->wynik += 120 - 20 * musik[j].kolor;
				}
			}
		}
	}

	int id_schodzacy = id_grajacy;

	for (int i = 0; i < ile_kolejek; i++)
	{	
		for (int j = 0; j < ile_gra; j++)
		{
			std::cout << "GRA" << std::endl;
			std::cout << "------------------" << std::endl;
			if (j != 0)
			{
				std::cout << "Na stole leza: ";
				
				HANDLE hOut;
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				
				wypisz_karty(wylozone);
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Zebrales w poprzedniej partii: ";
				wypisz_karty(wylozone);
				wylozone.erase(wylozone.begin(), wylozone.end());
				std::cout << std::endl;
			}
			gracze[id_schodzacy]->wypisz_talie();
			std::cout << std::endl << "Graczu " << id_schodzacy + 1 << " wybierz, ktora karte chcesz zagrac (wpisz jej pozycje od lewej): ";
			int poz;
			std::cin >> poz;
			if (j == 0) sprawdz_meldunek(id_schodzacy, poz);
			wylozone.push_back(gracze[id_schodzacy]->karty_w_rece[poz - 1]);
			usun_karte(id_schodzacy, poz);

			if (j == 0)
			{
				prowadzacy.first = id_schodzacy;
				prowadzacy.second = wylozone[0];
			}

			if (prowadzacy.second.kolor == wylozone.back().kolor)
			{
				if (prowadzacy.second.id < wylozone.back().id)
				{
					prowadzacy.first = id_schodzacy;
					prowadzacy.second = wylozone.back();
				}
			}
			else if (meldunek >= 1 && meldunek <= 4 && wylozone.back().kolor == meldunek)
			{
				prowadzacy.first = id_schodzacy;
				prowadzacy.second = wylozone.back();
			}

			if (j == ile_gra - 1)
			{
				std::cout << "Kolejke wygral Gracz " << prowadzacy.first + 1 << std::endl;
				gracze[prowadzacy.first]->punkty_w_partii += podlicz_punkty(wylozone);
				id_schodzacy = prowadzacy.first;
				nowa_kolejka(id_schodzacy);
				continue;
			}

			id_schodzacy++;
			if (id_schodzacy >= ile_graczy) id_schodzacy = 0;
			if (ile_graczy == 4 && id_schodzacy == id_rozdajacy) id_schodzacy++;
			if (id_schodzacy >= ile_graczy) id_schodzacy = 0;


			nowa_kolejka(id_schodzacy);
		}
	}

	
	for (int i = 0; i < ile_graczy; i++)
	{
		gracze[i]->punkty_w_partii += 5;
		gracze[i]->punkty_w_partii /= 10;
		gracze[i]->punkty_w_partii *= 10;

		if (i == id_grajacy)
		{
			if (gracze[i]->punkty_w_partii < wylicytowane) gracze[i]->punkty_w_partii = - wylicytowane;
			gracze[i]->wynik += gracze[i]->punkty_w_partii;
		}
		else if (gracze[i]->wynik<900) gracze[i]->wynik += gracze[i]->punkty_w_partii;
		gracze[i]->punkty_w_partii = 0;
		punkty_gracza[i] = gracze[i]->wynik;
	}

	system ("cls");
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

void Plansza::zabierz_musik(int lp = 1)
{
	switch (lp)
	{
	case 1:
		dodaj_karte(id_grajacy, musik);
		break;


	case 2:
		dodaj_karte(id_grajacy, musik_dodatkowy);
		break;
	}
}

void Plansza::wypisz_karty_gracza(int id_gracza)
{
	gracze[id_gracza]->wypisz_talie();
}


void Plansza::dodaj_karte(int id_gracza, Karta karta)
{
	gracze[id_gracza]->karty_w_rece.push_back(karta);
	gracze[id_gracza]->sortuj_karty();
}

void Plansza::dodaj_karte(int id_gracza, std::vector <Karta> karty)
{
	for (int i = 0; i < karty.size(); i++)
	{
		gracze[id_gracza]->karty_w_rece.push_back(karty[i]);
	}

	gracze[id_gracza]->sortuj_karty();
}

void Plansza::usun_karte(int id_gracza, Karta karta)
{
	for (int i = 0; i < gracze[id_gracza]->karty_w_rece.size(); i++)
	{
		if (gracze[id_gracza]->karty_w_rece[i].id == karta.id)
		{
			gracze[id_gracza]->karty_w_rece.erase(gracze[id_gracza]->karty_w_rece.begin() + i);
		}
	}
}

void Plansza::usun_karte(int id_gracza, int poz_karty)
{
	std::vector <Karta> temp;
	gracze[id_gracza]->karty_w_rece.erase(gracze[id_gracza]->karty_w_rece.begin()+poz_karty-1);
}

void Plansza::oddaj_karte(int id_gracza1, int id_gracza2, Karta karta)
{
	dodaj_karte(id_gracza2, karta);
	usun_karte(id_gracza1, karta);
}

void Plansza::oddaj_karte(int id_gracza1, int id_gracza2, int poz_karty)
{
	Karta karta = gracze[id_gracza1]->karty_w_rece[poz_karty - 1];
	
	dodaj_karte(id_gracza2, karta);
	usun_karte(id_gracza1, poz_karty);
}