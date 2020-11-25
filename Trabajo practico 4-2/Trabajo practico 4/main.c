#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int menu();


int main()
{
    int option=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* subLista;

    if(listaEmpleados==NULL)
    {
        printf("\nERROR No se pudo conseguir memoria\n\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        option=menu();
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nERROR en la carga de datos\n\n");
                }
                else
                {
                    printf("\nArchivo cargado con exito\n\n");
                }
                break;
            case 2:
               // controller_loadFromBinary("dataB.bin",listaEmpleados);
                break;
            case 3:
                system("cls");
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("ERROR al cargar los datos\n");
                }
                else
                {
                    printf("\nCarga exitosa\n\n");
                }
                break;
            case 4:
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("\nNo se realizo ningun cambio\n\n");
                }
                else
                {
                    printf("\nCambio realizado con exito\n\n");
                }
                break;
            case 5:
                system("cls");
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("\nBaja exitosa\n\n");
                }
                break;
            case 6:
                if(!controller_ListEmployee(listaEmpleados))
                {
                    printf("\nERROR\n\n");
                }
                break;
            case 7:
                //controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(!controller_saveAsText("data.csv" , listaEmpleados))
                {
                    printf("\nERROR al guardar los datos\n\n");
                }
                else
                {
                    printf("\nSe guardaron los datos con exito\n\n");
                }
                break;
            case 9:
                subLista=ll_subList(listaEmpleados, 50, 70);
                controller_ListEmployee(subLista);
                break;
            case 10:
                // Salida
                break;
            default:
                system("cls");
                printf("\nERROR, no es una opcion valida\n\n");
                break;
        }
        system("pause");
        system("cls");
    }while(option != 10);
    return 0;
}




int menu()
{
    int opcion;

    printf("Menu:\n");
    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Listar los empleados del 50 al 70");
    printf("\n10. Salir\n\n");

    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
