/*
 * utn.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include "utn.h"

static int esNumero(char cadena[]);
static int getString(char cadena[], int largo);
static int getInt(int* pResultado);

static int esNumeroFlotante(char cadena[]);
static int getFloat(float* pResultado);

static int esAlfanumerico(char cadena[]);
static int esAlfabetico(char cadena[]);


static int esNumero(char cadena[])
{
	int retorno = 1;
	int i = 0;

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

static int getString(char cadena[], int largo)
{
	int retorno = -1;

	if(cadena != NULL && largo > 0 && fgets(cadena,largo,stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(getString(buffer,sizeof(buffer)) == 1 && esNumero(buffer) == 1)
		{
			*pResultado = atoi(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getInt(&bufferInt) == 1)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 1;
					break;
				}
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}
	return retorno;
}

static int esNumeroFlotante(char cadena[])
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}

	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(getString(buffer,sizeof(buffer)) == 1 && esNumeroFlotante(buffer) == 1)
		{
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getFloat(&bufferFloat) == 1)
			{
				if(bufferFloat <= maximo && bufferFloat >= minimo)
				{
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				}
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}

	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			scanf("%c", &buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 1;
				break;
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}

	return retorno;
}

static int esAlfanumerico(char cadena[])
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}


static int esAlfabetico(char cadena[])
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getTexto(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getString(cadena, maximo) == 1 && esAlfanumerico(cadena) == 1)
			{
				if(strlen(cadena) >= minimo && strlen(cadena) <= maximo)
				{
					retorno = 1;
					break;
				}
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}

	return retorno;
}

int utn_getNombre(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int i = 1;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getString(cadena, maximo) == 1 && esAlfabetico(cadena) == 1)
			{
				if(strlen(cadena) >= minimo && strlen(cadena) <= maximo)
				{
					if(islower(cadena[0]) != 0)
					{
						cadena[0] = toupper(cadena[0]);
					}
					while(isupper(cadena[i]) != 0 || i < strlen(cadena))
					{
						cadena[i] = tolower(cadena[i]);
						i++;
					}
					retorno = 1;
					break;
				}
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}

	return retorno;
}







