#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/** \brief Imprime el menu y permite seleccionar la opcion
 *
 * \param Bandera de ingreso del primer operando
 * \param Bandera de ingreso del segundo operando
 * \param 1er operando, para imprimir el valor
 * \param 2do operando, para imprimir el valor
 * \return La opcion elegida por el usuario
 *
 */

int menu(int flagA, int flagB, float numA, float numB);

/** \brief suma dos operandos
 *
 * \param 1er operando
 * \param 2do operando
 * \return El resultado de la suma
 *
 */

float sumar(float a, float b);
/** \brief Resta dos operandos
 *
 * \param 1er operando
 * \param 2do operando
 * \return El resultado de la resta
 *
 */

float restar(float a, float b);

/** \brief Multiplica dos operandos
 *
 * \param 1er operando
 * \param 2do operando
 * \return El resultado de la multiplicacion
 *
 */

float multiplicar(float a, float b);

/** \brief Divide dos operandos
 *
 * \param 1er operando
 * \param 2do operando
 * \return El resultado de la division
 *
 */

float dividir(float a, float b);

/** \brief Calcula el factorial de un operando
 *
 * \param Operando
 * \return El resultado
 *
 */

int factorial(int num);

/** \brief Imprime los resultados de todas las operaciones
 *
 * \param Resultado de la suma
 * \param Resultado de la resta
 * \param Resultado de la multiplicacion
 * \param Resultado de la division
 * \param Resultado del factorial del primer operando
 * \param Resultado del factorial del segundo operando
 * \param Bandera que indica division por cero
 *
 */

void mostrar (float suma, float resta, float multiplicacion, float division, int factorialA, int factorialB, int flagDivisionXCero);
