#include "LinkedList.h"


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/** \brief  se pide al ususario datos del arcade
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int incorporarArcade(LinkedList* lista);

/** \brief  busca el id mas grande y lo devuelve
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int autoId(LinkedList* Lthis);

/** \brief  Imprime todos los arcades y sus datos
 *
 * \param lista LinkedList*
 * \return void
 *
 */
void mostrarLista(LinkedList* lista);

/** \brief carga los datos del archivo
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int leerArchivo(LinkedList* lista);

/** \brief Se guarda una lista en el archivo
 *
 * \param lista LinkedList*
 * \param char* path
 * \return int
 *
 */
int escribirArchivo(LinkedList* lista,char* path);
/** \brief se modifica un elemento
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int modificarOpcion(LinkedList* lista);
/** \brief  muestra todos los juegos de la lista(repetido)
 *
 * \param lista LinkedList*
 * \return int
 *
 */
void mostrarJuegos(LinkedList* lista);
/** \brief  se elimina un elemento
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int bajaArcade(LinkedList* lista);
/** \brief  funcion para comprobar el orden de los juegos
 *
 * \param juego1 void*
 * \param juego2 void*
 * \return int
 *
 */
int comparaJuego(void* juego1,void* juego2);
/** \brief  se guarda todos los juegos en un archivo (sin repetir)
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int juegoSinRepetir(LinkedList* lista);
/** \brief elimina de una lista los nodos que cumplen con el requisito de borrar
 *
 * \param this LinkedList*
 * \param (*pFunc)(void*) int
 * \return int
 *
 */
int ll_filter(LinkedList* this, int (*pFunc)(void*));
/** \brief se comprueba si el elemento cumple para ser eliminado
 *
 * \param elemento void*
 * \return int
 *
 */
int filtroJuego(void* elemento);
/** \brief crea una lista clon para filtrar y guardar en un archivo
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int multijugador(LinkedList* lista);
/** \brief  recorre toda la lista para pasar elementos a una funcion
 *
 * \param this LinkedList*
 * \param (*pFunc)(void*) void
 * \return int
 *
 */
int ll_map(LinkedList* this, void (*pFunc)(void*));
/** \brief recibe un elemento para duplicar las fichas
 *
 * \param elemento void*
 * \return void
 *
 */
void duplicarFichas(void* elemento);
/** \brief llama a la funcion ll_map para duplicar las fichas y despues los guarda en el archivo
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int actualizarFichas(LinkedList* lista);
#endif /* FUNCIONES_H_ */
