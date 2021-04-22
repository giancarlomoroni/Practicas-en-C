#include <stdio.h>
#include <stdlib.h>

/*
Se dispone del vector indicado mas abajo.
El objetivo de su programa es ordenarlo.
Existen docenas de algoritmos de ordenamiento, cada uno con sus ventajas y desventajas.
No pretendo que apliquen ninguno de estos algoritmos, si no que ustedes desarollen el suyo.
Si de casualidad coincide con alguno que busquen o intentan hacer uno ustedes no hay problema.
Mi objetivo es que aprendan a manejar vectores y si podemos aprender algo mas en el medio mejor.
*/


int vector[] = {32, 10, 45, 20, -8, 12, -20, 30, 17, 6, -37, 0, 11, -15, 9, 2};

int main (void)
{
    int flag = 1;                                   //Flag de ayuda para ver cuando termino el ordenamiento
    int i;                                          //Indice para recorrer el vector
    int aux;                                        //Auxiliar para el swap
    int elementos = sizeof(vector) / sizeof(int);     //Dimension del vector

    printf("Original\n");
    for(i = 0; i < elementos; i++)
    {
        printf("%d\n", vector[i]);
    }


    while (flag == 1)                               //Mantengo corriendo hasta que termine de ordenar
    {
        flag = 0;                                   //Fuezo el flag a 0 para que si no hay cambios salga del loop

        for (i = 0; i < elementos-1; i++)           //Recorro el vector hasta el anteultimo elemento
        {
            if (vector[i] > vector[i+1])            //Si el elemento actual es mayor que el siguiente hago el swap
            {
                aux = vector[i];                    //Sub rutina de swap
                vector[i] = vector[i+1];
                vector[i+1] = aux;
                flag = 1;
            }
        }
    }

    printf("Ordenado\n");
    for(i = 0; i < elementos; i++)
    {
        printf("%d\n", vector[i]);
    }

    return 0;                                       //Fin
}