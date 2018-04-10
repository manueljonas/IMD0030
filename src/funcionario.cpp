#include "funcionario.h"

Funcionario::Funcionario():
	m_nome("None"), m_salario(0.0), m_dt_admissao(Data(1,1,1900)) {
	m_cont++;
}

Funcionario::Funcionario(string nome_, double salario_, Data admissao_):
	m_nome(nome_), m_salario(salario_), m_dt_admissao(admissao_) {
	m_cont++;
}

Funcionario::~Funcionario(){
	m_cont--;
}

string 
Funcionario::getNome(){
	return m_nome;
}

double 
Funcionario::getSalario(){
	return m_salario;
}

Data 
Funcionario::getDtAdmissao(){
	return m_dt_admissao;
}

void 
Funcionario::atualizaSalario(double percentual){
	m_salario *= (1+(percentual/100));
}

ostream& operator<< ( ostream& o, const Funcionario& func){
	o << func.m_nome << " | " << func.m_salario << " | " << func.m_dt_admissao;
	return o;
}

istream& operator>> ( istream& i, Funcionario& func ){ 
	std::cout << "Nome: ";
	getline(i,func.m_nome);
	std::cout << "Salario: ";
	i >> func.m_salario;
	std::cout << "Data de Admissao (dd/mm/aaaa): ";
	i >> func.m_dt_admissao;
	return i;            
}

bool 
Funcionario::operator== (const Funcionario &outro_){
	return (this->m_nome==outro_.m_nome);
} 	

bool 
Funcionario::operator!= (const Funcionario &outro_){
	return !((*this)==outro_);
}