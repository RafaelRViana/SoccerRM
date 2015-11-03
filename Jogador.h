#ifndef JOGADOR
#define JOGADOR

#include <string>
#include <iostream>
#include "Dimensoes.h"
#include "ElementoRetangular.h"
#include "Colisao.h"

#include "GerenciadorTimes.h"

using namespace std;

class Jogador: public ElementoRetangular
{
	private:
		BITMAP *imagem;
		BITMAP *buffer;
		char* nome;
		int direita, esquerda, baixo, cima;	
		int xIni, yIni;
		Time *time;

		void deslocarParaDireita(int distancia);
		void deslocarParaEsquerda(int distancia);
		void deslocarParaCima(int distancia);
		void deslocarParaBaixo(int distancia);

	public:
		Jogador(BITMAP *campo, int x, int y, int direita, int esquerda, int baixo, int cima, Time *time);
		~Jogador();
		void mover();
		void desenhar();		
		void setPosicaoInicial(int x, int y);
		Time* getTime();
		void inicializar();

		void tratarColisao(int lado)
		{
			switch( lado )
			{
				case COLISAO_ESQUERDA:
					deslocarParaDireita(2);					
					break;
				case COLISAO_DIREITA:
					deslocarParaEsquerda(2);		
					break;
				case COLISAO_CIMA:
					deslocarParaBaixo(2);
					break;
				case COLISAO_BAIXO:
					deslocarParaCima(2);
					break;
			}
		}
};

Jogador::Jogador(BITMAP *campo, int x, int y, int direita, int esquerda, int baixo, int cima, Time *time):
	ElementoRetangular(x, y, ALTURA_JOGADOR, LARGURA_JOGADOR)
{	
	this -> buffer = campo;

	this -> direita = direita;
	this -> esquerda = esquerda;
	this -> baixo = baixo;
	this -> cima = cima;
	this -> time = time;
	
	this -> imagem =  time -> getUniformeJogador();

	setPosicaoInicial(x, y);

	desenhar();
}

Jogador::~Jogador()
{
	cout << "Limpando da memória objetos que não serão mais utilizados..." << "\n";
	destroy_bitmap(imagem);
}

void Jogador::desenhar()
{
	draw_sprite(buffer, imagem, x, y);	
}

void Jogador::inicializar()
{
	x = xIni;
	y = yIni;
}

void Jogador::setPosicaoInicial(int x, int y)
{
	this -> xIni = x;
	this -> yIni = y;
}

void Jogador::mover()
{
	if( key[direita] )		
		deslocarParaDireita(1);
	
	if( key[esquerda] )
		deslocarParaEsquerda(1);

	if( key[baixo] )
		deslocarParaBaixo(1);
	
	if( key[cima] )
		deslocarParaCima(1);
}

Time* Jogador::getTime()
{
	return time;
}

void Jogador::deslocarParaDireita(int distancia)
{
	if( x < LIMITE_DIREITA )
		x += distancia;
}

void Jogador::deslocarParaEsquerda(int distancia)
{
	if( x > LIMITE_ESQUERDA )
		x -= distancia;
}

void Jogador::deslocarParaCima(int distancia)
{
	if( y > LIMITE_SUPERIOR )
		y -= distancia;
}

void Jogador::deslocarParaBaixo(int distancia)
{
	if( y < LIMITE_INFERIOR )
		y += distancia;
}

#endif
