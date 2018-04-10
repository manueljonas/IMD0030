#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

#define MAX_FUNCIONARIOS 100

class Empresa
{
private:
	string m_cnpj;
	string m_razao_social;
	Funcionario * m_funcionarios[MAX_FUNCIONARIOS];
	int m_total_funcionarios;

	static int m_cont;

public:
	Empresa();
	Empresa(string cnpj_, string razao_social_);
	~Empresa();

	bool addFuncionario(Funcionario * novo_);
	bool removeFuncionario(string nome_);
	void listaFuncionarios();
	void atualizaSalarios(double percentual);

	string getCnpj();
	string getRazaoSocial();
	Funcionario ** getListaFuncionarios();
	int getTotalFuncionarios();

	static int getTotalInstancias(){
		return m_cont;
	}

	friend ostream& operator<< ( ostream& o, const Empresa& emp);

	friend istream& operator>> ( istream& i, Empresa& emp);
};

#endif