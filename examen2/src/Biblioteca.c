#include "biblioteca.h"




int utn_getChar(char cadena[], char *mensaje, char *mensajeError, int len, int reintentos){
	int retorno = -1;
	for(int i = 0 ; i < reintentos; i++){
		if(cadena!=NULL && mensaje != NULL && mensajeError != NULL && len > 0){
			printf("%s", mensaje);
			if(myGets(cadena, len)==0){
				retorno =0;
				break;
			}else{
				printf("%s",mensajeError);
			}
		}
	}
	return retorno;
}
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;
	int i;
	char bufferCadenaAux[20];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esFloat(bufferCadenaAux)==0)
				{
					bufferFloat = atof(bufferCadenaAux);

					if(bufferFloat >= minimo && bufferFloat <= maximo){
						*pResultado = bufferFloat;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}
int esFloat(char numero[]){
	int retorno = 0;
	int i=-1;
	if(numero != NULL && strlen(numero) > 0){
		while(numero[i] != '\0'){
			if(numero[i] == ','){
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int myGets(char pResultado[], int len){
	int retorno=-1;
	int indexFinal;
	if(fgets(pResultado,len,stdin)!=NULL)
	{
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n'){
			pResultado[indexFinal] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[50];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumerica(bufferCadenaAux)==0)
				{
					bufferInt = atoi(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int esNumerica(char cadena[])
{
	int i = 0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

