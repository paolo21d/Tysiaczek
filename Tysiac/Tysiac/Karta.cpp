#include "includes.h"
#include "classes.h"

void Karta::wypisz()
{
	/***
	Karta.id - wskazuje id karty (indexowane od 0)
	Karta.figura - wskazuje na figure karty (od 9 do 14-asa)
	Karta.kolor - wskazuje kolor karty (1-kier[serce], 2-karo[dzwonek], 3-trefl[øo≥πdü], 4-pik[wino] )
	***/

	//wypisywanie znaczka, potrzebna poprawa
	/*if (figura == 9 || figura == 10) std::cout << figura << " "<<(char) (kolor + 2);
	else if (figura == 11) std::cout << "Jopek " << (char) (kolor + 2);
	else if (figura == 12) std::cout << "Dama " << (char) (kolor + 2);
	else if (figura == 13) std::cout << "Krol " << (char) (kolor + 2);
	else if (figura == 14) std::cout << "As " << (char) (kolor + 2);*/

	if (kolor == 1)//serce
	{
		if (figura == 9 || figura == 10) std::cout << figura << " kier";
		else if (figura == 11) std::cout << "Jopek " << "kier";
		else if (figura == 12) std::cout << "Dama " << "kier";
		else if (figura == 14) std::cout << "As " << "kier";
	}
	else if (kolor == 2)//dzownek
	{
		if (figura == 9 || figura == 10) std::cout << figura << " karo";
		else if (figura == 11) std::cout << "Jopek " << "karo";
		else if (figura == 12) std::cout << "Dama " << "karo";
		else if (figura == 14) std::cout << "As " << "karo";
	}
	else if (kolor == 3)//øo≥πdü
	{
		if (figura == 9 || figura == 10) std::cout << figura << " trefl";
		else if (figura == 11) std::cout << "Jopek " << "trefl";
		else if (figura == 12) std::cout << "Dama " << "trefl";
		else if (figura == 14) std::cout << "As " << "trefl";
	}
	else if (kolor == 4)//wino
	{
		if (figura == 9 || figura == 10) std::cout << figura << " pik";
		else if (figura == 11) std::cout << "Jopek " << "pik";
		else if (figura == 12) std::cout << "Dama " << "pik";
		else if (figura == 14) std::cout << "As " << "pik";
	}
}