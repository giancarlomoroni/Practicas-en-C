#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#include "D:\SRC\ej26.h"


int main(void)
{
    ptr = &car[0];
    int vehiculo = 1;

    while (vehiculo != 0)
    {
        vehiculo = orden_vehiculo();

        if (vehiculo == 0)
        {
            vehiculo = 0;
        }

        else 
        {
            pruebas(vehiculo);
            files(vehiculo);
            printf("Vehiculo %d luces %d frenos %d gases %d\n", car[vehiculo].orden, car[vehiculo].luces, car[vehiculo].frenos, car[vehiculo].gases);
        }  
    }
    
    printf("---------------------------------------------\n");
    printf("\nDia finalizado\n");
    return 0;
}