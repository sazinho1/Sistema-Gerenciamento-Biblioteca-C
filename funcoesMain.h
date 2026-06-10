#ifndef FUNCOESMAIN_H
#define FUNCOESMAIN_H

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

void encerrarSistema(); // Dá free nos espaços de memória alocados

#endif