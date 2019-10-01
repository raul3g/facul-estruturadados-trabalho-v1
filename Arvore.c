#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <string.h>

typedef struct no No;

struct arvore {
	No * raiz;
};

struct no {
	char info[30];
	No * esq;
	No * dir;
};

Arvore * criar() {
   Arvore * a = malloc(sizeof(Arvore));
   a->raiz = NULL;
   return a;
}

void destruir(Arvore * a) {
	desalocar_nos_rec(a->raiz);
	free(a);
}

void desalocar_nos_rec(No * raiz) {
	if (raiz != NULL) {
		desalocar_nos_rec(raiz->esq);
		desalocar_nos_rec(raiz->dir);
		free(raiz);
	}
}

void imprimir(Arvore * a) {
  printf("\n");
	imp_in(a->raiz);
	printf("\n");
} 

void imp_in(No * raiz) {
	if (raiz != NULL) {
		imp_in(raiz->esq);
		printf("%s\n", raiz->info);
		imp_in(raiz->dir);
	}
}


No * inserir_rec(No * raiz, char * v ) {
	if (raiz != NULL) {
    int chave = strcmp(v, raiz->info);
    
		if (chave < 0) {
			raiz->esq = inserir_rec(raiz->esq, v);
		}
		else if (chave > 0) {
			raiz->dir = inserir_rec(raiz->dir, v);
		}
	} else {
		raiz = malloc(sizeof(No));
		strcpy(raiz->info, v);
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	return raiz;
}

void inserir(Arvore * arv, char * v) {
	arv->raiz = inserir_rec(arv->raiz, v);
}

int altura(Arvore * arv){
  return altura_rec(arv->raiz);
}

int altura_rec(No * raiz){
  if( raiz != NULL ){
    int ae = altura_rec(raiz->esq);
    int ad = altura_rec(raiz->dir);
    return ( ae > ad ? ae : ad ) + 1;
  }
  return -1;
}

int buscar(Arvore * arv, char * v){
  return buscar_rec(arv->raiz, v);
}

int buscar_rec(No * raiz, char * v){
  if( raiz != NULL ){
    int chave = strcmp(v, raiz->info);
    if( chave == 0 ){
      return 1;
    }else if(chave < 0){
      return buscar_rec(raiz->esq, v);
    }else{
      return buscar_rec(raiz->dir, v);
    }
  }
  return 0;
}

No * remover_maior(No * raiz, char * maior){
  if (raiz != NULL) {
		if (raiz->dir != NULL) {
			raiz->dir = remover_maior(raiz->dir, maior);
		} else {
			No * aux = raiz;
      strcpy(maior, raiz->info);
			raiz = raiz->esq;
			free(aux);
		}
	}
	return raiz;
}

No * remover_rec(No * raiz, char * v){
  if(raiz != NULL){
    int chave = strcmp(v, raiz->info);
    if(chave < 0){
      raiz->esq = remover_rec(raiz->esq, v);
    }else if(chave > 0){
      raiz->dir = remover_rec(raiz->dir, v);
    }else{
      No * aux = raiz;

      if(raiz->esq == NULL && raiz->dir == NULL){
        raiz = NULL;
        free(aux);
      }else if( raiz->esq == NULL || raiz->dir == NULL ){
        raiz = raiz->esq != NULL ? raiz->esq : raiz->dir;
        free(aux);
      }else{
        char maior[30];
        raiz->esq = remover_maior(raiz->esq, maior);
        strcpy(raiz->info, maior);
      }
    }

  }
  return raiz;
}

void remover(Arvore * arv, char * v){
  arv->raiz = remover_rec(arv->raiz, v);
}


No * handleShowAndRemoveToMenorBy_rec(No * raiz, char * nome){
  if(raiz != NULL){

    int chave = strcmp(nome, raiz->info);
    if( chave == 0 && raiz->esq != NULL ){
      imp_in(raiz->esq);
      desalocar_nos_rec(raiz->esq);
      raiz->esq = NULL;
    }
    else{
      if(chave < 0){
        raiz->esq = handleShowAndRemoveToMenorBy_rec(raiz->esq, nome);
        
      }else{
      	
        if(raiz->esq != NULL){
          imp_in(raiz->esq);
          desalocar_nos_rec(raiz->esq);
          raiz->esq = NULL;
        }
        printf("%s\n", raiz->info);
        raiz->dir = handleShowAndRemoveToMenorBy_rec(raiz->dir, nome);
        No * aux = raiz->dir;
        free(raiz);
        raiz = aux;
      }
    }
    
  }
  return raiz;
}

void handleShowAndRemoveToMenorBy( Arvore * arv, char * nome ){
  if( arv->raiz != NULL){
    arv->raiz = handleShowAndRemoveToMenorBy_rec(arv->raiz, nome);
  }else{
    printf("\n Nenhum nome e menor que %s\n", nome);
  }
}

No * handleShowAndRemoveToMaiorBy_rec(No * raiz, char * nome){
  if(raiz != NULL){
    int chave = strcmp(nome, raiz->info);
    if( chave == 0 && raiz->dir != NULL ){
      imp_in(raiz->dir);
      desalocar_nos_rec(raiz->dir);
      raiz->dir = NULL;
    }
    else{
      if(chave < 0){
        raiz->esq = handleShowAndRemoveToMaiorBy_rec(raiz->esq, nome);
        printf("%s\n", raiz->info);
        if(raiz->dir != NULL){
          imp_in(raiz->dir);
          desalocar_nos_rec(raiz->dir);
          raiz->dir = NULL;
        }
        No * aux = raiz->esq;
        free(raiz);
        raiz = aux;
        
      }else{
        raiz->dir = handleShowAndRemoveToMaiorBy_rec(raiz->dir, nome);
      }
    }
  }

  return raiz;
}

void handleShowAndRemoveToMaiorBy( Arvore * arv, char * nome ){
  if( arv->raiz != NULL){
    arv->raiz = handleShowAndRemoveToMaiorBy_rec(arv->raiz, nome);
  }else{
    printf("\n Nenhum nome e maior que %s\n", nome);
  }
}
void handleContainsBy(Arvore * arv, char * nome){
  if( arv->raiz != NULL){
    printf("\n");
    handleContainsBy_rec(arv->raiz, nome);
    printf("\n");
  }
}

void handleContainsBy_rec(No * raiz, char * nome){
  if(raiz != NULL){
    char * chave = strstr(raiz->info, nome);
    handleContainsBy_rec(raiz->esq, nome);
    if(chave != NULL){
      printf("%s\n", raiz->info);
    }
    handleContainsBy_rec(raiz->dir, nome);
  }
}

void salvarArvore_rec(No * raiz, FILE * file){
  if(raiz != NULL){
    fputs(raiz->info, file);
    fputc('\n', file);
    salvarArvore_rec(raiz->esq, file);
    salvarArvore_rec(raiz->dir, file);
  }
}

void salvarArvore(Arvore * arv){
  FILE * file = fopen("arquivo.txt", "w");
  if( file != NULL){
    salvarArvore_rec(arv->raiz, file);
  }
  fclose(file);
}

void removerNomes(Arvore *arv){
  desalocar_nos_rec(arv->raiz);
  arv->raiz = NULL;
}


