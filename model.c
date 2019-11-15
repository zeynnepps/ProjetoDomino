/*
 * dominoModel.c
 *
 *  Created on: 3 de out de 2019
 *      
 */

#include "dominoModel.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

tipo_Monte criarPecas() //cria as peças e deixa o monte com todas as peças
{
	tipo_Monte monte;
	monte.qtde = 28;
	int k, i, pos;
	pos = 0;

	for (k = 0; k <= 6; k++)
	{
		for (i = k; i <= 6; i++)
		{
			monte.pecas[pos].ladoEsquerdo = k;
			monte.pecas[pos].ladoDireito = i;
			pos = pos + 1;
		}
	}

	return monte;
}

tipo_Monte embaralharPecas(tipo_Monte monte)
{
	//criar inicilamente uma cópia do monte original
	tipo_Monte monteCopia;
	monteCopia.qtde = 28;
	monteCopia = criarPecas();
	
	//gerar valores aleatorios para pegar no monteCopia e inserir no original
	int local; //valor aleatorio gerado pela funcao
	int pos; //local no monte original que recebera o novo valor
	int i; //controlador do loop
	pos = 0; 

	srand(time(NULL));
	
	for (i = 0; i < 28; i++)
	{
		local = rand() % monteCopia.qtde; //gera um inteiro aleatorio entre 0 e monteCopia.qtde
		monte.pecas[pos] = monteCopia.pecas[local]; //copia o que esta em local do monteCopia ao monte original
		pos++;

		//remover local do monteCopia para nao inserir peças duplicadas no monte original
		if (local != monteCopia.qtde)
		{
			int j;
			for (j = local; j < (monteCopia.qtde - 1); j++)
			{
				monteCopia.pecas[j] = monteCopia.pecas[j+1];
			}
			
		}
		monteCopia.qtde = monteCopia.qtde - 1;
	}

	return monte;
}

tipo_Mao criarMaoJogador()
{
	tipo_Mao mJ;
	mJ.qtde = 0;

	return mJ;
}

tipo_Monte distribuirPecas(tipo_Monte monte, tipo_Mao *mJ1, tipo_Mao *mJ2) //receber o monte embaralhado
{
	int i;

	for (i = 0; i < 7; i++) //distribui peças para o jogador 1
	{
		(*mJ1).pecas[i] = monte.pecas[monte.qtde-1];
		monte.qtde--; mJ1->qtde++;
	}

	for (i = 0; i < 7; i++) //distribui peças para o jogador 2
	{
		(*mJ2).pecas[i] = monte.pecas[monte.qtde-1];
		monte.qtde--; mJ2->qtde++;
	}

	return monte;
}

bool comprarPeca(tipo_Monte *monte, tipo_Mao *mJ1)
{
	bool ok;
	ok = false;
	if (monte->qtde > 0)
	{
		mJ1->pecas[mJ1->qtde] = monte->pecas[(monte->qtde)-1];
		monte->qtde--; mJ1->qtde++;
		ok = true;
	}
	return ok; //retorna se foi possivel comprar
}

//a funcao organizar pecas reseta o monte e as maos
//obs: as maos estao vazias, pois ainda nao ocorreu a distribuicao das pecas, ou seja, qtde.monte  = 28
void organizarPecas(tipo_Monte *monte, tipo_Mao *mJ1, tipo_Mao *mJ2)
{
	*monte = criarPecas();
	*mJ1 = criarMaoJogador();
	*mJ2 = criarMaoJogador();
}

//se jogador = true, M1 começa. se jogador = false, M2 começa.
bool buscarPrimeiroJogador(tipo_Mao *M1, tipo_Mao *M2)
{
	bool p66 = false; //bool para a peça 66, pois se ela for encontrada, não é mais necessário verificar as outras peças.
	bool dupla = false;
	bool jogador = false; // decide quem é o primeiro jogador

	int dupla1 = -1; int dupla2 = -1; //recebera qual a maior peça dupla

	int i = 0;
	int qtde = M1->qtde;

	while ((qtde > 0) && (p66 == false)) //VERIFICAR A MAIOR PEÇA DUPLA
	{
		if (M1->pecas[i].ladoDireito == M1->pecas[i].ladoEsquerdo)
		{
			dupla = true;
			if (dupla1 <= M1->pecas[i].ladoDireito) dupla1 = M1->pecas[i].ladoDireito;
			if (dupla1 == 6)
			{
				p66 = true;
				jogador = true;

			}
		}

		if (M2->pecas[i].ladoDireito == M2->pecas[i].ladoEsquerdo)
		{
			dupla = true;
			if (dupla2 <= M2->pecas[i].ladoDireito) dupla2 = M2->pecas[i].ladoDireito;
			if (dupla2 == 6)
			{
				p66 = true;
			}
		}
		i++, qtde--;
	}

	if (dupla == false)//VERIFICA QUAL JOGADOR POSSUI MAO COM MENOR SOMA, SE NINGUEM TIVER PEÇA DUPLA
	{
		int somaM1 = 0;
		int somaM2 = 0;
		int aux1, aux2;

		for (i = 0; i < M1->qtde; i++)
		{
			aux1 = M1->pecas[i].ladoDireito + M1->pecas[i].ladoEsquerdo;
			somaM1 = somaM1 + aux1;
		}
		for (i = 0; i < M2->qtde; i++)
		{
			aux2 = M2->pecas[i].ladoDireito + M2->pecas[i].ladoEsquerdo;
			somaM2 = somaM2 + aux2;
		}

		//verifica qual a menor soma
		if (somaM1 > somaM2)
		{
			jogador = false;
		}
		else
		{
			jogador = true;
		}
	}

	return jogador;
}

//inverte as peça (12 = 21)
void inverterPeca(tipo_Peca *peca)
{
	int aux;
	aux = peca->ladoDireito;
	peca->ladoDireito = peca->ladoEsquerdo;
	peca->ladoEsquerdo = aux;
}

bool checarMaoVazia(tipo_Mao M1)
{
	bool maoVazia = false;
	if (M1.qtde == 0)
	{
		maoVazia = true;
	}
	return maoVazia;
}

bool jogarPeca(tipo_Mesa *mesa, tipo_Mao *M1, int peca, char ladoJogado)
{
	int qtdeMesa = mesa->qtde;
	bool jogou = false;
	int i;

	//verifica se pode jogar a peça
	if (qtdeMesa == 0)
	{
		mesa->pecas[0] = M1->pecas[peca - 1];
		mesa->qtde++;
		removerPecaMao(M1, peca);
		jogou = true;
	}
	else
	{
		if (ladoJogado == '1')
		{
			if (mesa->pecas[0].ladoEsquerdo == M1->pecas[peca - 1].ladoEsquerdo)
			{
				inverterPeca(&M1->pecas[peca - 1]);
				jogou = true;
			}
			else
			{
				if (mesa->pecas[0].ladoEsquerdo == M1->pecas[peca - 1].ladoDireito)
				{
					
					jogou = true;
					
				}
			}

			if (jogou == true)
			{
				for (i = (qtdeMesa - 1); i >= 0; i--)
				{
					mesa->pecas[i + 1] = mesa->pecas[i];
				}
				mesa->pecas[0] = M1->pecas[peca - 1];
				mesa->qtde++;
				removerPecaMao(M1, peca);
			}

		}

		else //ladoJogado = '2'
		{

			if (mesa->pecas[qtdeMesa-1].ladoDireito == M1->pecas[peca - 1].ladoDireito)
			{
				inverterPeca(&M1->pecas[peca - 1]);
				jogou = true;
			}
			else
			{
				if (mesa->pecas[qtdeMesa-1].ladoDireito == M1->pecas[peca - 1].ladoEsquerdo)
				{

					jogou = true;

				}
			}

			if (jogou == true)
			{
				mesa->pecas[qtdeMesa] = M1->pecas[peca - 1];
				mesa->qtde++;
				removerPecaMao(M1, peca);
			}
		}
	}
	return jogou;
}

void sairDoJogo()
{
	exit(0);
}

void removerPecaMao(tipo_Mao *M1, int peca)
{
	int i;

	if (peca == M1->qtde) 
	{
		M1->qtde--;
	}
	else
	{
		for (i = (peca-1); i < (M1->qtde - 1); i++)
		{
			M1->pecas[i] = M1->pecas[i + 1];
		}
		M1->qtde--;
	}
void salvarJogo()
{
	
	FILE * fPtr;
	
	fPtr = fopen("jogo.txt", "w"); //abre arquivo
	
		fputs(tipo_Mao,fptr);//w tipo_Mao
	
		fputs(tipo_Mesa,fptr);//w tipo_Mesa
	
		fputs(tipo_Peca,fptr);//w tipo_Peca
	
		fputs(tipo_Monte,fptr);//w tipo_Monte
	
	fclose(fPtr); //fecha arquivo
	
	printf("O jogo foi salvo!"); //depois colocar no view;


    return ok;
}
	
}
