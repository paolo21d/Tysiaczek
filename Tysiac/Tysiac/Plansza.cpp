#include "includes.h"
#include "classes.h"
Plansza::Plansza()
{
	//otworzenie pliku z zapisami
	plik.open("dane_gry.txt");
	if (!plik.good()) //nie udalo sie otworzyc pliku
	{

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
	4. 
	5. Talia gracza 1 ... - w nastpnych wierszach
	************************/
	int rok, miesiac, dzien, godzina, minuta;



	//plik << rok << "-" << miesiac << "-" << dzien << " " << godzina << "-" << minuta<<std::endl;
	plik << ile_graczy<<std::endl;
	for (int i = 0; i < ile_graczy; i++) // Ad 3 - opis graczy
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

	for (int i = 0; i < ile_graczy; i++) // Ad 5 - wypisywanie talii graczy
	{
		for (int j = 0; j < gracze[i]->karty_w_rece.size(); j++)
		{
			plik << gracze[i]->karty_w_rece[j].figura << " " <<gracze[i]->karty_w_rece[j].kolor << " ";
		}
	}
}
void Plansza::wczytaj_gre()
{

}