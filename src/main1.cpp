#include "cadastro.h"

int Funcionario::m_cont = 0;
int Empresa::m_cont = 0;

int main(int argc, char const *argv[])
{
	Cadastro cad;
	cad.menuPrincipal("\n Menu | Principal");
	return 0;
}