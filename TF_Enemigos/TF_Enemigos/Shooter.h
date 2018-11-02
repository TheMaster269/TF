#pragma once
#include "Enemigo.h"
#include "Bala.h"
#include <vector>

class Shooter :
	public Enemigo
{
	int shootCooldown;
	int shootDelay;
	std::vector<Bala*> balas;
public:
	Shooter();
	Shooter(int width, int height) : Enemigo(width, height)
	{
		shootCooldown = 0;
		shootDelay = rand() % 3 + 5;
		tag = 1;
	}
	~Shooter();
	void Mostrar(Graphics^ G, Bitmap^ bmp);
	void Mostrar(Graphics^ G, Bitmap^ bmp, Bitmap^ bmpB);
	void Mover(Graphics^ G);
	void Disparar();
	void MoverBalas(Graphics^ G, Bitmap^ bmpB);
	void CheckLive();
};

