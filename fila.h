#ifndef FILA_H
#define FILA_H

// Structs

// Definição do struct Reserva
typedef struct Reserva {
    char nomeUsuario [100];
    int codigoLivro;
} Reserva;

// Definição do struct NoFila
typedef struct NoFila {
    Reserva reserva;
    struct NoFila* proximo;
} NoFila;

// Definição do struct Fila
typedef struct Fila {
    NoFila* inicio;
    NoFila* fim;
    int tamanho; // Registra o tamanho da fila
} Fila;

//--------------------------------------------------------------------------

// Métodos

Fila* criarFila ();

Reserva* criarReserva(char nome[], int codigo); // Cria uma reserva com base no nome do usuario e no codigo do livro 

void enfileirarReserva(Fila* fila , Reserva reserva);

Reserva desenfileirarReserva(Fila* fila);

NoFila* procurarReserva(Fila* fila, int codigo); // Procura se há uma reserva para esse livro específico

int filaVazia(Fila* fila);

void exibirReservas(Fila* fila);

#endif