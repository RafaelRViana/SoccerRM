#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <allegro.h>
#include <string>

#include "ControladorJogo.h"
#include "MenuPrincipal.h"
#include "MenuEscolhaTimes.h"
#include "MenuEscolhaTempoJogo.h"
#include "AcoesMenu.h"
#include "GerenciadorTimes.h"

#define COLOR_BITS    32
#define VIDEO_CARD    GFX_AUTODETECT_WINDOWED

using namespace std;

void mostrarTelaDeApresentacao(BITMAP *buffer);
void iniciarPartida(BITMAP *buffer, ConfiguracoesJogo *configuracoes);
void mostrarMenuInicial(BITMAP *buffer);

/**
*	Funções para inicializar e finalizar a biblioteca Allegro 
*/
int inicia(void);
void finaliza(void);

/**
*	Funções para fazer cronometro do jogo funcionar. São declaradas em um escopo global devido a uma "limitação" da biblioteca Allegro para proporcionar compatibilidade com a linguagem C. 
*/
void inicializarContadorDeTempo();
void incrementarTempoJogo();
void pararContadorDeTempo();
Tempo tempoJogo;

void incrementarTempoJogo()
{
	tempoJogo.incrementar();
}
END_OF_FUNCTION(incrementarTempoJogo);

void inicializarContadorDeTempo()
{
	LOCK_VARIABLE(tempoJogo);
      LOCK_FUNCTION(incrementarTempoJogo);
      install_int(incrementarTempoJogo, 1000); //Chamar a função incrementar tempo a cada 1s
}

void pararContadorDeTempo()
{
	remove_int(incrementarTempoJogo);
}

int inicia (void)
{
      allegro_init();

      install_keyboard();
	install_mouse();
      install_timer();
	
      set_color_depth(COLOR_BITS);
      if (set_gfx_mode(VIDEO_CARD, MAX_X, MAX_Y, 0, 0) < 0)
      {
     		allegro_message("Erro ao inicializar o modo grafico");
      	return (FALSE);
      }

	return (TRUE);
}

void finaliza (void)
{
      allegro_exit();
}

int main (void)
{
      if (!inicia())
      {
            finaliza();
            exit(-1);
      }

	set_window_title("soccerRM SuperClássicos v.2.0");

      BITMAP *buffer = create_bitmap(MAX_X, MAX_Y);

      mostrarTelaDeApresentacao(buffer);
	mostrarMenuInicial(buffer);

      finaliza();
      exit(0);
}

void mostrarTelaDeApresentacao(BITMAP *buffer)
{
	buffer = load_bitmap("Imagens/imagemInicial.bmp", NULL);	
     	blit(buffer, screen, 0, 0, 0, 0, 800, 600 );

	rest(3000); 
}

void mostrarMenuInicial(BITMAP *buffer)
{
	ConfiguracoesJogo *configuracoes;
	MenuEscolhaTimes *menuEscolhaTimes = new MenuEscolhaTimes(buffer);
	MenuEscolhaTempoJogo *menuEscolhaTempoJogo = new MenuEscolhaTempoJogo(buffer);
	MenuPrincipal *menuPrincipal = new MenuPrincipal(buffer);

	while( menuPrincipal -> getIndiceSelecionado() != COMECAR_JOGO )
	{	
		//Uso do-while, pois preciso primeiro desenhar o menu para verificar o clique do mouse (apos uma partida)
		do
		{
			poll_mouse();		
			acquire_screen();	
			show_mouse(NULL); //Sempre desabilitar o mouse antes de desenhar qualquer coisa na tela...
			menuPrincipal -> desenhar();
			show_mouse(screen);
      		release_screen();
      		vsync();	
		} while( menuPrincipal -> aoClicarComOMouse() == NENHUM_ITEM_SELECIONADO );

		clear_keybuf();

		switch( menuPrincipal -> getIndiceSelecionado() )
		{
			case 0 :
				menuEscolhaTimes -> inicializar(); //Para permitir entrar outras vezes no menu para selecionar times 
				while( !menuEscolhaTimes -> getTimesJaForamSelecionados() )
				{
					poll_mouse();		
					acquire_screen();	
					show_mouse(NULL);
					menuEscolhaTimes -> desenhar();
					menuEscolhaTimes -> verificarCliqueDoMouse();
					show_mouse(screen);
					release_screen();
					rest(100);
					vsync();
				}
		 	 break;

	  		case 1:
				while( menuEscolhaTempoJogo -> aoClicarComOMouse() == NENHUM_ITEM_SELECIONADO )
				{
					poll_mouse();		
					acquire_screen();	
					show_mouse(NULL);
					menuEscolhaTempoJogo -> desenhar();
					show_mouse(screen);
					release_screen();
					vsync();
				}
			break;

  	  		case 3 : 
    				finaliza();
				exit(0);
	  		break;
		}
	}

	configuracoes = new ConfiguracoesJogo(menuEscolhaTempoJogo -> getIndiceSelecionado(), menuEscolhaTimes -> getTimeJogador1(), menuEscolhaTimes -> getTimeJogador2());
	iniciarPartida(buffer, configuracoes);
}

void iniciarPartida(BITMAP *buffer, ConfiguracoesJogo *configuracoes)
{
	show_mouse(NULL);

	ControladorJogo controlador(buffer, configuracoes);

	Menu *menu = new Menu(buffer);
	menu -> desenhar();

	bool precisaPausarJogo = false;
	bool resetarJogo = false;

	controlador.processar(); //Para desenhar a tela inicial do jogo.
	
	//Só começa o jogo apos apertar 1
	while(!key[KEY_1])
	{
		controlador.desenhar();
		controlador.renderizarTela();
		menu -> desenhar();

		if( key[KEY_ESC] ) //Posso sair antes de começar a partida
		{
			mostrarMenuInicial(buffer);
			return;
		}
	}

	controlador.reiniciarPartida();			
	tempoJogo.zerarTempo();

	while (!key[KEY_ESC])
      {
		menu -> desenhar();

		if( key[KEY_1])
		{
			inicializarContadorDeTempo();
		}

		if( key[KEY_2] || precisaPausarJogo)
		{
			precisaPausarJogo = false;
			pararContadorDeTempo();

			while( !key[KEY_1] )
			{
				if( key[KEY_ESC] ) //Volto para o menu principal, ao apertar ESC durante o pause
				{
					mostrarMenuInicial(buffer);
					return;
				}

				if( key[KEY_3] ) //Posso resetar jogo durante o pause	
					break;     //Saio do loop do pause para continuar, e entrar no if do reset
			}

			inicializarContadorDeTempo();			
		}

		if( key[KEY_3] )
		{
			controlador.reiniciarPartida();			
			tempoJogo.zerarTempo();	
			precisaPausarJogo = true;	
		}
		
		controlador.setTempoJogo(tempoJogo);
		controlador.processar();
	}

	//Apertei ESC durante a partida
	mostrarMenuInicial(buffer);
}
