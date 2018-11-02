#pragma once

using namespace System::Drawing;

class Bala
{
	int x, y;
	int dx, dy;
	bool vivo;
public:
	Bala();
	Bala(int x, int y, int dx, int dy) : x(x), y(y), dx(dx), dy(dy) { vivo = true; };
	void Mostrar(Graphics^ G, Bitmap^ bmp);
	void Mover(Graphics^ G);
	bool GetVivo();
	~Bala();
};

