#include <stdio.h>
#include "pilas.h"

void CopiarPila(tipoPila *pilaOrigen, tipoPila *pilaDestino);
int main() {
tipoPila original, copiaDestino;
CrearPila(&original);
CrearPila(&copiaDestino);
// Cargamos la pila original con 1 al fondo, 5 en el tope
Apilar(&original, 1);
Apilar(&original, 2);
Apilar(&original, 3);


printf("Original antes de copiar: ");
ImprimirTESTING(original);

CopiarPila(&original, &copiaDestino);

printf("Original despues de copiar: ");
ImprimirTESTING(original);
 printf("Copia: ");
ImprimirTESTING(copiaDestino);
}

void CopiarPila(tipoPila *pilaOrigen, tipoPila *pilaDestino) {
    CrearPila(pilaDestino); // Aseguramos que la pila destino esté vacía
    tipoPila pilaIntermedia;
    CrearPila(&pilaIntermedia); // Pila temporal para almacenar los elementos en orden inverso
    int valor;
    while (!PilaVacia(*pilaOrigen)) {
        Desapilar(pilaOrigen, &valor); // Desapilamos el nodo actual para obtener su valor
        Apilar(&pilaIntermedia, valor); // Apilamos el valor en la pila intermedia
    }
    while (!PilaVacia(pilaIntermedia)) {
        Desapilar(&pilaIntermedia, &valor); // Desapilamos el nodo actual para obtener su valor
        Apilar(pilaDestino, valor); // Apilamos el valor en la pila destino
        Apilar(pilaOrigen, valor); // Volvemos a apilar el valor en la pila original para restaurarla
    }
}