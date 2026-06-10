#ifndef FUNCOESMAIN_H
#define FUNCOESMAIN_H

// Precisa desses .h's para as funções de encerrar o sistema
#include "arvore.h"
#include "lista.h"
#include "fila.h"


// Atributos da inicialização do sistema (TAD's básicos para ele funcionar)
typedef struct ConjuntoSistema {
    Arvore* ArvorePrincipal;
    Fila* FilaPrincipal;
    Lista* ListaPrincipal;
} ConjuntoSistema;

// Métodos

void exibirMenu(); // Exibe o menu do sistema (interface)

void escolherOpcaoMenu(ConjuntoSistema* ConjuntoSistema, int opcaoEscolhida); // Seleciona a opção do menu desejada e chama sua respectiva função

int cadastrarLivro();

ConjuntoSistema* criarConjuntoSistema(); // Cria um conjunto dos TAD's básicos para o funcionamento do sistema dentro do struct "ConjuntoSistema", o qual contém uma árvore, uma fila e uma lista de empréstimos

ConjuntoSistema* inicializarSistema(); // Inicializa a árvore binária, fila de reservas e lista de empréstimos por meio do "Conjunto Sistema"

// FUNÇÕES PARA ENCERRAR O SISTEMA --------------------------------------------------------------------------

void liberarNosArvore(NoArvore* NoArvore); //Função pra liberar os nós da árvore e ser chamada recursivamente pela "limparArvore"

void limparArvore(Arvore* Arvore); //Função pra liberar a Árvore

void limparLista(Lista* lista); //Função pra liberar a Lista

void limparFila(Fila* fila); //Função pra liberar a Fila

void encerrarSistema(ConjuntoSistema* ConjuntoSistema); // Dá free em toda a memória alocada

#endif