/*
 * dominoView.h
 *
 *  Created on: 3 de out de 2019
 *     
 */
#ifndef DOMINOVIEW_H_
#define DOMINOVIEW_H_

#include "dominoModel.h"

char exibirMenu();
void flush_in();
char determinarQtdJogador();
char opcoesJogo();
void mostrarMsg(char* msg);
void mostrarPecas();
void mostrarMao(tipo_Mao mJ1);
void regrasDomino();
void mostrarMesa(tipo_Mesa mesa);
char mostrarOpcoes();
void numerodoJogador(int jogador);
char obterLadoJogado();
int obterPecaJogada();

void limparTela();

#endif /* DOMINOVIEW_H_ */
