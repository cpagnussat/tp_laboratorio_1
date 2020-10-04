#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"


int menuOpciones()
{
    int retorno;

    printf("    *** SISTEMA ABM ***    \n\n");
    printf("1- Alta empleado.\n");
    printf("2- Modificacion empleado. \n");
    printf("3- Baja empleado. \n");
    printf("4- Informar datos. \n\n");
    printf("5- Salir \n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &retorno);

    return retorno;
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
	printf("%5d    %10s    %10s    %5.2f    %d\n",unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sueldo, unEmpleado.sector);
}

int mostrarEmpleados(eEmpleado gente[], int tam)
{
	//system ("cls");
	int error = 1;
	int flag = 0 ;

	printf(" ID       Nombre       Apellido      Sueldo    Sector \n");
	printf("-------------------------------------------------------\n");

	if (gente !=NULL && tam > 0)
	{
		for(int i = 0 ; i < tam; i++)
		{
			if(gente[i].isEmpty == 0 )
			{
				mostrarEmpleado(gente[i]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("No hay empleados en la lista...");
		}

		error = 0;
	}

	printf("\n\n");

	return error;

}

int inicializarPersonas(eEmpleado gente[], int tam)
{
	int error = 1;

	if( gente != NULL && tam > 0 )
	{
		for(int i = 0 ; i < tam ; i++ )
		{
			gente[i].isEmpty = 1;
			gente[i].sueldo = 0; // para no sumar basura
		}

		error = 0;
	}
	return error;
}


int buscarLibre(eEmpleado gente[], int tam) // devuelve el indice de la primer estructura que encuentra libre (isempty == 1 )
{											// o si esta todo el vector lleno y no encuentra nada libre que devuelva -1
	int retorno = -1;

	if( gente != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(gente[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPersona(eEmpleado gente[], int tam, int id)
{
	int error = 1;
	int indiceEmpty;
	eEmpleado nuevoEmpleado; //estructura que vamos a ir cargando para luego copiar en la posicion disponible

	if( gente != NULL && tam > 0 && id > 0)
	{
		indiceEmpty = buscarLibre(gente, tam);

		if(indiceEmpty == -1)
		{
			printf("\n\nEl sistema esta completo...");
		}
		else
		{
			nuevoEmpleado.id = id;
			nuevoEmpleado.isEmpty = 0;

			printf("\nIngrese nombre: ");
			fflush(stdin);
			gets(nuevoEmpleado.nombre);

			printf("\nIngrese apellido: ");
			fflush(stdin);
			gets(nuevoEmpleado.apellido);

			printf("\nIngrese sueldo: ");
			scanf("%f", &nuevoEmpleado.sueldo);

			printf("\nIngrese sector: ");
			scanf("%d", &nuevoEmpleado.sector);

			gente[indiceEmpty] = nuevoEmpleado;

			error = 0;
		}
	}
	return error;
}

int ordenarEmpleadosApellido(eEmpleado gente[], int tam)
{
 	int error = 1;
 	eEmpleado auxPersona;

 	if ( gente != NULL && tam > 0 )
 	{
	 	for( int i = 0 ; i < tam -1 ; i++)
		{
			for(int j = i+1 ; j < tam ; j++)
			{
				if(strcmp(gente[i].apellido, gente[j].apellido) > 0 )
				{
					auxPersona = gente[i];
					gente[i] = gente[j];
					gente[j] = auxPersona;
				}
			}
		}

		error = 0;
 	}

 	return error;
}

int ordenarEmpleadosSector(eEmpleado gente[], int tam)
{
    int error = 1;
	eEmpleado auxPersona;

	if (gente != NULL && tam > 0)
    {
        for( int i = 0 ; i < tam -1 ; i++)
        {
            for(int j = i+1 ; j < tam ; j++)
            {
                if( gente[i].sector > gente[j].sector )
                {
                    auxPersona = gente[i];
                    gente[i] = gente[j];
                    gente[j] = auxPersona;
                }
            }
        }

        error = 0 ;
    }

	return error;
}

int sumaSalarios(eEmpleado gente[], int tam) //tambien hace el promedio
{
    int error = 1;
    float sumaSueldos = 0;
    int acumuladorEmpleadosConSueldo = 0;
    float promedioSalarios;

    if(gente != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            sumaSueldos = gente[i].sueldo + sumaSueldos;
            if(gente[i].sueldo != 0 )  // puse esta condicion para aprovechar el for e ir acumulando los empleados con sueldo
            {
                acumuladorEmpleadosConSueldo++;
            }
        }

        promedioSalarios = (float) sumaSueldos / acumuladorEmpleadosConSueldo;

        printf("\nLa suma de todos los sueldos es: %.2f\n", sumaSueldos);
        printf("\nEl promedio de los salarios es: %.2f \n\n", promedioSalarios );
        system("pause");

        error = 0;
    }

    return error;
}


int buscarEmpleado(eEmpleado gente[], int tam, int id)
{
	int retorno = -1;

	if( gente != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(gente[i].id == id && gente[i].isEmpty == 0 )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int bajaEmpleado(eEmpleado gente[], int tam)
{
	int error = 1;
	int id;
	int indice;
	char confirma;

	if( gente != NULL && tam > 0)
	{
		system("cls");
		printf("	*** Baja de empleado *** 	\n\n");

		mostrarEmpleados(gente, tam);

		printf("Ingrese el ID: ");
		scanf("%d", &id);

		indice = buscarEmpleado(gente, tam, id);

		if(indice == -1)
		{
			printf("No existe una persona con ese id... \n");
		}
		else
		{
			mostrarEmpleado(gente[indice]);
			printf("\nDesa dar de baja esta persona? s/n ");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				gente[indice].isEmpty = 1;

				error=0;
			}
			else
			{
				error = 2 ;
			}

		}
	}

	return error;
}


int modificarEmpleado(eEmpleado gente[], int tam)
{
	int error = 1;
	int id;
	int indice;
	char confirma;
	int opcionModif;

	eEmpleado empleadoAux;

	if( gente != NULL && tam > 0)
	{
		system("cls");
		printf("	*** Modificar persona *** 	\n\n");

		mostrarEmpleados(gente, tam);

		printf("Ingrese el ID: ");
		scanf("%d", &id);

		indice = buscarEmpleado(gente, tam, id);

		if(indice == -1)
		{
			printf("No existe un empleado con ese id... \n");
			system("pause");
		}
		else
		{
			mostrarEmpleado(gente[indice]);

			printf("\n\nSeleccione el dato a modificiar: \n\n");
			printf("1- Nombre\n");
			printf("2- Apellido\n");
			printf("3- Salario\n");
			printf("4- Sector\n\n");
			printf("Indique la opcion: ");
			scanf("%d", &opcionModif);

			switch(opcionModif)
			{
            case 1:
                printf("\nIngrese nuevo nombre: ");
                scanf("%s", empleadoAux.nombre);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    strcpy(gente[indice].nombre, empleadoAux.nombre );
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 2:
                printf("\nIngrese nuevo apellido: ");
                scanf("%s", empleadoAux.apellido);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    strcpy(gente[indice].apellido, empleadoAux.apellido );
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 3:
                printf("\nIngrese nuevo salario: ");
                scanf("%f", &empleadoAux.sueldo);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    gente[indice].sueldo = empleadoAux.sueldo;
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 4:
                printf("\nIngrese nuevo sector: ");
                scanf("%d", &empleadoAux.sector);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    gente[indice].sector = empleadoAux.sector;
                    mostrarEmpleado(gente[indice]);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            default:
                printf("\nError, ingrese una opcion valida... \n");
			}
        }
	}

	return error;
}



