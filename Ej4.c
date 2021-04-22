#include <stdio.h>
#include <stdlib.h> 

int main()
{
    float n1 = 1;
    float n2 = 1;
    float res;
    int x = 0;  // Tipo de operacion
    float resto;
    
    while (n1 != 0 && n2 != 0)   
        {
        printf("Cual sera su primer numero?\n");
        fflush(stdin);
        scanf("%f", &n1);

        printf("Cual sera su segundo numero?\n");
        fflush(stdin);
        scanf("%f", &n2);

        printf("Que tipo de operacion desea realizar?\n\t1-Suma\n\t2-Resta\n\t3-Multipliacion\n\t4-Division\n");
        fflush(stdin);
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                res = n1 + n2;
                printf("El valor de la variable sera %  .2f\n", res);
                break;
        
            case 2:
                res = n1 - n2;
                printf("El valor de la variable sera %.2f\n", res);
                break;

            case 3:
                res = n1 * n2;
                printf("El valor de la variable sera %.2f\n", res);
                break;

            case 4:
                res = n1 / n2; 
                

                printf("El valor de la variable sera %.2f\n", res);
                
                break;

            default:
            printf("Error en la opcion, debera elegir una opcion entre 1 y 4\n");
        }
    }


    return 0;
}
