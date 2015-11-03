#include <iostream>
#include "Dimensoes.h"

using namespace std;

class SegundoTempo: public ModoJogo
{
	private:
		Placar *placar;
		Jogador *jogador1;
		Jogador *jogador2;
		Goleiro *goleiro1;
		Goleiro *goleiro2;
		BITMAP *buffer;
		BITMAP *imagem1;
		BITMAP *imagem2;

	public:
		SegundoTempo(BITMAP *buffer, Placar *placar, Jogador *jogador1, Jogador *jogador2, Goleiro *goleiro1, Goleiro *goleiro2);
		void marcarGolNaGoleiraEsquerda()
		{
			placar -> marcarGolJogadorUm();
		}
		void marcarGolNaGoleiraDireita()
		{
			placar -> marcarGolJogadorDois();
		}
		void desenharPlacar()
		{
			int linhaTexto = ALTURA_CAMPO + 5;
		 	textout_ex(buffer, font, jogador2 -> getTime() -> getNome(), 300, linhaTexto + 80, makecol (255,255,255), -1);
			textout_ex(buffer, font, jogador1 -> getTime() -> getNome(), 670, linhaTexto + 80, makecol (255,255,255), -1);
	
			draw_sprite(buffer, imagem1, 250, linhaTexto + 55);
			draw_sprite(buffer, imagem2, 620, linhaTexto + 55);

			char temp[100];

			sprintf(temp, "%d", placar -> getGolsJogadorDois());
			textout_ex(buffer, font, temp, 320, linhaTexto+40, makecol (255,255,255), -1);
	
			sprintf(temp, "%d", placar -> getGolsJogadorUm());
			textout_ex(buffer, font, temp, 690, linhaTexto+40, makecol (255,255,255), -1);
	
			textout_ex(buffer, font, "Second Time", 450, linhaTexto + 60, makecol (255,255,255), -1);	

			textout_ex(buffer, font, placar -> getTempoJogo(), 450, linhaTexto+40, makecol (255,255,255), -1);
			
			sprintf(temp, "Game Speed: %d", placar -> getVelocidadeJogo());		
			textout_ex(buffer, font, temp, 450, linhaTexto + 80, makecol(255,255,255), -1);
		}

};

SegundoTempo::SegundoTempo(BITMAP *buffer, Placar *placar, Jogador *jogador1, Jogador *jogador2, Goleiro *goleiro1, Goleiro *goleiro2)
{
	this -> buffer = buffer;
	imagem1 = jogador2 -> getTime() -> getEscudo();
	imagem2 = jogador1 -> getTime() -> getEscudo();

	this -> placar = placar;
	this -> jogador1 = jogador1;
	this -> jogador2 = jogador2;
	this -> goleiro1 = goleiro1;
	this -> goleiro2 = goleiro2;	

	//Mudar o posicionamento original dos jogadores, para fazer a inversão de lado no campo
	jogador1 -> setPosicaoInicial(600, 200);
	jogador2 -> setPosicaoInicial(200, 200);
	goleiro1 -> setPosicaoInicial(765, (ALTURA_CAMPO/2)-(ALTURA_GOLEIRO/2));
	goleiro2 -> setPosicaoInicial(25, (ALTURA_CAMPO/2)-(ALTURA_GOLEIRO/2));
};
