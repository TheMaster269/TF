#include "Enemigo.h"



Enemigo::Enemigo()
{
}

Enemigo::Enemigo(int width, int height)
{
	x = rand() % ((7 * width) / 8);
	y = rand() % ((7 *height) / 8);
	rx = rand() % 5 + 10;
	ry = rand() % 5 + 10;

	dx = 0;
	dy = 5;

	col = 0;

	dir = 0;
	pasos = 0;

	activo = true;
	vivo = true;
}


Enemigo::~Enemigo()
{
}

int Enemigo::getTag()
{
	return tag;
}

