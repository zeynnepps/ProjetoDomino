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
#include <string.h>

#include "model.h"
#include "view.h"

void exibirMenu(void) {

	printf("MENU DO JOGO\n");
	
	//REQ01 NUMERO DE JOGADORES - função get char 
	
	//REQ03 EMBARALHAR PEÇAS
	printf("(03) - EMBARALHAR PEÇAS\n");
	
	//REQ04 DISTRIBUIR PEÇAS
	printf("(04) - DISTRIBUIR PEÇAS\n");
	
	//REQ05 INICIAR JOGO
	printf("(05) - INICIAR JOGO\n");
	
	//REQ06 SALVAR O JOGO
	printf("(06) - SALVAR JOGO\n");
	
	//REQ07 CARREGAR JOGO
	printf("(07) - CARREGAR JOGO\n");
	
	//REQ08 ORGANIZAR PEÇAS
	printf("(08) - ORGANIZAR PEÇAS\n");
	
	//REQ09 MOSTRAR TODAS AS PEÇAS
	printf("(09) - MOSTRAR TODAS AS PEÇAS \n");
	
	//REQ10 VER PEÇAS NA TELA
	printf("(10) - VER AS PEÇAS NA TELA \n");
	
}

char opcao() {
	char opcao;
	opcao = getchar();
	flush_in();
	return opcao;
}


void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
