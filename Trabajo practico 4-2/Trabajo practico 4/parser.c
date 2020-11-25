#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

#define BUFFER 1000

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[BUFFER];
    char bufferName[BUFFER];
    char bufferHorasTrabajadas[BUFFER];
    char bufferSueldo[BUFFER];
    Employee* pEmployee;
    int total=0;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            total+=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
            if(atoi(bufferSueldo) > 0)
            {
                pEmployee = employee_newParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);

                if(pEmployee != NULL && atoi(bufferId) >= 0)
                {
                    ll_add(pArrayListEmployee,pEmployee);
                    retorno = 0;
                }
            }
        }
        printf("\nSe cargaron %d datos\n\n", total);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
