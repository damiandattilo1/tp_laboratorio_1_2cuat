#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menu(int flagA, int flagB, float numA, float numB)
{
    int opcion;
    printf("*********MENU**********");
    printf("\n1. Ingresar 1er operando ");
    if(flagA==1)
        printf("(A = %.2f)", numA);
    else
        printf("(A = x)");
    printf("\n2. Ingresar 2do operando ");
    if(flagB==1)
        printf("(B = %.2f)", numB);
    else
        printf("(B = y)");
    printf("\n\n3. Calcular todas las operaciones");

    printf("\n    a) Calcular la suma ");
    if(flagA ==1)
        printf("(%.2f ", numA);
    else
        printf("(A ");
    if(flagB == 1)
        printf("+ %.2f)", numB);
    else
        printf("+ B)");

    printf("\n    b) Calcular la resta ");
    if(flagA ==1)
        printf("(%.2f ", numA);
    else
        printf("(A ");
    if(flagB == 1)
        printf("- %.2f)", numB);
    else
        printf("- B)");

    printf("\n    c) Calcular la division ");
        if(flagA ==1)
        printf("(%.2f ", numA);
    else
        printf("(A ");
    if(flagB == 1)
        printf("/ %.2f)", numB);
    else
        printf("/ B)");

    printf("\n    d) Calcular la multiplicacion ");
        if(flagA ==1)
        printf("(%.2f ", numA);
    else
        printf("(A ");
    if(flagB == 1)
        printf("* %.2f)", numB);
    else
        printf("* B)");

    printf("\n    e) Calcular el factorial ");
    if(flagA ==1)
        printf("(%d!)", (int)numA);
    else
        printf("(A!)");

    printf("\n\n4. Informar resultados");
    printf("\n5. Salir\n");

    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;

}

float sumar(float a, float b)
{
    return a+b;
}

float restar(float a, float b)
{
    return a-b;
}

float multiplicar(float a, float b)
{
    return a*b;
}

float dividir(float a, float b)
{
    return a/b;
}

int factorial(int num)
{
    int fact=1;

    for(int i=1;i<=num;i++)
    {
        fact=fact*i;

    }

    return fact;
}

void mostrar (float suma, float resta, float multiplicacion, float division, int factorialA, int factorialB, int flagDivisionXCero)
{
    printf("La suma es: %.2f\n", suma);
    printf("La resta es: %.2f\n", resta);
    printf("La multiplicacion es: %.2f\n", multiplicacion);

    if(flagDivisionXCero==1)
    {
        printf("No es posible dividir por cero\n");
    }
    else
    {
        printf("La division es: %.2f\n", division);
    }
    printf("El factorial del operando A es: %d\n", factorialA);
    printf("El factorial del operando B es: %d\n\n", factorialB);
}
