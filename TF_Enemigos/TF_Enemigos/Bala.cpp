#include "Bala.h"



Bala::Bala()
{
}

void Bala::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	if (vivo)
	{
		Mover(G);
		Rectangle cut(0, 0, bmp->Width, bmp->Height);
		G->DrawImage(bmp, x, y, cut, GraphicsUnit::Pixel);
	}
}

void Bala::Mover(Graphics ^ G)
{
	if (x + dx < G->VisibleClipBounds.Right
		&& x + dx > G->VisibleClipBounds.Left
		&& y + dy > G->VisibleClipBounds.Top
		&& y + dy < G->VisibleClipBounds.Bottom
		)
	{
		x += dx;
		y += dy;
	}
	else
		vivo = false;
}

bool Bala::GetVivo()
{
	return vivo;
}


Bala::~Bala()
{
}
