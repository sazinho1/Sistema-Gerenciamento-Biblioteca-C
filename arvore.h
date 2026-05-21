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

#endif