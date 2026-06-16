#ifndef FILA_H
#define FILA_H

// Structs

// Definição do struct Reserva
typedef struct Reserva
{
    char nomeUsuario[100];
    int codigoLivro;
} Reserva;

// Definição do struct NoFila
typedef struct NoFila
{
    Reserva reserva;
    struct NoFila *proximo;
} NoFila;

// Definição do struct Fila
typedef struct Fila
{
    NoFila *inicio;
    NoFila *fim;
    int tamanho; // Registra o tamanho da fila
} Fila;

//--------------------------------------------------------------------------

// Métodos

Fila *criarFila(); // Inicializa uma fila dinâmica vazia e aloca a estrutura de controle.

Reserva *criarReserva(char nome[], int codigo); // Cria uma reserva com base no nome do usuario e no codigo do livro.

void enfileirarReserva(Fila *fila, Reserva reserva); // Insere uma nova reserva no FIM da fila.

Reserva desenfileirarReserva(Fila *fila); // Remove a reserva do INÍCIO da fila e retorna os dados dela.

NoFila *procurarReserva(Fila *fila, int codigo); // Procura se há uma reserva para esse livro específico.

int filaVazia(Fila *fila); // Verifica se a fila está vazia.

void exibirReservas(Fila *fila); // Percorre toda a fila do início ao fim imprimindo os dados na tela.

#endif