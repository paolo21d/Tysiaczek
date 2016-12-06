#include "includes.h"
#include <iostream>
#include <cstdio>
#include <vector>

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
			kar.figura = j;
			kar.kolor = i;
			talia.push_back(kar);
		}
		//talia.push_back()
	}
}
int main()
{







	return 0;
}