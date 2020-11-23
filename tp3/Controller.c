#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validation.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

    FILE* f;
    char cod[100] = "./";
    strcat(cod,path);
    f = fopen(cod,"r");

    if(f != NULL)
    {
        parser_EmployeeFromText(f,pArrayListEmployee);
    }
    else
    {
        printf("\nNo se puede leer el archivo..");

    }



    fclose(f);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* f;
    char cod[100] = "./";
    strcat(cod,path);
    int todoOk = 0;

    f = fopen(cod, "rb");

    if(f != NULL)
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
        todoOk=1;
    }
    else
    {
        printf("No existe el archivo que desea abrir");

    }

    if(todoOk)
    {
        printf("\nSe cargo todo con exito\n");
        system("pause");
    }

    fclose(f);


    return 1;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error =  AltaEmpleado(pArrayListEmployee);

    if(error == 1){
        printf("\nEmpleado Cargado correctamente\n");
        system("pause");
    }else{
        printf("\nAlgo no salio Bien\t");
        system("pause");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idAux;
    int indice;


    system("cls");

    printf("    *** MODIFICAR EMPLEADO *** \n\n");

    printf("Ingrese el ID del empleado a modificar: ");
    fflush(stdin);
    scanf("%d",&idAux);

    indice = searchId(pArrayListEmployee,idAux);

    if(indice != -1){

        menuDeModificaciones(pArrayListEmployee,indice);
        system("pause");
    }
    else
    {
        printf("El ID ingresado no es valido... \n");
        system("pause");
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error;

    error = eliminarEmpleado(pArrayListEmployee);

    if(error==1){
        printf("\nEl empleado se elimino exitosamente... \n");
        system("pause");
    }else{
        printf("\nAlgo salio mal...");
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    mostrarEmplees(pArrayListEmployee);

    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    system("cls");

    printf("\n   ***   ORDENAR EMPLEADOS   ***\n\n");
    printf("1. Ordenar de menor a mayor.\n");
    printf("2. Ordenar de mayir a menor.\n");
    printf("\nSeleccione una opcion: ");
    scanf("%d",&opcion);

    switch(opcion){
    case 1:
        ordenarMenor(pArrayListEmployee);
        break;
    case 2:
        ordenarMayor(pArrayListEmployee);
        break;
    default:
        printf("Opcion invalida...");
        break;
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* emp;
    FILE* f;
    int todoOk=0;

    f = fopen(path,"w");

    if(f != NULL && ll_len(pArrayListEmployee) > 0)
    {

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {

            emp = ll_get(pArrayListEmployee,i);

            fprintf(f,"%d,%s,%d,%d \n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
            todoOk=1;

        }
        if(todoOk == 1)
        {
            printf("\t Se guardo con exito\n");
        }
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    int x = ll_len(pArrayListEmployee);
    int todoOk;

    if( pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "wb");
        if(f != NULL)
        {

            for(int i=0; i < ll_len(pArrayListEmployee); i++)
            {
                fwrite( ll_get(pArrayListEmployee,i), sizeof(Employee), 1, f);

                if((i+1) == x)
                {
                    todoOk=1;
                }
            }

        }
        if(todoOk == 1)
        {
            printf("\tSe guardo todo con exito\n");
            fclose(f);
        }
        else
        {
            printf("No se puedo guardar por algun motivo");
        }

    }


    return 1;
}




