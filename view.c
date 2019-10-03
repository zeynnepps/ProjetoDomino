/*
PROJETO DO SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
NOMES:   CAROLINA BREITENWIESER RA00222650
         CAROLINE UEHARA  RA00
         ZEYNEP SALIHOGLU RA00  
         
         
=======VIEW======
MENU
PEÇAS 
*/     
#include <stdio.h>
#include <ctype.h>

#include "model.h"
#include "view.h"

void menu(void) {
	 printf("BEM-VINDO(A)! QUER ENCARAR ESSE JOGO DE DOMINÓ?");
	 printf("MENU DO JOGO");
	 
}

char SimOuNao() {
	char opcao;
	opcao = getchar();
	flush_in();
	return opcao;
}


void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
