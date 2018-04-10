#include <iostream>

#include "jogador.h"

Jogador::Jogador():m_nome("None"),m_pontos(0),m_status(ATIVO){}
	
Jogador::Jogador(string nome_):m_nome(nome_),m_pontos(0),m_status(ATIVO){}

Jogador::~Jogador(){}

void 
Jogador::Jogar(Dado &d1, Dado &d2){
	int jogada = d1.jogar()+d2.jogar();
	m_pontos+=jogada;
	if (m_pontos>m_alvo){
		m_status=EXCLUIDO;
		std::cout << m_nome << " pontuou: " << jogada << " e estourou os pontos (" << m_pontos << ") e foi EXCLUIDO." << std::endl;
	} else {
		std::cout << m_nome << " pontuou: " << jogada << " | total: " << m_pontos << std::endl;
	}
}

int 
Jogador::getPontos(){
	return m_pontos;
}

string 
Jogador::getNome(){
	return m_nome;
}

StatusJogador 
Jogador::getStatus(){
	return m_status;
}

bool 
Jogador::podeJogar(){
	if (m_status==EXCLUIDO){
		return false;
	}
	char opcao;
	do{
		std::cout << m_nome << "(" << m_pontos << ")" << ", deseja jogar nesta rodada? (S/N): ";
		std::cin >> opcao;
		std::cin.ignore();
	} while (opcao!='S' && opcao!='s' && opcao!='N' && opcao!='n');
	if (opcao=='S' || opcao=='s'){
		m_status=ATIVO;
		return true;
	}
	m_status=PARADO;
	return false;
}

int 
Jogador::getAlvo(){
	return m_alvo;
}
