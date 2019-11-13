/*
 * dominoView.c
 *
 *  Created on: 3 de out de 2019
 *    
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominoView.h"
#include "dominoModel.h"

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
	printf("(2) - Regras do dominó\n");
	printf("(3) - Voltar ao menu\n");
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

void mostrarMao(tipo_Mao mJ1)
{
	int i;

	printf("### SUAS PEÇAS ###\n");
	for (i = 0; i < mJ1.qtde; i++)
	{
		printf("(%d)%d", (i+1), mJ1.pecas[i].ladoEsquerdo);
		printf("%d\t",mJ1.pecas[i].ladoDireito);
	}

	printf("\n\n");
}

void regrasDomino()
{
	printf("REGRAS DO DOMINÓ\n");
	printf("O monte é embaralhado e cada jogador recebe 7 peças.\n");
	printf("Começa o jogo quem tiver a peça 66 ou a maior peça dupla.\nSe ninguém possuir peças duplas, então o jogador que possuir a menor soma de suas peças começa.\n");
	printf("O jogador deve jogar uma peça que possua o mesmo número da que está na mesa.\n");
	printf("Quando o jogador não possuir peça para jogar, ele deve comprar até encontrar uma que possa ser jogada.\n");
	printf("Vence o jogador que jogar todas suas peças primeiro.\n");
	printf("\n");
}

void mostrarMesa(tipo_Mesa mesa)
{
	int i;
	
	if (mesa.qtde > 0)
	{
		printf("## MESA ##\n");
		for(i=0; i<mesa.qtde; i++)
		{
			printf("-%d%d-",mesa.pecas[i].ladoEsquerdo,mesa.pecas[i].ladoDireito);
		}
		printf("\n");
	}
	else
	{
		printf("Mesa vazia!\n");
		printf("\n");
	}
}

char mostrarOpcoes()
{
	char opcao;
	printf("(1)Jogar peça (2)Comprar peça (3)Salvar jogo (4)Sair do jogo\n");
	printf("Selecione a opção: ");
	opcao = getchar();

	return opcao;
}

void numerodoJogador(int jogador)
{
	printf("Vez do Jogador %d\n", jogador);
}

int obterPecaJogada()
{
	int opcao;
	printf("Qual peça será jogada?\n");
	printf("Opção: ");
	scanf("%d", &opcao);
	return opcao;
}

char obterLadoJogado()
{
	char opcao;
	printf("A peça será jogada no lado esquerdo ou lado direito?\n");
	printf("(1) Lado esquerdo (2) Lado direito\n");
	printf("Opcão: ");
	opcao = getchar();

	return opcao;
}

//limpa a tela a cada rodada, assim ó jogador vê apenas suas próprias peças
void limparTela()
{
	system("clear || cls");
}
