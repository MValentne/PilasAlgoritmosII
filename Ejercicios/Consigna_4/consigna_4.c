#include <stdio.h>
#include "../../TDA_PILA/pila.h"

void PilaPar(tipoPila *Pila1, tipoPila *PilaPares)
{
    while(!PilaVacia(*Pila1))
    {
        int numero;
        Desapilar(Pila1, &numero);
        if (numero % 2 == 0)
        {
            Apilar(PilaPares, numero);
        }
    }
}

int main ()
{
    tipoPila Pila1, PilaPares;

    CrearPila(&Pila1);
    CrearPila(&PilaPares);

    printf("Ingrese los numeros a la pila 1");
    for (int i = 0; i < 5; i++)
    {
        int numero;
        printf("\nNumero %d: ", i + 1);
        scanf("%d", &numero);
        Apilar(&Pila1, numero);
    }

    PilaPar(&Pila1, &PilaPares);
    printf("Pila Pares: ");

printf("[");
    while (!PilaVacia(PilaPares)) {
        printf("%d", PilaPares->info);
        if (PilaPares->sig != NULL) {
            printf(", ");
        }
        PilaPares = PilaPares->sig;
    }
    printf("]\n");
}