#ifndef MENU_ESCOLHA_TIMES
#define MENU_ESCOLHA_TIMES

#include "AcoesMenu.h"

class MenuEscolhaTimes
{

	private:
		BITMAP* buffer;
		BITMAP *imagemFundo;
		GerenciadorTimes *gerenciador;

		Time* timeJogador1;
		int indiceJogador1;
		Time* timeJogador2;
		int indiceJogador2;

		bool timesJaForamSelecionados;

	public:
		MenuEscolhaTimes(BITMAP *buffer);
		~MenuEscolhaTimes();
		
		Time* getTimeJogador1();
		Time* getTimeJogador2();

		void aoClicarNaPrimeiraSetaParaVoltar();
		void aoClicarNaPrimeiraSetaParaAvancar();
		void aoClicarNaSegundaSetaParaVoltar();
		void aoClicarNaSegundaSetaParaAvancar();

		bool mouseSobrePrimeiraSetaParaVoltar();
		bool mouseSobrePrimeiraSetaParaAvancar();
		bool mouseSobreSegundaSetaParaVoltar();
		bool mouseSobreSegundaSetaParaAvancar();
		bool mouseSobreBotaoConfirmar();

		int avancarIndice(int indice);
		int retrocederIndice(int indice);

		bool getTimesJaForamSelecionados();

		void verificarCliqueDoMouse();
		bool clicouBotaoEsquerdoMouse();
		void desenhar();
		void inicializar();
};

MenuEscolhaTimes::MenuEscolhaTimes(BITMAP *buffer)
{
	this -> buffer = buffer;
	this -> gerenciador = new GerenciadorTimes();
	
	inicializar();

	imagemFundo = load_bitmap("Imagens/select_team.bmp", NULL);
}

void MenuEscolhaTimes::inicializar()
{
	this -> indiceJogador1 = 0;
	this -> indiceJogador2 = 1;
	this -> timesJaForamSelecionados = false;

	this -> timeJogador1 = gerenciador -> buscarPorIndice(indiceJogador1);
	this -> timeJogador2 = gerenciador -> buscarPorIndice(indiceJogador2);
}

MenuEscolhaTimes::~MenuEscolhaTimes()
{
	destroy_bitmap(imagemFundo);
}

Time* MenuEscolhaTimes::getTimeJogador1()
{
	return timeJogador1;
}

Time* MenuEscolhaTimes::getTimeJogador2()
{
	return timeJogador2;
}

bool MenuEscolhaTimes::clicouBotaoEsquerdoMouse()
{
	return (mouse_b & 1);
}

void MenuEscolhaTimes::verificarCliqueDoMouse()
{
	if(clicouBotaoEsquerdoMouse())
	{
		if(mouseSobrePrimeiraSetaParaVoltar())
		{
			aoClicarNaPrimeiraSetaParaVoltar();
		}
		
		else if(mouseSobrePrimeiraSetaParaAvancar())
		{
			aoClicarNaPrimeiraSetaParaAvancar();
		}

		else if(mouseSobreSegundaSetaParaVoltar())
		{
			aoClicarNaSegundaSetaParaVoltar();
		}

		else if(mouseSobreSegundaSetaParaAvancar())
		{
			aoClicarNaSegundaSetaParaAvancar();
		}
		else if(mouseSobreBotaoConfirmar())
		{
			timesJaForamSelecionados = true;
		}
	}
}

bool MenuEscolhaTimes::mouseSobrePrimeiraSetaParaVoltar()
{
	return (mouse_x >= 35 && mouse_x <= 80) && (mouse_y >= 465 && mouse_y <= 510);
}

bool MenuEscolhaTimes::mouseSobrePrimeiraSetaParaAvancar()
{
	return (mouse_x >= 305 && mouse_x <= 350) && (mouse_y >= 465 && mouse_y <= 510);
}

bool MenuEscolhaTimes::mouseSobreSegundaSetaParaVoltar()
{
	return (mouse_x >= 420 && mouse_x <= 465) && (mouse_y >= 465 && mouse_y <= 510);
}

bool MenuEscolhaTimes::mouseSobreSegundaSetaParaAvancar()
{
	return (mouse_x >= 710 && mouse_x <= 755) && (mouse_y >= 465 && mouse_y <= 510);
}

bool MenuEscolhaTimes::mouseSobreBotaoConfirmar()
{
	return (mouse_x >= 710 && mouse_x <= 755) && (mouse_y >= 525 && mouse_y <= 575);
}

void MenuEscolhaTimes::aoClicarNaPrimeiraSetaParaVoltar()
{
	indiceJogador1 = retrocederIndice(indiceJogador1);
	timeJogador1 = gerenciador -> buscarPorIndice(indiceJogador1);
}

void MenuEscolhaTimes::aoClicarNaPrimeiraSetaParaAvancar()
{
	indiceJogador1 = avancarIndice(indiceJogador1);
	timeJogador1 = gerenciador -> buscarPorIndice(indiceJogador1);
}

void MenuEscolhaTimes::aoClicarNaSegundaSetaParaVoltar()
{
	indiceJogador2 = retrocederIndice(indiceJogador2);
	timeJogador2 = gerenciador -> buscarPorIndice(indiceJogador2);
}

void MenuEscolhaTimes::aoClicarNaSegundaSetaParaAvancar()
{
	indiceJogador2 = avancarIndice(indiceJogador2);
	timeJogador2 = gerenciador -> buscarPorIndice(indiceJogador2);
}

int MenuEscolhaTimes::avancarIndice(int indice)
{
	if(indice == 9)
		indice = 0;
	else 
		indice++;

	return indice;
}

int MenuEscolhaTimes::retrocederIndice(int indice)
{
	if(indice == 0)
		indice = 9;
	else 
		indice--;

	return indice;
}

bool MenuEscolhaTimes::getTimesJaForamSelecionados()
{
	return timesJaForamSelecionados;
}

void MenuEscolhaTimes::desenhar()
{
	draw_sprite( buffer, imagemFundo, 0, 0 );
	draw_sprite( buffer, timeJogador1 -> getUniformeJogador(), 180, 350);
	draw_sprite( buffer, timeJogador1 -> getLetreiro(), 85, 450);

	draw_sprite( buffer, timeJogador2 -> getUniformeJogador(), 570, 350);
	draw_sprite( buffer, timeJogador2 -> getLetreiro(), 480, 450);

	blit(buffer, screen, 0, 0, 0, 0, 800, 600 );	
}

#endif
