#include <stdio.h>
#include <stdlib.h>

#define cant 1

struct polar {
    float modu;
    float fase;
};

struct carac{
    float vi;
    float vo;
    struct polar zi;
    struct polar zo;
    int bw;
    char nums[10];
    float av;
};

struct carac ampli [3];

int main(void){

    int i;
    
    
    for ( i = 0; i < cant; i++)
    {
        printf("Ingrese los datos del amplificador %d-------------\n",i+1);
        

        printf("Ingrese el valor de vi\n");
        fflush(stdin);
        scanf("%f",&ampli[i].vi);

        printf("Ingrese el valor de vo\n");
        fflush(stdin);
        scanf("%f",&ampli[i].vo);

        printf("Ingrese el modulo de la impedancia de entrada\n");
        fflush(stdin);
        scanf("%f",&ampli[i].zi.modu);
        
        printf("Ingrese la fase de la impedancia de entrada\n");
        fflush(stdin);
        scanf("%f",&ampli[i].zi.fase);

        
        printf("Ingrese el modulo de la impedancia de salida\n");
        fflush(stdin);
        scanf("%f",&ampli[i].zo.modu);
        
        printf("Ingrese la fase de la impedancia de salida\n");
        fflush(stdin);
        scanf("%f",&ampli[i].zo.fase);

        printf("Ingrese la banda ancha del amplificador\n");
        fflush(stdin);
        scanf("%d",&ampli[i].bw);

        ampli[i].av = ampli[i].vo / ampli[i].vi;

        printf("Ingrese el numero de serie\n");
        fflush(stdin);
        scanf("%s", &ampli[i].nums);


    }

    for ( i = 0; i < cant; i++)
    {
        printf("Amplificador %d-----------------\n",i+1);
        printf("El valor de vo es %.2f\n",ampli[i].vo);
        printf("El valor de vi es %.2f\n",ampli[i].vi);
        printf("La ganancia es %.2f\n",ampli[i].av);
        printf("El modulo de la impedancia de entrada es es %.2f\n",ampli[i].zi.modu);
        printf("La fase de la impedancia de entrada es es %.2f\n",ampli[i].zi.fase);
        printf("El modulo de la impedancia de salida es es %.2f\n",ampli[i].zo.modu);
        printf("La fase de la impedancia de salida es es %.2f\n",ampli[i].zo.fase);
        printf("La banda ancha es de %d\n",ampli[i].bw);
        printf("El numero de serie es %s\n",ampli[i].nums);

        
    }
    
     
return 0;

} 

