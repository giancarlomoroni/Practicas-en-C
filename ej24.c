#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int cantidad[5] = {};

// 0 es A, 1 es B, 2 es C, 3 es D, 4 es E

void funcion_conteo(char dato){
   
    dato = tolower(dato); // pasamos a miniscula
    
    if (dato == 'a')
    {
        cantidad[0] ++;
    }

    if (dato == 'b')
    {
        cantidad[1] ++;
    }

    if (dato == 'c')
    {
        cantidad[2] ++;
    }

    if (dato == 'd')
    {
        cantidad[3] ++;
    }

    if (dato == 'e')
    {
        cantidad[4] ++;
    }

}


int main(void){
   
    char ingreso;

    while(ingreso != '*'){
       
        printf("Que bebida se vendio?\n");
        printf("Debe ser alguna de las siguientes: 'A', 'B', 'C', 'D' o 'E'\n");
        printf("Si desea parar el ingreso, debera presionar '*'\n");
        fflush(stdin);
        scanf("%s", &ingreso);
        funcion_conteo(ingreso);
    }

    char bebidas[5] = {'A', 'B', 'C', 'D', 'E'}; 

    for (int i = 0; i < 5; i++)
    {
        printf("La cantidad vendida del elemento %c es de %d\n", bebidas[i], cantidad[i]);
    }
    
    return 0;
}