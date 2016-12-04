#include "includes.h"
#include <iostream>
#include <cstdio>
#include <fstream>
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
void Plansza::tasuj()
{

}
void Plansza::rozdaj(int ile)
{

}
void Plansza::zapisz_gre()
{

}
void Plansza::wczytaj_gre()
{

}