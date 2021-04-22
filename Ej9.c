#include <stdio.h>
#include <stdlib.h>


int main(void){

    int matriz[2][2] = {};
    int matriz2[2][2] = {};
    int vector[4] = {};
    int suma1, suma2, i, j, aux = 0;

    printf("Ingrese el valor de la Matriz 1\n");
    printf("Valor 'X0'\n");
    fflush(stdin);
    scanf("%d",&matriz[0][0]);
    
    printf("Valor 'Y0'\n");
    fflush(stdin);
    scanf("%d",&matriz[0][1]);

    printf("Ingrese el valor de la Matriz 1\n");
    printf("Valor 'X1'\n");
    fflush(stdin);
    scanf("%d",&matriz[1][0]);

    printf("Valor 'Y1'\n");
    fflush(stdin);
    scanf("%d",&matriz[1][1]);

    printf("Ingrese el valor de la Matriz 2\n");
    printf("Valor 'X0'\n");
    fflush(stdin);
    scanf("%d",&matriz2[0][0]);
    
    printf("Valor 'Y0'\n");
    fflush(stdin);
    scanf("%d",&matriz2[0][1]);

    printf("Ingrese el valor de la Matriz 2\n");
    printf("Valor 'X1'\n");
    fflush(stdin);
    scanf("%d",&matriz2[1][0]);

    printf("Valor 'Y1'\n");
    fflush(stdin);
    scanf("%d",&matriz2[1][1]);

    for (i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2 ; j++, aux++)
        {
            vector[aux] = matriz[i][j] + matriz2[i][j];
        }
        
    }
    aux =0;
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++, aux ++)
        {
            printf("La suma de los eje ubicacion %d, %d es %d\n",j , i, vector[aux]);
        }
    }
    
    

   
    return 0;
}