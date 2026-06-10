#include <stdio.h>
#include "fila.c"
#include "fila.h"
#include "lista.c"
#include "lista.h"
#include "arvore.c"
#include "arvore.h"
#include "funcoesMain.c"
#include "funcoesMain.h"

int main(){
    ConjuntoSistema* ConjuntoSistema = inicializarSistema();
    
    int opcao; // Declaração da variavel para escolha da ação a ser tomada
    
    do{
    exibirMenu();

    scanf(""); // Para ele não pegar o /n do printf do "exibirMenu" como input sem querer.
    scanf("%d", &opcao);
    
    escolherOpcaoMenu(ConjuntoSistema, opcao);

    printf("Opcao escolida: %d\n", opcao);
    } while (opcao != 0);

    printf("\nSaindo..."); // Caso escolha sair do programa, ele printa e fecha.

    //encerrarSistema(ta faltando implementar);
    return 0;
}