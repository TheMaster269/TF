#include <vector>

#define PlayerX 65
#define PlayerY 600

#define ProyectilW 35
#define ProyectilH 25

#define SubimagenesX 1
#define SubimagenesY 1

#define AreaEscenarioX 800
#define AreaEscenarioY 600

using namespace std;
using namespace System::Drawing;

class Player
{
	short indSpriteX;
	short indSpriteY;
	Rectangle playerImagen;
	vector<Proyectil*>proyectiles;
	int num_proyectiles;
public:
	Player(Rectangle areaImagen,int nroSubimagenes) {
		this->playerImagen = areaImagen;
		this->num_proyectiles = 5;
	}
	~Player() {
		for (short i = 0; i < this->proyectiles.size(); i++)
			delete this->proyectiles[i];
	}

	void movePlayerY(short movimiento) {
		int y = this->playerImagen.Y;
		int h = this->playerImagen.Height;
		this->playerImagen.Y += (y + movimiento > 25 && y + h + movimiento < AreaEscenarioY) ? movimiento : 0;
	}
	void movePlayerX(short movimiento) {
		int x = this->playerImagen.X;
		int w = this->playerImagen.Width;
		this->playerImagen.X += (x + movimiento > 25 && x + w + movimiento < AreaEscenarioX ) ? movimiento : 0;
	}

	Rectangle getRectSubImagen(Bitmap^ img) { //Para saber en que Fragmento de la imagen esta
		short ancho = img->Width / SubimagenesX;
		short alto = img->Height / SubimagenesY;
		return Rectangle(this->indSpriteX * ancho, this->indSpriteY*alto, ancho, alto);
	}

	Rectangle getPlayerImagen() { return this->playerImagen; }
	vector<Proyectil*>getProyectiles() { return this->proyectiles; }

	bool Colision(Rectangle otraImagen) { 
		return this->playerImagen.IntersectsWith(otraImagen);
	}
	void lanzarProyectiles() {
		if (this->proyectiles.size() < this->num_proyectiles) {
			Proyectil* proy = new Proyectil(this->playerImagen.X,this->playerImagen.Y);
			this->proyectiles.push_back(proy);
		}
	}
	void drawPlayer(BufferedGraphics^ buffer1, Bitmap^ img)
	{
		img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->Graphics->DrawImage(img, this->playerImagen, this->getRectSubImagen(img), GraphicsUnit::Pixel);
		this->indSpriteX = (this->indSpriteX + 1 == SubimagenesX) ? 0 : this->indSpriteX + 1;//Condición X (mueve el corte sprite hacia la derecha)
		this->indSpriteY = (this->indSpriteY + 1 == SubimagenesY) ? 0 : this->indSpriteY + 1;//Condición Y (mueve el corte sprite hacia abajo)
	}

	void shootProyectil(BufferedGraphics^ buffer, int lderecho, Bitmap^ img) { //animación del proyectil
		for (short i = 0; i < this->proyectiles.size(); i++)
		{
			this->proyectiles[i]->drawProyectil(buffer, img);
			this->proyectiles[i]->moverProyectilX();//por ahora solo se mueve de derecha a izquierda
			if (this->proyectiles[i]->getX() > lderecho)
			{
				delete this->proyectiles[i];
				this->proyectiles.erase(this->proyectiles.begin() + i);
			}
		}
	}

	void eliminateProyectil(int i) {
		delete this->proyectiles.at(i);
		this->proyectiles.erase(this->proyectiles.begin() + i);
	}

};


class Proyectil
{

	Rectangle proyectilImagen;
public:
	Proyectil(short x,short y) {
		this->proyectilImagen = Rectangle(x + 20, y + 20, ProyectilW, ProyectilH);
	}
	~Proyectil() {}
	void drawProyectil(BufferedGraphics^ buffer1, Bitmap^ imagen) {
		imagen->MakeTransparent(imagen->GetPixel(0, 0));
		buffer1->Graphics->DrawImage(imagen, this->proyectilImagen);
	}
	bool Colision(Rectangle otraImagen) { 
		return this->proyectilImagen.IntersectsWith(otraImagen);
	}
	void drawProyectil(BufferedGraphics^ buffer1, Bitmap^ img) {
		img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->Graphics->DrawImage(img, this->proyectilImagen);
	}
	int getX() { return this->proyectilImagen.X; }
	int getY() {	return this->proyectilImagen.Y;}
	void moverProyectilX() { this->proyectilImagen.X += 30; } //cambiar dirección mediante un booleano o hacer un switch en MyForm
	void moverProyectilY() { this->proyectilImagen.Y += 30;} //cambiar dirección mediante un booleano o hacer un switch en MyForm
	//Falta tiempo de recarga

};
