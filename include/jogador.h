#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "dado.h"

using std::string;

enum StatusJogador{ATIVO,PARADO,EXCLUIDO};

class Jogador
{
private:
	string m_nome;
	int m_pontos;

	StatusJogador m_status;

	static int m_alvo;

public:

	Jogador();
	Jogador(string nome_);
	~Jogador();

	void Jogar(Dado &d1, Dado &d2);
	bool podeJogar();

	int getPontos();
	string getNome();
	StatusJogador getStatus();

	static int getAlvo();
	
};

#endif