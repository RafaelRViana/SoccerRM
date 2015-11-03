#ifndef GERENCIADOR_TIMES
#define GERENCIADOR_TIMES

#include "Time.h"

class GerenciadorTimes
{

	private:
		Time* times[10];

	public:
		GerenciadorTimes();
		~GerenciadorTimes();		

		Time* buscarPorIndice(int indice);
};

GerenciadorTimes::~GerenciadorTimes()
{
	delete times[0];
	delete times[1];
	delete times[2];
	delete times[3];
	delete times[4];
	delete times[5];
	delete times[6];
	delete times[7];
	delete times[8];
	delete times[9];
}

GerenciadorTimes::GerenciadorTimes()
{
	times[0] = new Time("GRÊMIO", load_bitmap("Imagens/jogador_gremio.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_gremio.bmp", NULL), 
                     load_bitmap("Imagens/escudo_gremio.bmp", NULL),
			   load_bitmap("Imagens/nome_gremio.bmp", NULL));

	times[1] = new Time("ASSOEVA", load_bitmap("Imagens/jogador_assoeva.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_assoeva.bmp", NULL), 
                     load_bitmap("Imagens/escudo_assoeva.bmp", NULL),
			   load_bitmap("Imagens/nome_assoeva.bmp", NULL));
	
	times[2] = new Time("INTERNACIONAL", load_bitmap("Imagens/jogador_inter.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_inter.bmp", NULL), 
                     load_bitmap("Imagens/escudo_inter.bmp", NULL),
			   load_bitmap("Imagens/nome_inter.bmp", NULL));

	times[3] = new Time("GUARANI VA", load_bitmap("Imagens/jogador_guarani.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_guarani.bmp", NULL), 
                     load_bitmap("Imagens/escudo_guarani.bmp", NULL),
			   load_bitmap("Imagens/nome_guarani.bmp", NULL));

	times[4] = new Time("BARCELONA", load_bitmap("Imagens/jogador_barcelona.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_barcelona.bmp", NULL), 
                     load_bitmap("Imagens/escudo_barcelona.bmp", NULL),
			   load_bitmap("Imagens/nome_barcelona.bmp", NULL));

	times[5] = new Time("REAL MADRID", load_bitmap("Imagens/jogador_real_madrid.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_real_madrid.bmp", NULL), 
                     load_bitmap("Imagens/escudo_real_madrid.bmp", NULL),
			   load_bitmap("Imagens/nome_real_madrid.bmp", NULL));

	times[6] = new Time("BOCA JUNIORS", load_bitmap("Imagens/jogador_boca_juniors.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_boca_juniors.bmp", NULL), 
                     load_bitmap("Imagens/escudo_boca_juniors.bmp", NULL),
			   load_bitmap("Imagens/nome_boca_juniors.bmp", NULL));

	times[7] = new Time("RIVER PLATE", load_bitmap("Imagens/jogador_river_plate.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_river_plate.bmp", NULL), 
                     load_bitmap("Imagens/escudo_river_plate.bmp", NULL),
			   load_bitmap("Imagens/nome_river_plate.bmp", NULL));

	times[8] = new Time("MILAN", load_bitmap("Imagens/jogador_milan.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_milan.bmp", NULL), 
                     load_bitmap("Imagens/escudo_milan.bmp", NULL),
			   load_bitmap("Imagens/nome_milan.bmp", NULL));

	times[9] = new Time("INTER MILÃO", load_bitmap("Imagens/jogador_inter_milao.bmp", NULL), 
			   load_bitmap("Imagens/goleiro_inter_milao.bmp", NULL), 
                     load_bitmap("Imagens/escudo_inter_milao.bmp", NULL),
			   load_bitmap("Imagens/nome_inter_milao.bmp", NULL));
}

Time* GerenciadorTimes::buscarPorIndice(int indice)
{
	return times[indice];
}


#endif
