#include <cstdlib> 	//abs
#include <cstdio>		//sprintf

using namespace std;

class Tempo
{
	private:
		int tempoTotal;
		char *tempo;
		void formatarTempo(int segundos, int minutos);
		
	public:	
		Tempo();
		char* toString();
		void incrementar();
		int getTempoTotal();
		void zerarTempo();
};

Tempo::Tempo()
{
	zerarTempo();
}

void Tempo::zerarTempo()
{
	tempoTotal = 0;
}

char* Tempo::toString()
{
	int minutos = tempoTotal / 60;
	int segundos = tempoTotal - (minutos * 60);
	
	formatarTempo(segundos, minutos);
	return tempo;
}

int Tempo::getTempoTotal()
{
	return tempoTotal;
}

void Tempo::formatarTempo(int segundos, int minutos)
{
	char buffer[2];

	tempo = new char[6];

	sprintf(buffer, "%i", abs(minutos/10));
	*tempo = buffer[0];
	
	sprintf(buffer, "%i", abs(minutos%10)); 
	*(tempo+1) = buffer[0];

	*(tempo+2) = ':';
	
	sprintf(buffer, "%i", abs(segundos/10)); 
	*(tempo+3) = buffer[0];
		
	sprintf(buffer, "%i", abs(segundos%10)); 
	*(tempo+4) = buffer[0];
	*(tempo+5) = '\0';
}

void Tempo::incrementar()
{
	tempoTotal++;
}
