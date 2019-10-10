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

char exibirMenu() {

	char opcao;

	printf("JOGO DOMINÓ\n");
	printf("MENU DO JOGO\n");
	opcao = getchar();

	printf("(1) - Iniciar jogo\n");
	printf("(2) - Opções do jogo\n");
	printf("(3) - Sair do jogo\n");
	printf("Selecione a opção desejada: ");

	return opcao;
	
}

char obterOpcao() {
	char opcao;
	opcao = getchar();
	flush_in();
	return opcao;
}

//funcao auxiliar para limpeza do buffer do teclado
void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

char opcoesJogo()
{
	printf("OPÇÕES DO JOGO");
	printf("(1) - Mostrar peças do dominó\n");
	printf("(2) - Carregar jogo salvo\n");
	printf("(3) - Organizar peças do dominó na sequência\n");
	printf("(4) - Embaralhar peças do dominó\n");
}

void mostrarPecas()
{
	printf("0|0 0|1 0|2 0|3 0|4 0|5 0|6\n1|1 1|2 1|3 1|4 1|5 1|6\n2|2 2|3 2|4 2|5 2|6\n3|3 3|4 3|5 3|6\n4|4 4|5 4|6\n5|5 5|6\n6|6");
}
