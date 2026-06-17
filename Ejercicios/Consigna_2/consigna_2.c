#include <stdio.h>
#include "../../TDA_PILA/pila.h"

void CopiarPila(tipoPila *pilaOriginal, tipoPila *pilaCopia);

int main() {
    tipoPila original, copiaDestino;
    CrearPila(&original);
    CrearPila(&copiaDestino);

    Apilar(&original, 1);
    Apilar(&original, 2);
    Apilar(&original, 3);

    tipoPila aux;

    printf("Original antes de copiar: [");
    aux = original;
    while (!PilaVacia(aux)) {
        printf("%d", aux->info);
        if (aux->sig != NULL) printf(", ");
        aux = aux->sig;
    }
    printf("]\n");

    CopiarPila(&original, &copiaDestino);

    printf("Original despues de copiar: [");
    aux = original;
    while (!PilaVacia(aux)) {
        printf("%d", aux->info);
        if (aux->sig != NULL) printf(", ");
        aux = aux->sig;
    }
    printf("]\n");

    printf("Copia: [");
    aux = copiaDestino;
    while (!PilaVacia(aux)) {
        printf("%d", aux->info);
        if (aux->sig != NULL) printf(", ");
        aux = aux->sig;
    }
    printf("]\n");
}

void CopiarPila(tipoPila *pilaOriginal, tipoPila *pilaCopia){
    tipoPila aux;
    CrearPila(&aux);
    int valor;
    // Vuelco pila en una auxiliar
    while(!PilaVacia(*pilaOriginal)){
        Desapilar(pilaOriginal, &valor);
        Apilar(&aux, valor);
    }

    // Vuelvo a volcar para recuperar la original y generar el clon.
    while(!PilaVacia(aux)){
        Desapilar(&aux, &valor);
        Apilar(pilaCopia, valor);
        Apilar(pilaOriginal, valor);
    }
}
