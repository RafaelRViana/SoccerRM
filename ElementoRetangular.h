#ifndef ELEMENTO_RETANGULAR
#define ELEMENTO_RETANGULAR

#include <iostream>

using namespace std;

class ElementoRetangular
{
	protected:
		int x, y;		
		int altura, largura;

	public:
		ElementoRetangular( int x, int y, int altura, int largura );
		int getX();
		int getY();
		int getAltura();
		int getLargura();
		virtual void tratarColisao(int ladoColisao) = 0;
};

ElementoRetangular::ElementoRetangular( int x, int y, int altura, int largura )
{
	this -> x = x;
	this -> y = y;
	this -> altura = altura;
	this -> largura = largura;
}

int ElementoRetangular::getX()
{
	return x;
}

int ElementoRetangular::getY()
{
	return y;
}

int ElementoRetangular::getAltura()
{
	return altura;
}

int ElementoRetangular::getLargura()
{
	return largura;
}

#endif
