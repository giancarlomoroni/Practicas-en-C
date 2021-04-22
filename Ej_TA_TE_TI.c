#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

/*Estimados.
Buenas tardes. Ayer me di cuenta que nunca subí el enunciado del TA-TE-TI asi que se los dejo a continuación.
Este ejercicio es de entrega obligatoria.

Realizar un juego de TA-TE-TI
Para el juego deberá realizar una función que imprima en pantalla el tablero en su estado actual.
La primera vez que se llame se deberá imprimir el tablero vació y a medida que se van ingresando,
las jugadas deberá imprimir nuevos tableros con todas las jugadas.

Las jugadas de cada jugador se manejaran con fila y columna dentro del tablero ("O" para J1 y "X" para J2)
Escriba una función que reciba las coordenadas de la jugada y verifique si esta ocupado el espacio o no.
Si esta ocupada deberá informarlo de alguna forma.

Escribir una función para solicitar jugadas del jugador en donde solicite fila y columna de su jugada.
Con estos datos la función colocara una "O" en el tablero en la posición considerada.

Usando la función anterior realice modificaciones para que escriba "X" para el jugador 2.

Escriba una función que genere aleatoriamente jugadas y agreguela en el codigo general.

Escribir el programa entero para que se pueda hacer un juego de TA-TE-TI.
No se preocupe por encontrar un ganador, solamente el juego.


Todas las variables deben ser locales, las únicas que se permite declararla en forma global son
es el tablero de juego y un auxiliar de posición de jugada.
Resumen:
 - Función de impresión del tablero actual
 - Función de verificar que la jugada es posible
 - Función de solicitar jugada
 - Función de jugada aleatoria
 - Usando todas las funciones armar un juego*/

//RESOLUCION

//Variable global del tablero, inicializo el tablero que tienen un punto para saber que todavia no se ingreso ningun dato, es decir
// es la posicion cero.
char tablero [3][3] = {{'.','.','.'},
                       {'.','.','.'},
                       {'.','.','.'}};

int jugada[4] = {};
//jugada[0] es para jugador 1 eje x
//jugada[1] es para jugador 1 eje y
//jugada[2] es para jugador 2 eje x
//jugada[3] es para jugador 2 eje y

void impresion(){

    
    printf("Posicion del tablero actual\n");
    printf("        1     2     3\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" %d   |  %c  |  %c  |  %c  |\n", i+1, tablero[i][0], tablero[i][1], tablero[i][2]);
        printf("------------------------\n");
    }
}

void jugador_1(){
    int eje_x;
    char eje_y;
    //ingreso de datos
    printf("Ingrese las coordenadas\n");
    //ingreso de los datos del eje y
    printf("Ingrese columna\n");
    fflush(stdin);
    scanf(" %d",&eje_y);
    
    //ingreso de los datos del eje x
    printf("Ingresa fila\n");
    fflush(stdin);
    scanf("%d",&eje_x);
    printf("-----------------------------------------------------------------\n");// para espaciacion
    
    eje_x -= 1; // le resto uno para que sea el numero correspondiente en la matriz, ya que va de 1 a 3 en el juego
    eje_y -= 1; // y de 0 a 2 en la matriz
   
   jugada[0] = eje_x; // guardo el valor en un vector
   jugada[1] = eje_y; // guardo el valor en el vector

}

void jugador_2(){
    
    srand(time(NULL));
    jugada[2] = rand() % 3; // jugada aleatoria
    jugada[3] = rand() % 3; // jugada aleatoria

}

int verificacion (){
    

//jugada del jugador 1
    jugador_1();

//NOTA: Lo trate de hacer con =! y me traia quilombo entonces puse la OR

    while (tablero[jugada[0]][jugada[1]] == 'X' || tablero[jugada[0]][jugada[1]] == 'O' )
    {
        printf("Posicion ocupada, debe ingresar nuevamente---------------\n");
        jugador_1();
    }

    /// guardo en la posicion elegida la O correspondiente al jugador 1 
    tablero[jugada[0]][jugada[1]] = 'O';
    

 //jugada del jugador 2   
    jugador_2();

    
    while (tablero[jugada[2]][jugada[3]] == 'O' || tablero[jugada[2]][jugada[3]] == 'X')
    {
       //Cuando juega la maquina no aviso que debe ingresar nuevamente por problema de la posicion ocupada, porque sino
       // me spamea todo el terminal.
       jugador_2();
    }

    /// guardo en la posicion elegida la X correspondiente al jugador 2 
    tablero[jugada[2]][jugada[3]] = 'X';

    
}

int winner(){
    int i = 0; // varibable para el for
    int j = 0; // variable para el for
    int aux = 3; // variable para sumar en un lazo for
    // vectores para guardar la cantidad de X y/o O en las matrices
    int jugadas_1[8] = {};
    int jugadas_2[8] = {};
    /* los vectores estan conformados:
    jugadas[0,1,2] para guardar las lecturas horizontales
    jugadas[3,4,5] para guardar las lecturas verticales
    jugadas[6] para guardar la lectura diagonal de izq a der
    jugadas[7] para guardar la lectura diagonal de der a izq*/
    
// lecturas horizontales    
    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (tablero[i][j] == 'O')
            {
                jugadas_1[i]++;
            }

            if (tablero[i][j] == 'X')
            {
                jugadas_2[i]++;
            }
        }
    }

//lectura verticales

    for (i = 0; i < 3; i++)
    { 
        for ( j = 0; j < 3; j++)
        {
            if (tablero[j][i] == 'O')
            {
                jugadas_1[aux]++;
            }

            if (tablero[j][i] == 'X')
            {
                jugadas_2[aux]++;
            }
        }
        aux++; // variable que uso para incrementar a partir de 3 para poder seguir guardando datos en el vector

    }
// lectura en diagonal de izquierda a derecha
    for (i = 0; i < 3; i++)
    {
        if(tablero[i][i] == 'O')
        {
            jugadas_1[6]++;
        }

        if(tablero[i][i] == 'X')
        {
            jugadas_2[6]++;
        }
    }
//lectura en diagonal de derecha a izquierda
    for (i = 2, j = 0; i >= 0; i--, j++)
    {
        if(tablero[j][i] == 'O')
        {
            jugadas_1[7]++;
        }

        if(tablero[j][i] == 'X')
        {
            jugadas_2[7]++;
        }
    }
    
    // for para poder visualizar y comprobar los vectores
    for (i = 0; i < 8; i++)
    {
        if (jugadas_1[i] == 3) // == 3 porque es una matriz de 3 x 3 y es lo necesario para poder ganar
        {
            printf("---------GANO JUGADOR 1-------------\n");
            return 0; // devuelve un 0 y termina el lazo while del main
        }

        if (jugadas_2[i] == 3)
        {
            printf("---------GANO JUGADOR 2-------------\n");
            return 0; // devuelve un 0 y termina el lazo while del main
        }
     
    }

    return 1;// si no se cumple las condiciones de arriba, devuelve un 1 para seguir ejecutando el while
    
}

int main(){
    impresion(); // impresion y verificacion los puse para que se ejecuten primeras en el programa para asi cuando ejecuta 
    verificacion(); // la funcion winner, no se me atrase una posicion en el tiempo todo.

    while (winner() == 1)
    {
        impresion();
        verificacion();
    }
    
    printf("------------El juego ha finalizado de la siguiente manera-----------\n");
    impresion(); // ultima impresion para ver como quedo el juego
    
    
    return 0;
}