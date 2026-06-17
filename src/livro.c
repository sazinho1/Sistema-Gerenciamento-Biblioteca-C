#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "arvore.h"

/* * Cria e aloca dinamicamente uma nova estrutura de Livro.
 * Define a quantidade disponível inicial igual à quantidade total de cópias.
 */
Livro *criarLivro(
    int codigo,
    char titulo[],
    char autor[],
    int ano,
    int quantidadeTotal)
{
    // Aloca memória para a estrutura do livro
    Livro *livro = (Livro *)malloc(sizeof(Livro));

    // Verificação de segurança caso o computador fique sem memória
    if (livro == NULL)
    {
        printf("Erro ao alocar memoria para a estrutura do livro.\n");
        return NULL;
    }

    // Copia e atribui os parâmetros recebidos para os campos da struct
    livro->codigo = codigo;
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    livro->ano = ano;
    livro->quantidadeTotal = quantidadeTotal;

    // No momento do cadastro, todos os exemplares estão disponíveis para empréstimo
    livro->quantidadeDisponivel = quantidadeTotal;

    // Retorna o ponteiro do livro pronto
    return livro;
}

/* * Imprime na tela todas as informações detalhadas de um livro específico.
 */
void exibirLivro(Livro *livro)
{
    // Verificação para evitar ler um ponteiro inválido
    if (livro == NULL)
    {
        printf("Livro nao encontrado ou inexistente.\n");
        return;
    }

    // Imprime as estatísticas do livro de forma organizada
    printf("----------------------------------------------------------");
    printf("Codigo: %d\n", livro->codigo);
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano: %d\n", livro->ano);
    printf("Quantidade Total: %d\n", livro->quantidadeTotal);
    printf("Quantidade Disponível: %d\n", livro->quantidadeDisponivel);
    printf("----------------------------------------------------------");

}

/* * Retorna o código do livro informado.
 */
int obterCodigoLivro(Livro *livro)
{
    if (livro == NULL)
        return -1; // Retorna um código inválido caso o livro não exista
    return livro->codigo;
}

/* * Retorna a quantidade atual de exemplares disponíveis na estante.
 */
int obterQuantidadeDisponivel(Livro *livro)
{
    if (livro == NULL)
        return 0;
    return livro->quantidadeDisponivel;
}

/* * Realiza a baixa de um exemplar (decrementa a disponibilidade) quando um empréstimo é feito.
 */
void emprestarExemplar(Livro *livro)
{
    if (livro == NULL)
        return;

    // Só permite emprestar se houver pelo menos 1 exemplar físico disponível na estante
    if (livro->quantidadeDisponivel > 0)
    {
        livro->quantidadeDisponivel--;
    }
    else
    {
        printf("Nao ha exemplares disponiveis para emprestimo no momento.\n");
    }
}

/* * Realiza a devolução de um exemplar (incrementa a disponibilidade).
 */
void devolverExemplar(Livro *livro)
{
    if (livro == NULL)
        return;

    // Só aceita a devolução se a quantidade na estante for menor do que o total cadastrado
    if (livro->quantidadeDisponivel < livro->quantidadeTotal)
    {
        livro->quantidadeDisponivel++;
    }
}