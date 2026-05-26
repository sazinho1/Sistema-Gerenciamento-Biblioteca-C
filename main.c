#include <stdio.h>

void exibirMenu(){
    printf("----------SISTEMA DE GERENCIAMENTO DA BIBLIOTECA ED----------\n\n");
    
    printf(
        "Selecione uma das opcoes a seguir:\n\n"
        "1. Cadastrar novo livro\n"
        "2. Buscar livro por codigo\n"
        "3. Listar livros em ordem crescente de codigo\n"
        "4. Listar livros em pre-ordem\n"
        "5. Listar livros em pos-ordem\n"
        "6. Realizar emprestimo de livro\n"
        "7. Devolver livro\n"
        "8. Exibir fila de reservas\n"
        "9. Exibir historico de emprestimos\n"
        "10. Exibir quantidade de livros cadastrados\n"
        "11. Exibir altura da arvore\n"
        "0. Sair\n\n"
    );

        // Não consegui colocar tudo em um unico printf porque o compilador tava bugando
}

int main(){
    int opcao; // Declaração da variavel para escolha da ação a ser tomada
    
    do{
    exibirMenu();

    scanf(""); // Para ele não pegar o /n do printf do "exibirMenu" como input sem querer.
    scanf("%d", &opcao);
    
    printf("Opcao escolida: %d\n", opcao);
    } while (opcao != 0);

    printf("\nSaindo...");

    return 0;
}