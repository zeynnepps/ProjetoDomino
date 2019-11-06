/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00222619
         ZEYNEP SALIHOGLU RA00227219  
*/     

#include "model.h"
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

//a funcao organizar pecas reseta o monte e as maos
//obs: as maos estao vazias, pois ainda nao ocorreu a distribuicao das pecas, ou seja, qtde.monte  = 28
void organizarPecas(tipo_Monte *monte, tipo_Mao *mJ1, tipo_Mao *mJ2)
{
	*monte = criarPecas();
	*mJ1 = criarMaoJogador();
	*mJ2 = criarMaoJogador();
}

//se jogador = true, M1 começa. se jogador = false, M2 começa.
bool buscarPrimeiroJogador(tipo_Mao* M1, tipo_Mao* M2) //ARRUMAR ISSO AQUI
{
	bool p66 = false;
	bool jogador = false;
	int i = 0;
	int qtde = M1->qtde;

	while ((qtde > 0) && (p66 == false)) //VERIFICA QUAL JOGADOR POSSUI A PEÇA 66
	{
		if ((M1->pecas[i].ladoDireito == 6) && (M1->pecas[i].ladoEsquerdo == 6))
		{
			p66 = true;
			jogador = true;
		}

		if ((M2->pecas[i].ladoDireito == 6) && (M2->pecas[i].ladoEsquerdo == 6))
		{
			p66 = true;
			jogador = false;
		}
		i++; qtde--;
	}

	bool achou = false;
	if (p66 == false)//VERIFICAR QUEM POSSUI A MAIOR PEÇA DUPLA
	{
		int qtde = M1->qtde;
		int local1 = 0; int local2 = 0;
		int x = 0;
		int dupla1 = -1; int dupla2 = -1; //recebera qual a peca dupla(se é 55, 44 etc)

		if(achou==false)
		{
			while (qtde > 0)//procura a maior peça dupla de cada mão
			{
				if (M1->pecas[x].ladoDireito == M1->pecas[x].ladoEsquerdo)
				{
					local1 = M1->pecas[x].ladoDireito;
					if(dupla1<= local1) dupla1 = M1->pecas[x].ladoDireito;
				}

				if (M2->pecas[x].ladoDireito == M2->pecas[x].ladoEsquerdo)
				{
					local2 = M2->pecas[x].ladoDireito;
					if (dupla2 <= local2) dupla2 = M2->pecas[x].ladoDireito;
				}

				x++; qtde--;
			}

			if (dupla1 > dupla2)
			{
				jogador = true;
				achou = true;
			}
			else
			{
				if (dupla2 > dupla1)
				{
					jogador = false;
					achou = true;
				}
			}
		}
	}

	if (p66 == false && achou == false)//VERIFICA QUAL JOGADOR POSSUI MAO COM MENOR SOMA, SE NINGUEM TIVER PEÇA DUPLA
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
