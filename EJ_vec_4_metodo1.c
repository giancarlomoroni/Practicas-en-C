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
    int x, aux ,vm, encontrado;
    int cant;
    cant = sizeof(vector) / sizeof(int);
    aux = 0;
    
    printf("Ingrese un valor que desee encontrar en el vector\n");
    fflush(stdin);
    scanf("%d",&x);

    while(encontrado == 0 && aux < cant)
    {
        if(vector[aux] >= x)
        {
            encontrado = 1;
        }

        else
        {
            aux++;    
        }
        
    }

    vm =vector[aux-1] - x;

    if(x > vector[aux-1] && x < vector[aux] )
    {
        if(vector[aux] - x < abs(vm) )
        {
            printf("El valor del vector es %d y su posicion es %d \n", vector[aux],aux);
        }

        else
        {
            printf("El valor del vector es %d y su posicion es %d \n", vector[aux-1],aux - 1);
        }
        
    }



return 0;
}