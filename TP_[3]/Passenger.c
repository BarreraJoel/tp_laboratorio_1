/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "input-UTN.h"
#include "LinkedList.h"

/**
 * @brief Busca los id minimo y mayor
 *
 * @param this Puntero a la LinkedList donde estan los pasajeros
 * @param idMinimo Puntero a int donde se guardara el id minimo
 * @param idMaximo Puntero a int donde se guardara el id maximo
 * @return Retorna (-1) Error: [Lista NULL o Punteros NULL]
 * 				   ( 1) OK
 */
int Passenger_obtenerIDMaximo(LinkedList* this,int* idMinimo,int* idMaximo)
{
	int i;
	int retorno = -1;
	int minimo;
	int maximo;
	int auxId;
	int banderaMinimo = 0;
	int banderaMaximo = 0;
	Passenger* pAux = NULL;

	if(this != NULL && idMinimo != NULL && idMaximo != NULL)
	{
		for(i = 0; i < ll_len(this); i++)
		{
			pAux = ll_get(this, i);
			if(pAux != NULL)
			{
				Passenger_getId(pAux, &auxId);
				if(auxId < minimo || banderaMinimo == 0)
				{
					minimo = auxId;
					banderaMinimo = 1;
				}
				if(auxId > maximo || banderaMaximo == 0)
				{
					maximo = auxId;
					banderaMaximo = 1;
				}
			}
		}
		*idMinimo = minimo;
		*idMaximo = maximo;
	}
	return retorno;
}

/**
 * @brief Imprime un pasajero de la LinkedList
 *
 * @param pElemento Puntero al elemento a imprimir
 */
void Passenger_imprimirUno(Passenger* pElemento)
{
	int auxId;
	char auxNombre[20];
	char auxApellido[20];
	float auxPrecio;
	int tipoPasajero;
	char auxTipoPasajeroStr[20];
	char auxCodigoVuelo[10];
	char auxEstadoVuelo[10];

	if(pElemento != NULL)
	{
		if( Passenger_getId(pElemento, &auxId) == 0 &&
			Passenger_getNombre(pElemento, auxNombre) == 0 &&
			Passenger_getApellido(pElemento, auxApellido) == 0 &&
			Passenger_getPrecio(pElemento, &auxPrecio) == 0 &&
			Passenger_getTipoPasajero(pElemento, &tipoPasajero) == 0 &&
			Passenger_getCodigoVuelo(pElemento, auxCodigoVuelo) == 0 &&
			Passenger_getEstadoVuelo(pElemento, auxEstadoVuelo) == 0)
		{
			Passenger_tipoPasajeroATexto(tipoPasajero, auxTipoPasajeroStr);
			printf("\n %-5d  %-16s  %-10s     %.2f   %-10s  %-15s %s",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajeroStr,auxEstadoVuelo);
		}
	}
}

/**
 * @brief Lista todos los pasajeros de la LinkedList
 *
 * @param pArrayListPassenger Puntero a la LinkedList donde estan los pasajeros
 * @return Retorna -1 [Puntero NULL o Largo no valido] 1 [OK]
 */
int Passenger_listarPasajeros(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pElemento = NULL;
	int i;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger) > 0)
	{
		printf("\n\n--------------------------------------------------------------------------------------------\n");
		printf("******************************** LISTADO DE PASAJEROS  *************************************");
		printf("\n--------------------------------------------------------------------------------------------\n");
		printf(" ID    NOMBRE            APELLIDO         PRECIO      CODIGO       TIPO           ESTADO ");
		printf("\n--------------------------------------------------------------------------------------------\n");
		for(i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			pElemento = ll_get(pArrayListPassenger, i);
			if(pElemento != NULL)
			{
				Passenger_imprimirUno(pElemento);
			}
		}
		retorno = 1;
	}

    return retorno;
}

/**
 * @brief Crea un pasajero y lo retorna
 *
 * @return Retorna Puntero a Passenger
 */
Passenger* Passenger_new()
{
	Passenger* pNuevoPassenger = NULL;

	pNuevoPassenger = (Passenger*)malloc(sizeof(Passenger));

	return pNuevoPassenger;
}

/**
 * @brief Crea un pasajero con los parametros recibidos y lo retorna
 *
 * @param idStr Cadena de caracteres donde se guarda un id
 * @param nombreStr Cadena de caracteres donde se guarda un nombre
 * @param apellidoStr Cadena de caracteres donde se guarda un apellido
 * @param precioStr Cadena de caracteres donde se guarda un precio
 * @param codigoVueloStr Cadena de caracteres donde se guarda un codigo de vuelo
 * @param tipoPasajeroStr Cadena de caracteres donde se guarda un tipo de pasajero
 * @param estadoVueloStr Cadena de caracteres donde se guarda un estado de vuelo
 * @return Retorna -1 [Punteros NULL] Puntero a Passenger [OK]
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr)
{
	Passenger* pNuevoPassenger = NULL;
	int auxTipoPasajero;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && codigoVueloStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL)
	{
		pNuevoPassenger = Passenger_new();

		if(pNuevoPassenger != NULL)
		{
			Passenger_tipoPasajeroANumero(tipoPasajeroStr, &auxTipoPasajero);

			if(	(Passenger_setId(pNuevoPassenger, atoi(idStr)) != 0) ||
				(Passenger_setNombre(pNuevoPassenger, nombreStr) != 0) ||
				(Passenger_setApellido(pNuevoPassenger, apellidoStr) != 0) ||
				(Passenger_setPrecio(pNuevoPassenger, atof(precioStr)) != 0) ||
				(Passenger_setCodigoVuelo(pNuevoPassenger, codigoVueloStr) != 0) ||
				(Passenger_setTipoPasajero(pNuevoPassenger, auxTipoPasajero) != 0) ||
				(Passenger_setEstadoVuelo(pNuevoPassenger, estadoVueloStr) != 0))
			{
				Passenger_delete(pNuevoPassenger);
			}
		}
	}
	return pNuevoPassenger;
}

/**
 * @brief Busca un id ingresado y retorna su indice
 *
 * @param pArrayListPassenger Puntero a la LinkedList donde estan los pasajeros
 * @param idPasajero ID ingresado a buscar
 * @return Retorna -1 [Puntero NULL o Largo no valido] Indice [OK]
 */
int Passenger_buscarIndicePorID(LinkedList* pArrayListPassenger,int idPasajero)
{
	int retorno = -1;
	int i;
	Passenger* pElementoAux = NULL;
	int auxId;

	if(pArrayListPassenger != NULL && idPasajero > 0)
	{
		for(i = 0; i < idPasajero; i++)
		{
			pElementoAux = ll_get(pArrayListPassenger, i);

			Passenger_getId(pElementoAux, &auxId);

			if(pElementoAux != NULL && auxId == idPasajero)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief Edita un pasajero en base a una opcion de modificacion ingresada
 *
 * @param pElemento Puntero a Passenger
 * @param opcionModificacion Opcion elegida para modificar
 * @return Retorna -1 [Puntero NULL u Opcion no valida] 1 [OK]
 */
int Passenger_editarUno(Passenger* pElemento, int opcionModificacion)
{
	int retorno = -1;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[10];
	int auxEstadoVueloOpcion;
	char auxEstadoVuelo[10];

	if(pElemento != NULL && opcionModificacion > 0)
	{
		switch(opcionModificacion)
		{
			case 1:
				if(utn_getNombre(auxNombre,"\nIngrese nombre: ","\nEl nombre ingresado no es valido\n",4,50,3) == 1)
				{
					Passenger_setNombre(pElemento, auxNombre);
					retorno = 1;
				}
				break;
			case 2:
				if(utn_getNombre(auxApellido,"\nIngrese apellido: ","\nEl apellido ingresado no es valido\n",4,50,3) == 1)
				{
					Passenger_setApellido(pElemento, auxApellido);
					retorno = 1;
				}
				break;
			case 3:
				if(utn_getNumeroFlotante(&auxPrecio,"\nIngrese el precio de vuelo: ","\nEl precio ingresado no es valido\n",50000,500000,3) == 1)
				{
					Passenger_setPrecio(pElemento, auxPrecio);
					retorno = 1;
				}
				break;
			case 4:
				if(utn_getTexto(auxCodigoVuelo,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",4,10,3) == 1)
				{
					Passenger_setCodigoVuelo(pElemento, auxCodigoVuelo);
					retorno = 1;
				}
				break;
			case 5:
				if(utn_getNumeroEntero(&auxTipoPasajero,"\n*** TIPO DE PASAJERO ***"
														"\n1.FirstClass"
														"\n2.ExecutiveClass"
														"\n3.EconomyClass"
														"\nElija una opcion: ","\nEl tipo ingresado no es valido\n",1,3,3) == 1)
				{
					Passenger_setTipoPasajero(pElemento, auxTipoPasajero);
					retorno = 1;
				}
				break;
			case 6:
				if(utn_getNumeroEntero(&auxEstadoVueloOpcion,"\n*** ESTADO DE VUELO***"
															 "\n1.Aterrizado"
															 "\n2.En Horario"
															 "\n3.En Vuelo"
															 "\n4.Demorado"
															 "\nElija una opcion: ","\nEl estado ingresado no es valido\n",1,4,3) == 1)
				{
					Passenger_estadoVueloATexto(auxEstadoVueloOpcion, auxEstadoVuelo);
					Passenger_setEstadoVuelo(pElemento, auxEstadoVuelo);
					retorno = 1;
				}
				break;
			default:
				break;
		}
	}
	return retorno;
}

/**
 * @brief Convierte un tipo de pasajero a texto
 *
 * @param tipoPasajero Tipo de pasajero en numero
 * @param tipoPasajeroStr Cadena de caracteres donde se guardara el texto
 */
void Passenger_tipoPasajeroATexto(int tipoPasajero, char* tipoPasajeroStr)
{
	if(tipoPasajero > 0 && tipoPasajeroStr != NULL)
	{
		if(tipoPasajero == 1)
		{
			strcpy(tipoPasajeroStr,"FirstClass");
		}
		else if(tipoPasajero == 2)
		{
			strcpy(tipoPasajeroStr,"ExecutiveClass");
		}
		else
		{
			strcpy(tipoPasajeroStr,"EconomyClass");
		}
	}
}

/**
 * @brief Convierte un tipo de pasajero a numero
 *
 * @param tipoPasajeroStr Cadena de caracteres de donde se obtiene el texto
 * @param tipoPasajero Puntero a int donde se guardara el numero del tipo
 */
void Passenger_tipoPasajeroANumero(char* tipoPasajeroStr,int* tipoPasajero)
{
	if(tipoPasajeroStr > 0 && tipoPasajero != NULL)
	{
		if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
		{
			*tipoPasajero = 1;
		}
		else if(strcmp(tipoPasajeroStr,"ExecutiveClass") == 0)
		{
			*tipoPasajero = 2;
		}
		else if(strcmp(tipoPasajeroStr,"EconomyClass") == 0)
		{
			*tipoPasajero = 3;
		}
	}
}

/**
 * @brief Convierte un estado de vuelo de numero a texto
 *
 * @param estadoVuelo Estado de vuelo en numero
 * @param estadoVueloStr Cadena de caracteres donde se guardara el texto
 */
void Passenger_estadoVueloATexto(int estadoVuelo,char* estadoVueloStr)
{
	if(estadoVuelo > 0 && estadoVuelo <= 4 && estadoVueloStr != NULL)
	{
		if(estadoVuelo == 1)
		{
			strcpy(estadoVueloStr,"Aterrizado");
		}
		else if(estadoVuelo == 2)
		{
			strcpy(estadoVueloStr,"En Horario");
		}
		else if(estadoVuelo == 3)
		{
			strcpy(estadoVueloStr,"En Vuelo");
		}
		else
		{
			strcpy(estadoVueloStr,"Demorado");
		}
	}
}

/**
 * @brief Le da formato a un texto ingresado como codigo de vuelo
 *
 * @param codigoVuelo Codigo de vuelo a convertir
 */
void Passenger_darFormatoCodigoVuelo(char* codigoVuelo)
{
	int i;

	if(codigoVuelo != NULL)
	{
		for(i = 0; i < strlen(codigoVuelo); i++)
		{
			if(islower((*(codigoVuelo+i))) != 0)
			{
				(*(codigoVuelo+i)) = toupper((*(codigoVuelo+i)));
			}
		}
	}
}

/**
 * @brief Compara dos elementos por nombre
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return Retorna
 */
int Passenger_compararPorNombre(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	char auxNombreUno[25];
	char auxNombreDos[25];

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Passenger_getNombre((Passenger*)pElementoUno, auxNombreUno) == 0 &&
			Passenger_getNombre((Passenger*)pElementoDos, auxNombreDos) == 0)
		{
			retorno = strcmp(auxNombreUno,auxNombreDos);
		}
	}

	return retorno;
}

/**
 * @brief Compara dos elementos por codigo de vuelo
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return
 */
int Passenger_compararPorCodigoDeVuelo(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	char auxCodigoUno[25];
	char auxCodigoDos[25];

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Passenger_getCodigoVuelo((Passenger*)pElementoUno, auxCodigoUno) == 0 &&
			Passenger_getCodigoVuelo((Passenger*)pElementoDos, auxCodigoDos) == 0)
		{
			retorno = strcmp(auxCodigoUno,auxCodigoDos);
		}
	}

	return retorno;
}

/**
 * @brief Compara dos elementos en base al precio de vuelo
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return
 */
int Passenger_compararPorPrecio(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	float auxPrecioUno;
	float auxPrecioDos;

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Passenger_getPrecio((Passenger*)pElementoUno, &auxPrecioUno) == 0 &&
			Passenger_getPrecio((Passenger*)pElementoDos, &auxPrecioDos) == 0)
		{
			retorno = auxPrecioUno > auxPrecioUno;
		}
	}

	return retorno;
}

/**
 * @brief Compara dos elementos en base al estado de vuelo
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return
 */
int Passenger_compararPorEstadoDeVuelo(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	char auxEstadoVueloUno[10];
	char auxEstadoVueloDos[10];

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Passenger_getEstadoVuelo((Passenger*)pElementoUno, auxEstadoVueloUno) == 0 &&
			Passenger_getEstadoVuelo((Passenger*)pElementoDos, auxEstadoVueloDos) == 0)
		{
			retorno = strcmp(auxEstadoVueloUno,auxEstadoVueloDos);
		}
	}

	return retorno;
}

/**
 * @brief Compara dos elementos por el tipo de pasajero en texto
 *
 * @param pElementoUno Puntero al primer elemento
 * @param pElementoDos Puntero al segundo elemento
 * @return
 */
int Passenger_compararPorTipoDePasajero(void* pElementoUno, void* pElementoDos)
{
	int retorno = -1;
	int auxTipoUno;
	int auxTipoDos;
	char auxTipoUnoStr[25];
	char auxTipoDosStr[25];

	if(pElementoUno != NULL && pElementoDos != NULL)
	{
		if( Passenger_getTipoPasajero((Passenger*)pElementoUno, &auxTipoUno) == 0 &&
			Passenger_getTipoPasajero((Passenger*)pElementoDos, &auxTipoDos) == 0)
		{
			Passenger_tipoPasajeroATexto(auxTipoUno, auxTipoUnoStr);
			Passenger_tipoPasajeroATexto(auxTipoDos, auxTipoDosStr);

			retorno = strcmp(auxTipoUnoStr,auxTipoDosStr);
		}
	}

	return retorno;
}

/**
 * @brief Elimina un pasajero
 *
 * @param pElementoUno Puntero al elemento a eliminar
 */
void Passenger_delete(Passenger* pElemento)
{
	if(pElemento != NULL)
	{
		free(pElemento);
		pElemento = NULL;
	}
}

/**
 * @brief Setea el ID de un pasajero
 *
 * @param this Puntero a Passenger
 * @param id ID a setear en el pasajero
 * @return Retorna -1 [Puntero NULL o ID no valido] 0 [OK]
 */
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id= id;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el ID de un pasajero
 *
 * @param this Puntero a Passenger
 * @param id variable donde se almacenara el ID del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Setea el nombre de un pasajero
 *
 * @param this Puntero a Passenger
 * @param nombre Cadena de caracteres que se copiara en el pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el nombre de un pasajero
 *
 * @param this Puntero a Passenger
 * @param nombre Cadena de caracteres donde se almacenara el nombre del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Setea el apellido de un pasajero
 *
 * @param this Puntero a Passenger
 * @param apellido Cadena de caracteres que se copiara en el pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el apellido de un pasajero
 *
 * @param this Puntero a Passenger
 * @param apellido Cadena de caracteres donde se almacenara el apellido del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Setea el precio de un pasajero
 *
 * @param this Puntero a Passenger
 * @param precio
 * @return Retorna -1 [Puntero NULL o Precio no valido] 0 [OK]
 */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el precio de vuelo de un pasajero
 *
 * @param this Puntero a Passenger
 * @param precio variable donde se almacenara el precio de vuelo del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Setea el codigo de vuelo de un pasajero
 *
 * @param this Puntero a Passenger
 * @param codigoVuelo Cadena de caracteres que se copiara en el pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el codigo de vuelo de un pasajero
 *
 * @param this Puntero a Passenger
 * @param codigoVuelo Cadena de caracteres donde se almacenara el codigo de vuelo del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);

		retorno = 0;
	}
	else
	{
		printf("\nno puede obtener el codigo");
	}
	return retorno;
}

/**
 * @brief Setea el tipo de pasajero de un pasajero
 *
 * @param this Puntero a Passenger
 * @param tipoPasajero tipo de pasajero que se copiara en un pasajero
 * @return Retorna -1 [Puntero NULL o Tipo no valido] 0 [OK]
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el tipo de pasajero de un pasajero
 *
 * @param this Puntero a Passenger
 * @param tipoPasajero variable donde se almacenara el tipo de pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Setea el estado de vuelo de un pasajero
 *
 * @param this Puntero a Passenger
 * @param estadoVuelo Cadena de caracteres que se copiara en el pasajeros
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

/**
 * @brief Obtiene el estado de vuelo de un pasajero
 *
 * @param this Puntero a Passenger
 * @param estadoVuelo Cadena de caracteres donde se almacenara el estado de vuelo del pasajero
 * @return Retorna -1 [Punteros NULL] 0 [OK]
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 0;
	}
	return retorno;
}














