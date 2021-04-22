#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
//www.programiz.com/c-programming/library-function/string.h/strcmp

/*Se necesita el software para el manejo de una máquina expendedora. La máquina posee 4 estantes (filas), 
en cada uno entran 3 productos (columnas), cada producto tiene un precio. Se debe realizar un programa que solicite al usuario
que ingrese que producto quiere (mediante fila y columna) y el programa informe cuántos ítems hay disponibles y el precio de dicho ítem. 
Una vez dada la información el programa deberá solicitar confirmación de la compra, si lo hace deberá reducir la cantidad de ítems 
disponibles de dicho producto en 1.
Para la consulta de precio y cantidad de ítems crear 2 funciones que reciben los parámetros fila y columna y 
devuelven la cantidad de ítems y el precio de cada ítem.

Nota: Realizar 2 matrices, una servirá para almacenar la cantidad ítems “cantidades” y la otra el precio de cada ítem “precios”. 
Considerar que ambas matrices ya tienen cargados los valores de precio y cantidad.*/


int cantidades[3][4] = {
                    {11 , 17, 4, 12},
                    {7, 11, 12, 25},
                    {7, 8, 6, 5},
};

int precios [3][4] = {
                 {150,200,250,350},
                 {200,150,360,450},
                 {150,250,400,700},
};

int funcion_precio(int fila, int columna){
    
    return precios[fila][columna];

}

int funcion_cantidad(int fila, int columna){

    return cantidades[fila][columna];
}

int main (void){

    int y , x, i;
    char compra[10];

    printf("Que producto desea comprar?\n");
    printf("Ingrese la columna en la que se encuentra\n");
    fflush(stdin);
    scanf("%d", &y);
    printf("Ingrese la fila en la que se encuentra\n");
    fflush(stdin);
    scanf("%d", &x);

    printf("El costo del producto es %d y la cantidad del mismo es de %d items\n",funcion_precio(x,y), funcion_cantidad(x,y));

    printf("Desea confirmar la compra si o no?\n");
    fflush(stdin);
    scanf("%s", &compra);

    for ( i = 0; i < 10; i++)
    {
        compra[i] = tolower(compra[i]); // paso a minuscula para luego comparar
    }
    

    if (compra[0] == 's')
    {
        cantidades[y][x] --;
        printf("Compra realizada correctamente\n");
    }

    else
        printf("Compra abortada\n");
    

    printf("Cantidad actual del producto %d\n",funcion_cantidad(x,y));
    
    return 0;
}