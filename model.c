/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00222619
         ZEYNEP SALIHOGLU RA00227219  
*/     
/*

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
		mJ1->pecas[mJ1->qtde] = monte->pecas[monte->qtde];
		monte->qtde--; mJ1->qtde++;
		ok = true;
	}
	return ok; //retorna se foi possivel comprar
}

