#ifndef MODO_JOGO
#define MODO_JOGO

class ModoJogo
{

	public:
		virtual void marcarGolNaGoleiraDireita() = 0;
		virtual void marcarGolNaGoleiraEsquerda() = 0;
		virtual void desenharPlacar() = 0;

};

#endif
