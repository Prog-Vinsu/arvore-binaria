#include "arvore.h"

int main() {
  No *T = NULL, *pred = NULL, *aux = NULL;
  int menu = 0, x;
  while (menu != 5) {
    printf("\nMENU\n");
    printf("1 - Inserir uma nova chave\n");
    printf("2 - Buscar uma chave\n");
    printf("3 - Imprimir a arvore\n");
    printf("4 - Excluir chave\n");
    printf("5 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &menu);
    switch (menu) {
      case 1:
        printf("Digite a chave a ser inserida: ");
        scanf("%d", &x);
        T = insere(T, x);
        break;
      case 2:
        printf("Digite a chave a ser buscada: ");
        scanf("%d", &x);
        aux = busca(T, x, &pred);
        if (aux != NULL)
          printf("Chave encontrada: %d\n", aux->chave);
        else
          printf("Chave nao encontrada.\n");
        break;
      case 3: {
          int n = contaNos(T);
          printf("Impressao Simetrica:\n");
          imprimeSimetrico(T, 0);
          printf("Impressao por Nivel:\n");
          imprimeNivel(T, n);
        }
        break;
      case 4:
        printf("Digite a chave a ser excluida: ");
        scanf("%d", &x);
        T = excluir(T, x);
        break;
      case 5:
        printf("Fim.\n");
        exit(0);
      default:
        printf("Opcao invalida!\n");
        break;
    }
  }
  return 0;
}
