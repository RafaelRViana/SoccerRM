#ifndef GOLEIRA
#define GOLEIRA

#include <iostream>

#include "Dimensoes.h"
#include "ElementoRetangular.h"

using namespace std;

class Goleira: public ElementoRetangular
{
	private:
		BITMAP *imagem;
		BITMAP *buffer;	

	public:
		Goleira(BITMAP *campo, int x, int y);
		~Goleira();
		void desenhar();

		void tratarColisao(int lado){ } //Goleira não se mexe...
};
Goleira::Goleira(BITMAP *campo, int x, int y):
	ElementoRetangular(x, y, ALTURA_GOLEIRA, LARGURA_GOLEIRA)
{
	this -> imagem = create_bitmap(LARGURA_GOLEIRA, ALTURA_GOLEIRA);
	this -> buffer = campo;

	this -> desenhar();
}

Goleira::~Goleira()
{
	cout << "Limpando da memória objetos que não serão mais utilizados..." << "\n";
	destroy_bitmap(imagem);
}

void Goleira::desenhar()
{
	rectfill(imagem, 0, 0, LARGURA_GOLEIRA, ALTURA_GOLEIRA, makecol(255, 255, 255));
	draw_sprite(buffer, imagem, x, y);	
}

#endif
