#include "lista.h"
#include <complex.h>
#include <stdio.h>

//Lista vacia
void CrearLista(tipoLista *punteroLista){
    *punteroLista = NULL;
}

bool EsVacia(tipoLista L){
    if (L == NULL) return (true);
    else return (false);
}

void CrearNodo(tipoLista *nuevoN){
    *nuevoN = malloc(sizeof(struct nodo)); //--> Asigna memoria a un nuevo nodo
    if (EsVacia(*nuevoN)) { // --> Caso en el que surge error y no se aloca memoria adecuadamente.
        printf("Error: no se pudo asignar memoria\n");
        exit(1);
    }
}

void InsertarPrincipio(tipoLista *L, int x) {
    tipoLista nuevoNodo; // --> Apunta a basura
    CrearNodo(&nuevoNodo); // --> Apunta al nuevo nodo
    nuevoNodo->info = x;
    nuevoNodo->sig = *L;
    *L = nuevoNodo;
}

void InsertarFinal(tipoLista *L, int x) {
    tipoLista nuevoNodo;
    tipoLista PI;
    CrearNodo(&nuevoNodo);
    nuevoNodo->info = x;
    nuevoNodo->sig = NULL;

    if (EsVacia(*L)) {
        *L = nuevoNodo;
    } else {
        PI = *L;
        while (!EsVacia((*L)->sig)) {
            *L = (*L)->sig;
        }
        (*L)->sig = nuevoNodo;
        *L = PI;
    }
}

void Borrar(tipoLista *L, int x){
    tipoLista PI, PA = NULL;
    PI = *L;

    while ((!EsVacia(*L)) && ((*L)->info != x)){
        PA = *L;
        *L = (*L)->sig;
    }
    if (!EsVacia(*L)){
        if (!EsVacia(PA)){
            PA->sig = (*L)->sig;
        }
        else{
            PI = PI->sig;
        }
        free(*L);
    }
    *L = PI;
}

void Imprimir(tipoLista L) {
    printf("[");
    while (!EsVacia(L)) {
        printf("%d", L->info);
        if (L->sig != NULL) {
            printf(", ");
        }
        L = L->sig;
    }
    printf("]\n");
}

void Sacar(tipoLista *L, int *x){
    if(*L == NULL){
        exit(1);
    }
    tipoLista primerNodo = *L;
    *L = primerNodo->sig;
    *x = primerNodo->info;
    free(primerNodo);
}

bool ExisteElemento(tipoLista L, int x){
    while (!EsVacia(L)) {
        if (L->info == x) {
            return true;
        }else {
        L = L->sig;
        }
    }
    return false;
}

void montoPrestamo (tipoLista *MontoPrestamos, tipoLista *PrestamosActualizadosOpción1, tipoLista *PrestamosActualizadosOpción2) {
    CrearLista(PrestamosActualizadosOpción1);
    CrearLista(PrestamosActualizadosOpción2);
    tipoLista clon;
    CrearLista(&clon);

    int descuento = 0;
    int auxiliar = 0;
    int auxiliar2 = 0;

    while (!EsVacia(*MontoPrestamos)) {
        Sacar(MontoPrestamos, &auxiliar);
        InsertarFinal(&clon, auxiliar);
        auxiliar2 = auxiliar;
        if (auxiliar < 50000) {
            descuento = (auxiliar * 15) / 100;
            auxiliar = auxiliar - descuento;
            InsertarFinal(PrestamosActualizadosOpción1, auxiliar);
        }
        if (auxiliar2 >= 5000) {
            descuento = (auxiliar2 * 5) / 100;
            auxiliar2 = auxiliar2 - descuento;
            InsertarFinal(PrestamosActualizadosOpción2, auxiliar2);
        }

    }
    *MontoPrestamos = clon;
}
