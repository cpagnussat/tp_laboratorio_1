#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main()
{
    char salir;
    int opcion1;
    char opcion2;
    int A, B;
    int flag1 = 0, flag2 = 0;


    do
    {
        system("cls");
        printf("**** CALCULADORA ****\n\n\n");
        printf("1. Ingrese el 1er operando.");
        if(flag1 == 0 )
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
        printf("3. Calcular todas las operaciones.\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Ingrese la opcion seleccionada: ");
        scanf("%d",&opcion1);

        switch(opcion1)
        {
        case 1:
            system("cls");
            printf("1. Ingrese el 1er operando: ");
            scanf("%d",&A);
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
                flag2++;
            }
            break;

        case 3:
            system("cls");
            fflush(stdin);
            if( flag1 == 0 || flag2 == 0)
            {
                printf("\n\nAntes de calcular ingrese ambos operandos.\n\n\n");
                system("pause");
            }
            else
            {
                printf("**** Calcular todas las operaciones: ****\n\n\n");
                printf("a. Calcular la suma de A+B.\n");
                printf("b. Calcular la resta de A-B.\n");
                printf("c. Calcular la division de A/B.\n");
                printf("d. Calcular la multiplicacion de A*B.\n");
                printf("e. Calcular el factorial de !A y !B \n\n");

                printf("Ingrese la opcion seleccionada: ");
                opcion2 = getchar();
                opcion2 = tolower(opcion2);

                switch(opcion2)
                {
                case 'a':
                    system("cls");
                    printf("La suma de %d+%d es: %d. \n\n",A,B,suma(A,B));
                    system("pause");
                    break;

                case 'b':
                    system("cls");
                    printf("La resta de %d-%d es: %d. \n\n",A,B,resta(A,B));
                    system("pause");
                    break;

                case 'c':
                    system("cls");
                    if(B == 0)
                    {
                        printf("No se puede dividir por 0.\n\n");
                        system("pause");
                    }
                    else
                    {
                        printf("La division de %d/%d es: %.2f. \n\n",A,B,division(A,B));
                        system("pause");
                    }
                    break;

                case 'd':
                    system("cls");
                    printf("La multiplicacion de %d*%d es: %d. \n\n",A,B,multiplicacion(A,B));
                    system("pause");
                    break;

                case 'e':
                    system("cls");
                    if( A < 0 && B < 0)
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
                    system("pause");
                    break;

                default:
                    system("cls");
                    printf("Opcion incorrecta, intente nuevamente.\n");
                    system("pause");
                    break;

                }
            }
            break;

        case 4:
            system("cls");
            fflush(stdin);
            if( flag1 == 0 || flag2 == 0)
            {
                printf("\n\nAntes de calcular ingrese ambos operandos.\n\n\n");
                system("pause");
            }
            else
            {
                printf("**** Informar los resultados ****\n\n");
                printf("a. El resultado de %d + %d es %d\n",A,B,suma(A,B));
                printf("b. El resultado de %d - %d es %d\n",A,B,resta(A,B));
                if( B == 0 )
                {
                    printf("c. No se puede resolver %d / %d, por ser B = 0. \n",A,B);
                }
                else
                {
                    printf("c. El resultado de %d / %d es %.2f \n",A,B,division(A,B));
                }
                printf("d. El resultado de %d * %d es %d\n",A,B,multiplicacion(A,B));
                if( A < 0 && B < 0)
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
                system("pause");
            }
            break;


        case 5:
            system("cls");
            fflush(stdin);
            printf("Esta seguro que desea salir ? S/N \n");
            salir = getchar();
            salir=tolower(salir);
            break;


        default:
            system("cls");
            fflush(stdin);//debuggeando el programa vi que si ingresaba un char o un string se loopeaba el default
                          //solo lo solucione agregando este fflush en el default, sino podia evaluar la variable opcion 1 como char
                          //y los numeros como caracteres '1','2', etc. para que tire error si ponia cualquier otra letra
                          // pero si ingresaba "1234" tomaba la opcion 1 por evaluar el primer caracter, asi que no
            printf("Opcion incorrecta, intente nuevamente.\n\n");
            system("pause");
        }

    }
    while(salir != 's');

    return 0;

}
