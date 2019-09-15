typedef struct arvore Arvore;

Arvore * criar();
void destruir(Arvore * arv);
void imprimir(Arvore * arv);

int altura(Arvore * arv);

int buscar(Arvore * arv, char * v);
void inserir(Arvore * arv, char *v );
void remover(Arvore * arv, char * v);
