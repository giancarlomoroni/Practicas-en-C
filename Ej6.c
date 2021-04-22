#include <stdio.h>
#include <stdlib.h>
#define APROBADO  // para determinar algo en todo el codigo, es muy comodo

int main()
{
    int notas = 0;
    int cont;
    float promedio;
    int ap;
    int des;
    int vmax = 0;
    int vmin = 11;
    int sumas = 0;

    float prom_aprob;
    float prom_desap;

    for(cont = 0; cont <10; cont ++ )
    {
    
        printf("Ingrese la nota del alumno %d: \n", cont+1);  // porque no se puede usar cont ++
        fflush(stdin);
        scanf("%d",&notas);
            
            while (notas <0 || notas >10 )
            {
                printf("La nota no es valida, debe ser entre 1 y 10\n");
                printf("Ingrese la primer nota %d: \n", cont+1);  // porque no se puede usar cont ++
                fflush(stdin);
                scanf("%d",&notas);
            }

                if(notas >= APROBADO)
                    {
                        ap ++;
                        prom_aprob += notas;
                    }
                
                else 
                    {
                        des ++;
                        prom_desap += notas;
                    }
                
                if(notas > vmax)
                    vmax = notas;
                    
                
                if (notas < vmin)
                    {
                        vmin = notas;
                    }    
        
        sumas += notas;
    }
        
        promedio = sumas / cont;
        prom_aprob = prom_aprob / ap;
        prom_desap = prom_desap / des;
        printf("El promedio de las notas es: %f\n", promedio);
        printf("El promedio de aprobados es: %f\n", prom_aprob);
        printf("El promedio de desaprobados es: %f\n", prom_desap);
        printf("La cantidad de aprobados es: %d\n",ap );
        printf("La cantidad de desaprobados es: %d\n",des );
        printf("La nota mas alta fue: %d\n", vmax);
        printf("La nota mas baja fue: %d\n", vmin);   
    
    return 0;

}