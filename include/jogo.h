#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "dado.h"
#include "jogador.h"

#define MAX_JOGADORES 10

class Jogo
{
private:
	Jogador * m_jogadores[MAX_JOGADORES];
	int m_total_jogadores;
	Jogador * m_vencedor = nullptr;
	int m_rodadas;
	Dado m_dado1;
	Dado m_dado2;
public:
	Jogo();
	~Jogo();

	void novaRodada();
	int totalEmJogo();
	void run();
	void addJogador(Jogador * novo_);

	int getAtivos();
	void mostrarResultado();
	
};

#endif