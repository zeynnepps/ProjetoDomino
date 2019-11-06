/*
 * dominoView.h
 *
 *  Created on: 3 de out de 2019
 *      Author: yumi
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "model.h"

char exibirMenu();
void flush_in();
char determinarQtdJogador();
char opcoesJogo();
void mostrarMsg(char* msg);
void mostrarPecas();
void mostrarMao(tipo_Mao mJ1);
void regrasDomino();
void mostrarMesa(tipo_Mesa mesa);

#endif /* DOMINOVIEW_H_ */
