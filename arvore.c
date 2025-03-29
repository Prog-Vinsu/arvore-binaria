#include "arvore.h"

No *criaNo(int ch) {
  No *novo = (No *)calloc(1, sizeof(No));
  if (!novo) {
    printf("Erro ao alocar memoria.\n");
    exit(1);
  }
  novo->chave = ch;
  return novo;
}

No *busca(No *T, int ch, No **pred) {
  No *aux = T;
  *pred = NULL;
  while (aux != NULL) {
    if (aux->chave == ch)
      break;
    *pred = aux;
    if (ch < aux->chave)
      aux = aux->esq;
    else
      aux = aux->dir;
  }
  return aux;
}

No *insere(No *T, int ch) {
  No *aux, *pred;
  aux = busca(T, ch, &pred);
  if (aux != NULL) {
    printf("Chave ja existente.\n");
    return T;
  } else {
    No *novo = criaNo(ch);
    if (T == NULL)
      return novo;
    if (ch < pred->chave)
      pred->esq = novo;
    else
      pred->dir = novo;
    return T;
  }
}

void imprimeSimetrico(No *T, int nivel) {
  if (T != NULL) {
    imprimeSimetrico(T->dir, nivel + 1);
    for (int i = 0; i < nivel; i++) {
      printf("  ");
    }
    printf("%d\n", T->chave);
    imprimeSimetrico(T->esq, nivel + 1);
  }
}

int contaNos(No *T) {
  if (T == NULL)
    return 0;
  return 1 + contaNos(T->esq) + contaNos(T->dir);
}

void imprimeNivel(No *T, int n) {
  if (T == NULL)
    return;
  // Aloca uma fila com tamanho igual ao número de nós na árvore
  No **fila = (No **)calloc(n, sizeof(No *));
  if (fila == NULL) {
    printf("Erro na alocacao da fila.\n");
    exit(1);
  }
  int inicio = 0, fim = 0;
  fila[fim++] = T;
  while (fim - inicio > 0) {
    No *aux = fila[inicio++];
    printf("%d ", aux->chave);
    if (aux->esq != NULL)
      fila[fim++] = aux->esq;
    if (aux->dir != NULL)
      fila[fim++] = aux->dir;
  }
  free(fila);
  printf("\n");
}

No *sucessor(No *X, No **paiSucessor) {
  No *aux = X->dir;
  *paiSucessor = X;
  if (aux == NULL)
    return NULL;
  while (aux->esq != NULL) {
    *paiSucessor = aux;
    aux = aux->esq;
  }
  return aux;
}

No *excluir(No *T, int ch) {
  No *paiaux = NULL;
  No *aux = busca(T, ch, &paiaux);
  if (aux == NULL)
    return T; // chave nao encontrada ou arvore vazia

  // Caso: nó folha (sem filhos)
  if (aux->esq == NULL && aux->dir == NULL) {
    if (paiaux == NULL) { // árvore com único elemento
      free(aux);
      return NULL;
    } else {
      if (aux == paiaux->esq)
        paiaux->esq = NULL;
      else
        paiaux->dir = NULL;
      free(aux);
      return T;
    }
  }
  // Caso: nó com apenas um filho ou com dois filhos
  else {
    No *paisuc = NULL;
    // Corrigido: buscar o sucessor a partir de 'aux' e não da raiz 'T'
    No *suc = sucessor(aux, &paisuc);
    if (suc == NULL) { // não há sucessor, logo possui apenas filho à esquerda
      if (paiaux == NULL) { // excluindo a raiz
        T = aux->esq;
        free(aux);
        return T;
      } else {
        if (aux == paiaux->esq)
          paiaux->esq = aux->esq;
        else
          paiaux->dir = aux->esq;
        free(aux);
        return T;
      }
    } else {
      aux->chave = suc->chave;
      if (suc == paisuc->esq)
        paisuc->esq = suc->dir;
      else
        paisuc->dir = suc->dir;
      free(suc);
      return T;
    }
  }
}
