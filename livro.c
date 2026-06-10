#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "arvore.h"

Livro *criarLivro(
    int codigo,
    char titulo[],
    char autor[],
    int ano,
    int quantidadeTotal)
{
    Livro *livro = (Livro *)malloc(sizeof(Livro));
    livro->codigo = codigo;
    strcpy(livro->titulo, titulo);
    strcpy(livro->autor, autor);
    livro->ano = ano;
    livro->quantidadeTotal = quantidadeTotal;
    livro->quantidadeDisponivel = quantidadeTotal;
    return livro;
}

void exibirLivro(Livro *livro)
{
    printf("Código: %d\n", livro->codigo);
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano: %d\n", livro->ano);
    printf("Quantidade Total: %d\n", livro->quantidadeTotal);
    printf("Quantidade Disponível: %d\n", livro->quantidadeDisponivel);
}

int obterCodigoLivro(Livro *livro)
{
    return livro->codigo;
}

int obterQuantidadeDisponivel(Livro *livro)
{
    return livro->quantidadeDisponivel;
}

void emprestarExemplar(Livro *livro)
{
    if (livro->quantidadeDisponivel > 0)
    {
        livro->quantidadeDisponivel--;
    }
}

void devolverExemplar(Livro *livro)
{
    if (livro->quantidadeDisponivel < livro->quantidadeTotal)
    {
        livro->quantidadeDisponivel++;
    }
}
