#include "pila.h"
//#include <complex.h> --> Innecesario?
#include <stdio.h>
#include <stdlib.h> //Usamos malloc

//Pila vacia
void CrearPila(tipoPila *punteroPila){
    *punteroPila = NULL;
}

bool PilaVacia(tipoPila punteroPila){
    if (punteroPila == NULL) return (true);
    else return (false);
}

//Accion fundamental para Apilar, podriamos integrarlo y deshacernos de este modulo
void CrearNodo(tipoPila *nuevoN){
    *nuevoN = malloc(sizeof(struct nodo)); //--> Asigna memoria a un nuevo nodo
    if (PilaVacia(*nuevoN)) { // --> Caso en el que surge error y no se aloca memoria adecuadamente.
        printf("Error: no se pudo asignar memoria\n");
        exit(1);
    }
}

void Apilar(tipoPila *punteroPila, int x) {
    tipoPila nuevoNodo; // --> Apunta a basura
    CrearNodo(&nuevoNodo); // --> Apunta al nuevo nodo
    nuevoNodo->info = x;
    nuevoNodo->sig = *punteroPila;
    *punteroPila = nuevoNodo;
}

//============ TO-DO ===============
// Arreglarlo para que imprima de final a principio (fondo a tope de pila)
void ImprimirTESTING(tipoPila punteroPila) {
    printf("[");
    while (!PilaVacia(punteroPila)) {
        printf("%d", punteroPila->info);
        if (punteroPila->sig != NULL) {
            printf(", ");
        }
        punteroPila = punteroPila->sig;
    }
    printf("]\n");
}

void Desapilar(tipoPila *punteroPila, int *x){
    if(*punteroPila == NULL){
        exit(1);
    }
    tipoPila primerNodo = *punteroPila;
    *punteroPila = primerNodo->sig;
    *x = primerNodo->info;
    free(primerNodo);
}
