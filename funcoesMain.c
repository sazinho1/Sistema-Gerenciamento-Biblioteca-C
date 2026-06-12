#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "lista.h"
#include "arvore.h"
#include "funcoesMain.h"

void exibirMenu()
{
    printf("\n----------SISTEMA DE GERENCIAMENTO DA BIBLIOTECA ED----------\n\n");

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
        "0. Sair\n\n");

    // Não consegui colocar tudo em um unico printf porque o compilador tava bugando
}

// Função para escolher a opção a ser realizada no menu principal
void escolherOpcaoMenu(ConjuntoSistema *ConjuntoSistema, int opcaoEscolhida)
{
    // Variáveis necessárias para algumas opções do menu:
    int codigoLivroEscolhido; // Opção 2

    switch (opcaoEscolhida)
    {
    case 1: // Cadastrar Novo Livro

        cadastrarLivro(ConjuntoSistema->ArvorePrincipal);
        break;

    case 2: // Buscar livro por código

        printf("Digite o codigo do livro: \n");
        scanf("%d\n", &codigoLivroEscolhido);
        Livro *livro = buscarLivroArvore(ConjuntoSistema->ArvorePrincipal, codigoLivroEscolhido); // Faz a busca do livro na árvore
        exibirLivro(livro);                                                                       // Mosta o livro
        break;

    case 3: // Listar livros em ordem crescente de codigo

        listarLivrosEmOrdem(ConjuntoSistema->ArvorePrincipal);
        break;

    case 4: // Listar livros em pre ordem

        listarLivrosPosOrdem(ConjuntoSistema->ArvorePrincipal);
        break;

    case 5: // Listar livros em pós ordem

        listarLivrosPreOrdem(ConjuntoSistema->ArvorePrincipal);
        break;

    case 6: {// Realizar empréstimo de livro

        // Variável necessária para pegar o nome do user
        char nomeUsuario[100];

        // Pega o codigo do livro a ser emprestado
        printf("Digite o codigo do livro: \n");
        scanf("%d\n", &codigoLivroEscolhido);

        // Pega o nome do usuario que quer pegar o livro
        printf("Digite o nome do usuario a alugar o livro: \n");
        scanf("%s\n",&nomeUsuario);

        // Chama a função que realiza esse empréstimo
        realizarEmprestimo(ConjuntoSistema, codigoLivroEscolhido, nomeUsuario);
        break;
    }

    case 7: // Devolver livro

        // Pega o codigo do livro a ser emprestado
        printf("Digite o codigo do livro: \n");
        scanf("%d\n", &codigoLivroEscolhido);

        // Chama a função que realiza essa devolução
        realizarDevolucao(ConjuntoSistema, codigoLivroEscolhido);

        break;

    case 8: // Exibir fila de reservas

        // Quebra a linha e printa as reservas
        printf("\n");
        exibirReservas(ConjuntoSistema->FilaPrincipal);
        break;

    case 9: // Exibir histórico de empréstimos

        // Quebra a linha e printa os empréstimos
        printf("\n");
        listarEmprestimos(ConjuntoSistema->ListaPrincipal);
        break;

    case 10: // Exibir quantidade de livros cadastrados

        printf("A quantidade de livros cadastrados (ou nos da arvore) eh %d", contarLivros(ConjuntoSistema->ArvorePrincipal));
        break;

    case 11: // Exibir altura da árvore

        printf("A altura da arvore eh %d", calcularAlturaArvore(ConjuntoSistema->ArvorePrincipal));
        break;

    case 0: // Sair

        encerrarSistema(ConjuntoSistema);
        break;

    default:
        break;
    }
}

int cadastrarLivro(Arvore *ArvorePrincipal)
{
    // Dados do livro a ser inserido
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidadeTotal;

    // Pega cada dado do livro
    printf("Digite o codigo do livro a ser inserido: \n");
    scanf("%d", &codigo);

    printf("Digite o titulo do livro a ser inserido: \n");
    scanf("%s", &titulo);
    scanf("");

    printf("Digite o autor/a autora do livro a ser inserido: \n");
    scanf("%s", &autor);
    scanf("");

    printf("Digite o ano de publicacao do livro a ser inserido: \n");
    scanf("%d", &ano);

    printf("Digite a quantidade de exemplares do livro a ser inserido: \n");
    scanf("%d", &quantidadeTotal);

    // Cria o novo livro
    Livro *NovoLivro = criarLivro(codigo, titulo, autor, ano, quantidadeTotal);

    // Caso dê erro na criação do livro
    if (NovoLivro == NULL)
    {
        printf("Erro na criação do livro.");
        return 0;
    }

    // Adciona o livro a arvore principal de livro
    inserirLivroArvore(ArvorePrincipal, NovoLivro);

    return 1;
}

void realizarEmprestimo(ConjuntoSistema *ConjuntoSistema, int codigo, char nome[])
{
    // Faz o empréstimo do livro, retornando um aviso de erro, no caso da falha e uma confirmação de sucesso, caso ocorra como esperado

    // Coloca um ponteiro pra ser o livro buscado
    Livro *livro = buscarLivroArvore(ConjuntoSistema->ArvorePrincipal, codigo);

    // Verifica se o livro existe
    if (livro != NULL)
    {

        // Caso não tenha exemplares desse livro disponiveis, abre a opção da reserva
        if (livro->quantidadeDisponivel == 0)
        {
            int escolha;

            printf("Não existe nenhum exemplar desse livro disponível agora. Gostaria de entrar na fila de reserva para esse livro?\n1 - Sim\n0 - Não\n");

            scanf("%d\n", &escolha);

            // Caso não queira a reserva, retorna
            if (escolha == 0)
                return;

            else
            {
                // Cria a reserva
                Reserva *reserva = criarReserva(nome, codigo);

                // Caso dê erro na criação da reserva
                if (reserva == NULL)
                    return;

                // Enfileira a reserva
                enfileirarReserva(ConjuntoSistema->FilaPrincipal, *reserva);
            }
        }

        // Caso o livro exista, remove uma unidade dele na árvore
        removerLivroArvore(ConjuntoSistema->ArvorePrincipal, codigo);

        // Cria o empréstimo e pega o ponteiro para ele na variavel "Emprestimo"
        Emprestimo *emprestimo = criarEmprestimo(nome, codigo, livro->titulo);

        // Insere o emprestimo na lista de emprestimos
        inserirEmprestimo(ConjuntoSistema->ListaPrincipal, *emprestimo);

        // Retorna a mensagem para informar o sucesso
        printf("\nEmpréstimo realizado com sucesso!\n");
    }

    // Caso o livro não exista, retorna o aviso do erro
    printf("\nERRO: LIVRO NÃO EXISTE\n");
    return;
}

void realizarDevolucao(ConjuntoSistema* ConjuntoSistema, int codigo)
{
    // Faz a devolução do livro, retornando um aviso de erro, no caso do livro não existir e uma confirmação de sucesso, caso ocorra como esperado

    // Coloca um ponteiro pra ser o livro buscado
    Livro *livro = buscarLivroArvore(ConjuntoSistema->ArvorePrincipal, codigo);

     // Verifica se o livro existe
    if (livro != NULL)
    {
        livro->quantidadeDisponivel++; // Aumenta em 1 a quantidade disponível desse livro
    
        // Pega o nó da reserva que tem para o livro devolvido, caso exista
        NoFila* reservaPossivel = procurarReserva(ConjuntoSistema->FilaPrincipal, codigo);

        // Caso tenha alguma reserva para um exemplar do livro requisitado
        if(reservaPossivel != NULL){

            // Printa a lista de reservas
            exibirReservas(ConjuntoSistema->FilaPrincipal);

            // Avisa ao usuário que havia alguém esperando um livro desse
            printf("\nTem um usuário na fila esperando para receber esse livro! Obrigado por devolvê-lo.\n");

            // Fecha a reserva e abre um empréstimo para quem estava esperando
            desenfileirarReserva(ConjuntoSistema->FilaPrincipal);
            criarEmprestimo(reservaPossivel->reserva.nomeUsuario, codigo, livro->titulo);

        }    
        
        // Caso o livro seja devolvido e não tenha nenhum usuário esperando por um exemplar
        printf("\nObrigado pela devolução! Volte sempre.\n");

    }

    printf("\nERRO: LIVRO NÃO EXISTE\n");
    return;

}

ConjuntoSistema *criarConjuntoSistema()
{
    // Aloca a memória para o cojunto dos TAD's essenciais do sistema
    ConjuntoSistema *ConjuntoSistema = malloc(sizeof(ConjuntoSistema));

    ConjuntoSistema->ArvorePrincipal = criarArvore();
    ConjuntoSistema->FilaPrincipal = criarFila();
    ConjuntoSistema->ListaPrincipal = criarLista();

    if (
        ConjuntoSistema->ArvorePrincipal == NULL ||
        ConjuntoSistema->FilaPrincipal == NULL ||
        ConjuntoSistema->ListaPrincipal == NULL)
        return NULL;

    return ConjuntoSistema;
}

ConjuntoSistema *inicializarSistema()
{
    printf("Inicializando o sistema...\n");

    ConjuntoSistema *ConjuntoSistema = criarConjuntoSistema();

    if (ConjuntoSistema == NULL)
    {
        printf("ERRO NA INCIALIZAÇÃO. POR FAVOR, REINCIE O SISTEMA");
        return NULL;
    }

    return ConjuntoSistema;
}

// FUNÇÕES PARA LIBERAR A MEMÓRIA DO SISTEMA AO SAIR --------------------------------------------------------------------------

// Função recursiva para limpar os nós de baixo para cima
void liberarNosArvore(NoArvore *noArvore)
{
    if (noArvore != NULL)
    {
        liberarNosArvore(noArvore->esquerda); // Vai até o fundo na esquerda
        liberarNosArvore(noArvore->direita);  // Vai até o fundo na direita

        free(noArvore->livro); // Libera o livro que foi alocado no criarLivro()
        free(noArvore);        // Libera o próprio nó
    }
}

// Função principal que limpa a árvore inteira
void limparArvore(Arvore *arvore)
{
    if (arvore != NULL)
    {
        liberarNosArvore(arvore->raiz); // Limpa todos os nós/livros até acabar (arvore ficar NULL)
        free(arvore);                   // Libera a struct árvore que havia sido instanciada
    }
}

// Função pra limpar a lista
void limparLista(Lista *lista)
{
    if (lista != NULL)
    {
        // Enquanto não acabar, vai repitindo o free dos nós da lista
        NoLista *atual = lista->inicio;

        while (atual != NULL)
        {
            NoLista *temp = atual;  // Guarda o nó atual
            atual = atual->proximo; // Pula pro próximo
            free(temp);             // Libera o nó que ficou para trás
        }

        free(lista); // Libera a struct lista que havia sido instanciada
    }
}

// Função pra limpar a fila
void limparFila(Fila *fila)
{
    if (fila != NULL)
    {
        // Enquanto não acabar, vai repitindo o free dos nós da fila
        NoFila *atual = fila->inicio;

        while (atual != NULL)
        {
            NoFila *temp = atual;
            atual = atual->proximo;
            free(temp);
        }

        free(fila); // Libera a struct fila que havia sido instanciada
    }
}

void encerrarSistema(ConjuntoSistema *ConjuntoSistema)
{

    // Libera a memória alocada na execução com as funções auxiliares, caso não tenha dado erro na alocação do "ConjuntoSistema" na inicialização
    if (ConjuntoSistema != NULL)
    {
        limparArvore(ConjuntoSistema->ArvorePrincipal);
        limparFila(ConjuntoSistema->FilaPrincipal);
        limparLista(ConjuntoSistema->ListaPrincipal);

        free(ConjuntoSistema);
    }
}