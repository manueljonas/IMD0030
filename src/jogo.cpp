#include "jogo.h"

Jogo::Jogo():m_total_jogadores(0), m_rodadas(0){}

Jogo::~Jogo(){}

void 
Jogo::novaRodada(){
	m_rodadas++;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "RODADA #" << m_rodadas << std::endl;
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		// Caso seja o unico jogador no jogo, ja o declara vencedor
		if (m_jogadores[i]->getStatus()!=EXCLUIDO && totalEmJogo()==1){
			m_vencedor = m_jogadores[i];
			break;
		}
		if (m_jogadores[i]->podeJogar()){
			m_jogadores[i]->Jogar(m_dado1, m_dado2);
			// Caso o jogado tenha alcancado o alvo, ja o declara vencedor
			if (m_jogadores[i]->getPontos()==Jogador::getAlvo()){
				m_vencedor = m_jogadores[i];
				break;
			}
		}
	}
	std::cout << "------------------------------------" << std::endl;
}
	
void 
Jogo::run(){
	while (m_vencedor==nullptr && totalEmJogo()>1 && getAtivos()>0){
		novaRodada();
	}
	// Caso exista mais de um jogador em jogo, mas todos decidiram parar na mesma rodada
	int maior=0;
	if (m_vencedor==nullptr){
		for (int i = 0; i < m_total_jogadores; ++i){
			if (m_jogadores[i]->getStatus()!=EXCLUIDO && m_jogadores[i]->getPontos()>maior){
				m_vencedor = m_jogadores[i];
				maior = m_jogadores[i]->getPontos();
			}
		}
	}
	mostrarResultado();
}

void 
Jogo::addJogador(Jogador * novo_){
	if (m_total_jogadores<MAX_JOGADORES){
		m_jogadores[m_total_jogadores++]=novo_;
	}
}

int 
Jogo::getAtivos(){
	int ativos=0;
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		if (m_jogadores[i]->getStatus()==ATIVO){
			ativos++;
		}
	}
	return ativos;
}

int 
Jogo::totalEmJogo(){
	int emjogo=0;
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		if (m_jogadores[i]->getStatus()==ATIVO || m_jogadores[i]->getStatus()==PARADO){
			emjogo++;
		}
	}
	return emjogo;
}

void
Jogo::mostrarResultado(){
	std::cout << "====================================" << std::endl;
	std::cout << "          RESULTADO DO JOGO " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	for (int i = 0; i < m_total_jogadores; ++i)
	{
		std::cout << m_jogadores[i]->getNome() << " --- " << m_jogadores[i]->getPontos() << " pontos.";
		if (m_jogadores[i]==m_vencedor){
			std::cout << " ** VENCEDOR ** ";
		}
		if (m_jogadores[i]->getStatus()==EXCLUIDO){
			std::cout << " >> EXCLUIDO << ";	
		}
		std::cout << std::endl;		
	}
	std::cout << "------------------------------------" << std::endl;
}
