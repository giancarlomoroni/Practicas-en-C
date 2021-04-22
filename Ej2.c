#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int n1;
    int n2;
    int resto;


    printf("Ingrese el valor de la variable 1 \n");
    fflush(stdin);
    scanf("%d",&n1);

    printf("Ingrese el valor de la variable 2 \n");
    fflush(stdin);
    scanf("%d",&n2);
    
    resto = n1 % n2;
    
        if (n1 % n2 == 0 )
    {
        printf("La variable 1 es divisible por la 2\n");
    }
        else{
        
        printf("Las variables no son divisibles\n");
    }
    
    return 0;


}