#ifndef BOLA
#define BOLA

#include <iostream>
#include "ElementoRedondo.h"

#define RAIO 10

using namespace std;

class Bola : public ElementoRedondo
{
	private:
		BITMAP *campo;
		BITMAP *imagem;
		int vertical, horizontal, reta;		
		bool emMovimento;
		int cor;

	public:
		Bola(BITMAP *campo, int cor);
		~Bola();
		void mover();
		void desenhar();
		void inicializar();
		void tratarColisao(int lado)
		{
			if( !emMovimento && lado != NENHUMA_COLISAO )
				emMovimento = true;
 
			if(lado == COLISAO_ESQUERDA){
				reta = 1;
			}
			if(lado == COLISAO_DIREITA){
				reta = 0;
			}
			if(lado == COLISAO_CIMA){
				reta = -1;
				horizontal = 1;
			}
			if(lado == COLISAO_BAIXO){
				reta = -1;
				horizontal = 0;	
			}
			if(lado == COLISAO_DIREITA_BAIXO){
				reta = -1;
				vertical = 1;
				horizontal = 0;
			}			
			if(lado == COLISAO_DIREITA_CIMA){
				reta = -1;
				vertical = 1;
				horizontal = 1;
			}
			if(lado == COLISAO_ESQUERDA_BAIXO){
				reta = -1;
				vertical = 0;
				horizontal = 0;
			}			
			if(lado == COLISAO_ESQUERDA_CIMA){
				reta = -1;
				vertical = 0;
				horizontal = 1;
			}
		}
};

Bola::Bola(BITMAP *campo, int cor):
	ElementoRedondo(x, y, RAIO)
{
	this -> imagem = create_bitmap(RAIO*2, RAIO*2);	
	this -> campo = campo;
	this -> cor = cor;
	
	inicializar();
}

Bola::~Bola()
{
	cout << "Limpando da memória objetos que não serão mais utilizados..." << "\n";
	destroy_bitmap(imagem);
}

void Bola::mover()
{
	if( emMovimento )
	{
		if(x == LIMITE_DIREITA - 15){
			if(reta == 0)
				reta = 1;
			else
				vertical = 0;
		}
		if(x == LIMITE_ESQUERDA + 25){
			if(reta == 1)
				reta = 0;
			else			
				vertical = 1;
				
				
		}
		if(y == LIMITE_INFERIOR + 50){
			reta = -1;
			horizontal = 1;
		}
		if(y == LIMITE_SUPERIOR + 40){
			reta = -1;
			horizontal = 0;
		}

		if(reta == 0 )
		{
			x++;
		}
		else if(reta == 1){
				x--;
			}
			else{

				if(vertical == 0)
					x--;
				else
					x++;

				if(horizontal == 0)
					y++;
				else
					y--;
			}
	}
}

void Bola::desenhar()
{
	circlefill(campo, x, y, RAIO, cor);
}

void Bola::inicializar()
{	
	emMovimento = false;
	vertical = 0;
	horizontal = 0;
	x = MAX_X / 2;
	y = ALTURA_CAMPO / 2;

	desenhar();
}

#endif
