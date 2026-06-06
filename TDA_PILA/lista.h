
#ifndef LISTA_H
#define LISTA_H
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Unidad elemental
struct nodo {
    int info;
    struct nodo *sig;
};

//Un puntero que referencia a un nodo
typedef struct nodo *tipoLista;

void CrearLista(tipoLista *punteroLista );

bool EsVacia(tipoLista L);

void CrearNodo(tipoLista *nuevoN);

void InsertarPrincipio(tipoLista *L, int x);

void InsertarFinal(tipoLista *L, int x);

void Borrar(tipoLista *L, int x);

void Imprimir(tipoLista L);

//Saca un valor de la lista a una variable, itera al siguiente elemento.
void Sacar(tipoLista *L, int *x);

//Busqueda lineal
bool ExisteElemento(tipoLista L, int x);

// void MontoPrestamo(tipoLista *MontoPrestamos, tipoLista *PrestamosActualizadosOpción1, tipoLista *PrestamosActualizadosOpción2);

#endif
