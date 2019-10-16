/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00
         ZEYNEP SALIHOGLU RA00  
*/

#include "controller.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

void iniciarJogo()
{
	tipo_Monte teste;
	teste = criarPecas();
	teste = embaralharPecas(teste);
	
	tipo_Mao M1, M2;
	M1 = criarMaoJogador();
	M2 = criarMaoJogador();

	teste = distribuirPecas(teste, &M1, &M2);

	bool ok;
	ok = comprarPeca(&teste, &M1);




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
				//opcao 1 jogador
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
			case '2': //ORGANIZA AS PECAS DO DOMINO
				printf("opcao organizar\n");
				break;
			case '3'://EMBARALHA AS PEÇAS DO DOMINO
				printf("opcao embaralhar\n");
				break;
			case '4'://SAI DAS OPCOES E VOLTA PARA O MENU
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
