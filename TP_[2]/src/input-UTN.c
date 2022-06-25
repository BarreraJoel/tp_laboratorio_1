/*
 * utn.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include "input-UTN.h"

/**
 * @brief Verifica que los caracteres sean numericos
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Caracter no numerico] - 1 [OK]
 */
static int esNumero(char* cadena, int largo);
/**
 * @brief Obtiene una cadena de caracteres
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
static int getString(char* cadena, int largo);
/**
 * @brief Obtiene y verifica si se ingresaron numeros enteros
 *
 * @param pResultado Puntero a int donde se guarda el resultado
 * @return Retorna -1 [Puntero NULL] - 1 [OK]
 */
static int getInt(int* pResultado);

/**
 * @brief Verifica si lo ingresado es un numero decimal
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Caracter no numerico] - 1 [OK]
 */
static int esNumeroFlotante(char* cadena, int largo);

/**
 * @brief Obtiene y verifica si se ingresaron numeros decimales
 *
 * @param pResultado Puntero a float donde se guarda el resultado
 * @return Retorna -1 [Puntero NULL] - 1 [OK]
 */
static int getFloat(float* pResultado);

/**
 * @brief Verifica si lo ingresado son letras
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Caracter no valido] - 1 [OK]
 */
static int esAlfabetico(char* cadena, int largo);

/**
 * @brief Obtiene y verifica si se ingresaron caracteres alfabeticos
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
static int getNombre(char* cadena, int largo);

/**
 * @brief Verifica si lo ingresado es alfanumerico
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Caracter no alfanumerico] - 1 [OK]
 */
static int esAlfanumerico(char* cadena, int largo);

/**
 * @brief Obtiene y verifica si se ingreso una calle
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
static int getCalle(char* cadena, int largo);

/**
 * @brief Verifica si lo ingresado son numeros
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Caracteres no numericos] - 1 [OK]
 */
static int esTelefono(char* cadena, int largo);

/**
 * @brief Obtiene y verifica si se ingreso un telefono
 *
 * @param cadena Puntero a un array de caracteres
 * @param largo Largo del array
 * @return Retorna -1 [Puntero NULL - Largo no valido] - 1 [OK]
 */
static int getTelefono(char* cadena, int largo);


static int esNumero(char* cadena, int largo)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && largo > 0)
	{
		while((*(cadena+i)) != '\0')
		{
			if((*(cadena+i)) < '0' || (*(cadena+i)) > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int getString(char* cadena, int largo)
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
		if(getString(buffer,sizeof(buffer)) == 1 && esNumero(buffer,sizeof(buffer)) == 1)
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

static int esNumeroFlotante(char* cadena, int largo)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && largo > 0)
	{
		while((*(cadena+i)) != '\0')
		{
			if(((*(cadena+i)) < '0' || (*(cadena+i)) > '9') && (*(cadena+i)) != '.')
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
		if(getString(buffer,sizeof(buffer)) == 1 && esNumeroFlotante(buffer,sizeof(buffer)) == 1)
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
			fflush(stdin);
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
	fflush(stdin);
	return retorno;
}

static int esAlfanumerico(char* cadena, int largo)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && largo > 0)
	{
		while((*(cadena+i)) != '\0')
		{
			if(!((*(cadena+i)) >= '0' && (*(cadena+i)) <= '9') && ((*(cadena+i)) >= 'A' && (*(cadena+i)) <= 'Z') && ((*(cadena+i)) >= 'a' && (*(cadena+i)) <= 'z'))
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int esAlfabetico(char* cadena, int largo)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && largo > 0)
	{
		while((*(cadena+i)) != '\0')
		{
			if(((*(cadena+i)) < 'A' || (*(cadena+i)) > 'Z') && ((*(cadena+i)) < 'a' || (*(cadena+i)) > 'z'))
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getTexto(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getString(cadena, maximo) == 1)
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

static int getNombre(char* cadena, int largo)
{
	int retorno = -1;

	if(cadena != NULL && largo > 0)
	{
		if(getString(cadena, largo) == 1 && esAlfabetico(cadena, largo) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getNombre(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int i = 1;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getNombre(cadena, maximo) == 1)
			{
				if(strlen(cadena) >= minimo && strlen(cadena) <= maximo)
				{
					if(islower((*(cadena+0))) != 0)
					{
						(*(cadena+0)) = toupper((*(cadena+0)));
					}
					while(i < strlen(cadena))
					{
						if(isupper((*(cadena+i))) != 0)
						{
							(*(cadena+i)) = tolower((*(cadena+i)));
						}
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

static int getCalle(char* cadena, int largo)
{
	int retorno = -1;

	if(cadena != NULL && largo > 0)
	{
		if(getString(cadena, largo) == 1 && esAlfanumerico(cadena, largo) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getCalle(char* cadena, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int i = 1;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getCalle(cadena, maximo) == 1)
			{
				if(strlen(cadena) >= minimo && strlen(cadena) <= maximo)
				{
					if(islower((*(cadena+0))) != 0)
					{
						(*(cadena+0)) = toupper((*(cadena+0)));
					}
					while(i < strlen(cadena))
					{
						if(islower((*(cadena+i))) != 0 && (*(cadena+i-1)) == ' ')
						{
							(*(cadena+i)) = toupper((*(cadena+i)));
						}
						else
						{
							(*(cadena+i)) = tolower((*(cadena+i)));
						}
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

static int esTelefono(char* cadena, int largo)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && largo > 0)
	{
		while((*(cadena+i)) != '\0')
		{
			if(!((*(cadena+i)) >= '0' && (*(cadena+i)) <= '9') && (*(cadena+i)) == '-')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

static int getTelefono(char* cadena, int largo)
{
	int retorno = -1;

	if(cadena != NULL && largo > 0)
	{
		if(getString(cadena, largo) == 1 && esTelefono(cadena, largo) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int utn_getTelefono(char* cadena, int limite, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char aux;

	if(cadena != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf(mensaje);
			if(getTelefono(cadena,limite) == 1)
			{
				if(strlen(cadena) <= limite)
				{
					retorno = 1;
				}
			}
			printf(mensajeError);
			reintentos--;
		}while(reintentos > 0);
	}
	return retorno;
}





