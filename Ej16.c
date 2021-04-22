#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <time.h>


int posicion(FILE * position, char caracter){

    char texto[255];

    fgets(texto, 255, (FILE*)position);

    for (int i = 0; i <  255 ; i++)
    {
        if (texto[i] == caracter)
        {
            return i; 
        }
        
    }
    
}


int main (void){

    FILE *archivo;
    char principal = 'r';
    int devolucion ;

    archivo = fopen("texto.txt", "r") ;

    devolucion = posicion(archivo, principal);

    printf("El caracter se encuentra en la posicion %d\n", devolucion);

    fclose(archivo);

    return 0;
}