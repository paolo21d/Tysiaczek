#pragma once
#include "includes.h"

class Karta 
{
public:
	int kolor;
	int figura;
	int id;
	/***
	Karta.id - wskazuje id karty (indexowane od 0)
	Karta.figura - wskazuje na figure karty (od 9 do 14-asa)
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[øo≥πdü], 4-pik[wino] )
	***/
};
class Gracz
{
public:
	std::vector <Karta> karty_w_rece;
	std::string nazwa;
	int typ_gracza; //0-komputer, 1-czlowiek
	int id_gracza;
	int wylicytowane;
	int punkty_w_partii;
	int wynik;
	////////////////////////////// metody virtualne
	virtual int melduj() = 0;
	virtual Karta wybierz() = 0;
	virtual int licytuj() = 0;

};
class Uzytkownik : public Gracz
{

public:
	void wypisz_talie();
};
class Komputer : public Gracz
{

};
class Plansza
{
private:
	int ile_graczy;
	int meldunek;
	Karta kar_na_gorze;
	//std::vector <Gracz*> gracze;
	Gracz* gracze[4];
	std::vector <Karta> musik; 
	std::vector <Karta> musik_dodatkowy;
	std::fstream plik;
public:
	std::vector <Karta> talia; // talia generowana - z niej sa wybierane karty do pozniejszych rozdan
	void inicjalizuj_karty();
	Plansza();
	~Plansza(); //destruktor
	int get_ilosc_graczy();
	int get_meldunek();
	void tasuj();
	void rozdaj(int ile);
	void zapisz_gre();
	void wczytaj_gre();
};

