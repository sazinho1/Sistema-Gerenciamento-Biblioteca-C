#ifndef LISTA_H
#define LISTA_H

// Structs

// Definição do struct Emprestimo
typedef struct Emprestimo {
    char nomeUsuario [100];
    int codigoLivro;
    char tituloLivro [100];
} Emprestimo;

// Definição do struct NoLista
typedef struct NoLista {
    Emprestimo emprestimo;
    struct NoLista* proximo;
} NoLista;

// Definição do struct Lista
typedef struct Lista {
    NoLista* inicio;
} Lista;

//--------------------------------------------------------------------------

// Métodos

Lista* criarLista ();

Emprestimo* criarEmprestimo(char nome[], int codigo, char titulo[]);

void inserirEmprestimo(Lista* lista , Emprestimo emprestimo);

void listarEmprestimos(Lista* lista);

int listaVazia(Lista* lista);

#endif