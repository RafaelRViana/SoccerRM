#ifndef DETECTOR_COLISOES
#define DETECTOR_COLISOES

#include <iostream>
#include <math.h>

#include "Colisao.h"
#include "ElementoRedondo.h"
#include "ElementoRetangular.h"

using namespace std;

class DetectorColisoes
{
	private:
		double calcularDistanciaEntreDoisPontos(int x1, int y1, int x2, int y2);
		int inversoDaColisao(int ladoColisao);

	public:
		int detectarColisao(ElementoRetangular *elementoA, ElementoRetangular *elementoB); 
		int detectarColisao(ElementoRetangular *elementoA, ElementoRedondo *elementoB); 

};

//Detectar colisão usando Bounding Box
int DetectorColisoes::detectarColisao(ElementoRetangular *elementoA, ElementoRetangular *elementoB)
{
	int colisao;
	int sobreposicao;

	if( elementoA -> getX() > (elementoB -> getX() + elementoB -> getLargura()) || 
			elementoA -> getY() > (elementoB -> getY() + elementoB -> getAltura()) ||
			(elementoA -> getX() + elementoA -> getLargura()) < elementoB -> getX() ||	
	 		(elementoA -> getY() + elementoA -> getAltura()) < elementoB -> getY() )
	{
		colisao = NENHUMA_COLISAO;
	}
	else
	{
	 	colisao = COLISAO_ESQUERDA;
	  	sobreposicao = abs(elementoA -> getX() - (elementoB -> getX() + elementoB -> getLargura()));

		int sobreposicaoTestada = abs((elementoA -> getX() + elementoA -> getLargura()) - elementoB -> getX());
		if(sobreposicaoTestada < sobreposicao)
	    	{
		  	colisao = COLISAO_DIREITA;
		  	sobreposicao = sobreposicaoTestada;
	    	}

		sobreposicaoTestada = abs(elementoA -> getY() - (elementoB -> getY() + elementoB -> getAltura()));
		if( sobreposicaoTestada < sobreposicao)
		{
			colisao = COLISAO_CIMA;
			sobreposicao = sobreposicaoTestada;
		}

		sobreposicaoTestada = abs((elementoA -> getY() + elementoA -> getAltura()) - elementoB -> getY());		
		if( sobreposicaoTestada < sobreposicao )
		{
			colisao = COLISAO_BAIXO;
			sobreposicao = sobreposicaoTestada;
		}

		elementoA -> tratarColisao(colisao);
		elementoB -> tratarColisao(inversoDaColisao(colisao));
	}
		
	return colisao;
}

int DetectorColisoes::detectarColisao(ElementoRetangular *elementoA, ElementoRedondo *elementoB)
{
	int ladoColisao = NENHUMA_COLISAO;
	
	for( int pixel = elementoA->getX(); pixel <= elementoA->getX() + elementoA->getLargura(); pixel++)
	{
		if(calcularDistanciaEntreDoisPontos(pixel, elementoA->getY(), elementoB->getX(), elementoB->getY()) <= (double)elementoB->getRaio())
		{
			ladoColisao = COLISAO_CIMA;
			break;		
		}
	
		if(calcularDistanciaEntreDoisPontos(pixel, elementoA->getY()+(elementoA->getAltura()), elementoB->getX(), elementoB->getY()) <= (double)elementoB->getRaio())
		{
			ladoColisao = COLISAO_BAIXO;
			break;	
		}
	}

	for( int pixel = elementoA->getY(); pixel <= elementoA->getY()+(elementoA->getAltura()); pixel++)
	{
		if(calcularDistanciaEntreDoisPontos( elementoA->getX(), pixel, elementoB->getX(), elementoB->getY()) <= (double)elementoB->getRaio())
		{
			if( pixel - elementoA->getY() < (elementoA->getAltura()/2) -5){
				ladoColisao = COLISAO_ESQUERDA_CIMA;
			}
			else if ( pixel - elementoA->getY() > (elementoA->getAltura()/2)+ 5){
				ladoColisao = COLISAO_ESQUERDA_BAIXO;
			}			
			else
				ladoColisao = COLISAO_ESQUERDA;	
			break;
		}

		if(calcularDistanciaEntreDoisPontos( elementoA->getX()+(elementoA->getLargura()), pixel, elementoB->getX(), elementoB->getY()) <= (double)elementoB->getRaio())
		{
			if( pixel - elementoA->getY() < elementoA->getAltura()/3){
				ladoColisao = COLISAO_DIREITA_CIMA;
			}
			else if ( pixel - elementoA->getY() > (elementoA->getAltura()/3)*2){
				ladoColisao = COLISAO_DIREITA_BAIXO;
			}			
			else
				ladoColisao = COLISAO_DIREITA;
			break;			
		}
	}

	elementoB -> tratarColisao(ladoColisao);
	

	if(ladoColisao == COLISAO_DIREITA_BAIXO || ladoColisao == COLISAO_DIREITA_CIMA){
		ladoColisao = COLISAO_DIREITA;
	}
	if(ladoColisao == COLISAO_ESQUERDA_BAIXO || ladoColisao == COLISAO_ESQUERDA_CIMA){
		ladoColisao = COLISAO_ESQUERDA;
	}

	elementoA -> tratarColisao(ladoColisao);
	return ladoColisao;
}

int DetectorColisoes::inversoDaColisao(int colisao)
{
	if( colisao == COLISAO_CIMA )
		return COLISAO_BAIXO;
	else if( colisao == COLISAO_BAIXO )
		return COLISAO_CIMA;
	else if( colisao == COLISAO_ESQUERDA )
		return COLISAO_DIREITA;
	else if( colisao == COLISAO_DIREITA )
		return COLISAO_ESQUERDA;

	return NENHUMA_COLISAO;
}

double DetectorColisoes::calcularDistanciaEntreDoisPontos(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

#endif
