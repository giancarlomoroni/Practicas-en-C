#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.1416


float resultado1;
float resultado2;

struct recta {
    float real;
    float imag;
};

struct polar {
    float modu;
    float fase;
};


struct recta inicial;
struct polar prin;

float modulo(float real, float imaginario)
{
    int aux;
    aux = sqrt(pow(real,2) + pow(imaginario,2));
    return aux;
}

float fase(float real, float imaginario)
{
    int aux;
    aux = ((atan(imaginario / real)) * 360) / (2 * PI) ;
    return aux;
}


int main(void){

    printf("Ingrese la componente real\n");
    fflush(stdin);
    scanf("%f", &inicial.real);

    printf("Ingrese la componente imaginaria\n");
    fflush(stdin);
    scanf("%f", &inicial.imag);

    resultado1 = modulo(inicial.real, inicial.imag);
    resultado2 = fase(inicial.real, inicial.imag);

    printf("El modulo es %.2f y la fase es %.2f\n", resultado1, resultado2);

    return 0;
}
