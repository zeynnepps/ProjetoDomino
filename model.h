/*
 * dominoModel.h
 *
 *  Created on: 3 de out de 2019
 *      
 */

#ifndef DOMINOMODEL_H_
#define DOMINOMODEL_H_

#include<stdbool.h>

typedef struct Peca
{
	int ladoEsquerdo;
	int ladoDireito;
} tipo_Peca;

//monte do dominó
typedef struct Monte
{
	tipo_Peca pecas[28];
	int qtde;
} tipo_Monte;

//conjunto de peças que cada jogador possui
typedef struct Mao
{
	tipo_Peca pecas[21];
	int qtde;
}tipo_Mao;

//a mesa do jogo
typedef struct Mesa
{
	tipo_Peca pecas[28];
	int qtde;
}tipo_Mesa;


tipo_Monte criarPecas();
tipo_Monte embaralharPecas(tipo_Monte monte);
tipo_Mao criarMaoJogador();
tipo_Monte distribuirPecas(tipo_Monte monte, tipo_Mao *mJ1, tipo_Mao *mJ2);
bool comprarPeca(tipo_Monte *monte, tipo_Mao *mJ1);
void organizarPecas(tipo_Monte* monte, tipo_Mao* mJ1, tipo_Mao* mJ2);
bool buscarPrimeiroJogador(tipo_Mao* M1, tipo_Mao* M2);
void inverterPeca(tipo_Peca *peca);
bool checarMaoVazia(tipo_Mao M1);

bool jogarPeca(tipo_Mesa* mesa, tipo_Mao* M1, int peca, char ladoJogado);
void removerPecaMao(tipo_Mao *M1, int peca);


void sairDoJogo();


#endif /* DOMINOMODEL_H_ */
