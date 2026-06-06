
#ifndef PILA_H
#define PILA_H
// #define MAX 100 --> Innecesario?
#include <stdio.h>
// #include <stdlib.h> --> Innecesario?
#include <stdbool.h>

// Unidad elemental
struct nodo {
    int info;
    struct nodo *sig;
};

//Un puntero que referencia a un nodo
typedef struct nodo *tipoPila;

void CrearPila(tipoPila *punteroPila);
bool PilaVacia(tipoPila punteroPila);
void CrearNodo(tipoPila *nuevoN);
void Apilar(tipoPila *punteroPila, int x);
void Desapilar(tipoPila *punteroPila, int *x);
void ImprimirPila(tipoPila punteroPila);

#endif
