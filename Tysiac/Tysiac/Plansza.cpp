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
void Plansza::tasuj()
{

}
void Plansza::rozdaj(int ile)
{

}
void Plansza::zapisz_gre() //ustalic na jakiej zasadzie beda zapisy, czy nastepne, czy nadpisujemy
{
	
}
void Plansza::wczytaj_gre()
{

}