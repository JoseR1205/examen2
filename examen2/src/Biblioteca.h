
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getChar(char cadena[], char *mensaje, char *mensajeError, int len, int reintentos);
int esNumerica(char* cadena);
int myGets(char pResultado[], int len);
int esFloat(char numero[]);

#endif /* BIBLIOTECA_H_ */
