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
		for (int j = 1; j < n - 1; j++)
			if (karty_w_rece[j - 1].id > karty_w_rece[j].id)
				std::swap(karty_w_rece[j - 1], karty_w_rece[j]);

	//sortowanie w obrebie koloru
	int poczatek = 0;
	int ile;
	for (int i = 0; i < n; i++)
	{
		ile = 0;
		for (int j = poczatek + 1; j < n; j++) // zlicznie ile kart z rzedu jest tego samego koloru
			if (karty_w_rece[poczatek].kolor == karty_w_rece[j].kolor)
				ile++;

		for (int x = poczatek; x<poczatek + ile; x++) //posortowanie kart rosnaco w obrebie danego koloru
			for (int j = poczatek + 1; j<poczatek + ile - 1; j++)
				if (karty_w_rece[j - 1].id > karty_w_rece[j].id)
					std::swap(karty_w_rece[j - 1], karty_w_rece[j]);
		poczatek += ile;
		i += ile;
	}
}

