
int suma(int numero1,int numero2)
{
    return numero1 + numero2;
}


int factorial(int numero)
{
    int factorial = 1;

    for( int i = numero ; i > 1 ; i-- )
    {
       factorial = factorial * i ;
    }

    return factorial;
}


int resta(int numero1,int numero2)
{
    int resta;

    resta = numero1 - numero2;

    return resta;
}


float division(int numero1,int numero2)   //agregarle la condicion para dividir por cero aca y sacarla del main
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
