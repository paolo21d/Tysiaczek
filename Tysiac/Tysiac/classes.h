#pragma once
#include "includes.h"

class Karta 
{
public:
	int kolor;
	int figura;
	int id;
	void wypisz();
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
	bool licytowal = false;
	int typ_gracza; //0-komputer, 1-czlowiek
	int id_gracza;
	int wylicytowane;
	int punkty_w_partii;
	int wynik;
	////////////////////////////// metody virtualne
	virtual void wypisz_talie() = 0;
	//virtual int melduj() = 0;
	//virtual Karta wybierz() = 0;
	//virtual int licytuj() = 0;
};

class Uzytkownik : public Gracz
{
public:
	void wypisz_talie();
	//virtual int melduj();
	//virtual Karta wybierz();
	//virtual int licytuj();
};

/*class Komputer : public Gracz
{
public:
	virtual int melduj();
	virtual Karta wybierz();
	virtual int licytuj();
};
*/

class Plansza
{
private:
	int ile_graczy;
	int rozdajacy;
	int meldunek;
	Karta kar_na_gorze;
	//std::vector <Gracz*> gracze;
	Uzytkownik uzyt[4];
	//Komputer komp[4];
	Gracz* gracze[4];
	std::vector <Karta> musik; 
	std::vector <Karta> musik_dodatkowy;
	std::fstream plik;
public:
	std::vector <Karta> talia; // talia generowana - z niej sa wybierane karty do pozniejszych rozdan
	int grajacy;
	void inicjalizuj_karty();
	void nowa_kolejka(int id_gracza);
	Plansza();
	~Plansza(); //destruktor
	int get_ilosc_graczy();
	void set_ilosc_graczy(int ilosc);
	int get_rozdajacy();
	void set_rozdajacy(int id);
	int get_meldunek();
	void set_meldunek(int meldunek);
	void tasuj();
	void rozdaj();
	void licytuj();
	void wypisz_musik(int lp);
	void zapisz_gre();
	void wczytaj_gre();
	void nowa_gra();
	bool sprawdz_plik();
};

