#pragma once

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
class Karta
{
	int kolor;
	int figura;
	int id;
};
class Plansza
{
	int ile_graczy;
	int meldunek;
	Karta kar_na_gorze;
	std::vector <Karta> karty_w_rece[4]; // najlepiej by bylo dynamicznie alokowac ten vector w tablice 
	std::fstream plik;
public: 
	Plansza();
	~Plansza(); //destruktor
	int get_ilosc_graczy();
	void tasuj();
	void rozdaj(int ile);
	void zapisz_gre();
	void wczytaj_gre();
};
class Gracz
{
	std::vector <Karta> karty;
};
class Uzytkownik : public Gracz
{

};
class Komputer : public Gracz
{

};