#include "Horde.h"

Horde::Horde(int n, int width, int height)
{
	Initialize(n, width, height);
}

Horde::Horde(int nM, int nS, int width, int height)
{
	Enemies.reserve(nM + nS);
	Enemigo* nuevo;
	for (int i = 0; i < nM; i++)
	{
			nuevo = new Melee(width, height);
		Enemies.emplace_back(nuevo);
	}

	for (int i = 0; i < nS; i++)
	{
		nuevo = new Shooter(width, height);
		Enemies.emplace_back(nuevo);
	}
}

void Horde::Initialize(int n, int width, int height)
{
	Enemies.reserve(n);
	Enemigo* nuevo;
	for (int i = 0; i < n; i++)
	{
		if (rand()% 2 == 0)
			nuevo = new Melee(width, height);
		else
			nuevo = new Shooter(width, height);
		Enemies.emplace_back(nuevo);
	}
}

void Horde::Mostrar(Graphics ^ G, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB)
{
	for each (Enemigo* var in Enemies)
	{
		if (var->getTag() == 0)
			var->Mostrar(G, bmpM);

		else if(var->getTag() == 1)
			var->Mostrar(G, bmpS, bmpB);
	}
}

void Horde::CheckLive()
{
	for each (Shooter* var in Enemies)
	{
		if (var->getTag() == 1)
			var->CheckLive();
	}
}


Horde::~Horde()
{
}
