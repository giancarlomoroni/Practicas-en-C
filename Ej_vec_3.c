#include <stdio.h>
#include <stdlib.h>

/*
Se desea un programa que tome los valores del vector1 y calcule, de acuerdo a la ecuacion indicada mas abajo, los valores.
Esos valores deben almacenarse en el vector 2 en la misma posicion que la del vector 1.
Mas adelante se muestra un ejemplo
V2 = (V1 * V1) - indice          donde el "indice" es la posicion del vector
Ejemplo
V1 = [1, -2, 7, ...]
V2 = [1, 3, 47, ...]
*/

int vector[] = {-2, 3, -10, 24, -8, 7, 9, 300, -244, 11, 25, -8};
int cantidad = sizeof(vector) / sizeof(int);
int vec2[12];
int aux;

int main (void)
{
    for(aux = 0; aux < cantidad; aux ++ )
    {
        vec2[aux] = vector[aux] * vector[aux] - aux;
    }    

    for(aux = 0; aux < cantidad; aux++)
    {
        printf("El valor %d del vector 1 es %d\n ", aux, vector[aux] );
        printf("El valor %d del vector 2 es %d\n\n ", aux, vec2[aux]);
    }
    return 0;
}