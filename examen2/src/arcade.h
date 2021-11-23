
#include "LinkedList.h"

typedef struct
{
	int id;
	char nacionalidad[120];
	int sonido; // 1. mono 2. estereo
	int jugadoresCant;
	int fichasMax;
	char salon[120];
	char juego[120];
}Arcade;


#ifndef ARCADE_H_
#define ARCADE_H_

Arcade* buscarPorId(LinkedList* lista, int idIngresado);
Arcade* arcadeDatosP(int id, char* nacionalidad, int sonido, int jugadoresCant, int fichasMax, char* salon, char* juego);
void arcadeDelete(Arcade* this);
Arcade* newArcade();
int setId(Arcade* this, int id);
int getId(Arcade* this, int *id);
int setNacionalidad(Arcade* this,char* nacionalidad);
int getNacionalidad(Arcade* this,char* nacionalidad);
int setSonido(Arcade* this, int tipo);
int getSonido(Arcade* this, int* tipo);
int setJugadores(Arcade* this, int jugadores);
int getJugadores(Arcade* this, int* jugadores);
int setFichas(Arcade* this, int fichas);
int getFichas(Arcade* this, int* fichas);
int setSalonNombre(Arcade* this, char* salonN);
int getSalonNombre(Arcade* this, char* salonN);
int setJuego(Arcade* this, char* juego);
int getJuego(Arcade* this, char* juego);

#endif /* ARCADE_H_ */
