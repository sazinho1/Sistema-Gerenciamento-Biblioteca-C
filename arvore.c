#include "arvore.h"
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

//FUNÇÕES PARA CRIAR ARVORE E INSERIR/BUSCAR NA ARVORE

Arvore* criarArvore(){
    Arvore *a = malloc(sizeof(Arvore)); //Faz a alocação de memória e bota o endereço de memória no ponteiro

    if (a == NULL) {
        printf("Erro na alocação de memória.\n");
        return ;
    } //Verifica se não deu erro na alocação

    a -> raiz = NULL; //Começa vazia

    return a; //Retorna o ponteiro
}



void inserirLivroArvore(Arvore* arvore, Livro* livro){
    //Complexidade mínima: O(1). Média: O(log n). Máxima: O(n).

    //Se fosse um programa real, seria legal pôr uma arvore balanceada pra diminuir a complexidade max pra log n, mas aumentaria mt o numero de linhas de codigo.


    // TRECHO PARA A ALOCAÇÃO E DEFINIÇÃO DO NÓ
    NoArvore *no = (NoArvore*) malloc(sizeof(NoArvore)); //Aloca o espaço pro novo nó

    if (no == NULL) {
        printf("Erro na alocação de memória.\n"); //Autoexplicativo
        return ;
    }

    no->livro = livro; //Coloca o livro indicado na assinatura do método como o livro dentro do nó
    no->esquerda = NULL;
    no->direita = NULL; //Como ele é um nó novo, ele não tem filhos (pelo menos não no momento da inserção dele).

    // TRECHO PARA INSERÇÃO NA ÁRVORE

    //Caso a árvore esteja vazia:
    if (arvore->raiz == NULL) {
        arvore->raiz = no;
        return;
    }

    //Caso já haja algum nó:
    NoArvore* atual = arvore->raiz; //Ponteiro para ser deslocado dentro da árvore 

    while (1) {//Faz em loop até achar ou não
        //Complexidade mínima: O(1). Média: O(log n). Máxima: O(n).

        //Código dos livros para comparação
        int codigoInformado = livro->codigo;

        int codigoDoNo = atual->livro->codigo;

        //Comparação com a esquerda
        if (codigoInformado < codigoDoNo) {

            //Caso o espaço esteja livre
            if (atual->esquerda == NULL) {
                atual->esquerda = no;
                return;
            }

            //Continua descendo
            atual = atual->esquerda;
        }

        //Comparação com a direita
        else if (codigoInformado > codigoDoNo) {

            //Caso o espaço esteja livre
            if (atual->direita == NULL) {
                atual->direita = no;
                return;
            }

            //Continua descendo
            atual = atual->direita;
        }

        //Caso o codigo informado no livro seja repetido
        else {
            printf("Codigo ja existente.\n");
            free(no);//Libera o nó
            return;
        }
    }

    return;
}



Livro* buscarLivroArvore(Arvore* arvore, int codigo){
    //Complexidade mínima: O(1). Média: O(log n). Máxima: O(n).


    //Código dos livros para comparação

    NoArvore *NoAtual = arvore->raiz;// Inicializando um nó para comparação para inicializar

    int codigoInformado = codigo;//Autoexplicativo


    //Caso esteja dentro da árvore:
    //(ele faz em loop até achar ou não)
    while (NoAtual != NULL) {

        int codigoNoAtual = NoAtual->livro->codigo; //Para não precisar escrever sempre "NoAtual->livro->codigo"

        //Compara o livro do nó atual
        if(codigoNoAtual == codigoInformado){

            //Retorna o livro achado
            return NoAtual->livro;
        }

        //Conferindo a esquerda
        if (codigoInformado < codigoNoAtual) {

            //Continua descendo
            NoAtual = NoAtual->esquerda;
        }

        //Conferindo a direita
        if (codigoInformado > codigoNoAtual) {

            //Continua descendo
            NoAtual = NoAtual->direita;
        }
        
    }
    
    //Se comparar tudo, chegar ao final e não houver o livro, ele retorna nulo.
    return NULL;
}



//FUNÇÕES PARA LISTAR LIVROS EXISTENTES


//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarEmOrdem(NoArvore* no){
    
    //Se chegou ao final
    if (no == NULL){
        return;
    }
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    // Raiz
    printf("%s / %d\n", no->livro->titulo, no->livro->codigo);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
}

void listarLivrosEmOrdem(Arvore* arvore){
    //Dá o nó inicial e vai printando os outros
    ListarEmOrdem(arvore->raiz);
}



//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarPreOrdem(NoArvore* no){
    
    //Se chegou ao final
    if (no == NULL){
        return;
    }
    
    // Raiz
    printf("%s / %d\n", no->livro->titulo, no->livro->codigo);
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
}

void listarLivrosPreOrdem(Arvore* arvore){
    //Dá o nó inicial e vai printando os outros
    ListarPreOrdem(arvore->raiz);
}



//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarPosOrdem(NoArvore* no){
    
    //Se chegou ao final
    if (no == NULL){
        return;
    }
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
    // Raiz
    printf("%s / %d\n", no->livro->titulo, no->livro->codigo);
    
}

void listarLivrosPosOrdem(Arvore* arvore){
    //Dá o nó inicial e vai printando os outros
    ListarPosOrdem(arvore->raiz);
}


//FUNÇÕES PARA CONTAR LIVROS EXISTENTES E INDENTIFICAR SUA ALTURA DA ARVORE

//Usando uma função auxiliar para ir pegando os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz. Isso é pra manter a assinatura original pedida no arquivo ("contarLivros(Arvore* arvore)").
int contarNaSubArvore(NoArvore* no){
    //Complexidade: O(n) em todos os casos (vai sempre visitar todos os nós pra somar todos e dar a quantidade final)

    // Caso base
    if(no == NULL){
        return 0;
    }

    //Soma, recursivamente, o numero de livros em cada sub arvore, até chegar no final e somar 0, ai sai voltando e somando tudo.
    return 1 + contarLivros(no->esquerda) + contarLivros(no->direita);
}

//Função principal pra "dar o start" na recursividade
int contarLivros(Arvore* arvore){
    contarNaSubArvore(arvore->raiz);
}
    

//Usando uma função auxiliar para ir pegando os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz. Isso é pra manter a assinatura original pedida no arquivo ("contarLivros(Arvore* arvore)").
int calcularAltura(NoArvore* no){

    //Complexidade: O(n) em todos os casos (vai sempre visitar todos os nós pra ver a altura da arvore)

    // Caso base
    if(no == NULL){
        return 0;
    }

    int alturaEsquerda = calcularAltura(no->esquerda);//Recursão na esquerda

    int alturaDireita = calcularAltura(no->direita);//Recursão na direita

    // Retorna a maior + 1 (raiz da sub arvore)
    if(alturaEsquerda > alturaDireita){

        return alturaEsquerda + 1;
    }
    
    return alturaDireita + 1;
}

int calcularAlturaArvore(Arvore* arvore){
    return calcularAltura(arvore->raiz);
}
    
    
    
    