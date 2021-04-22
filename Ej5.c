#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas;
    int cont;
    int suma;
    float promedio;

    for(cont = 0; cont <=3; cont ++ )
    {
 
        printf("Ingrese la primer nota %d: \n", cont+1);  // porque no se puede usar cont ++
        fflush(stdin);
        scanf("%d",&notas);
            while (notas < 0 || notas > 10 )
            {
                printf("La nota no es valida, debe ser entre 1 y 10\n");
                printf("Ingrese la primer nota %d: \n", cont+1);  // porque no se puede usar cont ++
                fflush(stdin);
                scanf("%d",&notas);
            }
            
        suma += notas;
    }
        
        promedio = (float) suma / cont; // el float se pone para castear el valor con coma de la division.

        printf("El promedio de las notas es: %f\n", promedio);


    return 0;
}