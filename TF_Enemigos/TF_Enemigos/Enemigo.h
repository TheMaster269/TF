#pragma once
#include <iostream>

using namespace System::Drawing;

class Enemigo
{
protected:
	int x, y;
	int dx, dy;
	int rx, ry;
	int col;
	int pasos;
	bool activo;
	bool vivo;
	int dir;
	int tag;
public:
	Enemigo();
	Enemigo(int width, int height);
	~Enemigo();
	virtual void Mostrar(Graphics^ G, Bitmap^ bmp) = 0;
	virtual void Mostrar(Graphics^ G, Bitmap^ bmp, Bitmap^ bmpB) = 0;
	virtual void Mover(Graphics^ G) = 0;
	int getTag();
};

