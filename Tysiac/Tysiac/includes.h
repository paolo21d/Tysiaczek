#pragma once

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

class Karta
{
	int numer;
	int kolor;
	//kolor: 1-trefl(zoladz) ,2-karo(dzwonek), 3-kier(serce), 4-pik(wino)
	void losuj(int graczy);
	void cos();
};