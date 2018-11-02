#include "Shooter.h"



Shooter::Shooter()
{
}


Shooter::~Shooter()
{
}

void Shooter::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	Mover(G);
	Rectangle cut(col * bmp->Width / 4, dir* bmp->Height / 4, bmp->Width / 4, bmp->Height / 4);
	G->DrawImage(bmp, x, y, cut, GraphicsUnit::Pixel);
	col++;
	col %= 4;

}

void Shooter::Mostrar(Graphics ^ G, Bitmap ^ bmp, Bitmap^ bmpB)
{
	Mover(G);
	MoverBalas(G, bmpB);
	Rectangle cut(col * bmp->Width / 4, dir* bmp->Height / 4, bmp->Width / 4, bmp->Height / 4);
	G->DrawImage(bmp, x, y, cut, GraphicsUnit::Pixel);
	col++;
	col %= 4;
}

void Shooter::Mover(Graphics ^ G)
{
	if (pasos == 0)
	{
		dir = rand() % 4;
		if(shootCooldown == 0)
			Disparar();
		
	}
	switch (dir)
	{
	case 0:
		dy = 5;
		dx = 0;
		if (y + 5 < G->VisibleClipBounds.Bottom)
			y += 5;
		pasos++;
		pasos %= ry;
		break;
	case 1:
		dy = -5;
		dx = 0;
		if (x - 5 > G->VisibleClipBounds.Left)
			x -= 5;
		pasos++;
		pasos %= rx;
		break;
	case 2:
		dx = 5;
		dy = 0;
		if (x + 5 < G->VisibleClipBounds.Right)
			x += 5;
		pasos++;
		pasos %= rx;
		break;
	case 3:
		dx = -5;
		dy = 0;
		if (y - 5 > G->VisibleClipBounds.Top)
			y -= 5;
		pasos++;
		pasos %= ry;
		break;
	default:
		break;
	}
	shootCooldown++;
	shootCooldown %= shootDelay;
}

void Shooter::Disparar()
{
	Bala* nueva = new Bala(x, y, dx, dy);
	balas.push_back(nueva);
}

void Shooter::MoverBalas(Graphics ^ G, Bitmap ^ bmpB)
{
	for each (Bala* var in balas)
	{
		var->Mostrar(G, bmpB);
	}
}

void Shooter::CheckLive()
{
	std::vector<Bala*>::iterator i = balas.begin();
	while (i != balas.end())
	{
		if (!(*i)->GetVivo())
		{
			i = balas.erase(i);
		}
		else
			++i;
	}
}
