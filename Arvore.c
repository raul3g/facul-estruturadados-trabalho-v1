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
	imp_pre(a->raiz);
	printf("\n");
} 

void imp_pre(No * raiz) {
	if (raiz != NULL) {
		printf("%s ", raiz->info);
		imp_pre(raiz->esq);
		imp_pre(raiz->dir);
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


