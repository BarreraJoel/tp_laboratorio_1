#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/**
 * @brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param pFile Puntero al archivo con datos de pasajeros
 * @param pArrayListPassenger LinkedList donde se van a almacenar los datos cargados
 * @return Retorna -1 [Punteros NULL o Lectura no completada] 1 [OK]
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAuxTexto = NULL;
	char auxId[10];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[50];
	char auxCodigoVuelo[50];
	char auxTipoPasajero[50];
	char auxEstadoVuelo[50];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAuxTexto = Passenger_new();
		if(pAuxTexto != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);

			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo) == 7)
				{
					pAuxTexto = Passenger_newParametros(auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo);
					if(pAuxTexto != NULL)
					{
						ll_add(pArrayListPassenger, pAuxTexto);
					}
				}
				else
				{
					break;
				}
			}while(!feof(pFile));
			retorno = 1;
		}
	}
	free(pAuxTexto);

    return retorno;
}

/**
 * @brief Parsea los datos los datos de los pasajeros desde el archivo dataDos.bin (modo binario).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (binario)
 * @param pArrayListPassenger LinkedList donde se van a almacenar los datos cargados
 * @return Retorna -1 [Punteros NULL] 1 [OK]
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAuxBinario = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAuxBinario = Passenger_new();
		if(pAuxBinario != NULL)
		{
			do
			{
				if(fread(pAuxBinario,sizeof(Passenger),1,pFile) == 1)
				{
					ll_add(pArrayListPassenger, pAuxBinario);
				}
			}while(!feof(pFile));
			retorno = 1;
		}
	}
	free(pAuxBinario);

    return retorno;
}

/**
 * @brief Escribe los datos de los pasajeros en el archivo dataDos.csv (modo texto).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (modo texto)
 * @param pArrayListPassenger LinkedList de donde salen los datos a escribir en el archivo
 * @return Retorna -1 [Punteros NULL] 1 [OK] 0 [Escritura no completada]
 */
int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAux = NULL;
	int i;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int tipoPasajero;
	char auxTipoPasajero[20];
	char auxCodigoVuelo[10];
	char auxEstadoVuelo[10];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAux = Passenger_new();
		if(pAux != NULL)
		{
			retorno = 1;

			fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

			for(i = 0; i < ll_len(pArrayListPassenger);i++)
			{
				pAux = ll_get(pArrayListPassenger, i);
				if(pAux != NULL)
				{
					if( Passenger_getId(pAux, &auxId) == 0 &&
						Passenger_getNombre(pAux, auxNombre) == 0 &&
						Passenger_getApellido(pAux, auxApellido) == 0 &&
						Passenger_getPrecio(pAux, &auxPrecio) == 0 &&
						Passenger_getCodigoVuelo(pAux, auxCodigoVuelo) == 0 &&
						Passenger_getTipoPasajero(pAux, &tipoPasajero) == 0 &&
						Passenger_getEstadoVuelo(pAux, auxEstadoVuelo) == 0)
					{
						Passenger_tipoPasajeroATexto(tipoPasajero,auxTipoPasajero);

						if(fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajero,auxEstadoVuelo) < 7)
						{
							retorno = 0;
							break;
						}
					}
				}
			}
		}
	}
	free(pAux);

	return retorno;
}

/**
 * @brief Escribe los datos de los pasajeros en el archivo dataDos.bin (modo binario).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (modo binario)
 * @param pArrayListPassenger LinkedList de donde salen los datos a escribir en el archivo
 * @return Retorna -1 [Punteros NULL o Escritura no completada] 1 [OK] 0 [No se pudo escribir]
 */
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAux = NULL;
	int i;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAux = Passenger_new();
		if(pAux != NULL)
		{
			retorno = 1;
			for(i = 0; i < ll_len(pArrayListPassenger);i++)
			{
				pAux = ll_get(pArrayListPassenger, i);
				if(pAux != NULL)
				{
					 if(fwrite(pAux,sizeof(Passenger),1,pFile) != 1)
					 {
						 Passenger_delete(pAux);
						 retorno = 0;
						 break;
					 }
				}
			}
		}
	}
	free(pAux);

	return retorno;
}



