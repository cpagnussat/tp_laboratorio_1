int factorial(int numero)
{
    int factorial = 1;

    for( int i = numero ; i > 1 ; i-- )
    {
       factorial = factorial * i ;
    }

    return factorial;
}

int suma(int numero1,int numero2)
{
    int suma;

    suma = numero1 + numero2;

    return suma;

}

int resta(int numero1,int numero2)
{
    int resta;

    resta = numero1 - numero2;

    return resta;

}

float division(int numero1,int numero2)
{
    float division;

    division = (float) numero1 / numero2;

    return division;

}

int multiplicacion(int numero1,int numero2)
{
    int multiplicacion;

    multiplicacion = numero1 * numero2;

    return multiplicacion;

}
