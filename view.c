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

#include "view.h"
#include "view.h"

void menu(void) {
	 printf("BEM-VINDX! QUER ENCARAR ESSE JOGO DE DOMINÓ?");
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
