#include "includes.h"
#include "classes.h"

void Karta::wypisz()
{
	if (figura == 9 || figura == 10) std::cout << figura << " "<<(char)kolor + 2;
	else if (figura == 11) std::cout << "Jopek " << (char)kolor + 2;
	else if (figura == 12) std::cout << "Dama " << (char)kolor + 2;
	else if (figura == 13) std::cout << "Krol " << (char)kolor + 2;
	else if (figura == 14) std::cout << "As " << (char)kolor + 2;
}