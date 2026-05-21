#ifndef LIVRO_H
#define LIVRO_H

// Struct

// Definição do struct Livro

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;
    int quantidadeDisponivel;
} Livro;

//--------------------------------------------------------------------------

// Métodos

Livro* criarLivro(
    int codigo,
    char titulo[],
    char autor[],
    int ano,
    int quantidadeTotal
); 
// Tá com indentação pra dar pra ver melhor

void exibirLivro(Livro* livro);

int obterCodigoLivro(Livro* livro);

int obterQuantidadeDisponivel(Livro* livro);

void emprestarExemplar(Livro* livro);

void devolverExemplar(Livro* livro);

#endif