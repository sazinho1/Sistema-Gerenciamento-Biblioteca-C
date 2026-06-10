#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "arvore.h"
#include "lista.h"

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void inserirEmprestimo(Lista *lista, Emprestimo emprestimo)
{
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    novoNo->emprestimo = emprestimo;
    novoNo->proximo = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    else
    {
        NoLista *atual = lista->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void listarEmprestimos(Lista *lista)
{
    NoLista *atual = lista->inicio;
    while (atual != NULL)
    {
        printf("Usuario: %s\n", atual->emprestimo.nomeUsuario);
        printf("Codigo do Livro: %d\n", atual->emprestimo.codigoLivro);
        printf("Titulo do Livro: %s\n", atual->emprestimo.tituloLivro);
        printf("-------------------------\n");
        atual = atual->proximo;
    }
}

int listaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}