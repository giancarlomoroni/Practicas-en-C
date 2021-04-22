#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define PI 3.14159265

double tension, frecuencia, fase;
double tiempo[20];
double senal[20];

void datos(){
    printf("Ingrese la amplitud de su señal\n");
    fflush(stdin);
    scanf("%lf",&tension);
    printf("Ingrese la frecuencia\n");
    fflush(stdin);
    scanf("%lf",&frecuencia);
    printf("Ingrese la fase en radianes\n");
    scanf("%lf",&fase);

}

void time(){
    double periodo = 1 / frecuencia;
    double segmento = periodo / 10;
    double completo = 0;

    for (int i = 0; i < 20; i++)
    {
        tiempo[i] = completo;
        completo = completo + segmento;
    }

    
}

void calculos(){
    double valores = 0;
    double actual;

    for (int i = 0; i < 20 ; i++)
    {
        valores =(double) (2* PI * frecuencia * tiempo[i]) + fase;
        actual =(double) sin(valores);
        senal[i] =(double) tension * actual;
        printf("Tiempo: %.4lf segundos -- Tension: %.4lf V\n", tiempo[i], senal[i]);
    }
    
}

int main(void){
    // a * sen(2*PI*F*t + B)
    datos();
    time();
    calculos();

    return 0;
}