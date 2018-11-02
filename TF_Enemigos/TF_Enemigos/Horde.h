#pragma once
#include "Melee.h"
#include "Shooter.h"
#include <vector>

class Horde
{
	std::vector<Enemigo*> Enemies;
public:
	Horde(int n, int width, int height);
	Horde(int nM, int nS, int width, int height);
	void Initialize(int n, int width, int height);
	void Mostrar(Graphics^G, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB);
	void CheckLive();
	~Horde();
};

