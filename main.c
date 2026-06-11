#include <stdio.h>
#include "fila.h"
#include "lista.h"
#include "arvore.h"
#include "funcoesMain.h"

int main(){
    ConjuntoSistema* ConjuntoSistema = inicializarSistema();
    
    int opcao; // Declaração da variavel para escolha da ação a ser tomada
    
    do{
    exibirMenu();

    scanf("%d", &opcao);
    
    printf("\nOpcao escolhida: %d\n\n", opcao);

    escolherOpcaoMenu(ConjuntoSistema, opcao);

    } while (opcao != 0);

    printf("\nSaindo..."); // Caso escolha sair do programa, ele printa e fecha.

    encerrarSistema(ConjuntoSistema);
    return 0;
}