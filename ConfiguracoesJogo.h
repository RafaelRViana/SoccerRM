#ifndef CONFIGURACOES_JOGO
#define CONFIGURACOES_JOGO

class ConfiguracoesJogo
{

	private:
		
		int tempoJogo;
		Time* timeJogador1;
		Time* timeJogador2;

	public:
		ConfiguracoesJogo(int tempoJogo, Time* timeJogador1, Time* timeJogador2);
		int getTempoJogo();
		Time* getTimeJogador1();
		Time* getTimeJogador2();

};

ConfiguracoesJogo::ConfiguracoesJogo(int tempoJogo, Time* timeJogador1, Time* timeJogador2)
{
	this -> tempoJogo = tempoJogo;
	this -> timeJogador1 = timeJogador1;
	this -> timeJogador2 = timeJogador2;
}

int ConfiguracoesJogo::getTempoJogo()
{
	return tempoJogo;
}

Time* ConfiguracoesJogo::getTimeJogador1()
{
	return timeJogador1;
}

Time* ConfiguracoesJogo::getTimeJogador2()
{
	return timeJogador2;
}

#endif
