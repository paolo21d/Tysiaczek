#include "includes.h"
#include "classes.h"
Plansza::Plansza()
{
	//otworzenie pliku z zapisami
	plik.open("dane_gry.txt", std::ios::in | std::ios::out);
	if (!plik.good()) //nie udalo sie otworzyc pliku
	{
		std::cout << "NIE UDALO SIE OTWORZYC PLIKU" <<std::endl;

	}
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
int Plansza::get_meldunek()
{
	return meldunek;
}
void Plansza::tasuj(std::vector <Karta> t) // jeszcze jakis zwrocic ta potasowana talie
{
	int k;
	for (int i = 0; i < t.size(); i++)
	{
		k = rand() % t.size();
		std::swap(t[i], t[k]);
	}
	//return t;
}
void Plansza::rozdaj(int ile)
{

}
void Plansza::zapisz_gre() //ustalic na jakiej zasadzie beda zapisy, czy nastepne, czy nadpisujemy
{
	/************************
	Struktura pliku od zapisu
	1. Data
	2. liczba graczy
	3. opis graczy - id, Typ(U-uzytkownik/K-komputer), nazwa - w nastpenych wierszach
	4. id gracza rozpoczynajacego nastpene rozdanie (rozdajacy)
	************************/


	/*Ad 1. DATA*/
	char buffer[64];
	time_t my_time;
	tm my_timeTM;

	time(&my_time); //pobranie obecnego czasu
	localtime_s(&my_timeTM, &my_time); //konwersja i zamiana na strefe lokalna
	strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", &my_timeTM); //zapis do stringa

	std::cout << "Save gry z: " << buffer << std::endl; //wypisanie
	


	/*Ad 3. OPIS GRACZY*/

	plik << ile_graczy<<std::endl;
	for (int i = 0; i < ile_graczy; i++)
	{
		if (gracze[i]->typ_gracza == 0) //komputer 
		{
			plik << gracze[i]->id_gracza <<" K " << gracze[i]->nazwa << std::endl;
		}
		else if (gracze[i]->typ_gracza == 1) //uzytkownik
		{
			plik << gracze[i]->id_gracza << " U " << gracze[i]->nazwa << std::endl;
		}
	}


}
void Plansza::wczytaj_gre()
{

}