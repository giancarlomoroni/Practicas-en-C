#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int carton[5][3] = { // matriz [y][x]
                    {5,8,9},
                    {2,15,14},
                    {1,3,11},
                    {4,7,12},
                    {6,10,13},
};

int marcas[5][3] = {};

int i, j , ingresado,cont;
bool flag = 0;

char x[] = {"x"};  

int main(void){

    
    while (flag == 0)
    {
        printf("Ingrese el numero \n");
        printf("Debe estar 0 y 30 \n");
        fflush(stdin);
        scanf("%d",&ingresado);
           
        while(ingresado < 0 || ingresado > 30)
        {
            printf("Debe estar 0 y 30, ingrese nuevamente \n");
            fflush(stdin);
            scanf("%d",&ingresado);
        }

        for (i = 0; i < 5; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                if(carton[i][j] == ingresado)
                {
                    marcas[i][j] = x[0];
                    cont++;
                }
            }
        } 
        if(cont == 15)
        {
            flag = 1;
        }
    }
    printf("Bingo\n");


    return 0;
}