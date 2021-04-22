#include <stdio.h>
#include <stdlib.h>

#define filas 4

#define colum 4


int main(void){

    int matriz[colum][filas] = {};
    int matriz2[colum][filas] = {};
    int i = 0 , j = 0;
    int res[colum][filas];

    for (i = 0; i < colum; i++)
    {
        for (j = 0; j < filas; j++)
        {
            printf("Ingrese el valor de la Matriz 1, ubicacion columna %d fila %d\n",i, j);
            fflush(stdin);
            scanf("%d",&matriz[i][j]);
            
            printf("Ingrese el valor de la Matriz 2, ubicacion columna %d fila %d\n",i, j);
            fflush(stdin);
            scanf("%d",&matriz2[i][j]);

            res[i][j] = matriz[i][j] + matriz2[i][j];
            
        }
    }
      for (i = 0; i < colum; i++)
    {
        for (j = 0; j < filas; j++)
        {
           printf("El resultado de la suma es %d, ubicado en la columna %d fila %d\n",res[i][j],i , j);
        }
    }
    
 

    return 0;
}