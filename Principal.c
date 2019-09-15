#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <string.h>

int main(int argc, char *argv[]) {
	Arvore * a = criar();
	
	
	inserir(a, "AAA" );
	inserir(a, "AA" );
	inserir(a, "BB" );
	inserir(a, "CC" );
	inserir(a, "AAAA" );
	inserir(a, "B" );
	
	
	imprimir(a);
	printf("%d \n", altura(a));
	printf("%d \n", buscar(a, "BB"));
	remover(a, "BB");
	imprimir(a);
	printf("%d \n", altura(a));
	printf("%d \n", buscar(a, "BB"));
	
	destruir(a);
	system("pause");
	
}
