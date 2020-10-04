#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

#define TAM 1000


int main()
{
    char continuar = 'n';
    int opcionIngresada;
    int opcionInformar;
    int proximoLegajo = 20000;
    int flagAlta = 0;
    int rtaBaja;
    int rtaModif;
    eEmpleado lista[TAM];

    inicializarPersonas(lista, TAM);

    do
    {
        system("cls");
        opcionIngresada = menuOpciones();

        switch(opcionIngresada)
        {
            case 1:
                if(altaPersona(lista, TAM, proximoLegajo) == 0)
                {
                    proximoLegajo++;

                    printf("\n\nAlta exitosa... \n");
                    flagAlta = 1;
                }
                else
                {
                    printf("\n\nHubo un error al cargar la persona... \n");
                }
                break;
            case 2:
                if( flagAlta== 0 )
                {
                    printf("\nPrimero debe realizar el alta de algun empleado\n\n");
                    system("pause");
                }
                else
                {
                    rtaModif = modificarEmpleado(lista, TAM);

                    if(rtaModif == 0)
                    {
                        printf("\nSe ha modificado correctamente al empleado... \n");
                    }
                    else if(rtaModif == 2)
                    {
                        printf("\nModificacion cancelada por el usuario...\n");
                    }
                    else
                    {
                        printf("\nHa ocurrido un error al modificar al empleado...\n");
                    }
                }
                break;
            case 3:
                   if( flagAlta== 0 )
                {
                    printf("\nPrimero debe realizar el alta de algun empleado\n\n");
                    system("pause");
                }
                else
                {
                    rtaBaja = bajaEmpleado(lista, TAM);

                    if (rtaBaja == 0)
                    {
                        printf("Baja exitosa\n\n");
                        mostrarEmpleados(lista, TAM);
                        system("pause");

                    }
                    else if(rtaBaja == 2)
                    {
                        printf("La baja se ha cancelado por el usuario\n\n");
                        mostrarEmpleados(lista, TAM);
                        system("pause");

                    }
                    else
                    {
                        printf(" se ha producido un error en la baja...\n");
                    }

                }
                break;
            case 4:
                   if( flagAlta== 0 )
                {
                    printf("\nPrimero debe realizar el alta de algun empleado\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("\n    *** INFORMAR EMPLEADOS *** \n\n");
                    printf("1- Listar por orden alfabetico de Apellido\n");
                    printf("2- Listar por sector\n");
                    printf("3- Listar total y promedio de los salarios\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &opcionInformar);

                    switch(opcionInformar)
                    {
                    case 1:
                        if(ordenarEmpleadosApellido(lista, TAM) == 1  )
                        {
                            printf("Hubo un problema al ordenar por apellido");
                        }
                        else
                        {
                            printf("\n Empleados ordenados con exito...\n\n");
                            mostrarEmpleados(lista,TAM);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(ordenarEmpleadosSector(lista,TAM) == 1)
                        {
                            printf("Hubo un problema al ordenar por sector");
                        }
                        else
                        {
                            printf("\n Empleados ordenados con exito...\n\n");
                            mostrarEmpleados(lista,TAM);
                            system("pause");
                        }
                        break;
                    case 3:
                        if(sumaSalarios(lista, TAM) == 1)
                        {
                            printf("Hubo un problema al sumar los sueldos");
                        }
                        else
                        {
                            printf("\n Sueldos sumados con exito...\n\n");
                        }
                        break;
                    default:
                        printf("\nOpcion ingresada incorrecta, vuelva a intentar.\n");
                        system("pause");
                        break;
                    }
                }
                break;
            case 5:
                    printf("\nSeguro que desea salir? s/n \n\n");
                    fflush(stdin);
                    scanf("%c", &continuar);
                    continuar = tolower(continuar);
                    break;
            default:
                    printf("\nOpcion ingresada incorrecta, vuelva a intentar.\n");
                    system("pause");
                    break;
        }


    }while(continuar == 'n');

    return 0;
}
