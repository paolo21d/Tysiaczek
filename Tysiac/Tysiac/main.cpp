#include "includes.h"
#include "classes.h"
std::vector <Karta> talia;
void inicjalizuj_karty()
{
	int id = 0;
	Karta kar;
	for (int i = 9; i <= 11; i++)
	{
		kar.id = id;
		kar.figura = i;
		for (int j = 1; j <= 4; j++, id++)
		{
			kar.id = id;
			kar.figura = i;
			kar.kolor = j;
			talia.push_back(kar);
		}
	}
}
int main()
{
	srand(time(NULL));

	Plansza plansza;
	//plansza.zapisz_gre();
	int x;
	std::cin >> x;
	return 0;
}