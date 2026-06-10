#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "arvore.h"
#include "fila.h"

Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirarReserva(Fila *fila, Reserva reserva)
{
    NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    if (novoNo == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória para novo nó da fila.\n");
        return;
    }
    novoNo->reserva = reserva;
    novoNo->proximo = NULL;

    if (filaVazia(fila))
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

Reserva desenfileirarReserva(Fila *fila)
{
    if (filaVazia(fila))
    {
        fprintf(stderr, "Fila vazia. Não é possível desenfileirar.\n");
        Reserva reservaVazia = {"", -1}; // Retorna uma reserva vazia ou com código inválido
        return reservaVazia;
    }

    NoFila *temp = fila->inicio;
    Reserva reservaDesenfileirada = temp->reserva;

    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL)
    {
        fila->fim = NULL; // Se a fila ficar vazia, atualiza o fim para NULL
    }

    free(temp);
    return reservaDesenfileirada;
}

int filaVazia(Fila *fila)
{
    return fila->inicio == NULL;
}

void exibirReservas(Fila *fila)
{
    NoFila *atual = fila->inicio;
    while (atual != NULL)
    {
        printf("Usuario: %s\n", atual->reserva.nomeUsuario);
        printf("Codigo do Livro: %d\n", atual->reserva.codigoLivro);
        printf("-------------------------\n");
        atual = atual->proximo;
    }
}