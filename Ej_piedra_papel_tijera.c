#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
Realizar un programa que permita jugar al "piedra, papel o tijera" con la computadora.
Por consola se debe introducir un "r" (piedra), un "p" (papel) o un "t" (tijera) y la computadora debe generar su respuesta
en forma automatica y aleatoria. Luego comparar las respuestas e indicar el ganador de la ronda.
El mejor de 3 rondas es nombrado ganador del juego y el programa debe informarlo por consola.

Se recomienda:
 - Realizar una funcion que tome como argumentos las elecciones del jugador y de la PC y devuelva quien es el ganador de la ronda.
 - Realizar una funcion que no solicite nada y devuelva la eleccion de la PC (piedra papel o tijera)

Notas:
 - Si no se imagina como hacer las funciones en un principio para funcionar con letras, utilice numeros (1, 2 o 3) y luego
   cuando el programa funcione segun lo deseado realice las modificaciones a las funciones para que trabajen con letras.
*/


int aux_pc = 0; // variable global que cuenta cuantas rondas ganadas lleva la pc
int aux_per = 0; // variable global que cuenta cuantas rondas ganadas lleva la persona

int funcion_win(char maquina, char persona){

    // Senalizacion
    // empate 0
    // maquina gana 1
    // persona gana 2
    
    switch (persona)
    {
    case 'r': // analizamos caso si la persona eligio piedra
        if(maquina == 'r')
            return 0;
        
        if (maquina == 'p')
        {
            aux_pc++;
            return 1;
        }
        
        if (maquina == 't')
        {
            aux_per++;
            return 2;
        }
        break;
    
    case 'p': // analizamos caso si la persona eligio papel
        if(maquina == 'r')
        {
            aux_per++;
            return 2;
        }
        
        if (maquina == 'p')
            return 0;
        
        if (maquina == 't')
        {
            aux_pc++;
            return 1;
        }
        break;

    case 't': // analizamos caso si la persona eligio tijera
        if(maquina == 'r')
        {
            aux_pc++;
            return 1;
        }
        
        if (maquina == 'p')
        {
            aux_per++;
            return 2;
        }
        
        if (maquina == 't')
            return 0;

        break;
    }
}

char funcion_pc (){

    int numero; // variable para poder almacenar el resultado del numero rand
    numero = rand() % 3;
   
    if (numero == 0){
        printf("La maquina elijio roca\n");
        return 'r';}

    else if (numero == 1){
        printf("La maquina elijio papel\n");
        return 'p';}

    else if (numero == 2){
        printf("La maquina elijio tijera\n");
        return 't';}
}

int main(void){

    char elec; // variable para guardar lo que ingresa el operador
    int flag = 0; // variable para mantener el while
    char save; // variable para guardar la funcion pc
    int res; // variable para guardar la funcion win
    int aux = 0; // variable para contar la cantidad de rondas

    while(flag == 0)
    {
        printf("Ronda %d\n", aux+1);
        printf("Ingrese r (piedra), un p (papel) o un t (tijera)\n");
        fflush(stdin);
        scanf(" %c",&elec);

        save = funcion_pc(); // guardo la funcion pc, para que asi me la corra una sola vez por loop y no cada vez que este dentro de un if
        res = funcion_win(save,elec); // la guardo para no tener problemas de que me la ejecute varias veces por ronda.
        
        if(res == 0){ // if para comparar si es empate
            printf("Hay un empate\n\n");
            aux++;
        }

        if(res == 1) // if para comparar si gano la maquina
        {
            printf("Gano la ronda la maquina\n\n");
            aux++;
        }

        if(res == 2) // if para comparar si gano la persona
        {
            printf("Gano la ronda el humano\n\n");
            aux++;
        }

        if(aux_pc >= 3) // if para saber si ya gano tres rondas, por lo tanto, gana el juego
        {
            printf("Juego finalizado\n");
            printf("Gano la computadora\n");
            flag = 1;
        }

        if(aux_per >= 3) //if para saber si ya gano tres rondas, por lo tanto, gana el juego
        {
            printf("Juego finalizado\n");
            printf("Gano el humano\n");
            flag = 1;
        }
    } 
    return 0;
} 