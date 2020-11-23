#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "validation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/** \brief setter de ID
 *
 * \param  int* ID
 * \param Employee* this
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_setId(Employee* this,int id)
{

    int todoOk=0;

    if(this != NULL && id > 0)
    {

        this->id = id;
        todoOk=1;

    }

    return todoOk;
}









/** \brief getter de iD
 *
 * \param Employee* this
 * \param int* ID
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_getId(Employee* this,int* id)
{

    int todoOk=0;

    if(this != NULL && id != NULL)
    {

        *id = this->id;
        todoOk=1;

    }

    return todoOk;





}

/** \brief setter de nombre
 *
 * \param  Employee* this
 * \param int* NOMBRE
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_setNombre(Employee* this,char* nombre)
{

    int todoOk=0;


    if(this != NULL && nombre !=NULL && strlen(nombre) > 1 )
    {

        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;

}
/** \brief getter de nombre
 *
 * \param Employee* this
 * \param int* NOMRBE
 * \return  1 SI TODO SALIO BIEN
 *
 */

int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk=0;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }



    return todoOk;

}

/** \brief setter de horas
 *
 * \param Employee* this
 * \param int* HORASTRABAJADAS
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

    int todoOk=0;

    if(this != NULL && horasTrabajadas > 0)
    {

        this->horasTrabajadas = horasTrabajadas;
        todoOk=1;

    }

    return todoOk;


}

/** \brief getter de horas
 *
 * \param Employee* this
 * \param int* HORAS
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{


    int todoOk=0;

    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;

    }

    return todoOk;


}

/** \brief setter de sueldo
 *
 * \param Employee* this
 * \param int* sueldo
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_setSueldo(Employee* this,int sueldo){


    int todoOk=0;

    if(this != NULL && sueldo > 0)
    {

        this->sueldo = sueldo;
        todoOk=1;

    }

    return todoOk;


}

/** \brief getter de sueldo
 *
 * \param  Employee* this
 * \param int* sueldo
 * \return 1 SI TODO SALIO BIEN
 *
 */

int employee_getSueldo(Employee* this,int* sueldo){



    int todoOk=0;

    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;
        todoOk=1;

    }

    return todoOk;






}

/** \brief Allocs memory for new employee and initializes the structure
 *
 * \param
 * \param
 * \return  THIS (puntero a empleado)
 *
 */

Employee* employee_new()
{


    Employee* this = (Employee*) malloc(sizeof(Employee));


    if(this!=NULL)
    {
        this->id = 0;
        this->horasTrabajadas = 0;
        this->sueldo= 0;
        strcpy(this->nombre,"");
    }

    return this;

}


/** \brief CREA UN EMPLEADO SI LOS DATOS PASADOS POR PARAMETRO SON CORRECTOS
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return THIS ( puntero a empleado)
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    int validation = 0;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();

        if(employee_setId(this, atoi(idStr)) && employee_setNombre(this,nombreStr) && employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) && employee_setSueldo(this,atoi(sueldoStr)))
        {
          validation = 1;
        }

        if(validation == 0)
        {
            free(this);
            this = NULL;
        }


    }


    return this;


}


/** \brief MUESTRA UN EMPLEADO DE LA LISTA
 *
 * \param Employee* emp
 * \param
 * \return  VOID
 *
 */

void mostrarEmployee(Employee* emp){

    printf("\n%d   %10s    %d    %d   \n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);

}

/** \brief ORDENA EL SUELDO DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \param  LinkedList* pArrayListEmployee
 * \param
 * \return
 *
 */

int ordenarXsueldo(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->sueldo > p2->sueldo){
                retorno = 1;
            }

            else if(p1->sueldo < p2->sueldo){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;




}

/** \brief ORDENA LOS ID DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \param LinkedList* pArrayListEmployee
 * \return
 *
 */
int OrdenarXId(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->id > p2->id){
                retorno = 1;
            }

            else if(p1->id < p2->id){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;

}


/** \brief ORDENA LAS HORAS DE MENOR A MAYOR O DE MAYOR A MENOR
 *
 * \param LinkedList* pArrayListEmployee
 * \return
 *
 */
int OrdenarXHoras(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if(p1->horasTrabajadas > p2->horasTrabajadas){
                retorno = 1;
            }

            else if(p1->horasTrabajadas < p2->horasTrabajadas){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;

}


int menuOpcionesOrdenar(){

    int opc;

    printf("\n    *** ORDENAMIENTO *** \n\n");

    printf("1.Ordenar por sueldo\n");
    printf("2.Ordenar por id\n");
    printf("3.Odenar por nombre\n");
    printf("4.Ordenar por Horas\n");
    printf("\nSelecciones la opcion: ");
    scanf("%d",&opc);

    return opc;

}


/** \brief MENU DE ORDENAR DE MENOR A MAYOR
 *
 * \param LinkedList* pArrayListEmployee
 * \return RETORNA VOID
 *
 */
void ordenarMenor(LinkedList* pArrayListEmployee){

    system("cls");


    switch(menuOpcionesOrdenar())
    {
    case 1:
        ll_sort(pArrayListEmployee,ordenarXsueldo,1);
        break;
    case 2:
        ll_sort(pArrayListEmployee,OrdenarXId,1);
        break;
    case 3:
        ll_sort(pArrayListEmployee,ordenarNombre,1);
        break;
    case 4:
        ll_sort(pArrayListEmployee,OrdenarXHoras,1);
        break;
    default:
        printf("Opcion invalida");
        system("pause");
        break;
    }

}


/** \brief ORDENA LOS NOMBRE, ALFABETICAMENTE
 *
 * \param LinkedList* pArrayListEmployee
 * \return RETORNA 1 si se pudo ordenar correctamente
 *
 */
int ordenarNombre(void* emp1,void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;



    if(emp1 != NULL && emp2 != NULL){

            p1= (Employee*) emp1;
            p2=(Employee*) emp2;


            if((strcmp(p1->nombre,p2->nombre)==1)){
                retorno = 1;
            }

            else if((strcmp(p1->nombre,p2->nombre)!=1)){
                retorno = -1;
            }
            else{
                retorno = 0;
            }


    }


    return retorno;




}


/** \brief ORDENA DE MAYOR A MENOR
 *
 * \param LinkedList* pArrayListEmployee
 * \return RETORNA VOID
 *
 */
void ordenarMayor(LinkedList* pArrayListEmployee){

    system("cls");


    switch(menuOpcionesOrdenar()){
    case 1:
        ll_sort(pArrayListEmployee,ordenarXsueldo,0);
        break;
    case 2:
        ll_sort(pArrayListEmployee,OrdenarXId,0);
        break;
    case 3:
        ll_sort(pArrayListEmployee,ordenarNombre,0);
        break;
    case 4:
        ll_sort(pArrayListEmployee,OrdenarXHoras,0);
        break;
    default:
        printf("opcion incorrecta");
        break;
    }

}



int menuOpciones(){

    int opcion;

    printf("\n    ***     MENU DE OPCIONES    ***\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin.\n");
    printf("10. Salir\n\n");
    printf("Selecciones la opcion: ");
    scanf("%d",&opcion);

    return opcion;

}



/** \brief DA DE ALTA UN EMPLEADO
 *
 * \param LinkedList* pArrayListEmployee
 * \return RETORNA 1 si se dio de alta correctamente
 *
 */
int AltaEmpleado(LinkedList* pArrayListEmployee){

    char idAux[30];
    char auxNombre[30];
    char auxHoras[30];
    char auxSuledo[30];
    int id;
    int todoOk;
    Employee* emp;


    system("cls");

    printf("\n  ***  ALTA DE EMPLEADO   ***\n");

    id = incremetarID(pArrayListEmployee,1000);
    sprintf(idAux, "%d", id);
    printf("\nID del empleado: %s \n",idAux);


    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(auxNombre);
    validarCararteres(auxNombre);

    printf("\nIngrese las horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);
    validarNumero(auxHoras);

    printf("\nIngrese el sueldo: ");
    fflush(stdin);
    gets(auxSuledo);
    validarNumero(auxSuledo);

    emp = employee_newParametros(idAux,auxNombre,auxHoras,auxSuledo);

    if(emp != NULL){
        ll_add(pArrayListEmployee,emp);
        todoOk=1;

    }

    return todoOk;

}

/** \brief ELIMINA EL EMPLEADO
 *
 * \param LinkedList* pArrayListEmployee
 * \return RETORNA 1 si se dio de baja correctamente
 *
 */
int eliminarEmpleado(LinkedList* pArrayListEmployee){

    int idAux;
    int indice;
    int todoOk=0;

    system("cls");
    printf("\n    *** BAJA EMPLEADO *** \n");

    printf("\nIngrese el id del empleado: ");
    fflush(stdin);
    scanf("%d",&idAux);

    indice = searchId(pArrayListEmployee,idAux);

    if(indice != -1)
    {

        char opc;

        printf("\nUsted selecciono el siguiente empleado para dar de baja: \n");
        mostrarEmployee((Employee*)ll_get(pArrayListEmployee,indice));
        printf("\n\nSeguro de desea eliminar este empleado? S/N: ");
        fflush(stdin);
        scanf("%s",&opc);

        if(opc == 's')
        {
            ll_remove(pArrayListEmployee,indice);
        }
        todoOk=1;
    }
    else
    {
        printf("\nIngrese un ID valido... \n");
        system("pause");
    }

    return todoOk;


}

void mostrarEmplees(LinkedList* pArrayListEmployee){

    int opc;
    int num;
    system("cls");

    printf("   ***  LISTAR EMPLEADOS   *** \n\n");

    printf("1. Mostrar Todos los empleados\n");
    printf("2. Mostrar una cantidad de empleados\n\n");
    printf("Seleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&opc);

    if(opc == 2)
    {
        printf("\nNumero de empleados a mostrar: ");
        fflush(stdin);
        scanf("%d",&num);

        num=num-1;
        printf("\n  ID      NOMBRE    HORAS SUELDO\n\n");
        for(int i = 0; i <= num; i++)
        {
            mostrarEmployee((Employee*)ll_get(pArrayListEmployee,i));
        }
    }
    else
    {
        printf("\n ID       NOMBRE    HORAS  SUELDO");
        for(int i= 0; i<=(ll_len(pArrayListEmployee))-1; i++)
        {
            mostrarEmployee((Employee*)ll_get(pArrayListEmployee,i));
        }
    }

}


/** \brief MENU DE MODIFICACIONES
 *
 * \param LinkedList* pArrayListEmployee
 * \param int INDICE
 * \return retorna VOID
 *
 */
void menuDeModificaciones(LinkedList* pArrayListEmployee,int indice)
{
    int opcion;
    int todoOk=0;

    printf("1.Modificar Horas trabajadas\n");
    printf("2.Modificar Sueldo \n");
    printf("\nSeleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        todoOk = modificarHorasTrabajadas(pArrayListEmployee,indice);
        if(todoOk==1)
        {
            printf("\nModificacion exitosa\n");
            system("pause");
        }
        else
        {
            printf("No se pudo realizar la modificacion... \n");
        }
        break;
    case 2:
        todoOk = modificarSueldo(pArrayListEmployee,indice);
        if(todoOk==1)
        {
            printf("\nModificacion exitosa\n");
            system("pause");

        }
        else
        {
            printf("No se pudo actualizar correctamente");
        }
        break;
    default:
        printf("\tOpcion incorrecta\n");
        break;
    }

}

/** \brief MODIFICA LAS HORAS TRABAJAS
 *
 * \param LinkedList* pArrayListEmployee
 * \param int indice
 * \return RETORNA 1 si se pudo modificar correctamente, sino devuelve 0
 *
 */
int modificarHorasTrabajadas(LinkedList* pArrayListEmployee, int indice)
{

    int horasAux;
    int todoOk=0;
    Employee* emp;

    emp = ll_get(pArrayListEmployee,indice);

    printf("\n\n *** MODIFICAR HORAS ***\n");
    printf("\n Horas trabajadas:  ");
    fflush(stdin);
    scanf("%d",&horasAux);

    if(horasAux > 0)
    {
        emp->horasTrabajadas=horasAux;
        todoOk=1;
    }
    else
    {
        printf("No se pudo modificar las horas...");
    }



    return todoOk;

}


/** \brief MODIFICA EL SUELDO
 *
 * \param LinkedList* pArrayListEmployee
 * \param int indice
 * \return RETORNA 1 si se pudo moficiar correctamente, sino devuelve  0
 *
 */
int modificarSueldo(LinkedList* pArrayListEmployee, int indice)
{

    int sueldoAux;
    int todoOk=0;
    Employee* emp;

    emp = ll_get(pArrayListEmployee,indice);

    printf("\n  ***  MODIFICAR SUELDO  *** \n");
    printf("\n Sueldo nuevo: ");
    fflush(stdin);
    scanf("%d",&sueldoAux);

    if(sueldoAux > 0)
    {
        emp->sueldo=sueldoAux;
        todoOk=1;
    }
    else
    {
        printf("No se pudo modificar el sueldo ... ");
    }



    return todoOk;

}

/** \brief BUSCA EL ID
 *
 * \param LinkedList* pArrayListEmployee
 * \param int IDAUX
 * \return RETORNA EL INDICE del empleado si todo salio bien, sino devuelve -1
 *
 */
int searchId(LinkedList* pArrayListEmployee,int idAux){

    Employee* empAux;
    int indice = -1;

    for(int i=0;i<ll_len(pArrayListEmployee);i++){
        empAux = ll_get(pArrayListEmployee,i);
        if(empAux->id == idAux){
            indice=i;
        }
    }

    return indice;

}

/** \brief INCREMETA EL ID Y BUSCA QUE NO ESTE REPETIDO
 *
 * \param LinkedList* pArrayListEmployee
 * \param int DESDE
 * \return RETORNA EL ID CREADO
 *
 */
int incremetarID(LinkedList* pArrayListEmployee,int desde){

    int idAnterior=desde;
    int x;

    x=searchId(pArrayListEmployee,idAnterior);

    while(x!=-1){
        idAnterior+=1;
        x=searchId(pArrayListEmployee,idAnterior);
    }

    return idAnterior;


}



