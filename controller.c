/*
 * dominoController.c
 *
 *  Created on: 3 de out de 2019
 *     
 */

#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"
#include <stdbool.h>
#include <stdio.h>


void iniciarJogo()
{
	char opcao, jogadores, opJogo;
	bool fim;
	fim = false;

	do
	{
		opcao = exibirMenu();
		flush_in();
		switch (opcao)
		{
		case '1': //INICIAR JOGO
			jogadores = determinarQtdJogador();
			flush_in();
			switch (jogadores) 
			{
			case '1':
				//criar "ia"
				break;
			case '2':
				iniciarPartida();
				break;
			default:
				mostrarMsg("Opção inválida.\n");
				break;
			}
			break;
		case '2': //CARREGAR JOGO SALVO
			printf("opcao carregar jogo\n");
			break;
		case '3': //ABRE OPCOES DO JOGO
			opJogo = opcoesJogo();
			switch (opJogo)
			{
			case '1': //MOSTRA AS PECAS DO DOMINO
				mostrarPecas();
				break;
			case '2': //REGRAS DO DOMINO
				regrasDomino();
				break;
			case '3':
				break;
			default:
				mostrarMsg("Opção inválida.\n");
				break;
			}
			break;
		case '4'://SAI DO JOGO
			fim = true;
			break;
		default:
			mostrarMsg("Opção inválida.\n");
			break;
		}
	} while (!fim);

}

void iniciarPartida()
{
	tipo_Monte monte;
	tipo_Mao M1, M2;
	tipo_Mesa mesa; mesa.qtde = 0;
	bool primeiro;
	bool fimJogo = false;
	int jogador1 = 1; int jogador2 = 2;

	monte = criarPecas();
	monte = embaralharPecas(monte);
	M1 = criarMaoJogador();
	M2 = criarMaoJogador();
	monte = distribuirPecas(monte, &M1, &M2);

	mostrarMsg("Iniciando jogo...\n\n");

	primeiro = buscarPrimeiroJogador(&M1, &M2);
	if (primeiro == true)
	{
		do
		{
			vezJogador(&M1, &mesa, &monte, jogador1);
			fimJogo = checarMaoVazia(M1);
			if (fimJogo == true)
			{
				mostrarMsg("FIM DE JOGO. O JOGADOR 1 VENCEU.\n");
			}
			else
			{
				vezJogador(&M2, &mesa, &monte, jogador2);
				fimJogo = checarMaoVazia(M2);
				if (fimJogo == true)
				{
					mostrarMsg("FIM DE JOGO. O JOGADOR 2 VENCEU.\n");
				}
			}
		} while (!fimJogo);
	}
	else
	{
		do
		{
			vezJogador(&M2, &mesa, &monte, jogador2);
			fimJogo = checarMaoVazia(M2);
			if (fimJogo == true)
			{
				mostrarMsg("FIM DE JOGO. O JOGADOR 2 VENCEU.\n");
			}
			else
			{
				vezJogador(&M1, &mesa, &monte, jogador1);
				fimJogo = checarMaoVazia(M1);
				if (fimJogo == true)
				{
					mostrarMsg("FIM DE JOGO. O JOGADOR 1 VENCEU.\n");
				}
			}
		} while (!fimJogo);
	}
}

void vezJogador(tipo_Mao *M1, tipo_Mesa *mesa, tipo_Monte *monte, int jogador)
{
	char opcao; bool fim = true; bool ok; char lado; int peca; bool jogou = false;

	do
	{
		mostrarMesa(*mesa);
		numerodoJogador(jogador);
		mostrarMao(*M1);
		opcao = mostrarOpcoes();
		flush_in();

		switch (opcao)
		{
		case '1':
			peca = obterPecaJogada();
			flush_in();

			lado = obterLadoJogado();
			flush_in();

			jogou = jogarPeca(mesa, M1, peca, lado);
			if (jogou == true)
			{
				fim = false;
			}
			break;
		case '2':
			ok = comprarPeca(monte, M1);
			if (ok == false)
			{
				mostrarMsg("Monte vazio. Você passará sua vez.\n");
				fim = false;
			}
			break;
		case '3':
			salvarJogo();
			mostrarMsg("Jogo salvo!\n");
			break;
		case '4':
			sairDoJogo();
			break;
		default:
			mostrarMsg("Opção inválida.\n");
			break;
		}
		limparTela();
	} while (fim);
}

