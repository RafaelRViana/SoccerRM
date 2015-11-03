#ifndef GOLEIRO
#define GOLEIRO

#include <iostream>

#include "Dimensoes.h"
#include "ElementoRetangular.h"

using namespace std;

class Goleiro: public ElementoRetangular
{
	private:
		BITMAP *imagem;
		BITMAP *buffer;	
		int cima, baixo;
		int xIni, yIni;
		Time* time;

		void deslocarParaCima(int distancia);
		void deslocarParaBaixo(int distancia);

	public:
		Goleiro(BITMAP *campo, int x, int y, int cima, int baixo, Time *time);
		~Goleiro();
		Time* getTime();
		void desenhar();
		void mover();
		void setPosicaoInicial(int x, int y);
		void inicializar();	

		void tratarColisao(int lado)
		{
			switch( lado )
			{
				case COLISAO_CIMA:
					deslocarParaBaixo(2);
					break;
				case COLISAO_BAIXO:
					deslocarParaCima(2);
					break;
			} 
		}
};

Goleiro::Goleiro(BITMAP *campo, int x, int y, int cima, int baixo, Time *time):
	ElementoRetangular(x, y, ALTURA_GOLEIRO, LARGURA_GOLEIRO)
{
	this -> buffer = campo;
	this -> cima = cima;
	this -> baixo = baixo;
	this -> time = time;

	this -> imagem =  time -> getUniformeGoleiro();

	setPosicaoInicial(x, y);

	this -> desenhar();
}

Goleiro::~Goleiro()
{
	cout << "Limpando da memória objetos que não serão mais utilizados..." << "\n";
	destroy_bitmap(imagem);
}

void Goleiro::desenhar()
{
	draw_sprite(buffer, imagem, x, y);	
}

void Goleiro::mover()
{
	if( key[cima] )
		deslocarParaCima(1);
	if( key[baixo] )
		deslocarParaBaixo(1);
}

Time* Goleiro::getTime()
{
	return time;
}

void Goleiro::deslocarParaCima(int distancia)
{
	if( y > LIMITE_SUPERIOR_AREA )
		y -= distancia;
}

void Goleiro::deslocarParaBaixo(int distancia)
{
	if( y < LIMITE_INFERIOR_AREA )
		y += distancia;
}

void Goleiro::inicializar()
{
	x = xIni;
	y = yIni;
}

void Goleiro::setPosicaoInicial(int x, int y)
{
	this -> xIni = x;
	this -> yIni = y;
}

#endif
