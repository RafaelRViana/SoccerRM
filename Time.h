#ifndef TIME
#define TIME

class Time
{
	
	private:
		char* nome;
		BITMAP *uniformeJogador;
		BITMAP *uniformeGoleiro;
		BITMAP *escudo;
		BITMAP *letreiro;

	public:
		Time(char* nome, BITMAP* uniformeJogador, BITMAP* uniformeGoleiro, BITMAP* escudo, BITMAP* letreiro);
		~Time();
		char* getNome();
		BITMAP* getUniformeJogador();
		BITMAP* getUniformeGoleiro();
		BITMAP* getEscudo();
		BITMAP* getLetreiro();

};

Time::Time(char* nome, BITMAP* uniformeJogador, BITMAP* uniformeGoleiro, BITMAP* escudo, BITMAP* letreiro)
{
	this -> nome = nome;
	this -> uniformeJogador = uniformeJogador;
	this -> uniformeGoleiro = uniformeGoleiro;
	this -> escudo = escudo;
	this -> letreiro = letreiro;
}

Time::~Time()
{
	destroy_bitmap(uniformeJogador);
	destroy_bitmap(uniformeGoleiro);
	destroy_bitmap(escudo);
	destroy_bitmap(letreiro);
}

char* Time::getNome()
{
	return nome;
}

BITMAP* Time::getUniformeJogador()
{
	return uniformeJogador;
}

BITMAP* Time::getUniformeGoleiro()
{
	return uniformeGoleiro;
}

BITMAP* Time::getEscudo()
{
	return escudo;
}

BITMAP* Time::getLetreiro()
{
	return letreiro;
}

#endif
