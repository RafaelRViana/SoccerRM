#ifndef MENU_PRINCIPAL
#define MENU_PRINCIPAL

#include "AcoesMenu.h"

class MenuPrincipal
{

	private:
		BITMAP* buffer;
		BITMAP *imagem;

		BITMAP* menuStartGameSelecionado;
		BITMAP* menuSelectTimeSelecionado;
		BITMAP* menuSelectTeamSelecionado;
		BITMAP* menuExitGameSelecionado;
		BITMAP* menuNenhumItemSelecionado;

		BITMAP *marcadorMenu;
		int indiceSelecionado;

	public:
		MenuPrincipal(BITMAP *buffer);
		~MenuPrincipal();

		bool mouseSobreStartGame();
		bool mouseSobreSelectTeam();
		bool mouseSobreSelectTime();
		bool mouseSobreExitGame();

		int aoClicarComOMouse();
		bool clicouBotaoEsquerdoMouse();
		int getIndiceSelecionado();	
	
		void desenhar();

};

MenuPrincipal::MenuPrincipal(BITMAP *buffer)
{
	this -> buffer = buffer;
	this -> imagem = create_bitmap(800, 640);

	indiceSelecionado = 0;

	menuSelectTeamSelecionado = load_bitmap("Imagens/menu1.bmp", NULL);
	menuSelectTimeSelecionado = load_bitmap("Imagens/menu2.bmp", NULL);
	menuStartGameSelecionado = load_bitmap("Imagens/menu3.bmp", NULL);
	menuExitGameSelecionado = load_bitmap("Imagens/menu4.bmp", NULL);
	menuNenhumItemSelecionado = load_bitmap("Imagens/menu.bmp", NULL);
}

MenuPrincipal::~MenuPrincipal()
{
	destroy_bitmap(menuStartGameSelecionado);
	destroy_bitmap(menuSelectTimeSelecionado);
	destroy_bitmap(menuSelectTeamSelecionado);
	destroy_bitmap(menuExitGameSelecionado);
}

bool MenuPrincipal::clicouBotaoEsquerdoMouse()
{
	return (mouse_b & 1);
}

int MenuPrincipal::aoClicarComOMouse()
{
	indiceSelecionado = NENHUM_ITEM_SELECIONADO;

	if(clicouBotaoEsquerdoMouse())
	{
		if(mouseSobreSelectTeam())
		{
			indiceSelecionado = SELECIONAR_TIMES;
		}
		
		else if(mouseSobreSelectTime())
		{
			indiceSelecionado = SELECIONAR_TEMPO;
		}

		else if(mouseSobreStartGame())
		{
			indiceSelecionado = COMECAR_JOGO;
		}

		else if(mouseSobreExitGame())
		{
			indiceSelecionado = FECHAR_JOGO;
		}
	}

	return indiceSelecionado;
}

int MenuPrincipal::getIndiceSelecionado()
{
	return indiceSelecionado;
}

bool MenuPrincipal::mouseSobreSelectTeam()
{
	return (mouse_x >= 85 && mouse_x <= 305) && (mouse_y >= 95 && mouse_y <= 125);
}

bool MenuPrincipal::mouseSobreSelectTime()
{
	return (mouse_x >= 85 && mouse_x <= 250) && (mouse_y >= 170 && mouse_y <= 225);
}

bool MenuPrincipal::mouseSobreStartGame()
{
	return (mouse_x >= 85 && mouse_x <= 300) && (mouse_y >= 300 && mouse_y <= 340);
}

bool MenuPrincipal::mouseSobreExitGame()
{
	return (mouse_x >= 85 && mouse_x <= 290) && (mouse_y >= 415 && mouse_y <= 455);
}

void MenuPrincipal::desenhar()
{
	if( mouseSobreSelectTeam() )
		draw_sprite( buffer, menuSelectTeamSelecionado, 0, 0 );
	else if( mouseSobreSelectTime() )
		draw_sprite( buffer, menuSelectTimeSelecionado, 0, 0 );
	else if( mouseSobreStartGame() )
		draw_sprite( buffer, menuStartGameSelecionado, 0, 0 );
	else if( mouseSobreExitGame() )
		draw_sprite( buffer, menuExitGameSelecionado, 0, 0 );
	else
		draw_sprite( buffer, menuNenhumItemSelecionado, 0, 0 );

	blit(buffer, screen, 0, 0, 0, 0, 800, 600 );	
}

#endif
