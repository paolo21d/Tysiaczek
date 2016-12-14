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