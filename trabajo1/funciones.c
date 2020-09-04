/** \brief devuelve la suma de los parametros
 *
 * \param a int primer valor a sumar
 * \param b int segundo valor a sumar
 * \return int suma los parametros
 *
 */

int suma(int numero1,int numero2)
{
    int rdo; //retorno

    rdo = numero1 + numero2;

    return rdo;

}


/** \brief devuelve la factorial del parametro
 *
 * \param a int valor a calcular su factorial
 * \param
 * \return int realiza la factorial del parametro
 *
 */

int factorial(int numero)
{
    int factorial = 1;

    for( int i = numero ; i > 1 ; i-- )
    {
       factorial = factorial * i ;
    }

    return factorial;
}


/** \brief devuelve la resta de los parametros
 *
 * \param a int primer valor a restar
 * \param b int segundo valor a restar
 * \return int realiza la resta
 *
 */

int resta(int numero1,int numero2)
{
    int resta;

    resta = numero1 - numero2;

    return resta;

}


/** \brief realiza la division de los parametros ingresados
 *
 * \param a int dividendo
 * \param b int divisor
 * \return int realiza la division
 *
 */

float division(int numero1,int numero2)   //agregarle la condicion para dividir por cero aca y sacarla del main
{
    float division;

    division = (float) numero1 / numero2;

    return division;

}


/** \brief realiza la multiplicacion de los parametros ingresados
 *
 * \param a int numero a ser multiplicado
 * \param b int multiplicador
 * \return int devuelve la multiplicacion
 *
 */

int multiplicacion(int numero1,int numero2)
{
    int multiplicacion;

    multiplicacion = numero1 * numero2;

    return multiplicacion;

}
