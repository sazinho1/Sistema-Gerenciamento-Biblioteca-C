#ifndef LISTA_H
#define LISTA_H

// Structs

// Definição do struct Emprestimo
typedef struct Emprestimo
{
    char nomeUsuario[100];
    int codigoLivro;
    char tituloLivro[100];
} Emprestimo;

// Definição do struct NoLista
typedef struct NoLista
{
    Emprestimo emprestimo;
    struct NoLista *proximo;
} NoLista;

// Definição do struct Lista
typedef struct Lista
{
    NoLista *inicio;
} Lista;

//--------------------------------------------------------------------------

// Métodos

Lista *criarLista(); // Inicializa uma lista encadeada vazia.

Emprestimo *criarEmprestimo(char nome[], int codigo, char titulo[]); // Cria e aloca dinamicamente uma nova estrutura de Emprestimo.

void inserirEmprestimo(Lista *lista, Emprestimo emprestimo); // Insere um novo empréstimo no final da lista encadeada.

void listarEmprestimos(Lista *lista); // Percorre toda a lista do início ao fim imprimindo os dados de cada empréstimo.

int listaVazia(Lista *lista); // Verifica se a lista está vazia.

#endif