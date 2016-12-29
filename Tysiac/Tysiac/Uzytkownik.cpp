#include "includes.h"
#include "classes.h"

void Uzytkownik::wypisz_talie()
{
	/***
	Karta.id - wskazuje id karty (indexowane od 0)
	Karta.figura - wskazuje na figure karty (od 9 do 14-asa)
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[øo≥πdü], 4-pik[wino] )
	***/
	std::cout << "Twoje karty: ";
	for(int i=0; i<karty_w_rece.size(); i++)
	{
		karty_w_rece[i].wypisz();
		std::cout << " | ";
	}
}
void Uzytkownik::sortuj_karty()
{
	// sortowanie po kolorze
	int n = karty_w_rece.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-1; j++)
			if (karty_w_rece[j].kolor > karty_w_rece[j+1].kolor)
				std::swap(karty_w_rece[j], karty_w_rece[j+1]);

	//sortowanie w obrebie koloru
	int poczatek = 0;
	int ile;
	for (int i = 0; i < n; i++)
	{
		if (n <= 1) break; // ilosc kart w rece gracza <= 1, nie wykonuje sie
		ile = 1;
		for (int j = poczatek + 1; j < n; j++) // zlicznie ile kart z rzedu jest tego samego koloru
		{
			if (karty_w_rece[poczatek].kolor == karty_w_rece[j].kolor)
				ile++;
			else break;
		}

		for (int x = poczatek; x<poczatek + ile; x++) //posortowanie kart rosnaco w obrebie danego koloru
			for (int j = poczatek ; j<poczatek + ile - 1; j++)
				if (karty_w_rece[j].id > karty_w_rece[j+1].id)
					std::swap(karty_w_rece[j], karty_w_rece[j+1]);

		poczatek += ile;
		i += ile;
	}
}

