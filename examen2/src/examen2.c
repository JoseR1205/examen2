
#include "LinkedList.h"
#include "funciones.h"
#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Biblioteca.h"

int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaArcade = ll_newLinkedList();
	int archivo =0;
	int opcion=0;
	while(opcion<9){
		utn_getInt(&opcion, "\nIngresar opcion:\n1_LEER ARCADES DESDE ARCHIVO CSV\n2_INCORPORAR ARCADE\n3_MODIFICAR ARCADE\n4_ELIMINAR ARCADE\n5_IMPRIMIR ARCADES ordenados por nombre de juego\n6_Generar archivo con JUEGOS\n7_Generar un archivo con arcades “Multijugador”\n8_Actualizar cantidad de fichas\n9_Salir\n", "\nError\n", 1, 9, 5);
		switch(opcion){
				case 1:
					if(archivo == 0){
						leerArchivo(listaArcade);
						archivo =1;
					}else{
						printf("\nYa se cargo el archivo anteriormente\n");
					}
					break;
				case 2:
					if(archivo == 1){
						incorporarArcade(listaArcade);
						archivo = 0;
					}else{
						printf("\nIngresar el archivo antes\n");
					}

					break;
				case 3:
					if(archivo ==1){
						mostrarLista(listaArcade);
						modificarOpcion(listaArcade);
						archivo = 0;
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
				case 4:
					if(archivo ==1){
						mostrarLista(listaArcade);
						bajaArcade(listaArcade);
						archivo =0;
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
				case 5:
					if(archivo == 1){
						ll_sort(listaArcade, comparaJuego, 1);
						mostrarLista(listaArcade);
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
				case 6:
					if(archivo == 1){
						juegoSinRepetir(listaArcade);
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
				case 7:
					if(archivo == 1){
						multijugador(listaArcade);
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
				case 8:
					if(archivo == 1){
						actualizarFichas(listaArcade);
						archivo = 0;
					}else{
						printf("\nIngresar el archivo antes\n");
					}
					break;
			}
	}
	return 0;
}
