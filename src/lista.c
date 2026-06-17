#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para função "strcpy()"
#include "livro.h"
#include "arvore.h"
#include "lista.h"

/* * Inicializa uma lista encadeada vazia.
 * Aloca a estrutura de controle e define o início como NULL.
 */
Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
    {
        printf("Erro ao alocar memoria para a lista.\n");
        return NULL;
    }
    lista->inicio = NULL;
    return lista;
}

/* * Cria e aloca dinamicamente uma nova estrutura de Emprestimo.
 */
Emprestimo *criarEmprestimo(char nome[], int codigo, char titulo[])
{
    // Aloca a memória necessária pro empréstimo do livro
    Emprestimo *emprestimo = malloc(sizeof(Emprestimo));

    // Verificação de segurança caso o sistema fique sem memória RAM
    if (emprestimo == NULL)
    {
        printf("Erro ao criar o emprestimo. Tente novamente.\n");
        return NULL;
    }

    // Copia os dados recebidos para dentro da estrutura alocada
    strcpy(emprestimo->nomeUsuario, nome);
    emprestimo->codigoLivro = codigo;
    strcpy(emprestimo->tituloLivro, titulo);

    // Retorna o empréstimo pronto
    return emprestimo;
}

/* * Insere um novo empréstimo no FINAL da lista encadeada.
 */
void inserirEmprestimo(Lista *lista, Emprestimo emprestimo)
{
    // Aloca o nó que vai guardar o empréstimo dentro da lista
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));

    // Verificação de segurança
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memoria para o no da lista.\n");
        return;
    }

    novoNo->emprestimo = emprestimo;
    novoNo->proximo = NULL; // Como entra no fim, o próximo dele é sempre NULL

    // Se a lista estiver vazia, o novo nó se torna o primeiro elemento (início)
    if (lista->inicio == NULL)
    {
        lista->inicio = novoNo;
    }
    // Caso contrário, percorre a lista até encontrar o último nó para conectar o novo
    else
    {
        NoLista *atual = lista->inicio;

        // Caminha pela lista parando exatamente no NÓ ATUAL cujo próximo é NULL (o último)
        while (atual->proximo != NULL)
        {
            atual = atual->proximo; // Avança para o próximo nó
        }
        // Conecta o antigo último nó ao novo nó
        atual->proximo = novoNo;
    }
}

/* * Percorre toda a lista do início ao fim imprimindo os dados de cada empréstimo.
 */
void listarEmprestimos(Lista *lista)
{
    NoLista *atual = lista->inicio;

    // Mensagem de aviso caso não existam empréstimos cadastrados
    if (listaVazia(lista))
    {
        printf("Nenhum emprestimo registrado na lista.\n");
        return;
    }

    // Loop que caminha pela lista imprimindo os dados até chegar ao fim (NULL)
    while (atual != NULL)
    {
        
        printf("\n-------------------------\n");
        printf("Usuario: %s\n", atual->emprestimo.nomeUsuario);
        printf("Codigo do Livro: %d\n", atual->emprestimo.codigoLivro);
        printf("Titulo do Livro: %s\n", atual->emprestimo.tituloLivro);
        atual = atual->proximo; // Avança para o próximo nó
    }
}

/* * Verifica se a lista está vazia.
 * Retorna 1 (verdadeiro) se o início for NULL, ou 0 (falso) caso contrário.
 */
int listaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}