#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int status = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* MAT;
        MAT = fopen(path, "r");
        parser_EmployeeFromText(MAT, pArrayListEmployee);
        fclose(MAT);
        status = 1;
    }
    return status;
}*/

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"r");
    int todoOk=0;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        todoOk=1;
    }
    fclose(pArchivo);
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int id;
    char nombre[20]; // !!!!!!!!!!!
    int horasTrabajadas;
    float sueldo;
    Employee* auxEmployee=NULL;
    auxEmployee=employee_new();

    if(auxEmployee!=NULL)
    {
        printf("Ingrese id: ");
        scanf("%d", &id);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese horas trabajadas: ");
        scanf("%d", &horasTrabajadas);

        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo);
        if(!(employee_setId(auxEmployee, id)
            &&employee_setHorasTrabajadas(auxEmployee, horasTrabajadas)
            &&employee_setSueldo(auxEmployee, sueldo)
            &&employee_setNombre(auxEmployee, nombre)))
        {
            free(auxEmployee);
        }
        else
        {
            ll_add(pArrayListEmployee, auxEmployee);
            todoOk=1;
        }
    }
    else
    {
        printf("\nERROR No se pudo conseguir menoria\n\n");
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int auxId;
    int i=-1;
    int flag=0;
    char confirma;
    Employee* auxEmployee;

    printf("Ingrese el id del empleado a modificar: ");
    scanf("%d", &auxId);

    do
    {
        i++;
        auxEmployee =(Employee*)ll_get(pArrayListEmployee, i);
    }while((auxEmployee->id)!=auxId && i<ll_len(pArrayListEmployee));
    if(i==ll_len(pArrayListEmployee))
    {
        printf("\nERROR, no existe el id ingresado\n\n");
    }
    else
    {
        printf("Desea cambiar el id? ");
        fflush(stdin);
        do
        {
            scanf("%s", &confirma);
            confirma=tolower(confirma);
            if(confirma!='s' && confirma!='n')
            {
                printf("\nERROR, ingrese nuevamente\n");
            }
            else if(confirma=='s')
            {
                printf("\nIngrese nuevo id: ");
                scanf("%d", &auxEmployee->id);
                flag=1;
            }
        }while(confirma!='s' && confirma!='n');

        printf("Desea cambiar el nombre? ");
        fflush(stdin);
        do
        {
            scanf("%s", &confirma);
            confirma=tolower(confirma);
            if(confirma!='s' && confirma!='n')
            {
                printf("\nERROR, ingrese nuevamente\n");
            }
            else if(confirma=='s')
            {
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(auxEmployee->nombre);
                flag=1;
            }
        }while(confirma!='s' && confirma!='n');

        printf("Desea cambiar las horas trabajadas? ");
        fflush(stdin);
        do
        {
            scanf("%s", &confirma);
            confirma=tolower(confirma);
            if(confirma!='s' && confirma!='n')
            {
                printf("\nERROR, ingrese nuevamente\n");
            }
            else if(confirma=='s')
            {
                printf("\nIngrese nuevo horas trabajadas: ");
                scanf("%d", &auxEmployee->horasTrabajadas);
                flag=1;
            }
        }while(confirma!='s' && confirma!='n');

        printf("Desea cambiar el sueldo? ");
        fflush(stdin);
        do
        {
            scanf("%s", &confirma);
            confirma=tolower(confirma);
            if(confirma!='s' && confirma!='n')
            {
                printf("\nERROR, ingrese nuevamente\n");
            }
            else if(confirma=='s')
            {
                printf("\nIngrese nuevo sueldo: ");
                scanf("%f", &auxEmployee->sueldo);
                flag=1;
            }
        }while((confirma!='s') && (confirma!='n'));
        if(flag==1)
        {
            ll_remove(pArrayListEmployee, i);
            ll_add(pArrayListEmployee, auxEmployee);
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=1;
    int auxId;
    Employee* auxEmp;
    int i=-1;
    char confirma;

    printf("\nIngrese el id a eliminar: ");
    scanf("%d", &auxId);
    do
    {
        i++;
        auxEmp =(Employee*)ll_get(pArrayListEmployee, i);
    }while((auxEmp->id)!=auxId && i<ll_len(pArrayListEmployee));

    if(i==ll_len(pArrayListEmployee))
    {
        printf("\nERROR, no existe el id ingresado\n\n");
    }
    else
    {
        printf("\n\n");
        listEmployee(auxEmp);
        do
        {
            printf("\n\nConfirma eliminar?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma=tolower(confirma);
            if(confirma!='s' && confirma!='n')
            {
                printf("\nERROR no es una respuesta valida, ingrese nuevamente");
            }
            else if(confirma=='s')
            {
                ll_remove(pArrayListEmployee, i);
                retorno=0;
            }
            else if(confirma=='n')
            {
                printf("\nBaja cancelada por el usuario\n\n");
            }
        }while(confirma!='s' && confirma!='n');
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    int tam=ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    int flag=0;

    if(pArrayListEmployee != NULL && tam > 0 )
    {
        todoOk=1;

        printf("***Listado de empleados***\n");
        printf("   ID      NOMBRE    HORAS TRABAJADAS        SUELDO\n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
            if(auxEmployee!= NULL)
            {
                listEmployee(auxEmployee);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\nERROR No hay empleados\n\n");
        }
    }

    return todoOk;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int todoOk=0;
    Employee* auxEmployee;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path, "w");
        if(pFile!=NULL)
        {
            for(int i=0;i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee, i);
                if(auxEmployee!=NULL)
                {
                    fprintf(pFile, "%d,%s,%d,%.2f\n", auxEmployee->id, auxEmployee->nombre,auxEmployee->horasTrabajadas, auxEmployee->sueldo );
                    todoOk=1;
                }
            }
            fclose(pFile);
        }
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

