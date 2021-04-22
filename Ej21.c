#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>





int main(void){
    FILE* archivo;
    int alumnos = 3;
    int cursos = 1;
    int lineas = alumnos + cursos;
    char texto [255];

    archivo = fopen("Alumnos.txt", "r");

    for (int i = 0; i < lineas; i++)
    {
        fgets(texto, 255, (FILE*)archivo); // el fgets lee la primera linea y la guarda, luego a la sguiente lo sobreescribe la cadena  
        printf(" %s", texto);
    }

    fclose(archivo);
    return 0;
}