#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcion(char string[11],char car)
{
    int i, aux = 0;
    for(i = 0; i <= 10; i++ ){
        if(string[i] == car)
        {
            aux = i;
            break;
        }
    }

    return aux;
}


int main(void){

    char string[11];
    char car;

    int aux;

    printf("Ingrese el nombre\n");
    fflush(stdin);
    scanf("%s",&string); // computadora

    printf("Ingrese un caracter a buscar en el string\n");
    fflush(stdin);
    scanf("%s",&car); // u

    aux = funcion(string,car);
    aux += 1;

    printf("El caracter se encuentra en la posicion %d\n",aux);
    return 0;

}