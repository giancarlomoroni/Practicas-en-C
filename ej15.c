#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

struct dato{

    int entero;
    float decimal;
    char caracter;

};

struct dato info;

struct dato* punt_estr;  // no se guarda en memoria, solo lo declaras para que el programa sepa que dentro de esta estructura,
//se pueda guardar los datos int float y caracter

//Prototipo
void modif_int (struct  dato*);
void modif_flo (struct  dato*);
void modif_char (struct  dato*);


int main(void){

    punt_estr = &info;

    printf("Ingrese el valor entero\n");
    fflush(stdin);
    scanf("%d", &info.entero);

    printf("Ingrese el valor decimal\n");
    fflush(stdin);
    scanf("%f", &info.decimal);

    printf("Ingrese el caracter\n");
    fflush(stdin);
    scanf(" %c", &info.caracter);

    modif_int(punt_estr);
    modif_flo(punt_estr);
    modif_char(punt_estr);

    printf("Nuevo valor del entero: %d\n", info.entero);
    printf("Nuevo valor del decimal: %.2f\n", info.decimal);
    printf("Nuevo valor del caracter: %c\n", info.caracter);


    return 0;
}

void modif_int (struct  dato* puntero){
    
    printf("Ingresa el nuevo valor int\n");
    scanf("%d",&(puntero->entero));
}
void modif_flo (struct  dato* puntero){
    
    printf("Ingresa el nuevo valor del char\n");
    scanf("%f",&(puntero->decimal));
}
void modif_char (struct  dato* puntero){
    
    printf("Ingresa el nuevo valor del char\n");
    scanf(" %c",&(puntero->caracter));
}
