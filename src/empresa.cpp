#include "empresa.h"

Empresa::Empresa():
	m_cnpj("00000/00-00"), m_razao_social("None"), m_total_funcionarios(0) {
	m_cont++;
}

Empresa::Empresa(string cnpj_, string razao_social_):
	m_cnpj(cnpj_), m_razao_social(razao_social_), m_total_funcionarios(0) {
	m_cont++;
}

Empresa::~Empresa(){
	for (int i = 0; i < m_total_funcionarios; ++i)
	{
		delete m_funcionarios[i];
	}
	m_cont--;
}
	
bool 
Empresa::addFuncionario(Funcionario * novo_){
	if (m_total_funcionarios==MAX_FUNCIONARIOS) {
		return false;
	}
	for (int i = 0; i < m_total_funcionarios; ++i)
	{
		if ((*m_funcionarios[i])==(*novo_)){
			return false;
		}
	}
	m_funcionarios[m_total_funcionarios++] = novo_;
	return true;
}

bool 
Empresa::removeFuncionario(string nome_){
	int ajustar = false;
	for (int i = 0; i < m_total_funcionarios; ++i)
	{
		if (m_funcionarios[i]->getNome()==nome_) {
			delete m_funcionarios[i];
			m_total_funcionarios--;
			ajustar = true;
		} 
		if (ajustar){
			m_funcionarios[i] = m_funcionarios[i+1];
		}
	}
	return ajustar;
}

void 
Empresa::listaFuncionarios(){
	std::cout << "Empregados da Empresa: " << m_razao_social << std::endl; 
	std::cout << "----------------------------" << std::endl;
	for (int i = 0; i < m_total_funcionarios; ++i)
	{
		std::cout << (*m_funcionarios[i]) << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}

void 
Empresa::atualizaSalarios(double percentual){
	for (int i = 0; i < m_total_funcionarios; ++i)
	{
		m_funcionarios[i]->atualizaSalario(percentual);
	}
}

string 
Empresa::getCnpj(){
	return m_cnpj;
}

string 
Empresa::getRazaoSocial(){
	return m_razao_social;
}

Funcionario ** 
Empresa::getListaFuncionarios(){
	return m_funcionarios;
}

int 
Empresa::getTotalFuncionarios(){
	return m_total_funcionarios;
}

ostream& operator<< ( ostream& o, const Empresa& emp){
	o << emp.m_cnpj << " | " << emp.m_razao_social << " | " << emp.m_total_funcionarios << " funcionarios";
	return o;
}

istream& operator>> ( istream& i, Empresa& emp ){ 
	std::cout << "CNPJ: ";
	getline(i,emp.m_cnpj);
	std::cout << "Razao Social: ";
	getline(i,emp.m_razao_social);
	return i;            
}


