#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    float numeroA;
    float numeroB;

    char confirma = 'n'; //Confirmacion de salida

    int flagA=0;
    int flagB=0;
    int flagCalcular=0;
    int flagDivisionXCero=0;

    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factorialA;
    int factorialB;

    do
    {
        switch(menu(flagA, flagB, numeroA, numeroB))
        {
        case 1:
            system("cls");

            printf("Ingrese primer operando: ");
            scanf("%f", &numeroA);
            if(flagCalcular==1)
            {
                printf("\nNOTA: Debe calcular nuevamente\n\n");
                flagCalcular=0;
            }

            flagA=1;
            break;
        case 2:
            system("cls");

            printf("Ingrese segundo operando: ");
            scanf("%f", &numeroB);
            if(flagCalcular==1)
            {
                printf("\nNOTA: Debe calcular nuevamente\n\n");
                flagCalcular=0;
            }

            flagB=1;
            if(numeroB==0)
            {
                flagDivisionXCero=1;
            }
            break;
        case 3:
            system("cls");

            if(flagA==0 && flagB==0)
            {
                printf("\nERROR, falta ingresar los dos operandos\n\n");
            }
            else if(flagA==0 && flagB==1)
            {
                printf("\nERROR, falta ingresar el primer operando\n\n");
            }
            else if(flagA==1 && flagB==0)
            {
                printf("\nERROR, falta ingresar el segundo operando\n\n");
            }
            else
            {
                suma=sumar(numeroA, numeroB);
                resta=restar(numeroA, numeroB);
                multiplicacion=multiplicar(numeroA, numeroB);
                if(flagDivisionXCero==0)
                {
                    division=dividir(numeroA, numeroB);
                }
                factorialA=factorial((int)numeroA);
                factorialB=factorial((int)numeroB);
                printf("\nSe han realizado los calculos\n\n");
                flagCalcular=1;
            }
            break;
        case 4:
            system("cls");

            if(flagCalcular==0)
            {
                if(flagA==0 && flagB==0)
                {
                    printf("\nERROR, falta ingresar los dos operandos y calcular\n\n");
                }
                else if(flagA==0 && flagB==1)
                {
                    printf("\nERROR, falta ingresar el primer operando y calcular\n\n");
                }
                else if(flagA==1 && flagB==0)
                {
                    printf("\nERROR, falta ingresar el segundo operando y calcular\n\n");
                }
                else
                {
                    printf("ERROR: Para mostrar resultados, primero hay que calcular\n\n");
                }
            }
            else
            {
                mostrar(suma, resta, multiplicacion, division, factorialA, factorialB, flagDivisionXCero);

                flagA=0;
                flagB=0;
                flagCalcular=0;
                flagDivisionXCero=0;
            }
            break;
        case 5:
            system("cls");

            printf("\nConfirma salida?");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma=tolower(confirma);
            break;
        default:
            printf("\nNo es una opcion valida\n\n");
            break;
        }

        system("pause");
        system("cls");
    }while(confirma!='s');
    return 0;
}
