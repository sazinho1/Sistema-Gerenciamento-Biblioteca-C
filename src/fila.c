#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "arvore.h"
#include "fila.h"

/* * Inicializa uma fila dinâmica vazia.
 * Aloca a estrutura de controle (ponteiros de início, fim e tamanho).
 */
Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    if (fila == NULL)
    {
        printf("Erro ao alocar memoria para a fila.\n");
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

/* * Cria e aloca dinamicamente uma nova estrutura de Reserva.
 * Retorna o ponteiro para a reserva preenchida.
 */
Reserva *criarReserva(char nome[], int codigo)
{
    // Aloca a memória necessária pra reserva do livro
    Reserva *reserva = malloc(sizeof(Reserva));

    // Verificação de segurança caso o sistema fique sem memória
    if (reserva == NULL)
    {
        printf("Erro ao criar a reserva. Tente novamente.\n");
        return NULL;
    }

    // Copia os dados recebidos para dentro da estrutura alocada
    strcpy(reserva->nomeUsuario, nome);
    reserva->codigoLivro = codigo;

    // Retorna a reserva pronta
    return reserva;
}

/* * Insere uma nova reserva no FIM da fila (Conceito FIFO: First In, First Out).
 */
void enfileirarReserva(Fila *fila, Reserva reserva)
{
    // Aloca o nó que vai carregar a reserva dentro da fila encadeada
    NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memoria para novo no da fila.\n");
        return;
    }
    novoNo->reserva = reserva;
    novoNo->proximo = NULL; // Como entra no fim, o próximo dele é sempre NULL

    // Se a fila estiver vazia, o novo nó será o início e o fim ao mesmo tempo
    if (filaVazia(fila))
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    // Caso contrário, conecta o antigo fim ao novo nó, e atualiza o ponteiro de fim
    else
    {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;
}

/* * Remove e retorna a reserva que está no INÍCIO da fila (Mais antiga).
 */
Reserva desenfileirarReserva(Fila *fila)
{
    // Tratamento de erro caso tentem remover algo de uma fila sem elementos
    if (filaVazia(fila))
    {
        printf("Fila vazia. Não eh possivel desenfileirar.\n");
        Reserva reservaVazia = {"", -1}; // Retorna uma reserva com dados inválidos para indicar que a operação falhou
        return reservaVazia;
    }

    // Guarda o nó do início e os dados da reserva que será retornada
    NoFila *temp = fila->inicio;
    Reserva reservaDesenfileirada = temp->reserva;

    // Avança o início da fila para o próximo elemento
    fila->inicio = fila->inicio->proximo;

    // Se a fila ficou vazia após a remoção, o fim também deve apontar para NULL
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    // Libera a memória do nó que foi removido para evitar Memory Leak
    free(temp);

    fila->tamanho--;
    return reservaDesenfileirada;
}

/** Procura se há uma reserva para esse livro específico por meio de uma busca linear
 */
NoFila *procurarReserva(Fila *fila, int codigo)
{

    // Verifica se a fila NÃO está vazia
    if (filaVazia(fila) == 0)
    {
        NoFila *noAux = fila->inicio;

        // Percorre a fila nó por nó comparando os códigos dos livros
        for (int i = 0; i < fila->tamanho; i++)
        {
            if (noAux->reserva.codigoLivro == codigo)
            {
                return noAux; // Retorna o nó onde a reserva foi encontrada
            }
            noAux = noAux->proximo; // Avança para o próximo nó
        }
    }
    return NULL; // Retorna NULL se não encontrar ou se a fila estiver vazia
}

/* * Verifica se a fila está vazia.
 * Retorna 1 (verdadeiro) se o início for NULL, ou 0 (falso) caso contrário.
 */
int filaVazia(Fila *fila)
{
    return fila->inicio == NULL;
}

/* * Percorre toda a fila do início ao fim imprimindo os dados na tela.
 */
void exibirReservas(Fila *fila)
{
    NoFila *atual = fila->inicio;

    if (filaVazia(fila))
    {
        printf("Nenhuma reserva na fila atualmente.\n");
        return;
    }

    // Loop que caminha pela estrutura encadeada até encontrar o NULL (fim da fila)
    while (atual != NULL)
    {
        printf("Usuario: %s\n", atual->reserva.nomeUsuario);
        printf("Codigo do Livro: %d\n", atual->reserva.codigoLivro);
        printf("-------------------------\n");
        atual = atual->proximo; // Vai para o próximo da fila
    }
}