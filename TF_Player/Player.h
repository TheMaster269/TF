#pragma once
#include <vector>
enum Direction { Zero, Up, Down, Left, Right };

#define ProyectilW 35 //tamaño del proyectil
#define ProyectilH 25
#define PersonajeW 45
#define PersonajeH 35
#define SubimagenesX 3
#define SubimagenesY 4


using namespace std;
using namespace System::Drawing;
class Proyectil
{
	int dpx;
	int dpy;
	short indProyX;
	short indProyY;
	Rectangle proyectilImagen;
public:
	Proyectil(short x, short y) {
		this->proyectilImagen = Rectangle(x, y, ProyectilW, ProyectilH);
		this->indProyX = 0;
		this->indProyY = 0;
	}
	~Proyectil() {}
	bool Colision(Rectangle otraImagen) {
		return this->proyectilImagen.IntersectsWith(otraImagen);
	}
	Rectangle getRectSubImgProy(Bitmap^ img) { //Para saber en que Fragmento de la imagen del proyectil esta
		short ancho = img->Width / 4;
		short alto = img->Height / 4;
		return	Rectangle(this->indProyX * ancho, this->indProyY*alto, ancho, alto);
	}
	void drawProyectil(BufferedGraphics^ buffer1, Bitmap^ img) {
		img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->Graphics->DrawImage(img, this->proyectilImagen, this->getRectSubImgProy(img), GraphicsUnit::Pixel);
		proyectilImagen.X += dpx;
		proyectilImagen.Y += dpy;

	}
	int getX() { return this->proyectilImagen.X; }
	int getY() { return this->proyectilImagen.Y; }
	void moveProyectil(Direction tecla, BufferedGraphics^ buffer1, Bitmap^ img) {
		switch (tecla)
		{
		case Direction::Up:
			this->indProyY = 3;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 0;
			this->dpy = -10;
			break;
		case Direction::Down:
			this->indProyY = 2;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 0;
			this->dpy = 10;
			break;
		case Direction::Left:
			this->indProyY = 1;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = -10;
			this->dpy = 0;
			break;
		case Direction::Right:
			this->indProyY = 0;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 10;
			this->dpy = 0;
			break;

		}
		drawProyectil(buffer1, img);
	}
	//Falta tiempo de recarga

};

class Player
{
	short indSpriteX;
	short indSpriteY;
	int dx;
	int dy;
	Rectangle playerImagen;
	vector<Proyectil*>proyectiles;
	unsigned int municiones;
	Direction TeclaEnd; //para saber en que tecla terminó
public:
	Direction direccion;
	Player(int x, int y) {
		this->playerImagen.X = x;
		this->playerImagen.Y = y;
		this->playerImagen.Width = PersonajeW;
		this->playerImagen.Height = PersonajeH;
		this->municiones = 100;
		this->TeclaEnd = Direction::Down;
		this->direccion = Direction::Zero;
		this->indSpriteX = 1;
		this->indSpriteY = 2;
	}
	~Player() {
		for (unsigned short i = 0; i < this->proyectiles.size(); i++)
			delete this->proyectiles[i];
	}

	Rectangle getRectSubImagen(Bitmap^ img) { //Para saber en que Fragmento de la imagen esta
		short ancho = img->Width / SubimagenesX;
		short alto = img->Height / SubimagenesY;
		return	Rectangle(this->indSpriteX * ancho, this->indSpriteY*alto, ancho, alto);
	}


	Rectangle getPlayerImagen() { return this->playerImagen; }
	vector<Proyectil*>getProyectiles() { return this->proyectiles; }

	bool Colision(Rectangle otraImagen) {
		return this->playerImagen.IntersectsWith(otraImagen);
	}
	void drawPlayer(BufferedGraphics^ buffer1, Bitmap^ img) // animación del personaje
	{
		img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->Graphics->DrawImage(img, this->playerImagen, this->getRectSubImagen(img), GraphicsUnit::Pixel);
		playerImagen.X += dx;
		playerImagen.Y += dy;
	}
	void movePlayer(BufferedGraphics^ buffer1, Bitmap^ img) //movimiento del personaje
	{
		switch (direccion)
		{
		case Direction::Up:
			this->indSpriteY = 3;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = 0;
			this->dy = -10;
			this->TeclaEnd = Up;
			break;
		case Direction::Down:
			this->indSpriteY = 0;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2) { indSpriteX++; }
			else
			{
				indSpriteX = 1;
			}
			this->dx = 0;
			this->dy = 10;
			this->TeclaEnd = Down;
			break;

		case Direction::Left:
			this->indSpriteY = 1;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = -10;
			this->dy = 0;
			this->TeclaEnd = Left;
			break;
		case Direction::Right:
			this->indSpriteY = 2;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = +10;
			this->dy = 0;
			this->TeclaEnd = Right;
			break;
		case Direction::Zero:
			this->dx = 0;
			this->dy = 0;
			switch (TeclaEnd)
			{
			case Up:
				this->indSpriteX = 1;
				this->indSpriteY = 3;
				break;
			case Down:
				this->indSpriteX = 1;
				this->indSpriteY = 0;
				break;
			case Left:
				this->indSpriteX = 1;
				this->indSpriteY = 1;
				break;
			case Right:
				this->indSpriteX = 1;
				this->indSpriteY = 2;
				break;
			}
			break;
		}
		drawPlayer(buffer1, img);
	}
	void shootProyectiles() { //generación de proyectiles-cambiar
		if (this->proyectiles.size() < this->municiones) {
			Proyectil* proy = new Proyectil(this->playerImagen.X, this->playerImagen.Y);
			this->proyectiles.push_back(proy);
		}
	}
	

	void animateProyectil(BufferedGraphics^ buffer, Bitmap^ img) { //animación del proyectil
		for (unsigned short i = 0; i < this->proyectiles.size(); i++)
		{
			this->proyectiles[i]->moveProyectil(TeclaEnd,buffer,img);

			if (this->proyectiles[i]->getX() > buffer->Graphics->VisibleClipBounds.Width && this->proyectiles[i]->getX()< 0)
			{
				//delete this->proyectiles[i];
				//this->proyectiles.erase(this->proyectiles.begin() + i);
				eliminateProyectil(i);
			}
			else if (this->proyectiles[i]->getY() > buffer->Graphics->VisibleClipBounds.Height && this->proyectiles[i]->getX() < 0)
			{
				//delete this->proyectiles[i];
				//this->proyectiles.erase(this->proyectiles.begin() + i);
				eliminateProyectil(i);
			}

			
		}
	}
	void eliminateProyectil(int i) {
		delete this->proyectiles.at(i);
		this->proyectiles.erase(this->proyectiles.begin() + i);
	}

};






