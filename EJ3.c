#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int n1;
    int n2;
    int res;


    printf("Ingrese el valor de la variable 1 \n");
    fflush(stdin);
    scanf("%d",&n1);

    printf("Ingrese el valor de la variable 2 \n");
    fflush(stdin);
    scanf("%d",&n2);
    
    res = n1 % n2;
    
        if (res == 0 )
    {
            printf("La variable 1 es divisible por la 2\n");
    }
        else{
        
            printf("El resto de la operacion es: %d\n", res);
    }
    
    return 0;


}