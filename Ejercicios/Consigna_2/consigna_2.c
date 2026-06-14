#include <stdio.h>
#include "pilas.h"

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