#include <stdio.h>
#include "fila.h"
#include "lista.h"
#include "arvore.h"
#include "funcoesMain.h"

int main(){
    ConjuntoSistema* conjunto = inicializarSistema();
    
    int opcao; // Declaração da variavel para escolha da ação a ser tomada
    
    do{

        // O scanf retorna 1 se conseguiu ler 1 variável corretamente.
        // Se retornar 0, significa que o user digitou algo errado (como uma letra, por exemplo).
        if (scanf("%d", &opcao) != 1) {
            
            printf("\nERRO: Entrada invalida. Por favor, digite um numero.\n\n");
            
            // limpa o buffer da seguinte forma: lê e descarta todos os caracteres até achar o Enter (\n)
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // EOF é "End Of File", isto é, caso o user dê cntrl + z, que envia um sinal de EOF forçado e o sistema    entraria num loop e quebraria.
            
            // Atribui um valor inválido para forçar o menu a repetir sem entrar em nenhum 'case'
            opcao = -1; 
            continue; // Pula direto para o final do 'do-while' e recomeça o loop
        }

    escolherOpcaoMenu(conjunto, opcao);

    } while (opcao != 0);

    printf("\nSaindo..."); // Caso escolha sair do programa, ele printa e fecha.

    encerrarSistema(conjunto);
    return 0;
}