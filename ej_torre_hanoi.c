#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

/*
Torre de Hanoi
En este juego se tienen 3 torres cada una puede contener 5 numeros.
En el comienzo la torre 1 (primera torre) posee los numeros del 5 al 1 ordenados decreciente, de la siguiente forma:
1: 5 4 3 2 1
2:
3:
El objetivo del juego es mover los numeros de la Torre A a la torre C en la menor cantidad de movimientos posibles
La unica regla es que los numeros siempre tienen que estar de mayor a menor en la torre, si se realiza un movimiento
que deja los numeros mal ordenados el juego termina.

Para las diferentes torres se usara una matriz de 3x5 (filas y columnas) que debera comenzar inicializada
Para cada movimiento el juego preguntara origen y destino del movimiento y movera el numero que este mas "alto" en la torre
a la torre destino, esto se computara como 1 movimiento.
Luego de cada movimiento se mostrara el resultado de la torre.
El programa debera reconocer cada vez que se comete un error y terminar el programa en ese momento.


Funciones:
 - Funcion que imprima el estado actual de las torres
 - Funcion que verifique una torre para ver que los numeros son decendentes
 - Funcion que realiza el movimiento del numero de una torre a otra
 - Funcion que pide origen y destino del movimiento
*/

int torres [3][5] = {{5, 4, 3, 2,1},
                     {0, 0, 0, 0, 0},
                     {0, 0 ,0, 0, 0}};

int destino = 0;
int origen = 0;
int cant = 0;

void estado_torres(){
    
    printf("Torre 1      Torre 2     Torre 3\n");

    for (int j = 4; j >= 0; j--)
        {
            printf("  %d            %d           %d      \n", torres[0][j], torres[1][j], torres[2][j]);
        }
    printf("\n");
        
}

int verif_torres(){

    int cont = 0;

    if (torres[2][4] == 1) // en caso de ganar, devuelve un 1
        {
            estado_torres();
            printf("Ganaste\n");
            return 1;
        }

    for (int i = 0; i < 4; i++)
    {
        if(torres[0][i] >= torres[0][i+1] && torres[1][i] >= torres[1][i+1] && torres[2][i] >= torres[2][i+1])
        {
            cont++;
        }
    }

    if (cont == 4)
    {
        return 0; // sigue el juego
    }

    else
    {
        printf("Perdiste\n");
        return 1; // si devuelve 1, termina el juego
    }
    
}

void movimientos(){
    int i = 0;
    int aux = 0;
    int help = 0;

    for (int j = 0; j < 5; j++)
    {
        if(torres[destino][j] == 0)
        {
            help = j; // busco que parte de la matriz se encuentra el numero a reemplazar
            j = 5;// salgo del for
        }
    }
    
    for (i = 4; aux == 0; i--)
    {
        if(torres[origen][i] != 0)
        {
            torres[destino][help] = torres[origen][i];
            torres[origen][i] = 0;
            cant++;
            aux = 1;
        }
    }
    
}

void origen_destino (){

    printf("En que torre se encuentra el objeto que desea mover?\n");
    fflush(stdin);
    scanf("%d",&origen);

    printf("A que torre desea moverse?\n");
    fflush(stdin);
    scanf("%d",&destino);

    origen = origen - 1;
    destino = destino - 1;
}

int main(){
    
    while(verif_torres() == 0)
    {
        estado_torres();
        origen_destino();
        movimientos();
        printf("Movimientos realizados: %d\n\n",cant);
        printf("---------------------------------------------------\n\n");

        /*if (torres[2][4] == 5)
        {
            printf("Ganaste\n");
        }*/
        
    }

    printf("Juego Finalizado\n");

    return 0;

}
