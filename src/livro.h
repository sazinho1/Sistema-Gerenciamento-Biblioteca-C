#ifndef LIVRO_H
#define LIVRO_H

// Struct

// Definição do struct Livro

typedef struct
{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;
    int quantidadeDisponivel;
} Livro;

//--------------------------------------------------------------------------

// Métodos

Livro *criarLivro(
    int codigo,
    char titulo[],
    char autor[],
    int ano,
    int quantidadeTotal);
// Cria e aloca dinamicamente uma nova estrutura de Livro.

void exibirLivro(Livro *livro); // Imprime na tela todas as informações detalhadas de um livro específico.

int obterCodigoLivro(Livro *livro); // Retorna o código do livro informado.

int obterQuantidadeDisponivel(Livro *livro); // Retorna a quantidade atual de exemplares disponíveis na estante.

void emprestarExemplar(Livro *livro); // Realiza a baixa de um exemplar quando um empréstimo é feito.

void devolverExemplar(Livro *livro); // Realiza a devolução de um exemplar.

#endif