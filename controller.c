/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00
         ZEYNEP SALIHOGLU RA00  
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
				//iniciarPartida();
				break;
			case '2':
				//opcao 2 jogador
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
	bool primeiro;

	monte = criarPecas();
	monte = embaralharPecas(monte);
	M1 = criarMaoJogador();
	M2 = criarMaoJogador();
	monte = distribuirPecas(monte, &M1, &M2);
	
	primeiro = buscarPrimeiroJogador(&M1, &M2);
	if (primeiro == true)
	{
		printf("O jogador M1 é o primeiro a jogar\n"); //apenas teste
	}
	else
	{
		printf("O jogador M2 é o primeiro a jogar\n"); //apenas teste
	}

}
