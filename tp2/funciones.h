#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;

}eEmpleado;


#endif // FUNCIONES_H_INCLUDED


int menuOpciones();
/** \brief es el menu principal de opciones
 * \return int retorna la opcion ingresada para luego evaluarla en posteriores condiciones
 *
 */

int altaPersona(eEmpleado gente[], int tam, int id);
/** \brief da de alta un elemento dentro de la estructura eEmpleado
 *
 * \param eEmpleado array
 * \param int el tamaño predefinido
 * \param int id predefinido como 20000 y creciente
 * \return int devuelve 1 si no pudo realizarse o 0 si no hubo ningun error
 *
 */

int buscarLibre(eEmpleado gente[], int tam);
/** \brief busca el primer lugar en el array que se encuentra disponible para escribir sobre el, complemento de la funcion altaPersona
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int retorna el indice en el array del primer elemento que tiene el parametro isEmpty seteado en 1
 *
 */
int inicializarPersonas(eEmpleado gente[], int tam);
/** \brief setea los parametros isEmpty en 1 y sueldo en 0
 *
 * \param unaPersona eEmpleado
 * \return int retorna 1 si hubo algun error en el proceso o 0 si pudo settear todo bien
 *
 */
void mostrarEmpleado(eEmpleado unaPersona);
/** \brief muestra un solo elemento
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return void
 *
 */
int mostrarEmpleados(eEmpleado gente[], int tam);
/** \brief muesta todos los elementos del array que se encuentrne con el valor isEmpty seteado en 0, es decir con datos cargados
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return
 *
 */
int ordenarEmpleadosApellido(eEmpleado gente[], int tam);
/** \brief ordena por orden descendente del parametro .apellido a los elementos del array
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int retorna 1 si hubo algun error, 0 si pudo completarse
 *
 */
int ordenarEmpleadosSector(eEmpleado gente[], int tam);
/** \brief ordena de manera descendente los elementos del array evaluando el valor .sector
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int retorna 1 si hubo algun error, 0 si pudo completar
 *
 */
int sumaSalarios(eEmpleado gente[], int tam);
/** \brief suma los salarios de los elementos cargados en el array y saca su promedio
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int retorna 1 si hubo algun error, 0 si pudo completarse
 *
 */
int bajaEmpleado(eEmpleado gente[], int tam);
/** \brief cambia el valor del parametro isEmpty de 0 a 1 para no hacer una baja logica del elemento en el array
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int retorna 1 si hubo algun error, 0 si pudo completar la baja logica, 2 si se cancelo la baja logica por el usuario
 *
 */
int buscarEmpleado(eEmpleado gente[], int tam, int id);
/** \brief busca un elemento del array por su numero de legajo / id mientras su valor de isEmpty sea 0
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int devuelve -1 si hubo algun error, o el valor del indice del array correspondiente al buscado si pudo completar
 *
 */
int modificarEmpleado(eEmpleado gente[], int tam);
/** \brief  permite modificar un valor del elemento seleccionado manualmente
 *
 * \param gente[] eEmpleado
 * \param tam int
 * \return int retorna 1 si hubo algun error, 0 si pudo completar la modificacion, 2 si se cancelo la modificacion por el usuario
 *
 */



