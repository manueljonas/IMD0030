#ifndef CADASTRO_H
#define CADASTRO_H

#include "empresa.h"

#define MAX_EMPRESAS 50

class Cadastro
{
private:
	Empresa * m_empresas[MAX_EMPRESAS];
	int m_total_empresas;
public:
	Cadastro();
	~Cadastro();

	char menuPrincipal(string titulo);
	char submenuEmpresa(string titulo);
	void adicionarEmpresa();
	void removerEmpresa();
	void listarEmpresas();

	int findEmpresa(string nome_);

	char submenuEditar(string titulo);
	void adicionarFuncionario();
	void removerFuncionario();
	void listarFuncionarios();
	void atualizarValorSalarios();

	void imprimirMediaFuncionariosPorEmpresa();
};

#endif