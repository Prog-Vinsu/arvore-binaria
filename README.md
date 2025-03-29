# 🌳 Árvore Binária em C

Este repositório contém a implementação de uma árvore binária de busca (ABB) na linguagem C, incluindo funções para inserção, remoção, busca e impressão da árvore.

Este código foi desenvolvido a partir das aulas de **Estrutura de Dados** na **UFES - Campus São Mateus**.

## ✨ Funcionalidades

- Inserir um novo elemento na árvore.
- Buscar um elemento na árvore.
- Imprimir a árvore em ordem simétrica e por níveis.
- Remover um elemento da árvore.

## 🛠️ Como Compilar e Executar

### Requisitos

Certifique-se de ter o compilador `gcc` instalado. Se estiver usando Linux, instale com:

```sh
sudo apt install gcc
```

### Compilando o Código

Use o `make` para compilar o projeto:

```sh
make all
```

Caso não tenha `make`, compile manualmente:

```sh
gcc -o arvore main.c arvore.c -Wall -Werror -Wextra
```

### Executando o Programa

```sh
./arvore
```

## 📙 Estrutura do Projeto

```
/
├── arvore.h          # Definição das estruturas e protótipos das funções
├── arvore.c          # Implementação das funções da árvore binária
├── main.c            # Função principal com o menu de interação
├── Makefile          # Script para compilação automatizada
└── README.md         # Documentação do projeto
```
---

Desenvolvido por [Vincenzo Tognere Polonini](https://github.com/Prog-Vinsu) 💪

