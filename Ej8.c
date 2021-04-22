#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float tension[2];
    float corriente[2];
    float impedancia[2];

    printf("Cual sera su tension: \n");
    fflush(stdin);
    scanf("%f", &tension[0]);

    printf("Cual sera su fase: \n");
    fflush(stdin);
    scanf("%f", &tension[1]);
    
    printf("Cual sera su impedancia: \n");
    fflush(stdin);
    scanf("%f", &impedancia[0]);
    
    printf("Cual sera su fase: \n");
    fflush(stdin);
    scanf("%f", &impedancia[1]);

    //Calculos
    corriente[0] = tension[0] / impedancia [0];
    corriente[1] = tension[1] - impedancia [1];

    printf("El valor de la corriente es %f y su fase es %f \n",corriente[0],corriente[1]);

    return 0;
}
