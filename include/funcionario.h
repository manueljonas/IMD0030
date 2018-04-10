#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include "data.h"

using std::string;
using std::ostream;
using std::istream;

class Funcionario
{
private:
	string m_nome;
	double m_salario;
	Data m_dt_admissao;

	static int m_cont;
public:
	Funcionario();
	Funcionario(string nome_, double salario_, Data admissao_);
	~Funcionario();

	string getNome();
	double getSalario();
	Data getDtAdmissao();

	void atualizaSalario(double percentual);

	friend ostream& operator<< ( ostream& o, const Funcionario& func);

	friend istream& operator>> ( istream& i, Funcionario& func);

	bool operator== (const Funcionario &outro); 	
	bool operator!= (const Funcionario &outro);

	static int getTotalInstancias(){
		return m_cont;
	}
};

#endif