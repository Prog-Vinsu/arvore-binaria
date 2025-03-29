#ifndef __ARVORE_H__
#define __ARVORE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} No;

// Cria um novo nó com a chave informada
No *criaNo(int ch);

// Busca o nó com a chave informada. O parâmetro pred recebe o nó pai do nó buscado.
No *busca(No *T, int ch, No **pred);

// Insere um novo nó com a chave na árvore
No *insere(No *T, int ch);

// Imprime a árvore de forma simétrica (em ordem)
void imprimeSimetrico(No *T, int nivel);

// Imprime a árvore por nível (em largura)
// A função utiliza uma fila cujo tamanho é definido pelo número de nós da árvore
void imprimeNivel(No *T, int n);

// Conta o número de nós da árvore (auxiliar para alocar a fila)
int contaNos(No *T);

// Encontra o sucessor do nó X e retorna seu ponteiro, atualizando o pai do sucessor
No *sucessor(No *X, No **paiSucessor);

// Exclui o nó com a chave informada da árvore
No *excluir(No *T, int ch);

#endif
