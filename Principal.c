#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <string.h>

void menu(int * option){
	printf("------------------------------------------------- \n");
	printf("| 1. Recarregar a listagem de nomes.            | \n");
	printf("| 2. Listar os nomes.                           | \n");
	printf("| 3. Listar os nomes que contem uma substring.  | \n");
	printf("| 4. Inserir um nome.                           | \n");
	printf("| 5. Remover um nome.                           | \n");
	printf("| 6. Listar e remover os nomes maiores.         | \n");
	printf("| 7. Listar e remover os nomes menores.         | \n");
	printf("| 8. Salvar.                                    | \n");
	printf("------------------------------------------------- \n => ");
	scanf("%d", option);
	while(*option <  1 || *option > 8 ){
		printf("Opicao invalida, digite um numero entre 1 e 8.\n => ");
		scanf("%d", option);
	}

}

void toLowercase(char * nome){
	int i, j;
	for(i = 0; nome[i] != '\0'; i++){
		for(j = 0; j<26 ; j++ ){
			if(nome[i] == ( 'A'+j ) ){
				nome[i] = 'a'+j;
			}
		}		
	}
}

void getNome( char * nome ){
	system("cls");
	printf("Digite o nome com no maximo 30 caracteres?\n obs: o nome sera convertido para minusculo.\n=> ");
	fflush(stdin);
	gets(nome);
	toLowercase(nome);

}

void handleExeptionNome( char * nome ){
	int i;
	for(i = 0; *(nome + i) != '\0'; i++ ){
		if( *(nome + i) == '\n' ){
			*(nome + i) = '\0';
			break;
		}
	}
	toLowercase(nome);

}

void startArvore( Arvore * a, FILE *file){
	removerNomes(a);
	char c[30];
	while( !feof(file) ){
		fgets(c, 30, file);
		if(feof(file)){
			break;
		}
		handleExeptionNome(c);
		inserir(a, c);
	}
}

void startGame(Arvore * a){
	FILE * file = fopen("arquivo.txt", "r");
	if(file != NULL){
		startArvore(a, file);
	}
	fclose(file);
}


int main(int argc, char *argv[]) {

	Arvore * a = criar();
	startGame(a);
	int * option = malloc(sizeof(int));
	printf("-- TITULO --\n");

	do{
		menu(option);
		switch(*option){
			case 1:{
				startGame(a);
				break;
			}
			case 2:{
				system("cls");
				printf("\n-- Listando os nomes --\n ");
				imprimir(a);
				break;
			}
			case 3:{
				char nome[30];
				getNome(nome);
				printf("\n-- Listando os nomes que contem %s... --\n", nome);
				handleContainsBy(a, nome);
				break;
			}
			case 4:{
				char nome[30];
				getNome(nome);
				printf("\n-- Inserindo o nome %s... --\n", nome);
				inserir(a, nome);
				break;
			}
			case 5:{
				char nome[30];
				getNome(nome);
				printf("\n-- Removendo o nome %s... --\n", nome);
				remover(a, nome);
				break;
			}
			case 6:{
				char nome[30];
				getNome(nome);
				printf("\n-- Listando e removendo os nomes maiores que %s... --\n", nome);
				handleShowAndRemoveToMaiorBy(a, nome);
				break;
			}
			
			case 7:{
				char nome[30];
				getNome(nome);
				printf("\n-- Listando e removendo os nomes menores que %s... --\n", nome);
				handleShowAndRemoveToMenorBy(a, nome);
				break;
			}
			case 8:{
				printf("\n-- Salvando os nomes no aquivo... --\n");
				salvarArvore(a);
				break;
			}
			default:
				break;
		}

	}while(*option >= 1 && *option <= 8);
	free(option);
	destruir(a);
	system("pause");
}
	
