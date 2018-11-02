#pragma once
#include "Enemigo.h"
class Melee :
	public Enemigo
{
public:
	Melee();
	Melee(int width, int height) : Enemigo(width, height)
	{
		tag = 0;
	}
	~Melee();
	void Mostrar(Graphics^ G, Bitmap^ bmp, Bitmap^bmpS);
	void Mostrar(Graphics^ G, Bitmap^ bmp);
	void Mover(Graphics ^ G);
};

