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


int vector[] = {32, 10, 45, 20, -8, 12, -20, 30, 17, 6, -37, 0, 11};
int elementos = sizeof(vector) / sizeof(int); 
int flag = 1;

int main (void)
{
int cont, vec, c = 0, x;

    while(flag == 1)
    {
        flag = 0;

        for(c = 0; c < elementos-1; c++ )
        {    
            if(vector[c] > vector[c+1])
                {
                    x=vector[c+1];
                    vector[c+1]=vector[c];
                    vector[c]=x;
                    flag = 1;
                }
        }       
        

        }
        for (c = 0; c < elementos; c++)
        {
            printf("Vector %d valor %d\n", c, vector[c]);
        }
    return 0;
}