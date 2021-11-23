#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Arcade* buscarPorId(LinkedList* lista, int idIngresado){
	Arcade* aux = NULL;
	if(lista!=NULL && idIngresado > 0){
		for(int i = 0 ; i < ll_len(lista);i++){
			aux =ll_get(lista, i);
			if(aux->id == idIngresado){
				break;
			}else{
				aux = NULL;
			}
		}
	}
	return aux;
}

Arcade* arcadeDatosP(int id, char* nacionalidad, int sonido, int jugadoresCant, int fichasMax, char* salon, char* juego){
	Arcade* arcade = NULL;
	if(id>0 && nacionalidad != NULL && (sonido == 1 || sonido == 2) && jugadoresCant >0 && fichasMax > 0 && salon != NULL && juego != NULL){
		arcade = newArcade();
		if(setId(arcade, id)==0 && setNacionalidad(arcade, nacionalidad)==0 && setSonido(arcade, sonido)==0 && setJugadores(arcade, jugadoresCant)==0 && setFichas(arcade, fichasMax)==0 && setSalonNombre(arcade, salon)==0 && setJuego(arcade, juego)==0){
			printf("\nSe ingreso los datos correctamente");
		}else{
			printf("\nError en los datos ingresador");
			arcadeDelete(arcade);
		}
	}
	return arcade;
}

void arcadeDelete(Arcade* this){
	if(this != NULL){
		free(this);
		this=NULL;
	}
}


Arcade* newArcade(){
	Arcade* arcade = (Arcade*)malloc(sizeof(Arcade));
	return arcade;
}


int setId(Arcade* this, int id){
	int retorno = -1;
	if(this != NULL && id > 0){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int getId(Arcade* this, int *id){
	int retorno = -1;
	if(this != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int setNacionalidad(Arcade* this,char* nacionalidad){
	int retorno = -1;
	if(this != NULL && nacionalidad !=NULL){
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}
	return retorno;
}
int getNacionalidad(Arcade* this,char* nacionalidad){
	int retorno = -1;
	if(this != NULL){
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}
int setSonido(Arcade* this, int tipo){
	int retorno = -1;
	if(this != NULL && (tipo == 1 || tipo == 2)){
		this->sonido = tipo;
		retorno = 0;
	}
	return retorno;
}
int getSonido(Arcade* this, int* tipo){
	int retorno = -1;
	if(this != NULL){
		*tipo = this->sonido;
		retorno = 0;
	}
	return retorno;
}
int setJugadores(Arcade* this, int jugadores){
	int retorno = -1;
	if(this !=NULL && jugadores > 0){
		this->jugadoresCant = jugadores;
		retorno = 0;
	}
	return retorno;
}
int getJugadores(Arcade* this, int* jugadores){
	int retorno = -1;
	if(this != NULL){
		*jugadores = this->jugadoresCant;
		retorno = 0;
	}
	return retorno;
}
int setFichas(Arcade* this, int fichas){
	int retorno = -1;
	if(this != NULL && fichas >0){
		this->fichasMax = fichas;
		retorno = 0;
	}
	return retorno;
}
int getFichas(Arcade* this, int* fichas){
	int retorno = -1;
	if(this != NULL){
		*fichas = this->fichasMax;
		retorno = 0;
	}
	return retorno;
}
int setSalonNombre(Arcade* this, char* salonN){
	int retorno = -1;
	if(this != NULL && salonN != NULL){
		strcpy(this->salon, salonN );
		retorno = 0;
	}
	return retorno;
}
int getSalonNombre(Arcade* this, char* salonN){
	int retorno = -1;
	if(this != NULL){
		strcpy(salonN, this->salon);
		retorno = 0;
	}
	return retorno;
}
int setJuego(Arcade* this, char* juego){
	int retorno = -1;
	if(this != NULL && juego != NULL){
		strcpy(this->juego, juego);
		retorno = 0;
	}
	return retorno;
}
int getJuego(Arcade* this, char* juego){
	int retorno = -1;
	if(this != NULL){
		strcpy(juego, this->juego);
		retorno = 0;
	}
	return retorno;
}
