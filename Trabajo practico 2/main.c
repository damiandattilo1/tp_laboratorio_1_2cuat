#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

#define TAM 1000
//TP 2 2do cuatrimestre


int menu();
void informes (Employee list[], int tam);
char menuInformes();

int main()
{
    Employee e[TAM];

    char salir='n';

    int flagAlta=0;
    int idR;

    initEmployees(e, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            enterEmployee(e, TAM);
            flagAlta=1;
            break;
        case 2:
            if(flagAlta==0)
                printf("ERROR. Debe hacer al menos un alta\n");
            else
            {
                modifyEmployee(e, TAM);
            }
            break;
        case 3:
            if(flagAlta==0)
                printf("ERROR. Debe hacer al menos un alta\n");
            else
            {
                system("cls");
                printf("Ingrese id a remover: ");
                scanf("%d", &idR);
                removeEmployee(e, TAM, idR);
            }
            break;
        case 4:
            if(flagAlta==0)
                printf("ERROR. Debe hacer al menos un alta\n");
            else
            {
                informes(e, TAM);
            }
            break;
        case 5:
            printf("Confirma salida? ");
            fflush(stdin);
            scanf("%c", &salir);
            salir=tolower(salir);
            fflush(stdin);
            break;
        default:
            printf("ERROR: no es una opcion valida");
            break;
        }
        system("pause");
        system("cls");
    }while(salir!='s');
    return 0;

}

int menu()
{
    int opcion;

    printf("*******MENU**********\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informes\n");
    printf("5. Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informes (Employee list[], int tam)
{
    char orden;
    char salir = 'n';
    do
    {
        system("pause");
        system("cls");
        switch(menuInformes())
        {
        case'a':
            printf("\nIngrese orden( A ascendente, D descendente) ");
            fflush(stdin);
            scanf("%c", &orden);
            orden=tolower(orden);
            if(orden=='a')
            {
                sortEmployees(list, tam, 0);
            }
            else if(orden == 'd')
            {
                sortEmployees(list, tam, 1);
            }

            printEmployees(list, tam);
            break;
        case 'b':
            informeSalarios(list, tam);
            break;
        case 'c':
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &salir);
            salir=tolower(salir);
        }

    }while(salir == 'n');
}

char menuInformes()
{
    char opcion;

    printf("****MENU INFORMES****\n\n");
    printf("A_ Listado alfabetico\n");
    printf("B_ Total y promedio de los salarios\n");
    printf("C_ Volver al menu principal\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
