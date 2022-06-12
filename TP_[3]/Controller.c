#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input-UTN.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \param pArrayListPassenger LinkedList*
 * \return int Retorna -1 [Punteros NULL o Lectura no completada] 1 [OK]
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_PassengerFromText(pArchivo, pArrayListPassenger) == 1)
			{
				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo dataDos.bin (modo binario).
 *
 * \param path char* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList de donde se obtienen los datos a cargar
 * \return int Retorna -1 [Punteros NULL o Lectura no completada] 1 [OK]
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL)
		{
			if(parser_PassengerFromBinary(pArchivo, pArrayListPassenger) == 1)
			{
				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList donde se guardara el empleado cargado
 * \return int Retorna -1 [Puntero NULL o Alta no completada] 1 [OK]
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pAuxiliar = NULL;
	int idIncremental = ll_len(pArrayListPassenger)+1;

	if(pArrayListPassenger != NULL)
	{
		pAuxiliar = Passenger_new();

		if(pAuxiliar != NULL)
		{
			if(utn_getNombre(pAuxiliar->nombre,"\nIngrese nombre: ","\nEl nombre ingresado no es valido\n",4,50,3) == 1)
			{
				if(utn_getNombre(pAuxiliar->apellido,"\nIngrese apellido: ","\nEl apellido ingresado no es valido\n",4,50,3) == 1)
				{
					if(utn_getNumeroFlotante(&pAuxiliar->precio,"\nIngrese el precio de vuelo: ","\nEl precio ingresado no es valido\n",50000,500000,3) == 1)
					{
						if(utn_getTextoAlfanumerico(pAuxiliar->codigoVuelo,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",4,10,3) == 1)
						{
							if(utn_getNumeroEntero(&pAuxiliar->tipoPasajero,"\n*** TIPO DE PASAJERO ***\n1.FirstClass\n2.ExecutiveClass\n3.EconomyClass\nElija una opcion: ","\nEl tipo ingresado no es valido\n",1,3,3) == 1)
							{
								if(utn_getTextoAlfanumerico(pAuxiliar->estadoVuelo,"\n*** ESTADO DE VUELO***\n1.Aterrizado\n2.En Horario\nElija una opcion: ","\nEl estado ingresado no es valido\n",1,15,3) == 1)
								{
									Passenger_setId(pAuxiliar, idIncremental);

									if(strcmp(pAuxiliar->estadoVuelo,"1") == 0)
									{
										strcpy(pAuxiliar->estadoVuelo,"Aterrizado");
									}
									else if(strcmp(pAuxiliar->estadoVuelo,"2") == 0)
									{
										strcpy(pAuxiliar->estadoVuelo,"En Horario");
									}

									ll_add(pArrayListPassenger, pAuxiliar);

									idIncremental++;

									retorno = 1;
								}
							}
						}
					}
				}
			}
		}
		free(pAuxiliar);
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList donde estan los empleados a modificar
 * \return int Retorna -1 [Punteros NULL o Modificacion no completada] 1 [OK]
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idModificacion;
	int indicePasajero;
	Passenger* pAuxModificacion = NULL;
	int limiteLista = ll_len(pArrayListPassenger);
	int opcionModificacion;

	if(pArrayListPassenger != NULL)
	{
		Passenger_listarPasajeros(pArrayListPassenger);
		if(utn_getNumeroEntero(&idModificacion, "\nIngrese el ID a modificar: ","\nEl ID ingresado no es valido\n",limiteLista-limiteLista+1,limiteLista,3) == 1)
		{
			indicePasajero = Passenger_buscarIndicePorID(pArrayListPassenger,idModificacion);
			if(indicePasajero >= 0)
			{
				pAuxModificacion = ll_get(pArrayListPassenger, indicePasajero);
				if(pAuxModificacion != NULL)
				{
					do
					{
						Passenger_imprimirUno(pAuxModificacion);
						if(utn_getNumeroEntero(&opcionModificacion, "\n*** MENU DE MODIFICACION ***"
																	"\n1.Modificar Nombre"
																	"\n2.Modificar Apellido"
																	"\n3.Modificar Precio de Vuelo"
																	"\n4.Modificar Codigo de Vuelo"
																	"\n5.Modificar Tipo de Pasajero"
																	"\n6.Modificar Estado de Vuelo"
																	"\n7.Salir"
																	"\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,7,3) == 1)
						{
							if(Passenger_editarUno(pAuxModificacion,opcionModificacion) == 1)
							{
								retorno = 1;
								printf("\nindice modificacion: %d", indicePasajero);
							}
						}
					}while(opcionModificacion != 7);
				}
			}
		}
		free(pAuxModificacion);
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList donde estan los empleados a borrar
 * \return int Retorna -1 [Punteros NULL o Baja no completada] 1 [OK]
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int idBaja;
	int indicePasajero;
	Passenger* pAuxBaja = NULL;
	int limiteLista = ll_len(pArrayListPassenger);
	int confirmacionBaja;

	if(pArrayListPassenger != NULL)
	{
		Passenger_listarPasajeros(pArrayListPassenger);
		if(utn_getNumeroEntero(&idBaja, "\nIngrese el ID a dar de baja: ","\nEl ID ingresado no es valido\n",limiteLista-limiteLista+1,limiteLista,3) == 1)
		{
			indicePasajero = Passenger_buscarIndicePorID(pArrayListPassenger, idBaja);
			if(indicePasajero >= 0)
			{
				pAuxBaja = ll_get(pArrayListPassenger, indicePasajero);
				if(pAuxBaja != NULL)
				{
					Passenger_imprimirUno(pAuxBaja);
					if(utn_getNumeroEntero(&confirmacionBaja,"\nConfirma la baja del pasajero?\n1.SI\n2.NO\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,2,3) == 1
						&& confirmacionBaja == 1)
					{
						ll_remove(pArrayListPassenger, indicePasajero);
						retorno = 1;
					}
				}
			}
		}
		free(pAuxBaja);
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList donde estan los empleados a mostrar
 * \return int Retorna -1 [Puntero NULL] 1 [OK]
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		Passenger_listarPasajeros(pArrayListPassenger);
		retorno = 1;
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList* Puntero a LinkedList donde estan los empleados a ordenar
 * \return int Retorna -1 [Puntero NULL] 1 [OK]
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo dataDos.csv (modo texto).
 *
 * \param path char* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \param pArrayListPassenger LinkedList* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \return int Retorna -1 [Punteros NULL o Lectura no completada] 1 [OK]
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivoTxt = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivoTxt = fopen(path,"w");
		if(pArchivoTxt != NULL)
		{
			if(parser_PassengerToText(pArchivoTxt, pArrayListPassenger) == 1)
			{
				printf("\nLa funcion guardar txt retorno 1\n");
				retorno = 1;
			}
		}
		fclose(pArchivoTxt);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo dataDos.bin (modo binario).
 *
 * \param path char* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \param pArrayListPassenger LinkedList* Cadena de caracteres donde se escribe la ubicacion y nombre del archivo
 * \return int Retorna -1 [Punteros NULL o Escritura no completada] 1 [OK]
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivoBin = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivoBin = fopen(path,"wb");
		if(pArchivoBin != NULL)
		{
			if(parser_PassengerToBinary(pArchivoBin, pArrayListPassenger) == 1)
			{
				retorno = 1;
			}
		}
		fclose(pArchivoBin);
	}
	return retorno;
}

