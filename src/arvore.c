#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "livro.h"

//FUNÇÕES PARA CRIAR ARVORE E INSERIR/BUSCAR NA ARVORE --------------------------------------------------------------------------

Arvore* criarArvore(){
    // Complexidade: O(1). Aloca (já atribuindo a variável), faz uma verificação para ver se não deu erro e uma atribuição e retorna. Sem recursividade ou loops, portanto, O(1).

    Arvore *a = malloc(sizeof(Arvore)); //Faz a alocação de memória e bota o endereço de memória no ponteiro

    if (a == NULL) {
        printf("Erro na alocação de memória.\n");
        return NULL;
    } //Verifica se não deu erro na alocação

    a -> raiz = NULL; //Começa vazia

    return a; //Retorna o ponteiro
}


NoArvore* inserirLivroAuxiliar(NoArvore *no, Livro* livro){
    // Complexidade Máxima: O(log n), já que tempo de descida é O(log n). Na volta da recursão, o algoritmo verifica o balanceamento e faz, no máximo, duas rotações (que custam O(1)), dando uma complexidade de tempo de O(log n) na volta e uma complexidade total de O(log n).

    // TRECHO PARA ALOCAÇÃO E DEFINIÇÃO DO NÓ
    if (no == NULL) {
        NoArvore *novoNo = (NoArvore*) malloc(sizeof(NoArvore)); // Aloca o espaço pro novo nó
        novoNo->livro = livro; // Coloca o livro indicado na assinatura do método como o livro dentro do nó
        novoNo->esquerda = NULL;
        novoNo->direita = NULL; // Como ele é um nó novo, ele não tem filhos (pelo menos não no momento da inserção dele).
        novoNo->altura = 1; // Nó folha começa com altura 1
        return novoNo;
    }

    // Decide pra qual lado do nó original vai o novo nó com o livro novo
    if (livro->codigo < no->livro->codigo) { // Comparação com a esquerda
        no->esquerda = inserirLivroAuxiliar(no->esquerda, livro);
    } else if (livro->codigo > no->livro->codigo) { // Comparação com a direita
        no->direita = inserirLivroAuxiliar(no->direita, livro);
    } else {
        printf("Codigo ja existente.\n");
        return no; // Não permite chaves duplicadas
    }

    // Atualiza a altura do nó ancestral atual
    no->altura = 1 + max(getAlturaNo(no->esquerda), getAlturaNo(no->direita));

    // Obtém o fator de balanceamento para checar se desbalanceou
    int balanceamento = getFatorDeBalanceamento(no);

    // CASOS DE DESBALANCEAMENTO:
    // Esquerda-Esquerda
    if (balanceamento > 1 && livro->codigo < no->esquerda->livro->codigo)
        return rotacaoPraDireita(no);

    // Direita-Direita
    if (balanceamento < -1 && livro->codigo > no->direita->livro->codigo)
        return rotacaoPraEsquerda(no);

    // Esquerda-Direita
    if (balanceamento > 1 && livro->codigo > no->esquerda->livro->codigo) {
        no->esquerda = rotacaoPraEsquerda(no->esquerda);
        return rotacaoPraDireita(no);
    }

    // Direita-Esquerda
    if (balanceamento < -1 && livro->codigo < no->direita->livro->codigo) {
        no->direita = rotacaoPraDireita(no->direita);
        return rotacaoPraEsquerda(no);
    }

    // Retorna o nó (inalterado se já tivesse balanceado)
    return no;
}


void inserirLivroArvore(Arvore* arvore, Livro* livro){
    //Complexidade mínima: O(1). Média: O(log n). Máxima: O(logn).

    // Chama recursivamente a função de inserir auxiliar até chegar num nó folha para, então, inserir o novo nó
    if (arvore != NULL) {
        arvore->raiz = inserirLivroAuxiliar(arvore->raiz, livro);
    }

}



Livro* buscarLivroArvore(Arvore* arvore, int codigo){
    //Complexidade máxima: O(log n). A busca é igual a de uma ABB comum, apesar de ter uma melhora no desempenho, dado que a AVL garante a árvore está balanceada, mantendo constante a complexidade O(log n) mesmo no pior caso.


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


NoArvore* acharMenorNo(NoArvore* no){
    //Função auxiliar pra achar o menor nó a partir de um específico (que pode ser a raiz da árvore ou não)
    // Complexidade: O(n), já que, como ele percorre só andando para a esquerda, é como se ele estivesse
    // fazendo uma busca numa lista encadeada, a qual tem complexidade O(n).

    // Coloca o nó auxiliar (atual) como sendo o primeiro
    NoArvore* atual = no;

    // Enquanto o nó auxiliar não é o último, passa 1 nó pra frente (atual vira o nó da sua esquerda) 
    // e faz a verificação denovo até chegar no último, onde retorna o atual
    while(atual->esquerda != NULL){
        atual = atual->esquerda;
    }
    return atual;
}

NoArvore* removerLivroAuxiliar(NoArvore* raiz, int codigo) {
    // Função recursiva para remover e balancear
    // Caso a árvore esteja vazia
    if (raiz == NULL)
        return raiz;

    // Desce na árvore pra achar o nó a ser removido
    if (codigo < raiz->livro->codigo)
        raiz->esquerda = removerLivroAuxiliar(raiz->esquerda, codigo);
    else if (codigo > raiz->livro->codigo)
        raiz->direita = removerLivroAuxiliar(raiz->direita, codigo);
    
    // Quando acha o nó, cai nesse else e continua
    else {
        // Caso o nó tenha apenas um filho ou nenhum filho
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {

            NoArvore* aux = raiz->esquerda ? raiz->esquerda : raiz->direita; // Pega o nó q não é NULL

            // Sem filhos
            if (aux == NULL) {
                aux = raiz;
                raiz = NULL;
            }

            else { // Caso tenha um filho, copia o conteúdo do filho para o nó atual
                *raiz = *aux; 
            }

            free(aux); // Libera a memória do nó antigo
        }

        // Caso ele seja um nó com dois filhos
        else {

            // Pega o sucessor (menor nó da subárvore direita)
            NoArvore* aux = acharMenorNo(raiz->direita);

            // Copia os dados do sucessor para o nó atual
            raiz->livro = aux->livro;

            // Deleta o sucessor lá de baixo
            raiz->direita = removerLivroAuxiliar(raiz->direita, aux->livro->codigo);
        }
    }

    // Se a árvore só tinha um nó, então retorna nulo
    if (raiz == NULL)
        return raiz;

    // Atualiza a altura do nó atual
    raiz->altura = 1 + max(getAlturaNo(raiz->esquerda), getAlturaNo(raiz->direita));

    // Pega o fator de balanceamento
    // Lembrando que o balanceamento é (altura nó mais embaixo da esquerda) - (altura nó mais embaixo da direita)
    int balanceamento = getFatorDeBalanceamento(raiz);


    // Balanceia, fazendo a rotação adequada para cada caso:
    
    // Caso Esquerda-Esquerda
    if (balanceamento > 1 && getFatorDeBalanceamento(raiz->esquerda) >= 0)
        return rotacaoPraDireita(raiz);
        
    // Caso Direita-Direita
    if (balanceamento < -1 && getFatorDeBalanceamento(raiz->direita) <= 0)
    return rotacaoPraEsquerda(raiz);
        
    // Caso Esquerda-Direita
    if (balanceamento > 1 && getFatorDeBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoPraEsquerda(raiz->esquerda);
        return rotacaoPraDireita(raiz);
    }
        
    // Caso Direita-Esquerda
    if (balanceamento < -1 && getFatorDeBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoPraDireita(raiz->direita);
        return rotacaoPraEsquerda(raiz);
    }

    return raiz;
}

// A função principal que chama a recursão
void removerLivroArvore(Arvore* arvore, int codigo) {
    if (arvore != NULL && arvore->raiz != NULL) {
        arvore->raiz = removerLivroAuxiliar(arvore->raiz, codigo);
    } else {
        printf("A arvore esta vazia ou nao foi inicializada.\n");
    }
}

// FUNÇÕES PARA LISTAR LIVROS EXISTENTES --------------------------------------------------------------------------


//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarEmOrdem(NoArvore* no){
    // Complexidade: O(n), já que vai percorrer todos os nós, imprimindo-os um a um, fazendo, portanto, n operações de impressão. 

    // Detalhe: uma vantagem da AVL aqui é que a complexidade de espaço é O(log n), já que a árvore está balanceada, e, portanto, ela tem o consumo de memória na recursão como sendo apenas O(log n) no pior caso.

    // Imprimindo da seguinte maneira:  esquerda -> raiz -> direita

    //Se chegou ao final
    if (no == NULL){
        return;
    }
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    // Raiz
    printf("\n%s / %d\n", no->livro->titulo, no->livro->codigo);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
}

void listarLivrosEmOrdem(Arvore* arvore){
    // Complexidade: O(1). Essa função apenas chama a outra para começar a recursão, portanto, O(1).

    //Dá o nó inicial e vai printando os outros
    printf("\n----------------------------------------\n");
    ListarEmOrdem(arvore->raiz);
    printf("\n----------------------------------------\n");
}



//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarPreOrdem(NoArvore* no){
    // Complexidade: O(n), já que vai percorrer todos os nós, imprimindo-os um a um, fazendo, portanto, n operações de impressão.

    //Se chegou ao final
    if (no == NULL){
        return;
    }

    // Imprimindo da seguinte maneira: raiz -> esquerda -> direita

    // Raiz
    printf("\n%s / %d\n", no->livro->titulo, no->livro->codigo);
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
}

void listarLivrosPreOrdem(Arvore* arvore){
    // Complexidade: O(1). Essa função apenas chama a outra para começar a recursão, portanto, O(1).

    //Dá o nó inicial e vai printando os outros
    printf("\n----------------------------------------\n");
    ListarPreOrdem(arvore->raiz);
    printf("\n----------------------------------------\n");
}



//Usando uma função auxiliar para imprimir os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz.
void ListarPosOrdem(NoArvore* no){
    // Complexidade: O(n), já que vai percorrer todos os nós, imprimindo-os um a um, fazendo, portanto, n operações de impressão.
    
    // Imprimindo da seguinte maneira:  esquerda -> direita -> raiz

    //Se chegou ao final
    if (no == NULL){
        return;
    }
    
    //Recursão a esquerda
    ListarEmOrdem(no->esquerda);
    
    //Recursão a direita
    ListarEmOrdem(no->direita);
    
    // Raiz
    printf("\n%s / %d\n", no->livro->titulo, no->livro->codigo);
    
}

void listarLivrosPosOrdem(Arvore* arvore){
    // Complexidade: O(1). Essa função apenas chama a outra para começar a recursão, portanto, O(1).

    //Dá o nó inicial e vai printando os outros
    printf("\n----------------------------------------\n");
    ListarPosOrdem(arvore->raiz);
    printf("\n----------------------------------------\n");
}


//FUNÇÕES PARA CONTAR LIVROS EXISTENTES E INDENTIFICAR SUA ALTURA DA ARVORE -------------------------------------------------------------------


//Usando uma função auxiliar para ir pegando os Nós, e não a Arvore, já que a árvore inteira é só um ponteiro para a raiz. Isso é pra manter a assinatura original pedida no arquivo ("contarLivros(Arvore* arvore)").
int contarNaSubArvore(NoArvore* no){
    //Complexidade: O(n) em todos os casos (vai sempre visitar todos os nós pra somar todos e dar a quantidade final)

    // Caso base
    if(no == NULL){
        return 0;
    }

    //Soma, recursivamente, o numero de livros em cada sub arvore, até chegar no final e somar 0, ai sai voltando e somando tudo.
    return 1 + contarNaSubArvore(no->esquerda) + contarNaSubArvore(no->direita);
}

//Função principal pra "dar o start" na recursividade
int contarLivros(Arvore* arvore){
    return contarNaSubArvore(arvore->raiz);
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

// FUNÇÕES PARA O BALANCEAMENTO DA ÁRVORE --------------------------------------------------------------------------

int getAlturaNo(NoArvore *NoArvore){
    //Complexidade: O(1), já que faz uma verificação e retorna um valor simples, sem chamadas recursivas ou loops, o que lhe garante uma complexidade constante

    if(NoArvore == NULL) return -1; // "-1" é pra dizer que ele não existe, já que, caso ele estivesse na raiz, aí seria 0.

    return NoArvore -> altura;
}

int getFatorDeBalanceamento(NoArvore *NoArvore){
    //Complexidade: O(1), já que faz uma verificação, uma operação de subtração e a chamada de duas funções não recursivas, o que lhe garante uma complexidade constante

    if(NoArvore == NULL) return 0; // "0" porque, caso a árvore esteja vazia, ela não está desbalanceada para nenhum dos lados.
    
    return (getAlturaNo(NoArvore->esquerda) - getAlturaNo(NoArvore->direita));
}

int max(int a, int b){
    //Complexidade: O(1), já que somente realiza uma comparação e retorna
    
    return (a>b) ? a : b; // "O a é maior que o b ? se sim, retorne a, senão, retorne b."
}

NoArvore* rotacaoPraDireita(NoArvore *y){
    //Complexidade: O(1), já que somente realiza atribuições simples e chamadas de funções não recursivas, garantindo uma complexidade constante

    NoArvore* x = y->esquerda;
    NoArvore* T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;
    // Coloca o 'x' como o nó raiz da sub árvore, a qual, anteriormente o 'y' era a raiz

    // Atualiza as alturas
    y->altura = (max(getAlturaNo(y->esquerda), getAlturaNo(y->direita)) + 1);
    x->altura = (max(getAlturaNo(x->esquerda), getAlturaNo(x->direita)) + 1);

    return x;
}

NoArvore* rotacaoPraEsquerda(NoArvore *x){
    //Complexidade: O(1), já que somente realiza atribuições simples e chamadas de funções não recursivas, garantindo uma complexidade constante

    NoArvore* y = x->direita;
    NoArvore* T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;
    // Coloca o 'y' como o nó raiz da sub árvore, a qual, anteriormente o 'x' era a raiz

    // Atualiza as novas alturas
    x->altura = (max(getAlturaNo(x->esquerda), getAlturaNo(x->direita)) + 1);
    y->altura = (max(getAlturaNo(y->esquerda), getAlturaNo(y->direita)) + 1);

    return y;
}
    
    
    