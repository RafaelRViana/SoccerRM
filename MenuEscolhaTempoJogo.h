#ifndef MENU_ESCOLHA_TEMPO_JOGO
#define MENU_ESCOLHA_TEMPO_JOGO

#include "AcoesMenu.h"

class MenuEscolhaTempoJogo
{

	private:
		BITMAP *buffer;
		BITMAP *imagem;

		BITMAP *selecionadoUmMinuto;
		BITMAP *selecionadoDoisMinutos;
		BITMAP *selecionadoQuatroMinutos;

		int indiceSelecionado;

	public:
		MenuEscolhaTempoJogo(BITMAP *buffer);
		~MenuEscolhaTempoJogo();

		bool mouseSobreUmMinuto();
		bool mouseSobreDoisMinutos();
		bool mouseSobreQuatroMinutos();

		int aoClicarComOMouse();
		bool clicouBotaoEsquerdoMouse();
		int getIndiceSelecionado();	
	
		void desenhar();
};

MenuEscolhaTempoJogo::MenuEscolhaTempoJogo(BITMAP *buffer)
{
	this -> buffer = buffer;

	selecionadoUmMinuto = load_bitmap("Imagens/time1.bmp", NULL);
	selecionadoDoisMinutos = load_bitmap("Imagens/time2.bmp", NULL);
	selecionadoQuatroMinutos = load_bitmap("Imagens/time3.bmp", NULL);

	indiceSelecionado = UM_MINUTO;
}

MenuEscolhaTempoJogo::~MenuEscolhaTempoJogo()
{
	destroy_bitmap(selecionadoUmMinuto);
	destroy_bitmap(selecionadoDoisMinutos);
	destroy_bitmap(selecionadoQuatroMinutos);
}

bool MenuEscolhaTempoJogo::clicouBotaoEsquerdoMouse()
{
	return (mouse_b & 1);
}

int MenuEscolhaTempoJogo::aoClicarComOMouse()
{
	indiceSelecionado = NENHUM_ITEM_SELECIONADO;

	if(clicouBotaoEsquerdoMouse())
	{
		if(mouseSobreUmMinuto())
		{
			indiceSelecionado = UM_MINUTO;
		}
		
		else if(mouseSobreDoisMinutos())
		{
			indiceSelecionado = DOIS_MINUTOS;
		}

		else if(mouseSobreQuatroMinutos())
		{
			indiceSelecionado = QUATRO_MINUTOS;
		}
	}

	return indiceSelecionado;
}

int MenuEscolhaTempoJogo::getIndiceSelecionado()
{
	return indiceSelecionado;
}

bool MenuEscolhaTempoJogo::mouseSobreUmMinuto()
{
	return (mouse_x >= 120 && mouse_x <= 250) && (mouse_y >= 125 && mouse_y <= 200);
}

bool MenuEscolhaTempoJogo::mouseSobreDoisMinutos()
{
	return (mouse_x >= 120 && mouse_x <= 250) && (mouse_y >= 250 && mouse_y <= 280);
}

bool MenuEscolhaTempoJogo::mouseSobreQuatroMinutos()
{
	return (mouse_x >= 120 && mouse_x <= 250) && (mouse_y >= 320 && mouse_y <= 400);
}

void MenuEscolhaTempoJogo::desenhar()
{
	if( mouseSobreUmMinuto() )
		draw_sprite( buffer, selecionadoUmMinuto, 0, 0 );
	else if( mouseSobreDoisMinutos() )
		draw_sprite( buffer, selecionadoDoisMinutos, 0, 0 );
	else if( mouseSobreQuatroMinutos() )
		draw_sprite( buffer, selecionadoQuatroMinutos, 0, 0 );

	blit(buffer, screen, 0, 0, 0, 0, 800, 600 );		
}

#endif
