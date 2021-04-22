#include <stdio.h>
#include <stdlib.h>

/*
Dado el vector guardado en memoria mostrado mas adelante, se desea un programa
que solicite un numero por teclado y busque el mismo en el vector.
El programa debera encontrar el numero ingresado o el numero mas cercano que este
en el vector e informar el valor mas carcano y su indice.
*/

int vector[] = {-20, -18, -15, -12, -10, -5, 0, 2, 3, 8, 9, 12, 15, 20, 30, 50};

int main (void)
{
    int buscado, largo;
    int encontrado = 0;
    int comp; // cantidad de comparaciones
    largo = sizeof(vector) / sizeof(int);
    int aux = 0;
    int mitad; // mitad del vector
    int tope = largo; 
    int i = 0;

    mitad = largo / 2;

    printf("Ingrese un valor que desee encontrar en el vector\n");
    fflush(stdin);
    scanf("%d",&buscado);

    while (encontrado == 0)
    {
        if (buscado == vector[mitad])
        {
            encontrado = 1;
        }

        else
        {
            if(buscado > vector[mitad])
            {
                aux = mitad;
                mitad = tope - (tope - aux)/2;
                comp ++;
            }

            else
            {
                tope = mitad;
                mitad = tope - (tope - aux) /2;
                comp ++;
            }

            if(tope == aux +1 )
            {
                encontrado = 1;
            }
            

        }

    }   

    i =vector[mitad-1] - buscado;
    
    if(buscado > vector[mitad-1] && buscado < vector[mitad] )
    {
        if(vector[mitad] - buscado < abs(i) )
        {
            printf("El valor del vector es %d y su posicion es %d \n", vector[mitad],mitad);
        }

        else
        {
            printf("El valor del vector es %d y su posicion es %d \n", vector[mitad-1], mitad - 1);
        }
        
    }
    printf("Cantidad de comparaciones %d\n",comp);

    return 0;

    }
    