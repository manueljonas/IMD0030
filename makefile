# Makefile for "imd0030"
# Created by Silvio Sampaio 10/08/2016
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor o codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binario/executavel final
OBJS_1 = $(OBJ)/data.o $(OBJ)/funcionario.o $(OBJ)/empresa.o $(OBJ)/cadastro.o $(OBJ)/main1.o
OBJS_2 = $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/jogo.o $(OBJ)/main2.o

all : $(OBJS_1) $(OBJS_2)
	$(CC) $(LDFLAGS) -o $(BIN)/questao1 $(OBJS_1)
	$(CC) $(LDFLAGS) -o $(BIN)/questao2 $(OBJS_2)

# Alvo para a compilação com informações de debug
# Altera a flag CFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main1.o : $(SRC)/main1.cpp $(OBJ)/data.o $(OBJ)/funcionario.o $(OBJ)/empresa.o $(OBJ)/cadastro.o 
	$(CC) $(CPPFLAGS) -c $(SRC)/main1.cpp -o $@

$(OBJ)/data.o : $(INC)/data.h $(SRC)/data.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/data.cpp -o $@

$(OBJ)/funcionario.o : $(INC)/funcionario.h $(SRC)/funcionario.cpp $(OBJ)/data.o
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $@

$(OBJ)/empresa.o : $(INC)/empresa.h $(SRC)/empresa.cpp $(OBJ)/funcionario.o
	$(CC) $(CPPFLAGS) -c $(SRC)/empresa.cpp -o $@

$(OBJ)/cadastro.o : $(INC)/cadastro.h $(SRC)/cadastro.cpp $(OBJ)/empresa.o
	$(CC) $(CPPFLAGS) -c $(SRC)/cadastro.cpp -o $@

$(OBJ)/dado.o : $(INC)/data.h $(SRC)/dado.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp -o $@

$(OBJ)/jogador.o : $(INC)/jogador.h $(SRC)/jogador.cpp $(OBJ)/dado.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp -o $@

$(OBJ)/jogo.o : $(INC)/jogo.h $(SRC)/jogo.cpp $(OBJ)/jogador.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogo.cpp -o $@

$(OBJ)/main2.o : $(SRC)/main2.cpp $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/jogo.o $(OBJ)/jogo.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main2.cpp -o $@

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(PROG) $(OBJS_1) $(OBJS_2)
