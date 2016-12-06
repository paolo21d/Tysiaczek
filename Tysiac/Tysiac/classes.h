#pragma once
#include "includes.h"
class Karta // nie potrzeby plik .cpp
{
public:
	int kolor;
	int figura;
	int id;
};
class Gracz //nie potrzebny plik .cpp
{
public:
	std::vector <Karta> karty_w_rece;
	std::string nazwa;
	int typ_gracza; //0-komputer, 1-czlowiek
	int id_gracza;
	int wylicytowane;
	int punkty_w_partii;
	int wynik;
	virtual int melduj() = 0;
	virtual Karta wybierz() = 0;
	virtual int licytuj() = 0;

};
class Uzytkownik : public Gracz
{

};
class Komputer : public Gracz
{

};
class Plansza
{
	int ile_graczy;
	int meldunek;
	Karta kar_na_gorze;
	//std::vector <Karta> karty_w_rece; // najlepiej by bylo dynamicznie alokowac ten vector w tablice 
	std::vector <Gracz*> gracze;
	std::fstream plik;
public:
	Plansza();
	~Plansza(); //destruktor
	int get_ilosc_graczy();
	int get_meldunek();
	void tasuj(std::vector <Karta>);
	void rozdaj(int ile);
	void zapisz_gre();
	void wczytaj_gre();
};
