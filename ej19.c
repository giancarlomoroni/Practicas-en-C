#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define cant 1 // cantidad de cursos
#define cant_max 40 // cantidad de alumnos maxima


struct persona {
    char nombre[20];
    char apellido[20];
    int dni;
};

struct cursos{
    int ano;
    char turno[20];
    int cant_alum;
    struct persona alumnos[cant_max];
}curso[cant]; 

    
void ingresar_curso (FILE* ubicacion){   
     int aux, i ,j ;
     for(i = 0; i < cant; i++)
     {
        printf("Ingrese el año del curso %d a datear\n",i+1);
        fflush(stdin);
        scanf("%d",&curso[i].ano);
        printf("Ingrese si el mimso es corresponde a turno mañana o tarde\n");
        fflush(stdin);
        scanf("%s",&curso[i].turno);
        printf("Ingrese la cantidad de alumnos que posee el mismo\n");
        fflush(stdin);
        scanf("%d",&curso[i].cant_alum);
        printf("\n");

        fprintf(ubicacion,"Curso %d turno %s cantidad de almunos %d\n", curso[i].ano,curso[i].turno, curso[i].cant_alum);
     }
}

void ingresar_alumno(FILE* puntero){
    int i, j;
    for(i = 0; i < cant; i++) // senaliza al curso
    {   
        printf("Ingrese los datos correspondientes al curso %d\n",curso[i].ano);
        for(j = 0; j < curso[i].cant_alum; j++) // senaliza el vector de los alumnos
        {
            printf("Ingrese el nombre del alumno %d\n",j+1);
            scanf("%s",&curso[i].alumnos[j].nombre);
            printf("Ingrese el apellido del alumno\n");
            scanf("%s",&curso[i].alumnos[j].apellido);
            printf("Ingrese el dni del alumno\n");
            scanf("%d",&curso[i].alumnos[j].dni);
            printf("\n");

            fprintf(puntero,"%s %s, DNI %d\n",curso[i].alumnos[j].nombre, curso[i].alumnos[j].apellido, curso[i].alumnos[j].dni);
        }
    }

}
void imprimir_curso(int i){
    
    printf("%d año turno %s posee %d alumnos\n",curso[i].ano, curso[i].turno,curso[i].cant_alum);

}

void imprimir_alumno(int i){
    
    int j;
    
    for(j = 0; j < curso[i].cant_alum; j++)
    {
        printf("Alumno %d\n",j+1);
        printf("Nombre: %s\n",curso[i].alumnos[j].nombre);
        printf("Apellido: %s\n",curso[i].alumnos[j].apellido);
        printf("DNI: %d\n",curso[i].alumnos[j].dni);
    }

}

int main(void)
{
    int aux;
    int flag = 1;
    FILE * archivo;

    archivo = fopen("Alumnos.txt","a");

    ingresar_curso(archivo);
    ingresar_alumno(archivo);
    while(flag == 1)
    {   
        printf("Que curso desea imprimir?\n");
        fflush(stdin);
        scanf("%d",&aux);
        imprimir_curso(aux-1);
        imprimir_alumno(aux-1);
        printf("Desea imprimir otro curso\n");
        printf("Señalice con un 1 si es un SI o con un 0 si es un NO\n");
        fflush(stdin);
        scanf("%d",&flag);
    
    }

    fclose(archivo);
    printf("Tarea finalizada\n");
    return 0; 
}