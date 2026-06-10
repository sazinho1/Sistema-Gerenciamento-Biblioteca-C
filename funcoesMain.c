#include <stdio.h>
#include "fila.c"
#include "fila.h"
#include "lista.c"
#include "lista.h"
#include "arvore.c"
#include "arvore.h"
#include "funcoesMain.h"

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

// Função para escolher a opção a ser realizada no menu principal
void escolherOpcaoMenu(ConjuntoSistema* ConjuntoSistema, int opcaoEscolhida){
    // Variáveis necessárias para algumas opções do menu:
    int codigoLivroEscolhido; // Opção 2


    switch (opcaoEscolhida){
    case 1:
        cadastrarLivro(ConjuntoSistema->ArvorePrincipal);
        break;
    
    
    case 2:
        printf("Digite o codigo do livro: \n");
        scanf(""); // Pra não pegar o \n
        scanf("%d\n", &codigoLivroEscolhido);
        Livro* livro = buscarLivroArvore(ConjuntoSistema->ArvorePrincipal, codigoLivroEscolhido); // Faz a busca do livro na árvore
        exibirLivro(livro); // Mosta o livro
        break;
    
    
    case 3:
        /* code */
        break;
    
    
    case 4:
        /* code */
        break;
    
    
    case 5:
        /* code */
        break;
    
    
    case 6:
        /* code */
        break;
    
    
    case 7:
        /* code */
        break;
    
    
    case 8:
        /* code */
        break;
    
    
    case 9:
        /* code */
        break;
    

    case 10:
        /* code */
        break;
    
    default:
        break;
    }

}

int cadastrarLivro(Arvore* ArvorePrincipal){
    // Dados do livro a ser inserido
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;

    // Pega cada dado do livro
    printf("Digite o codigo do livro a ser inserido \n:");
    scanf("");
    scanf("%d", &codigo);

    printf("Digite o titulo do livro a ser inserido \n:");
    scanf("");
    scanf("%s", &titulo);

    printf("Digite o autor/a autora do livro a ser inserido \n:");
    scanf("");
    scanf("%s", &autor);

    printf("Digite o ano de publicacao do livro a ser inserido \n:");
    scanf("");
    scanf("%d", &ano);

    printf("Digite a quantidade de exemplares do livro a ser inserido \n:");
    scanf("");
    scanf("%d", &quantidadeTotal);

    // Cria o novo livro
    Livro* NovoLivro = criarLivro(codigo, titulo, autor, ano, quantidadeTotal);

    // Caso dê erro na criação do livro
    if(NovoLivro == NULL){
        printf("Erro na criação do livro.");
        return 0;
    }

    // Adciona o livro a arvore principal de livro
    inserirLivroArvore(&ArvorePrincipal, NovoLivro);

    return 1;
}

ConjuntoSistema* criarConjuntoSistema(){
    // Aloca a memória para o cojunto dos TAD's essenciais do sistema
    ConjuntoSistema* ConjuntoSistema = malloc(sizeof(ConjuntoSistema));

    ConjuntoSistema->ArvorePrincipal = criarArvore();
    ConjuntoSistema->FilaPrincipal = criarFila();
    ConjuntoSistema->ListaPrincipal = criarLista();

    if(
    ConjuntoSistema->ArvorePrincipal == NULL ||
    ConjuntoSistema->FilaPrincipal == NULL ||
    ConjuntoSistema->ListaPrincipal == NULL
    ) return NULL;
    
    return ConjuntoSistema;
}

ConjuntoSistema* incializarSistema(){
    printf("Inicializando o sistema...\n");

    ConjuntoSistema* ConjuntoSistema = criarConjuntoSistema();

    if(ConjuntoSistema == NULL){
        printf("ERRO NA INCIALIZAÇÃO. POR FAVOR, REINCIE O SISTEMA");
        return NULL; 
    }

    return ConjuntoSistema;
}