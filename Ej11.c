#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.1416

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


int main(void){

    printf("Ingrese la componente real\n");
    fflush(stdin);
    scanf("%f", &inicial.real);

    printf("Ingrese la componente imaginaria\n");
    fflush(stdin);
    scanf("%f", &inicial.imag);

    prin.modu = sqrt(pow(inicial.real,2) + pow(inicial.imag,2));
    
    prin.fase = ((atan(inicial.imag / inicial.real)) * 360) / (2 * PI) ;

    printf("El modulo es %.2f y la fase es %.2f\n", prin.modu, prin.fase);
    







    return 0;
}





