#include <stdio.h>
#include <stdlib.h>

/*
Dado el vector guardado en memoria mostrado mas adelante, se desea un programa
que busque el maximo, el minimo y el promedio y los indique en pantalla.
*/

int vector[] = {47, 23, -12, -20, -18, -15, -12, -10, -5, 0, 2, 3, 8, 9, 12, 15, 20, 30, 50, -8, -31, 11, -17};

int main (void)
{
   
    int aux = 0, vmax = 0, vmin = 11, suma = 0;
    float prom;
    int elementos = sizeof(vector) / sizeof(int);

   for(aux = 0; aux < elementos; aux ++)
   {
       if(vector[aux]> vmax)
       {
           vmax = vector[aux];
       }

       if(vector[aux]< vmin)
       {
           vmin = vector[aux];
       }

       suma = suma + vector[aux]; 

   }
    
    prom = (float) suma / elementos;

    printf("El vector maximo es %d\n", vmax);
    printf("El vector minimo es %d\n", vmin);
    printf("El promedio de los vectores es %f\n", prom);

    return 0;
}

