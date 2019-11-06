#ifndef MODEL_H_
#define MODEL_H_

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
	tipo_Peca pecas[20];
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

#endif /* MODEL_H_ */
