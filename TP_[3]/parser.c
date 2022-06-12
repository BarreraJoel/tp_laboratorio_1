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
	int cantEscaneada;
	char id[50],nombre[50],apellido[50],precio[50],codigoVuelo[50],tipoPasajero[50],estadoVuelo[50];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAuxTexto = Passenger_new();
		if(pAuxTexto != NULL)
		{
			cantEscaneada = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

			do
			{
				cantEscaneada = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(cantEscaneada == 7)
				{
					pAuxTexto = Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
					ll_add(pArrayListPassenger, pAuxTexto);
				}
				else
				{
					break;
				}
			}while(!feof(pFile));
			retorno = 1;
		}
		free(pAuxTexto);
	}

    return retorno;
}

/**
 * @brief Parsea los datos los datos de los pasajeros desde el archivo dataDos.bin (modo binario).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (binario)
 * @param pArrayListPassenger LinkedList donde se van a almacenar los datos cargados
 * @return Retorna -1 [Punteros NULL o Lectura no completada] 1 [OK]
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 1;
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
					printf("\n %d    %-15s %-10s     %.2f   %-10s  %-15d %s",pAuxBinario->id,pAuxBinario->nombre,pAuxBinario->apellido,pAuxBinario->precio,pAuxBinario->codigoVuelo,pAuxBinario->tipoPasajero,pAuxBinario->estadoVuelo);
					ll_add(pArrayListPassenger, pAuxBinario);
				}
				else
				{
					retorno = -1;
					break;
				}
			}while(!feof(pFile) && retorno == 1);
		}
		free(pAuxBinario);
	}

    return retorno;
}

/**
 * @brief Escribe los datos de los pasajeros en el archivo dataDos.csv (modo texto).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (modo texto)
 * @param pArrayListPassenger LinkedList de donde salen los datos a escribir en el archivo
 * @return Retorna -1 [Punteros NULL o Escritura no completada] 1 [OK]
 */
int parser_PassengerToText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	int cantEscrita;
	Passenger* pAux = NULL;
	int i;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char tipoPasajeroAux[20];
	char codigoVuelo[10];
	char estadoVuelo[10];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAux = Passenger_new();
		if(pAux != NULL)
		{
			for(i = 0; i < ll_len(pArrayListPassenger);i++)
			{
				pAux = ll_get(pArrayListPassenger, i);

				if(pAux != NULL)
				{
					Passenger_getId(pAux, &id);
					Passenger_getNombre(pAux, nombre);
					Passenger_getApellido(pAux, apellido);
					Passenger_getPrecio(pAux, &precio);
					Passenger_getCodigoVuelo(pAux, codigoVuelo);
					Passenger_getTipoPasajero(pAux, &tipoPasajero);
					Passenger_getEstadoVuelo(pAux, estadoVuelo);

					if(tipoPasajero == 1)
					{
						strcpy(tipoPasajeroAux,"FirstClass");
					}
					else if(tipoPasajero == 2)
					{
						strcpy(tipoPasajeroAux,"ExecutiveClass");
					}
					else
					{
						strcpy(tipoPasajeroAux,"EconomyClass");
					}

					cantEscrita = fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajeroAux,estadoVuelo);

					if(cantEscrita == 1)
					{
						retorno = 1;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
			}
		}
		free(pAux);
	}
	return retorno;
}


/**
 * @brief Escribe los datos de los pasajeros en el archivo dataDos.bin (modo binario).
 *
 * @param pFile Puntero al archivo con datos de pasajeros (modo binario)
 * @param pArrayListPassenger LinkedList de donde salen los datos a escribir en el archivo
 * @return Retorna -1 [Punteros NULL o Escritura no completada] 1 [OK]
 */
int parser_PassengerToBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAux = NULL;
	int limiteLista = ll_len(pArrayListPassenger);
	int i;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		pAux = Passenger_new();

		if(pAux != NULL)
		{
			for(i = 0; i < limiteLista;i++)
			{
				pAux = ll_get(pArrayListPassenger, i);
				if(pAux != NULL)
				{
					 if(fwrite(pAux,sizeof(Passenger),1,pFile) == 1)
					 {
						 retorno = 1;
					 }
					 else
					 {
						 break;
					 }
				}
			}
		}
		free(pAux);
	}
	return retorno;
}



