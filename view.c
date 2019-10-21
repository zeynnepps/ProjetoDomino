/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00
         ZEYNEP SALIHOGLU RA00  
         
         
=======VIEW======
MENU
PEÇAS 
*/     
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dominoView.h"

//menu de quando o jogo é aberto
char exibirMenu()
{
	char opcao;

	printf("*~*~*~*~* J O G O  D O M I N Ó *~*~*~*~*\n");
	printf("MENU DO JOGO\n");
	printf("(1) - Iniciar jogo\n");
	printf("(2) - Carregar jogo salvo\n");
	printf("(3) - Opções do jogo\n");
	printf("(4) - Sair do jogo\n");
	printf("Selecione a opção desejada: ");
	opcao = getchar();
	printf("\n");

	return opcao;
}

//limpeza do buffer do teclado
void flush_in()
{
	int ch;
	while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
}

char determinarQtdJogador()
{
	char opcao;

	printf("Qual a quantidade de jogadores?\n");
	printf("(1) - 1 jogador\n");
	printf("(2) - 2 jogadores\n");
	printf("Selecione a opção desejada: ");
	opcao = getchar();
	printf("\n");

	return opcao;
}

char opcoesJogo()
{
	char opcao;

	printf("OPÇÕES DO JOGO\n");
	printf("(1) - Mostrar peças do dominó\n");
	printf("(2) - Organizar peças do dominó na sequência\n"); //no inicio do jogos as peças sâo embaralhadas automaticamente
	printf("(3) - Embaralhar peças do dominó\n");
	printf("(4) - Voltar ao Menu\n");
    printf("(5) - Salvar jogo\n");
	printf("Selecione a opção desejada: ");
	opcao = getchar();
	flush_in();
	printf("\n");

	return opcao;
}

void mostrarMsg(char* msg)
{
	printf("%s", msg);
}

void mostrarPecas()
{
	printf("PEÇAS DO DOMINÓ\n");
	printf("0|0 0|1 0|2 0|3 0|4 0|5 0|6\n1|1 1|2 1|3 1|4 1|5 1|6\n2|2 2|3 2|4 2|5 2|6\n3|3 3|4 3|5 3|6\n4|4 4|5 4|6\n5|5 5|6\n6|6\n");
	printf("\n");
}
