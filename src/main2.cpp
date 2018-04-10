#include "jogo.h"

int Jogador::m_alvo = 50;

int main(int argc, char const *argv[])
{
	Jogo game;
	game.addJogador(new Jogador("Boy"));
	game.addJogador(new Jogador("Boyzinha do Boy"));
	game.addJogador(new Jogador("Galado"));
	game.run();
	return 0;
}