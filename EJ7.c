#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    float pesos [10];
    int aux = 0;
    float pesomin = 1000, pesomax = 0, prom; 
    float suma = 0;

    for(aux=0; aux < 10; aux++)
    {
        printf("Ingrese el valor del peso %d: \n", aux+1);
        fflush(stdin);
        scanf("%f", &pesos[aux]);

        suma += pesos[aux]; 

            if(pesos[aux]>pesomax)
            {
                pesomax = pesos[aux];
            }
            
            if(pesos[aux]<pesomin)
            {
                pesomin = pesos[aux];
            }
    }

    prom = suma / aux;

    printf("El promedio de peso es %.2f: \n", prom);
    printf("El peso mas bajo es %.2f: \n", pesomin);
    printf("El peso mas alto es %.2f: \n", pesomax);

return 0;
}