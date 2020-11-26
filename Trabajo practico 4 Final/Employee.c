#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


int listEmployee(Employee* oneEmployee)
{
    printf("%4d   %10s  %12d  %20.2f \n", oneEmployee->id, oneEmployee->nombre, oneEmployee->horasTrabajadas, oneEmployee->sueldo);


    return 0;
}




Employee* employee_new()
{
    return (Employee*)malloc((sizeof(Employee)));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxEmployee=NULL;

    auxEmployee=employee_new();
    if(auxEmployee!=NULL)
    {
        if(!(employee_setId(auxEmployee, atoi(idStr))
            &&employee_setHorasTrabajadas(auxEmployee, atoi(horasTrabajadasStr))
            &&employee_setSueldo(auxEmployee, atof(sueldoStr))
            &&employee_setNombre(auxEmployee, nombreStr)))
        {
            free(auxEmployee);
        }
    }

    return auxEmployee;
}
/** \brief Recibe dos elementos de empleados y deteermina cual tiene el mayor sueldo
 *
 * \param puntero a void de elemento I
 * \param puntero a void de elemento J
 * \return  -1 si sueldo de I es mayor a sueldo de J , 1 si sueldo de J es mayor a sueldo de I, 0 si ambos sueldos son inguales
 *
 */

int criterio(void* elementoI, void* elementoJ)
{
    int retorno=1;
    Employee* auxI;
    Employee* auxJ;

    if(elementoI!=NULL && elementoJ!=NULL)
    {
        auxI=(Employee*)elementoI;
        auxJ=(Employee*)elementoJ;

        if((auxI->sueldo)>(auxJ->sueldo))
        {
            retorno=-1;
        }
        else if((auxI->sueldo)==(auxJ->sueldo))
        {
            retorno=0;
        }
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        todoOk=1;
    }

    return todoOk;
}
//int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }

    return todoOk;
}


//int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }

    return todoOk;
}


//int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk=1;
    }

    return todoOk;
}
//int employee_getSueldo(Employee* this,float* sueldo);
