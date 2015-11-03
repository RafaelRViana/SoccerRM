#ifndef ESTADIO
#define ESTADIO

#include "Dimensoes.h"

class Estadio
{
	private:
		BITMAP *buffer;			

	public:
		Estadio(BITMAP *buffer);
		void desenhar();

		void desenharCampo();
		void desenharArea();
		void desenharCirculoCentral();
		void desenharLinhasLaterais();
		void desenharLinhaCentral();
		void desenharSeparadores();
};

Estadio::Estadio(BITMAP *buffer)
{
	this -> buffer = buffer;
}

void Estadio::desenharCampo()
{
	rectfill(buffer, 0, 0, MAX_X, ALTURA_CAMPO, makecol(0,204,0));
}

void Estadio::desenharArea()
{
	circlefill(buffer, LARGURA_AREA, ALTURA_CAMPO/2, 40, makecol(255, 255, 255));
	circlefill(buffer, LARGURA_AREA, ALTURA_CAMPO/2, 35, makecol(0,204,0));
	rectfill(buffer, 20, ALTURA_CAMPO/2-100, LARGURA_AREA, ALTURA_AREA, makecol(255, 255, 255));
	rectfill(buffer, 20, ALTURA_CAMPO/2-95, LARGURA_AREA-5, ALTURA_AREA-5, makecol(0,204,0));


	circlefill(buffer, MAX_X-LARGURA_AREA, ALTURA_CAMPO/2, 40, makecol(255, 255, 255));
	circlefill(buffer, MAX_X-LARGURA_AREA, ALTURA_CAMPO/2, 35, makecol(0,204,0));
	rectfill(buffer, MAX_X-20, ALTURA_CAMPO/2-100, MAX_X-LARGURA_AREA, ALTURA_AREA, makecol(255, 255, 255));
	rectfill(buffer, MAX_X-20, ALTURA_CAMPO/2-95, MAX_X-(LARGURA_AREA-5), ALTURA_AREA-5, makecol(0,204,0));
}

void Estadio::desenharCirculoCentral()
{
	circlefill(buffer, MAX_X/2, ALTURA_CAMPO/2, 100, makecol(255, 255, 255));
	circlefill(buffer, MAX_X/2, ALTURA_CAMPO/2, 96, makecol(0,204,0));
	circlefill(buffer, (MAX_X / 2), (ALTURA_CAMPO / 2), 12, makecol(255, 255, 255)); //Marcação Bola
}

void Estadio::desenharLinhasLaterais()
{
	rectfill(buffer, 15, 30, 20, ALTURA_CAMPO-30, makecol(255, 255, 255)); //Linha Esquerda
	rectfill(buffer, MAX_X - 15, 30, MAX_X -20, ALTURA_CAMPO-30, makecol(255, 255, 255)); //Linha Direita
	rectfill(buffer, 15, 30, MAX_X-15, 35, makecol(255, 255, 255)); //Linha Cima
	rectfill(buffer, 15, ALTURA_CAMPO-30, MAX_X-15, ALTURA_CAMPO -35, makecol(255, 255, 255)); //Linha Baixo
}

void Estadio::desenharSeparadores()
{
	rectfill(buffer, 0, 0, MAX_X, 5, makecol(255, 255, 255));	//Separador Superior
	rectfill(buffer, 0, ALTURA_CAMPO, MAX_X, ALTURA_CAMPO - 5, makecol(255, 255, 255)); //Separador Inferior
}

void Estadio::desenharLinhaCentral()
{
	rectfill(buffer, (MAX_X / 2) - 1, 30, (MAX_X / 2) + 1, ALTURA_CAMPO-30, makecol(255, 255, 255));
}

void Estadio::desenhar()
{
	desenharCampo();
	desenharArea();
	desenharCirculoCentral();
	desenharLinhasLaterais();
	desenharLinhaCentral();
	desenharSeparadores();
}

#endif
