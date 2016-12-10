#include "includes.h"
#include "classes.h"

void Uzytkownik::wypisz_talie()
{
	/***
	Karta.id - wskazuje id karty (indexowane od 0)
	Karta.figura - wskazuje na figure karty (od 9 do 14-asa)
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[øo≥πdü], 4-pik[wino] )
	***/
	std::cout << "Twoje karty: " << std::endl;
	for(int i=0; i<karty_w_rece.size(); i++)
	{
		if (karty_w_rece[i].figura == 11)
			std::cout << "Jopek " << (char)karty_w_rece[i].figura + 4;
		else if (karty_w_rece[i].figura == 12)
			std::cout << "Dama " << (char)karty_w_rece[i].figura + 4;
		else if (karty_w_rece[i].figura == 13)
			std::cout << "Krol " << (char)karty_w_rece[i].figura + 4;
		else if (karty_w_rece[i].figura == 14)
			std::cout << "As " << (char)karty_w_rece[i].figura + 4;
	}
}