#include "funciones.h"
#include "Biblioteca.h"
#include "arcade.h"
#include "wchar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int actualizarFichas(LinkedList* lista){
	int retorno = -1;
	if(lista!=NULL){
		ll_map(lista, duplicarFichas);
		escribirArchivo(lista, "arcades.csv");
		retorno = 0;
	}
	return retorno;
}

void duplicarFichas(void* elemento){
	if(elemento != NULL){
		((Arcade*)elemento)->fichasMax = ((Arcade*)elemento)->fichasMax * 2;
	}
}

int ll_map(LinkedList* lista, void (*pFunc)(void*)){
	int retorno = -1;
	void* aux;
	if(lista != NULL && pFunc != NULL){
		for(int i = 0; i< ll_len(lista); i++){
			aux = ll_get(lista, i);
			if(aux != NULL){
				pFunc(aux);
			}
		}
		retorno=0;
	}

	return retorno;
}

int multijugador(LinkedList* lista){
	int retorno = -1;
	LinkedList* listaClone=NULL;
	if(lista!=NULL){
		listaClone = ll_clone(lista);
		if(ll_filter(listaClone, filtroJuego)==0){
			escribirArchivo(listaClone, "multijugador.csv");
		}
	}
	return retorno;
}

int filtroJuego(void* elemento){
	int retorno = 1;
	Arcade* aux = elemento;
	if(aux->jugadoresCant==1){
		retorno = 0;
	}
	return retorno;
}

int ll_filter(LinkedList* listaC, int (*pFunc)(void*)){
	int retorno=-1;
	int criterio;
	void* pAuxiliar;
	if(listaC != NULL && pFunc != NULL){
		for(int i=ll_len(listaC)-1; i >= 0; i--){
			pAuxiliar = ll_get(listaC, i);
			if(pAuxiliar != NULL){
				criterio = pFunc(pAuxiliar);
				if(criterio == 0){
					retorno = ll_remove(listaC, i);
				}
			}
		}

	}

	return retorno;
}

int juegoSinRepetir(LinkedList* lista){
	int retorno = -1;
	LinkedList* listaClone = NULL;

	Arcade* elementoAux1;
	Arcade* elementoAux2;
	if(lista != NULL){
		listaClone = ll_clone(lista);
		for(int i = 0; i<ll_len(listaClone);i++){
			for(int j = 0; j<ll_len(listaClone);j++){
				elementoAux1 = ll_get(listaClone, i);
				elementoAux2 = ll_get(listaClone, j);
				if(i!=j){
					if(strcmp(elementoAux1->juego,elementoAux2->juego)==0){
						ll_remove(listaClone, j);
					}
				}
			}
		}
	 	FILE* f = fopen("juegos.txt","w");
	 	Arcade* aux;
		if(f!=NULL){
			for(int i=0; i<ll_len(listaClone); i++){
				aux = ll_get(listaClone,i);
				fprintf(f,"%s\n",aux->juego);
			}
			fclose(f);
			retorno = 0;
		}
		ll_clear(listaClone);
	}
	return retorno;
}

int comparaJuego(void* juego1,void* juego2){
	if(((Arcade*)juego1)->juego[0] > ((Arcade*)juego2)->juego[0]){
		return 1;
	}
	if(((Arcade*)juego1)->juego[0] <((Arcade*)juego2)->juego[0]){
		return -1;
	}
	return 0;
}

int bajaArcade(LinkedList* lista){
	Arcade* aux= NULL;
	int confirmar;
	int retorno = -1;
	int idIngresado;
	utn_getInt(&idIngresado, "\nIngresar id a eliminar\n", "\nError", 1, 9999, 5);
	aux = buscarPorId(lista, idIngresado);
	if(lista != NULL && aux!=NULL){
		for(int i = 0 ; i < ll_len(lista);i++){
			if(aux == ll_get(lista, i)){
				utn_getInt(&confirmar, "\nEsta seguro de eliminar?\n1.Si o 2.No\n", "\nError", 1, 2, 5);
				if(confirmar == 1){
					ll_remove(lista, i);
					free(aux);
					printf("\nSe elimino correctamente\n");
					escribirArchivo(lista,"arcades.csv");
				}else{
					printf("\nSe mantuvo el arcade");
				}
				break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

void mostrarJuegos(LinkedList* lista){
	Arcade* aux = NULL;
	if(lista != NULL){
		for(int i = 0; i < ll_len(lista);i++){
			aux =ll_get(lista, i);
			printf("\n%s", aux->juego);
		}
	}
}
int modificarOpcion(LinkedList* lista){
	int retorno = -1;
	int opcion;
	int opcion2;
	int jugadoresAux;
	char juegoAux[120];
	Arcade* aux = NULL;
	utn_getInt(&opcion, "\nIngresar id a modificar\n", "\nError", 1, 9999, 5);
	aux = buscarPorId(lista, opcion);
	if(aux!=NULL){
		utn_getInt(&opcion2, "\nIngresar opcion a modificar\n1_Cantidad de jugadores\n2_Juego\n", "\nError", 1, 2, 5);
		switch (opcion2) {
			case 1:
				if(utn_getInt(&jugadoresAux, "\nIngresar jugadores", "\nError", 1, 999, 5)==0){
					setJugadores(aux, jugadoresAux);
				}
				break;
			case 2:
				mostrarJuegos(lista);
				if(utn_getChar(juegoAux, "\nIngresar juego", "\nError", 120, 5)==0){
					setJuego(aux, juegoAux);
				}
				break;
		}
		escribirArchivo(lista,"arcades.csv");
	}
	return retorno;
}

int escribirArchivo(LinkedList* lista,char* path){
	int retorno = -1;
 	FILE* f = fopen(path,"w");
 	Arcade* aux;
	if(f!=NULL && lista!=NULL){
		fprintf(f,"id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");
		for(int i=0; i<ll_len(lista); i++){
			aux = ll_get(lista,i);
			if(aux->sonido==1){
				fprintf(f,"%d,%s,MONO,%d,%d,%s,%s\n",aux->id,aux->nacionalidad,aux->jugadoresCant,aux->fichasMax,aux->salon,aux->juego);
			}else{
				fprintf(f,"%d,%s,STEREO,%d,%d,%s,%s\n",aux->id,aux->nacionalidad,aux->jugadoresCant,aux->fichasMax,aux->salon,aux->juego);
			}
			//arcadeDelete(aux);
		}
		fclose(f);
		retorno = 0;
	}
	ll_clear(lista);
	return retorno;
}

int leerArchivo(LinkedList* lista){
	char tipoSonidoaux[10]={"MONO"};
	char idAux[10];
	char nacionalidad[120];
	char tipoSonido[10];
	char cantJugadores[10];
	char fichasMax[10];
	char salon[120];
	char juego[120];
	int retorno = -1;
	Arcade* aux;
	if(lista !=NULL){
		FILE* f = fopen("arcades.csv","r");
		if(f!=NULL){
			fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nacionalidad,tipoSonido,cantJugadores,fichasMax,salon,juego);
			do{
				if(fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nacionalidad,tipoSonido,cantJugadores,fichasMax,salon,juego)==7){
					if(strcmp(tipoSonido,tipoSonidoaux)==0){
						aux = arcadeDatosP(atoi(idAux), nacionalidad, 1, atoi(cantJugadores), atoi(fichasMax), salon, juego);
					}else{
						aux = arcadeDatosP(atoi(idAux), nacionalidad, 2, atoi(cantJugadores), atoi(fichasMax), salon, juego);
					}
					if(aux!=NULL){
						ll_add(lista, aux);
					}
				}
			}while(feof(f)==0);
			fclose(f);
			retorno = 0;
		}

	}
	return retorno;
}

void mostrarLista(LinkedList* lista){
	int id;
	char nacionalidad[120];
	int sonido;
	int jugadoresCant;
	int fichasMax;
	char salon[120];
	char juego[120];
	if(lista != NULL){
		for(int i = 0 ; i < ll_len(lista);i++){
			getId(ll_get(lista, i), &id);
			getNacionalidad(ll_get(lista, i), nacionalidad);
			getSonido(ll_get(lista, i), &sonido);
			getJugadores(ll_get(lista, i), &jugadoresCant);
			getFichas(ll_get(lista, i), &fichasMax);
			getSalonNombre(ll_get(lista, i), salon);
			getJuego(ll_get(lista, i), juego);
			printf("\nId:|%d| Nacionalidad:|%s| jugadores:|%d| fichas:|%d| nombre del salon:|%s| juego|%s|", id, nacionalidad, jugadoresCant, fichasMax, salon, juego);
			if(sonido == 1){
				printf("sonido:|MONO|");
			}else{
				printf("sonido:|STEREO|");
			}

		}
	}
}

int incorporarArcade(LinkedList* lista){
	int retorno = -1;
	if(lista != NULL){
		int id;
		char nacionalidad[120];
		int sonido;
		int jugadoresCant;
		int fichasMax;
		char salon[120];
		char juego[120];
		id = autoId(lista);
		if(utn_getChar(nacionalidad, "\nIngresar Nacionalidad\n", "\nError", 120, 5) == 0){
			if(utn_getInt(&sonido, "\nIngresar\n1.Mono\n2.Estereo\n", "\nError", 1, 2, 5)==0){
				if(utn_getInt(&jugadoresCant, "\nIngresar cantidad de jugadores\n", "\nError", 1, 999, 5)==0){
					if(utn_getInt(&fichasMax, "\nIngresar cantidad de fichas\n", "\nError", 1, 999, 5)==0){
						if(utn_getChar(salon, "\nIngresar nombre del salon\n", "\nError", 120, 5)==0){
							if(utn_getChar(juego, "\nIngresar nombre del juego\n", "\nError", 120, 5)==0){
								ll_add(lista, arcadeDatosP(id, nacionalidad, sonido, jugadoresCant, fichasMax, salon, juego));
								escribirArchivo(lista,"arcades.csv");
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}
	return retorno;
}


int autoId(LinkedList* Lthis){
	int idAux;
	int idMayor=0;
	if(Lthis != NULL){
		for(int i = 0; i< ll_len(Lthis);i++){
			getId(ll_get(Lthis, i), &idAux);
			if(idMayor<idAux){
				idMayor = idAux;
			}
		}
	}
	return idMayor+1;
}
