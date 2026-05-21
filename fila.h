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
} Fila;

//--------------------------------------------------------------------------

// Métodos

Fila* criarFila ();

void enfileirarReserva(Fila* fila , Reserva reserva);

Reserva desenfileirarReserva(Fila* fila);

int filaVazia(Fila* fila);

void exibirReservas(Fila* fila);

#endif