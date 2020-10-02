#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(Employee list[], int len)
{
    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;
    }
    return 0;
}

int addEmployees(Employee list[], int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int posicion;

    posicion=findEmpty(list, len);

    if(posicion==-1)
    {
        printf("ERROR, sistema lleno!!\n");
        return -1;
    }
    else
    {
        list[posicion].id=id;
        strcpy(list[posicion].name, name);
        strcpy(list[posicion].lastName, lastName);
        list[posicion].salary=salary;
        list[posicion].sector=sector;

        list[posicion].isEmpty=0;
    }
    return 0;

}

int findEmpty(Employee list[], int len)
{
    int posicion=-1;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            posicion=i;
            break;
        }

    }

    return posicion;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int posicion=-1;

    for(int i=0; i < len; i++)
    {
        if(list[i].id == id)
        {
            posicion = i;
            break;
        }
    }

    return posicion;
}

int removeEmployee(Employee list[], int len, int id)
{
    int index;
    char confirma;

    index = findEmployeeById(list, len, id);

    if(index==-1)
    {
        printf("ERROR, El id ingresado no existe\n\n");
    }
    else
    {

        printf("%d    %s     %s     %.2f      %d", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);

        do
        {
            printf("Confirma baja? ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma=tolower(confirma);

            switch(confirma)
            {
            case 's':
                list[index].isEmpty = 1;
                break;
            case 'n':
                printf("\nOperacion cancelada\n\n");
                break;

            default:
                printf("\nOpcion no valida");
                break;
            }
        }while(confirma != 's' && confirma != 'n');

    }

    return -1;
}

int printEmployees(Employee list[], int length)
{
    system("cls");
    printf("\nId      Name        Last name     Salary       Sector\n\n");
    for(int i=0; i<length; i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("%d    %s      %s        %.2f       %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
        }
    }
    printf("\n");
    return 0;
}


void enterEmployee(Employee list[], int len)
{
    int id;
    int sector;

    char name[20];
    char lastName[20];

    float salary;

    system ("cls");

    printf("Ingrese Id:");
    scanf("%d", &id);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(name);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(lastName);

    printf("Ingrese salario: ");
    scanf("%f", &salary);

    printf("Ingrese sector: ");
    scanf("%d", &sector);

    addEmployees(list, len, id, name, lastName, salary, sector);
}

void modifyEmployee(Employee list[], int len)
{
    int id;
    int index;
    char opcion;

    char name[20];
    char lastName[20];
    float salary;
    int sector;

    system("cls");

    printf("Ingrese ID a modificar: ");
    scanf("%d", &id);

    index = findEmployeeById(list, len, id);

    if(index==-1)
    {
        printf("\nERROR, ID no valido\n\n");
    }
    else
    {
        printf("\nDesea modificar nombre? ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);

        if(opcion == 's')
        {
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            gets(name);
            strcpy(list[index].name, name);
        }
        else if(opcion=='n')
        {
            printf("\nOperacion cancelada\n\n");
        }
        else
        {
            printf("ERROR: operacion no valida");
        }
        printf("\nDesea modificar apellido? ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
        if(opcion == 's')
        {
            printf("\nIngrese nuevo apellido: ");
            fflush(stdin);
            gets(lastName);
            strcpy(list[index].lastName, lastName);
        }
        else if(opcion=='n')
        {
            printf("\nOperacion cancelada\n\n");
        }
        else
        {
            printf("ERROR: operacion no valida");
        }
        printf("\nDesea modificar sueldo? ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
        if(opcion == 's')
        {
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &salary);
            list[index].salary=salary;
        }
        else if(opcion=='n')
        {
            printf("\nOperacion cancelada\n\n");
        }
        else
        {
            printf("ERROR: operacion no valida");
        }
        printf("\nDesea modificar sector? ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
        if(opcion == 's')
        {
            printf("\nIngrese nuevo sector: ");
            scanf("%d", &sector);
            list[index].sector=sector;
        }
        else if(opcion=='n')
        {
            printf("\nOperacion cancelada\n\n");
        }
        else
        {
            printf("ERROR: operacion no valida");
        }

    }

}

void informeSalarios(Employee list[], int len)
{
    float suma=0;
    float prom;
    int superaProm = 0;
    int cantEmployee=0;
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            suma=suma+list[i].salary;
            cantEmployee++;
        }
    }
    prom=(suma/cantEmployee);

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0 && list[i].salary>prom)
        {
            superaProm++;
        }
    }

    printf("\nEl total de los salarios es de %.2f\nEl promedio de los salarios es de %.2f\n%d empleados superan el salario promedio\n\n", suma, prom, superaProm);
}

int sortEmployees(Employee list[], int len, int order)
{
    int error=-1;
    Employee aux;
    for(int i = 0; i < len-1; i++)
    {
        for(int j= i+1 ; j < len; j++)
        {
            if((strcmp(list[i].lastName, list[j].lastName)>0) && order==0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
            else if((strcmp(list[i].lastName, list[j].lastName)<0) && order==1)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
        }
    }
    return error;
}
