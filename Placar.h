#ifndef PLACAR
#define PLACAR

class Placar
{
	private:
		BITMAP *buffer;
		int golsJogador1;
		int golsJogador2;
		char* tempoJogo;
		int velocidadeJogo;

	public:
		Placar(BITMAP *buffer);
		void inicializar();
		void marcarGolJogadorUm();
		void marcarGolJogadorDois();
		int getGolsJogadorUm();
		int getGolsJogadorDois();
		void setTempoJogo(char* tempo);
		char* getTempoJogo();
		void setVelocidadeJogo(int velocidadeJogo);	
		int getVelocidadeJogo();
};

Placar::Placar(BITMAP *buffer)
{
	this -> buffer = buffer;
	this -> golsJogador1 = 0;
	this -> golsJogador2 = 0;
}

void Placar::inicializar()
{
	this -> golsJogador1 = 0;
	this -> golsJogador2 = 0;
	this -> setTempoJogo("0:00");
}

void Placar::marcarGolJogadorUm()
{
	golsJogador1++;	
}

void Placar::marcarGolJogadorDois()
{
	golsJogador2++;
}

int Placar::getGolsJogadorUm()
{
	return golsJogador1;
}

int Placar::getGolsJogadorDois()
{	
	return golsJogador2;
}

char* Placar::getTempoJogo()
{
	return tempoJogo;
}

void Placar::setTempoJogo(char* tempo)
{
	this -> tempoJogo = tempo;
}

void Placar::setVelocidadeJogo(int velocidadeJogo)
{
	this -> velocidadeJogo = velocidadeJogo;
}

int Placar::getVelocidadeJogo()
{
	return velocidadeJogo;
}

#endif
