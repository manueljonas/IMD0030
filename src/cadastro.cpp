#include <iostream>

#include "cadastro.h"

using std::cout;
using std::cin;

Cadastro::Cadastro():m_total_empresas(0){}

Cadastro::~Cadastro(){
	for (int i = 0; i < m_total_empresas; ++i)
	{
		delete m_empresas[i];
	}
}

char 
Cadastro::menuPrincipal(string titulo){
	char opcao;
 
 	do {
		cout << titulo;
		cout << "\n===================";
		cout << "\n 1 - Empresa";
		cout << "\n 2 - Funcionario";
		cout << "\n 3 - Media de funcionarios por empresa";
		cout << "\n 4 - Sair";
		cout << "\n Opcao: ";
		// lendo a opcao
		cin>>opcao;
		// remove o enter para nao dar problemas com o getline
		cin.ignore(); 
		 
		switch(opcao)
		{
			case '1' : submenuEmpresa("\n Menu | Empresa");
					break;
			case '2' : submenuEditar("\n Menu | Funcionario");
					break;
			case '3' : imprimirMediaFuncionariosPorEmpresa();
					break;
			case '4' : // nada a fazer, apenas sair
					break;
			// Qualquer outra opcao diferente de 1,2,3 ou 4 eh considerada invalida
			default : cout << "\n Opcao invalida!";
		}
		cout<<"\n";
	} while (opcao!='4');
	return opcao;
}

char 
Cadastro::submenuEmpresa(string titulo){
	char opcao;
 
 	do {
		cout << titulo;
		cout << "\n=================";
		cout << "\n 1 - Adicionar";
		cout << "\n 2 - Remover";
		cout << "\n 3 - Editar";
		cout << "\n 4 - Listar empresas";
		cout << "\n 5 - Sair";
		cout << "\n Opcao: ";
		// lendo a opcao
		cin>>opcao;
		// remove o enter para nao dar problemas com o getline
		cin.ignore();
		 
		switch(opcao)
		{
			case '1' : adicionarEmpresa();
					break;
			case '2' : removerEmpresa();
					break;
			case '3' : submenuEditar("\n Menu | Empresa | Editar");
					break;
			case '4' : listarEmpresas();
					break;
			case '5' : // nada a fazer, apenas sair
					break;
			// Qualquer outra opcao diferente de 1,2,3,4 ou 5 eh considerada invalida
			default : cout << "\n Opcao invalida!";
		}
		cout<<"\n";
	} while (opcao!='5');

	return opcao;
}

void 
Cadastro::adicionarEmpresa(){
	Empresa * e = new Empresa();
	std::cin >> (*e);
	if (m_total_empresas<MAX_EMPRESAS){
		m_empresas[m_total_empresas++] = e;
	}
}

void 
Cadastro::removerEmpresa(){
	string nome;
	std::cout << "Razao Social: ";
	getline(std::cin, nome);
	bool ajustar = false;
	for (int i = 0; i < m_total_empresas; ++i)
	{
		if (m_empresas[i]->getRazaoSocial()==nome){
			delete m_empresas[i];
			m_total_empresas--;
			ajustar = true;
		}
		if (ajustar){
			m_empresas[i]=m_empresas[i+1];
		}
	}
	if (ajustar){
		std::cout << "Empresa " << nome << " removida.";
	} else {
		std::cout << "Empresa " << nome << " nao encontrada.";
	}
}

void 
Cadastro::listarEmpresas(){
	std::cout << "Empresas cadastradas: " << m_total_empresas << std::endl; 
	std::cout << "----------------------------" << std::endl;
	for (int i = 0; i < m_total_empresas; ++i)
	{
		std::cout << (*m_empresas[i]) << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}

char 
Cadastro::submenuEditar(string titulo){
	char opcao;
 
 	do {
		cout << titulo;
		cout << "\n==========================";
		cout << "\n 1 - Adicionar Funcionario";
		cout << "\n 2 - Remover Funcionario";
		cout << "\n 3 - Listar Funcionarios";
		cout << "\n 4 - Atualizar salarios";
		cout << "\n 5 - Sair";
		cout << "\n Opcao: ";
		// lendo a opcao
		cin>>opcao;
		// remove o enter para nao dar problemas com o getline
		cin.ignore();
		 
		switch(opcao)
		{
			case '1' : adicionarFuncionario();
					break;
			case '2' : removerFuncionario();
					break;
			case '3' : listarFuncionarios();
					break;
			case '4' : atualizarValorSalarios();
					break;
			case '5' : // nada a fazer, apenas sair
					break;
			// Qualquer outra opcao diferente de 1,2,3,4 ou 5 eh considerada invalida
			default : cout << "\n Opcao invalida!";
		}
		cout<<"\n";
	} while (opcao!='5');

	return opcao;
}

void 
Cadastro::adicionarFuncionario(){
	string nome;
	std::cout << "Razao Social: ";
	getline(std::cin, nome);
	int index = findEmpresa(nome);
	if (index==-1){
		std::cout << "Empresa " << nome << " nao encontrada." << std::endl;
	} else {
		Funcionario * f = new Funcionario();
		std::cin >> (*f);
		if (m_empresas[index]->getTotalFuncionarios()<MAX_FUNCIONARIOS){
			m_empresas[index]->addFuncionario(f);
		}
	}
}

void 
Cadastro::removerFuncionario(){
	string nome;
	std::cout << "Razao Social: ";
	getline(std::cin, nome);
	int index = findEmpresa(nome);
	if (index==-1){
		std::cout << "Empresa " << nome << " nao encontrada." << std::endl;
	} else {
		std::cout << "Nome do funcionario: ";
		getline(std::cin, nome);
		if (m_empresas[index]->removeFuncionario(nome)){
			std::cout << "Funcionario " << nome << " removido.";
		} else {
			std::cout << "Funcionario " << nome << " nao encontrado.";
		}
	}
}

void 
Cadastro::listarFuncionarios(){
	string nome;
	std::cout << "Razao Social: ";
	getline(std::cin, nome);
	int index = findEmpresa(nome);
	if (index==-1){
		std::cout << "Empresa " << nome << " nao encontrada." << std::endl;
	} else {
		m_empresas[index]->listaFuncionarios();
	}
}

void 
Cadastro::atualizarValorSalarios(){
	string nome;
	std::cout << "Razao Social: ";
	getline(std::cin, nome);
	int index = findEmpresa(nome);
	if (index==-1){
		std::cout << "Empresa " << nome << " nao encontrada." << std::endl;
	} else {
		double ajuste;
		std::cout << "Fator de reajuste (%): ";
		std::cin >> ajuste;	
		m_empresas[index]->atualizaSalarios(ajuste);
	}
}


void 
Cadastro::imprimirMediaFuncionariosPorEmpresa(){
	std::cout << "Total de Empresas: " << Empresa::getTotalInstancias() << std::endl;
	std::cout << "Total de Funcionarios: " << Funcionario::getTotalInstancias() << std::endl;
	std::cout << "Média de Funcionarios por Empresa: " << ((double) Funcionario::getTotalInstancias()/Empresa::getTotalInstancias()) << std::endl;
	
}

int 
Cadastro::findEmpresa(string nome_){
	int indice = -1;
	for (int i = 0; i < m_total_empresas; ++i)
	{
		if (m_empresas[i]->getRazaoSocial()==nome_){
			return i;
		}
	}
	return indice;
}

