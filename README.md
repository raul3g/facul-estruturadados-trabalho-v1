<h1 align="center" >
  <img src="https://portal.fbuni.edu.br/images/logo-login.png" />
</h1>

<h1 align="center" >Trabalho da V1 de Estrutura de Dados II</h1>

## Objetivo: Manutenção em um cadastro de _nomes_ de pessoas.

## Description:

- Linguagem: **C**
- O programa, ao ser iniciado, deverá carregar uma base de dados de nomes inicial a partir de um `arquivo texto`.
  Cada nome, com **_não_** mais que 30 caracteres, deverá ser inserido em uma árvore de pesquisa binária mantida
  em memória RAM através de uma chamada à operação inserir, usando como chave o próprio nome

## A tela do programa deverá fornecer um menu para permitir as seguintes operações:

1. Recarregar a listagem de nomes a partir do arquivo. Para tanto, todo o conteúdo da árvore anterior deverá ser removido e uma nova carga deverá ser feita, como descrito acima.

2. Listar todos os nomes em ordem **alfabética**.

3. Listar todos os nomes que contém uma **substring** fornecida.

4. Inserir um novo nome na memória.

5. Remover um nome da memória.

6. Listar e remover da memória todos os nomes que _são maiores_, em ordem
   alfabética, que um nome fornecido.

7. Listar e remover da memória todos os nomes que _são menores_, em ordem alfabética, que um nome fornecido.

8. Salvar o conteúdo da memória em um `arquivo texto`. Para facilitar a implementação, armazene todas os nomes em letras minúsculas, e considere as entradas fornecidas nas operações como sendo minúsculas.

## Estrutura da Árvore:

- `Arvore * criar():` Inicia a árvore.
- `void destruir(Arvore * arv):` Limpa a árvore da memória.
- `void imprimir(Arvore * arv):` Imprime a árvore em in-ordem.
- `int altura(Arvore * arv):` Calcula a _altura_ da árvore.
- `int buscar(Arvore * arv, char * v):` Retorna se existe um dado vetor do tipo char em uma árvore.
- `void inserir(Arvore * arv, char *v ):` Insere um vetor do tipo char, pelo método de pesquisa.
- `void remover(Arvore * arv, char * v):` Remove um item da árvore, pelo método da pesquisa.
- `void handleShowAndRemoveToMaiorBy( Arvore * arv, char * nome ):` Imprime o remote todos os nomes maiores que um valor.
- `void handleShowAndRemoveToMenorBy( Arvore * arv, char * nome ):` Imprime o remote todos os nomes menores que um valor.
