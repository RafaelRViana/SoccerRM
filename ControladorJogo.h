#ifndef CONTROLADOR_JOGO
#define CONTROLADOR_JOGO

#include <cstdio>

#include "Dimensoes.h"
#include "Jogador.h"
#include "Bola.h"
#include "Estadio.h"
#include "DetectorColisoes.h"
#include "Goleira.h"
#include "Placar.h"
#include "Goleiro.h"
#include "Menu.h"
#include "ModoJogo.h"
#include "PrimeiroTempo.h"
#include "SegundoTempo.h"
#include "Tempo.h"
#include "ConfiguracoesJogo.h"

class ControladorJogo
{

	private:
		BITMAP *buffer;

		Estadio *estadio;
		Bola *bola;
		Jogador *jogador1;
		Jogador *jogador2;
		Goleiro *goleiro1;
		Goleiro *goleiro2;
		Goleira *goleiraEsquerda;
		Goleira *goleiraDireita;
		Placar *placar;
		ModoJogo *modoJogo;
	
		DetectorColisoes detector;
		Tempo tempoJogo;
		int tempoTotalJogo;
		bool jogoTerminou;
		int velocidadeJogo;

		void aumentarVelocidade();
		void diminuirVelocidade();

		void mover();
		void detectarColisoes();
		void reiniciar();	

	public:
		ControladorJogo(BITMAP *bufferReceived, ConfiguracoesJogo *configuracoes);	
		~ControladorJogo();
		void processar();
		void setTempoJogo(Tempo tempo);
		void setModoJogo(ModoJogo *modo);
		void reiniciarPartida();
		void desenhar();		
		void renderizarTela();	
};

ControladorJogo::ControladorJogo(BITMAP *bufferReceived, ConfiguracoesJogo *configuracoes)
{
	buffer = bufferReceived;
 	tempoJogo = Tempo();
	velocidadeJogo = 0;
	
	tempoTotalJogo = configuracoes -> getTempoJogo(); 
	estadio = new Estadio(buffer);
	bola = new Bola(buffer, makecol(255,255,255));
	jogador1 = new Jogador(buffer, 200, 200, KEY_D, KEY_A, KEY_S, KEY_W, configuracoes -> getTimeJogador1());
	jogador2 = new Jogador(buffer, 600, 200, KEY_RIGHT, KEY_LEFT, KEY_DOWN, KEY_UP, configuracoes -> getTimeJogador2());	
	goleiro1 = new Goleiro(buffer, 25, (ALTURA_CAMPO/2)-(ALTURA_GOLEIRO/2), KEY_T, KEY_G, configuracoes -> getTimeJogador1());
	goleiro2 = new Goleiro(buffer, 765, (ALTURA_CAMPO/2)-(ALTURA_GOLEIRO/2), KEY_O, KEY_L, configuracoes -> getTimeJogador2());
	goleiraEsquerda = new Goleira(buffer, 0, (ALTURA_CAMPO / 2) - (ALTURA_GOLEIRA / 2));
	goleiraDireita = new Goleira(buffer, MAX_X - 19, (ALTURA_CAMPO/2) - (ALTURA_GOLEIRA / 2));
	placar = new Placar(buffer);
	modoJogo = new PrimeiroTempo(buffer, placar, jogador1, jogador2, goleiro1, goleiro2);	
	detector = DetectorColisoes();
}

ControladorJogo::~ControladorJogo()
{
	destroy_bitmap(buffer);
}

void ControladorJogo::setModoJogo(ModoJogo *modoJogo)
{
	this -> modoJogo = modoJogo;
}

void ControladorJogo::setTempoJogo(Tempo tempo)
{
	this -> tempoJogo = tempo;
}

void ControladorJogo::processar()
{
	if( !jogoTerminou )	
	{
		if( key[KEY_MINUS] )
			diminuirVelocidade();
		if( key[KEY_EQUALS] )
			aumentarVelocidade();

		placar -> setTempoJogo(tempoJogo.toString());
		placar -> setVelocidadeJogo(velocidadeJogo);
		mover();
		desenhar();	
		detectarColisoes();		

		if( tempoJogo.getTempoTotal() == (tempoTotalJogo / 2))
		{
			modoJogo = new SegundoTempo(buffer, placar, jogador1, jogador2, goleiro1, goleiro2);
			reiniciar();
		}
		if( tempoJogo.getTempoTotal() == tempoTotalJogo )
		{
			jogoTerminou = true;
		}
	}
	else
	{
		char temp[100];

		if( placar -> getGolsJogadorUm() > placar -> getGolsJogadorDois() )
			sprintf(temp, "%s WINS!", jogador1 -> getTime() -> getNome());
		else if( placar -> getGolsJogadorUm() < placar -> getGolsJogadorDois() )
			sprintf(temp, "%s WINS!", jogador2 -> getTime() -> getNome());
		else
			sprintf(temp, "%s", "DRAW!");

		desenhar();	//Desenhar antes de escrever a mensagem na tela para não sobrescrever
		textout_ex(buffer, font, temp, (MAX_X / 2) - (text_length(font, temp) / 2), (MAX_Y/2), makecol (255,255,0), 1);
	}
	
	renderizarTela();
}

void ControladorJogo::reiniciar()
{
	bola -> inicializar();
	jogador1 -> inicializar();
	jogador2 -> inicializar();
	goleiro1 -> inicializar();
	goleiro2 -> inicializar();
}

void ControladorJogo::reiniciarPartida()
{
	modoJogo = new PrimeiroTempo(buffer, placar, jogador1, jogador2, goleiro1, goleiro2);
	reiniciar();
	placar -> inicializar();
	jogoTerminou = false;
}

void ControladorJogo::mover()
{
	jogador1 -> mover();	
	jogador2 -> mover();
	goleiro1 -> mover();
	goleiro2 -> mover();
	bola -> mover();	
}

void ControladorJogo::renderizarTela()
{
	blit(buffer, screen, 0,0,0,0, MAX_X, MAX_Y);	
	clear_bitmap(buffer);
}

void ControladorJogo::desenhar()
{
	estadio -> desenhar();
	goleiraEsquerda -> desenhar();
	goleiraDireita -> desenhar();		
	goleiro1 -> desenhar();
	goleiro2 -> desenhar();
	jogador1 -> desenhar();
	jogador2 -> desenhar();
	
	modoJogo -> desenharPlacar();
	bola -> desenhar();

	rest(velocidadeJogo);
}

void ControladorJogo::detectarColisoes()
{
	detector.detectarColisao(jogador1, jogador2);	
	detector.detectarColisao(jogador1, goleiraEsquerda);
	detector.detectarColisao(jogador1, goleiraDireita);
	detector.detectarColisao(jogador1, goleiro1);
	detector.detectarColisao(jogador1, goleiro2);
	detector.detectarColisao(jogador1, bola);
	detector.detectarColisao(jogador2, goleiraEsquerda);
	detector.detectarColisao(jogador2, goleiraDireita);
	detector.detectarColisao(jogador2, goleiro1);
	detector.detectarColisao(jogador2, goleiro2);
	detector.detectarColisao(jogador2, bola);		
		
	detector.detectarColisao(goleiro1, bola);
	detector.detectarColisao(goleiro2, bola);

	if(detector.detectarColisao(goleiraDireita, bola) == COLISAO_ESQUERDA)
	{
		modoJogo -> marcarGolNaGoleiraDireita();
		reiniciar();			
	}

	if(detector.detectarColisao(goleiraEsquerda, bola) == COLISAO_DIREITA)
	{
		modoJogo -> marcarGolNaGoleiraEsquerda();
		reiniciar();
	}
}

void ControladorJogo::aumentarVelocidade()
{
	velocidadeJogo += 1;
}

void ControladorJogo::diminuirVelocidade()
{
	if( velocidadeJogo >= 1 )
		velocidadeJogo -= 1;
}
#endif
