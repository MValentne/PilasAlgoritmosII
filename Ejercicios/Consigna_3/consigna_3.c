#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

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
ImprimirTESTING(pila1);
printf("Pila 2: ");
ImprimirTESTING(pila2);

printf("ahora realizaremos la copia entre los elementos de la pila 1 y pila 2");
while (!PilaVacia(pila1) && !PilaVacia(pila2)) {
    Desapilar(&pila1, &auxp1);
    Desapilar(&pila2, &auxp2);
    suma = auxp1 + auxp2;
    Apilar(&resultadoSuma, suma);
}
printf("Pila de suma: ");

ImprimirTESTING(resultadoSuma);
}