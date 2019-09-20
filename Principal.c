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

void startGamer(FILE *f, Arvore * a){

}
int main(int argc, char *argv[]) {

	Arvore * a = criar();
//	FILE * file = fopen('arquivo.txt', 'r');
//	startGamer(file, a);
//	fclose(file);
	

	int * option = malloc(sizeof(int));
	printf("-- TITULO --\n");

	do{
		
		menu(option);
		switch(*option){
			case 1:{
				break;
			}
			case 2:{
				system("cls");
				printf("-- Listando os nomes --\n ");
				imprimir(a);
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				system("cls");
				char nome[30];
				printf("Digite o nome com no maximo 30 caracteres?\n obs: o nome sera convertido para minusculo.\n=> ");
				fflush(stdin);
				gets(nome);
				toLowercase(nome);
				printf("-- Inserindo o nome... --\n");
				inserir(a, nome);
				break;
			}
			case 5:{
				system("cls");
				char nome[30];
				printf("Digite o nome com no maximo 30 caracteres?\n obs: o nome sera convertido para minusculo.\n=> ");
				fflush(stdin);
				gets(nome);
				toLowercase(nome);
				printf("-- Removendo o nome... --\n");
				remover(a, nome);
				break;
			}
			case 6:{
				system("cls");
				char nome[30];
				printf("Digite o nome com no maximo 30 caracteres?\n obs: o nome sera convertido para minusculo.\n=> ");
				fflush(stdin);
				gets(nome);
				toLowercase(nome);
				handleShowAndRemoveToMaiorBy(a, nome);
				break;
			}
			
			case 7:{
				system("cls");
				char nome[30];
				printf("Digite o nome com no maximo 30 caracteres?\n obs: o nome sera convertido para minusculo.\n=> ");
				fflush(stdin);
				gets(nome);
				toLowercase(nome);
				handleShowAndRemoveToMenorBy(a, nome);
				break;
			}
			case 8:{
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
	
