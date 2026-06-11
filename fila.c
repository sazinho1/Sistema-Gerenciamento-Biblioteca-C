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
    fila->tamanho = 0;
    return fila;
}

Reserva* criarReserva(char nome[], int codigo){
    // Aloca a memória necessária pra reserva do livro
    Reserva* reserva = malloc(sizeof(Reserva));

    if(reserva == NULL){
        printf("Erro ao criar a reserva. Tente novamente.");
        return NULL;
    }

    // Muda os dados para serem os da reserva atual
    strcpy(reserva->nomeUsuario, nome);
    reserva->codigoLivro = codigo;

    // Retorna a reserva pronta
    return reserva;
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

    fila->tamanho++;
    return;
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

NoFila* procurarReserva(Fila* fila, int codigo){
    // Procura se há uma reserva para esse livro específico por meio de uma busca linear

    // Se a fila não estiver vazia
    if(filaVazia == 0){
        NoFila* noAux = fila->inicio;

        for (int i = 0; i < fila->tamanho; i++)
        {
            if(noAux->reserva.codigoLivro == codigo){
                return noAux;
            }
            noAux = noAux->proximo;
        }
        return NULL;
    }
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