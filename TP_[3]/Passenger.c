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
 * @brief Imprime un pasajero de la LinkedList
 *
 * @param pElemento Puntero al elemento a imprimir
 */
void Passenger_imprimirUno(Passenger* pElemento)
{
	char auxTipoPasajero[20];

	if(pElemento != NULL)
	{
		if(pElemento->tipoPasajero == 1)
		{
			strcpy(auxTipoPasajero,"FirstClass");
		}
		else if(pElemento->tipoPasajero == 2)
		{
			strcpy(auxTipoPasajero,"ExecutiveClass");
		}
		else
		{
			strcpy(auxTipoPasajero,"EconomyClass");
		}
		printf("\n %d   %-16s  %-10s     %.2f   %-10s  %-15s %s",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->precio,pElemento->codigoVuelo,auxTipoPasajero,pElemento->estadoVuelo);
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
	int largoLista = ll_len(pArrayListPassenger);
	Passenger* pElemento = NULL;
	int i;

	if(pArrayListPassenger != NULL && largoLista > 0)
	{
		printf("\n\n------------------------------------------------------------------------------------\n");
		printf("****************************** LISTADO DE PASAJEROS  ***********************************");
		printf("\n--------------------------------------------------------------------------------------\n");
		printf(" ID    NOMBRE         APELLIDO         PRECIO     CODIGO       TIPO          ESTADO ");
		printf("\n--------------------------------------------------------------------------------------\n");
		for(i = 0; i < largoLista; i++)
		{
			pElemento = ll_get(pArrayListPassenger, i);
			if(pElemento != NULL)
			{
				Passenger_imprimirUno(pElemento);
			}
		}
		retorno = 1;
	}
	free(pElemento);

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

	if(pNuevoPassenger != NULL)
	{
		Passenger_setId(pNuevoPassenger,0);
		Passenger_setNombre(pNuevoPassenger," ");
		Passenger_setApellido(pNuevoPassenger," ");
		Passenger_setPrecio(pNuevoPassenger,0);
		Passenger_setCodigoVuelo(pNuevoPassenger," ");
		Passenger_setTipoPasajero(pNuevoPassenger,0);
		Passenger_setEstadoVuelo(pNuevoPassenger," ");
	}

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
			if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
			{
				auxTipoPasajero = 1;
			}
			else if(strcmp(tipoPasajeroStr,"ExecutiveClass") == 0)
			{
				auxTipoPasajero = 2;
			}
			else if(strcmp(tipoPasajeroStr,"EconomyClass") == 0)
			{
				auxTipoPasajero = 3;
			}

			Passenger_setId(pNuevoPassenger, atoi(idStr));
			Passenger_setNombre(pNuevoPassenger, nombreStr);
			Passenger_setApellido(pNuevoPassenger, apellidoStr);
			Passenger_setPrecio(pNuevoPassenger, atof(precioStr));
			Passenger_setCodigoVuelo(pNuevoPassenger, codigoVueloStr);
			Passenger_setTipoPasajero(pNuevoPassenger, auxTipoPasajero);
			Passenger_setEstadoVuelo(pNuevoPassenger, estadoVueloStr);
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
	Passenger* pAuxBusqueda = NULL;

	if(pArrayListPassenger != NULL && idPasajero > 0)
	{
		for(i = 0; i < idPasajero; i++)
		{
			pAuxBusqueda = ll_get(pArrayListPassenger, i);

			if(pAuxBusqueda != NULL && pAuxBusqueda->id == idPasajero)
			{
				retorno = i;
				break;
			}
		}
		free(pAuxBusqueda);
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
	Passenger* pAuxiliar = NULL;

	if(pElemento != NULL && opcionModificacion > 0)
	{
		pAuxiliar = Passenger_new();
		if(pAuxiliar != NULL)
		{
			switch(opcionModificacion)
			{
				case 1:
					if(utn_getNombre(pAuxiliar->nombre,"\nIngrese nombre: ","\nEl nombre ingresado no es valido\n",4,50,3) == 1)
					{
						Passenger_setNombre(pElemento, pAuxiliar->nombre);
						retorno = 1;
					}
					break;
				case 2:
					if(utn_getNombre(pAuxiliar->apellido,"\nIngrese apellido: ","\nEl apellido ingresado no es valido\n",4,50,3) == 1)
					{
						Passenger_setApellido(pElemento, pAuxiliar->apellido);
						retorno = 1;
					}
					break;
				case 3:
					if(utn_getNumeroFlotante(&pAuxiliar->precio,"\nIngrese el precio de vuelo: ","\nEl precio ingresado no es valido\n",50000,500000,3) == 1)
					{
						Passenger_setPrecio(pElemento, pAuxiliar->precio);
						retorno = 1;
					}
					break;
				case 4:
					if(utn_getTexto(pAuxiliar->codigoVuelo,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",4,10,3) == 1)
					{
						Passenger_setCodigoVuelo(pElemento, pAuxiliar->codigoVuelo);
						retorno = 1;
					}
					break;
				case 5:
					if(utn_getNumeroEntero(&pAuxiliar->tipoPasajero,"\n*** TIPO DE PASAJERO ***\n1.FirstClass\n2.ExecutiveClass\n3.EconomyClass\nElija una opcion: ","\nEl tipo ingresado no es valido\n",1,3,3) == 1)
					{
						Passenger_setTipoPasajero(pElemento, pAuxiliar->tipoPasajero);
						retorno = 1;
					}
					break;
				case 6:
					if(utn_getTexto(pAuxiliar->estadoVuelo,"\n*** ESTADO DE VUELO***\n1.Aterrizado\n2.En Horario\nElija una opcion: ","\nEl estado ingresado no es valido\n",1,10,3) == 1)
					{
						Passenger_setEstadoVuelo(pElemento, pAuxiliar->estadoVuelo);
						retorno = 1;
					}
					break;
				default:
					break;
			}
		}
		free(pAuxiliar);
	}
	return retorno;
}

int Passenger_ordenar(Passenger* pElementoUno, Passenger* pElementoDos)
{
	int retorno = -1;

	if(pElementoUno != NULL && pElementoDos != NULL)
	{

	}

	return retorno;
}

/*
void Passenger_delete(Passenger* this)
{

}*/

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

	if(this != NULL && tipoPasajero >= 0)
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














