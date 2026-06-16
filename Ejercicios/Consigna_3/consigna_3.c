#include <stdio.h>
#include <stdlib.h>
#include "../../TDA_PILA/pila.h"

int main() {
tipoPila pila1, pila2, resultadoSuma;
CrearPila(&pila1);
CrearPila(&pila2);
CrearPila(&resultadoSuma);
int auxp1, auxp2, suma;

printf ("Ingrese 5 elementos para la pila 1: \n");
for (int i = 0; i < 5; i++) {
    int valor;
    scanf("%d", &valor);
    Apilar(&pila1, valor);
}

printf ("Ingrese 5 elementos para la pila 2: \n");
for (int i = 0; i < 5; i++) {
    int valor;
    scanf("%d", &valor);
    Apilar(&pila2, valor);
}
printf("Pila 1: ");

printf("[");
    while (!PilaVacia(pila1)) {
        printf("%d", pila1->info);
        if (pila1->sig != NULL) {
            printf(", ");
        }
        pila1 = pila1->sig;
    }
    printf("]\n");

printf("Pila 2: ");
printf("[");
    while (!PilaVacia(pila2)) {
        printf("%d", pila2->info);
        if (pila2->sig != NULL) {
            printf(", ");
        }
        pila2 = pila2->sig;
    }
    printf("]\n");

printf("ahora realizaremos la copia entre los elementos de la pila 1 y pila 2 ");
while (!PilaVacia(pila1) && !PilaVacia(pila2)) {
    Desapilar(&pila1, &auxp1);
    Desapilar(&pila2, &auxp2);
    suma = auxp1 + auxp2;
    Apilar(&resultadoSuma, suma);
}
printf("Pila de suma: ");

printf ("[");
    while (!PilaVacia(resultadoSuma)) {
        printf("%d", resultadoSuma->info);
        if (resultadoSuma->sig != NULL) {
            printf(", ");
        }
        resultadoSuma = resultadoSuma->sig;
    }
    printf("]\n");
}
