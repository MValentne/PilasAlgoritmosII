/*
 * Desarrollar un modulo para imprimir una pila al reves.
 * Siguiendo definicion de pila, no podemos acceder al contenido sin desapilar.
 */

#include <stdio.h>
#include "../../TDA_PILA/pila.h"

void ImprimirPilaInverso(tipoPila pila);

int main(){
    //=======================Muestra de prueba
    // Se carga una pila de prueba
    tipoPila pilaPrueba;
    CrearPila(&pilaPrueba);
    int valor;
    int elementos = 5; //variable de prueba.
    printf("Por favor ingrese %d elementos a la pila: \n", elementos);
    for(int i = 0; i < elementos; i++){
        scanf("%d", &valor);
        Apilar(&pilaPrueba, valor);
    }
    printf("La pila inversa es: \n");
    ImprimirPilaInverso(pilaPrueba);
    printf("\n");
    return 0;
}

void ImprimirPilaInverso(tipoPila pila){
    //Volcamos la pila en otra pila (inversa)
    tipoPila pilaNueva;
    CrearPila(&pilaNueva);
    int valor;
    while(!PilaVacia(pila)){
        Desapilar(&pila, &valor);
        printf("%d ", valor);
        Apilar(&pilaNueva, valor);
    }
    //Volvemos a volcar la pila para generar la original
    while(!PilaVacia(pilaNueva)){
        Desapilar(&pilaNueva, &valor);
        Apilar(&pila, valor);
    }
    //Pila original recuperada, inverso impreso.
    return;
}
