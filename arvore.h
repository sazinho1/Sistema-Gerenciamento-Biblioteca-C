#ifndef ARVORE_H
#define ARVORE_H

#include "livro.h"  // Tem que incluir pra ele conseguir acessar o struct Livro na criação do struct NoArvore

//--------------------------------------------------------------------------

// Structs

// Definição do struct NoArvore
typedef struct NoArvore {
    Livro* livro;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
    int altura // Guarda a altura do nó específico da árvore
    } NoArvore;

// Definição do struct Arvore
typedef struct Arvore {
    NoArvore* raiz;
} Arvore;

//--------------------------------------------------------------------------

// Métodos
Arvore* criarArvore ();

void inserirLivroArvore(Arvore* arvore , Livro* livro);

Livro* buscarLivroArvore(Arvore* arvore , int codigo);

void removerLivroArvore(Arvore* arvore, int codigo);

void listarLivrosEmOrdem(Arvore* arvore);

void listarLivrosPreOrdem(Arvore* arvore);

void listarLivrosPosOrdem(Arvore* arvore);

int contarLivros(Arvore* arvore);

int calcularAlturaArvore(Arvore* arvore);

// FUNÇÕES EXTRAS PARA AUXILIAR NO BALANCEAMENTO DA ÁRVORE --------------------------------------------------------------------------

int getAlturaNo(NoArvore *NoArvore); // Devolve a altura da árvore

int getFatorDeBalanceamento(NoArvore *NoArvore); // Devolve o fator de balanceamento da árvore

int max(int a, int b); // Pega o maior entre os dois números

NoArvore* rotacaoPraDireita(NoArvore *y); // Rotaciona a árvore para a direita

NoArvore* rotacaoPraEsquerda(NoArvore *x); // Rotaciona a árvore para a esquerda

#endif