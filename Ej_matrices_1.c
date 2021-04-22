#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <time.h>



char* vector(FILE* local, int inicial ){
    char* final; // vector a devolver
    char almacenamiento[inicial + 20]; // almacenar del fgets
    char* puntero;// almacenar el puntero de fgets

    fgets(almacenamiento, inicial + 20 , (FILE*) local);

    puntero = &almacenamiento[0];
    final = puntero + inicial;

   return final;

}

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
    char* caracteres;
    int devolucion;
    int numero = 6;

    archivo = fopen("texto.txt", "r") ;

    devolucion = posicion(archivo, principal);

    caracteres = vector(archivo, numero);

    printf("El caracter se encuentra en la posicion %d\n", devolucion);
    printf("El caracter correspondiente es: %c\n", caracteres);


    fclose(archivo);

    return 0;
}


