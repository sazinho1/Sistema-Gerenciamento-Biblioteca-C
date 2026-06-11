#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Pra função "strcpy()"
#include "livro.h"
#include "arvore.h"
#include "lista.h"

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

Emprestimo* criarEmprestimo(char nome[], int codigo, char titulo[]){
    // Aloca a memória necessária pro empréstimo do livro
    Emprestimo* emprestimo = malloc(sizeof(Emprestimo));

    if(emprestimo == NULL){
        printf("Erro ao criar o empréstimo. Tente novamente.");
        return NULL;
    }

    // Muda os dados para serem os do empréstimo atual
    strcpy(emprestimo->nomeUsuario, nome);
    emprestimo->codigoLivro = codigo;
    strcpy(emprestimo->nomeUsuario, titulo);

    // Retorna o empréstimo pronto
    return emprestimo;
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