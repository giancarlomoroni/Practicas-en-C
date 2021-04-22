#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.1416

float resultados [2];

float* ptr;

struct recta {
    float real;
    float imag;
};

struct polar {
    float modu;
    float fase;
};


struct recta inicial;
struct polar argumento;
struct polar* punt; 


struct polar* conv(float real, float imaginario)
{
    struct polar resultados;
    struct polar* ptr;

    ptr = &resultados;

    resultados.modu = sqrt(pow(real,2) + pow(imaginario,2));
    resultados.fase = ((atan(imaginario / real)) * 360) / (2 * PI) ;

    return ptr;
}

int main(void){
    
    punt = &argumento;
    
    printf("Ingrese la componente real\n");
    fflush(stdin);
    scanf("%f", &inicial.real);

    printf("Ingrese la componente imaginaria\n");
    fflush(stdin);
    scanf("%f", &inicial.imag); 

    punt = conv(inicial.real, inicial.imag);

    printf("El modulo es %.2f y la fase es %.2f\n", punt->modu, punt->fase);

    return 0;
}
