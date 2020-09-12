#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    char salir = 'n';
    int opcion1;
    char opcion2;
    int A, B;
    int flag1 = 0, flag2 = 0;
    int flagSuma = 0, flagResta = 0, flagDivision = 0, flagMultip = 0, flagFact = 0;

    do
    {
        system("cls");
        printf("**** CALCULADORA ****\n\n\n");
        printf("1. Ingrese el 1er operando.");
        if(flag1 == 0 )//condicion para mostrar el valor al lado de la opcion o no mostrar nada
        {
            printf("\n");
        }
        else
        {
            printf(" A = %d. \n",A);
        }
        printf("2. Ingrese el 2do operando.");
        if(flag2 == 0 )
        {
            printf("\n");
        }
        else
        {
            printf(" B = %d. \n",B);
        }
        printf("3. Realizar las operaciones individualmente.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Ingrese la opcion seleccionada: ");
        scanf("%d",&opcion1);
        fflush(stdin);

        switch(opcion1)//switch del primer menu
        {
        case 1:
            system("cls");
            printf("1. Ingrese el 1er operando: "); //aca no se como se validaria que ingrese un numero y no una letra o una string
            scanf("%d",&A);
            fflush(stdin);
            flag1++;

            break;

        case 2:
            system("cls");
            if(flag1 == 0)
            {
                printf("Primero ingrese el 1er operando.\n\n");
                system("pause");
            }
            else
            {
                printf("2. Ingrese el 2do operando: ");
                scanf("%d",&B);
                fflush(stdin);
                flag2++;
            }
            break;

        case 3:
            system("cls");
            if( flag1 == 0 || flag2 == 0)
            {
                printf("\n\nAntes de realizar las operaciones ingrese ambos operandos.\n\n\n");
                system("pause");
            }
            else
            {
                printf("**** Realizar todas las operaciones: ****\n\n\n");
                printf("a. Calcular la suma de A+B.\n");
                printf("b. Calcular la resta de A-B.\n");
                printf("c. Calcular la division de A/B.\n");
                printf("d. Calcular la multiplicacion de A*B.\n");
                printf("e. Calcular el factorial de !A y !B \n\n");

                printf("Ingrese la opcion seleccionada: ");
                opcion2 = getchar();
                opcion2 = tolower(opcion2);
                fflush(stdin);

                switch(opcion2) //switch del menu 2 para solamente "calcular" individualmente resultados pero no mostrarlos
                {
                case 'a':
                    system("cls");
                    printf("La suma de %d+%d ha sido calculada. \n\n",A,B);
                    flagSuma++;
                    system("pause");
                    break;

                case 'b':
                    system("cls");
                    printf("La resta de %d-%d ha sido calculada. \n\n",A,B);
                    flagResta++;
                    system("pause");
                    break;

                case 'c':
                    system("cls");
                    if(B == 0) // condicion para dar error si se divide por cero
                    {
                        printf("No se puede dividir por 0.\n\n");
                        flagDivision++;
                        system("pause");
                    }
                    else
                    {
                        printf("La division de %d/%d ha sido calculada. \n\n",A,B);
                        flagDivision++;
                        system("pause");
                    }
                    break;

                case 'd':
                    system("cls");
                    printf("La multiplicacion de %d*%d ha sido calculada. \n\n",A,B);
                    flagMultip++;
                    system("pause");
                    break;

                case 'e':
                    system("cls");
                    if( A < 0 && B < 0) // condiciones para mostrar si alguno de los numeros es negativo, no calcular la factorial
                    {
                        printf("e. No se puede calcular la factorial de %d ni de %d.\n\n",A,B);
                    }
                    else if( A < 0 )
                    {
                        printf("e. La factorial de %d no se puede calcular, la factorial de %d ha sido calculada. \n\n",A,B);
                        flagFact++;
                    }
                    else if( B < 0 )
                    {
                        printf("e. La factorial de %d ha sido calculada, la factorial de %d no se puede calcular.\n\n",A,B);
                         flagFact++;
                    }
                    else
                    {
                        printf("e. La factorial de %d y de %d han sido calculadas. \n\n",A,B);
                         flagFact++;
                    }
                    system("pause");
                    break;

                default:
                    system("cls");
                    printf("Opcion incorrecta, intente nuevamente.\n\n\n");
                    system("pause");
                    break;

                }
                // fin del switch del segundo menu
            }
            break;

        case 4:
            system("cls");
            if( flag1 == 0 || flag2 == 0)
            {
                printf("\n\nAntes de mostrar los resultados ingrese ambos operandos.\n\n\n");
                system("pause");
            }
            //si no se realizo ninguna de las operaciones, mostrar un mensaje
            else if(flagSuma == 0 && flagDivision == 0 && flagMultip == 0 && flagResta == 0 && flagFact == 0)
            {
                printf("\n\nAntes de mostrar los resultados debe realizar al menos una operacion.\n\n\n");
                system("pause");
            }
            else
            {
                printf("**** Informar los resultados ****\n\n");
                if(flagSuma!=0)//bandera de las operaciones para desbloquear los resultados si fueron "calculados" previamente
                {
                    printf("a. El resultado de %d + %d es %d\n",A,B,suma(A,B));
                }
                else
                {
                    printf("a. El resultado de %d + %d no ha sido calculado.\n",A,B);
                }

                if(flagResta != 0)
                {
                    printf("b. El resultado de %d - %d es %d\n",A,B,resta(A,B));
                }
                else
                {
                    printf("b. El resultado de %d - %d no ha sido calculado.\n",A,B);
                }

                if(flagDivision != 0)
                {
                    if( B == 0 )
                    {
                        printf("c. No se puede resolver %d / %d, por ser B = 0. \n",A,B);
                    }
                    else
                    {
                        printf("c. El resultado de %d / %d es %.2f \n",A,B,division(A,B));
                    }
                }
                else
                {
                    printf("c. El resultado de %d / %d no ha sido calculado.\n",A,B);
                }

                if(flagMultip != 0 )
                {
                    printf("d. El resultado de %d * %d es %d\n",A,B,multiplicacion(A,B));
                }
                else
                {
                    printf("d. El resultado de %d * %d no ha sido calculado.\n",A,B);
                }

                if(flagFact != 0)
                {
                    if( A < 0 && B < 0) // condiciones para no calcular factorial de numeros negativos
                    {
                        printf("e. No se puede calcular la factorial de %d ni de %d.\n\n",A,B);
                    }
                    else if( A < 0 )
                    {
                        printf("e. La factorial de %d no se puede calcular, la factorial de %d es: %d.\n\n",A,B,factorial(B));
                    }
                    else if( B < 0 )
                    {
                        printf("e. La factorial de %d es: %d, la factorial de %d no se puede calcular.\n\n",A,factorial(A),B);
                    }
                    else
                    {
                        printf("e. La factorial de %d es: %d y la factorial de %d es: %d.\n\n",A,factorial(A),B,factorial(B));
                    }
                }
                else{
                    printf("e. El resultado de las factoriales de %d y %d no han sido calculadas.\n",A,B);
                }

                system("pause");
            }
            break;


        case 5:
            system("cls");
            printf("Esta seguro que desea salir ? S/N \n");
            salir = getchar();
            salir=tolower(salir);
            fflush(stdin);
            break;


        default:
            system("cls");
            printf("Opcion incorrecta, intente nuevamente.\n\n");
            system("pause");
        }
        //fin del switch de opcion1

    }
    while(salir != 's' && salir == 'n'); // condicion para que el programa solo salga con salir = 's'

    return 0;

}

