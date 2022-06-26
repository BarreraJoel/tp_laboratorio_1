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
			retorno = parser_PassengerFromText(pArchivo, pArrayListPassenger);
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
			retorno = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
		}
		fclose(pArchivo);
	}

    return retorno;
}

int controller_reordenarID(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{

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
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[10];
	int auxEstadoVueloOpcion;
	char auxEstadoVuelo[10];

	if(pArrayListPassenger != NULL)
	{
		pAuxiliar = Passenger_new();

		if(pAuxiliar != NULL)
		{
			if( utn_getNombre(auxNombre,"\nIngrese nombre: ","\nEl nombre ingresado no es valido\n",4,50,3) == 1 &&
				utn_getNombre(auxApellido,"\nIngrese apellido: ","\nEl apellido ingresado no es valido\n",4,50,3) == 1 &&
				utn_getNumeroFlotante(&auxPrecio,"\nIngrese el precio de vuelo: ","\nEl precio ingresado no es valido\n",50000,500000,3) == 1 &&
				utn_getTextoAlfanumerico(auxCodigoVuelo,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",4,10,3) == 1 &&
				utn_getNumeroEntero(&auxTipoPasajero,"\n*** TIPO DE PASAJERO ***"
													 "\n1.FirstClass"
													 "\n2.ExecutiveClass"
													 "\n3.EconomyClass"
													 "\nElija una opcion: ","\nEl tipo ingresado no es valido\n",1,3,3) == 1 &&
				utn_getNumeroEntero(&auxEstadoVueloOpcion,"\n*** ESTADO DE VUELO***"
														  "\n1.Aterrizado"
														  "\n2.En Horario"
														  "\n3.En Vuelo"
														  "\n4.Demorado"
														  "\nElija una opcion: ","\nEl estado ingresado no es valido\n",1,4,3) == 1)
			{
				Passenger_darFormatoCodigoVuelo(auxCodigoVuelo);
				Passenger_estadoVueloATexto(auxEstadoVueloOpcion, auxEstadoVuelo);

				if(	Passenger_setId(pAuxiliar, idIncremental) == 0 &&
					Passenger_setNombre(pAuxiliar, auxNombre) == 0 &&
					Passenger_setApellido(pAuxiliar, auxApellido) == 0 &&
					Passenger_setPrecio(pAuxiliar, auxPrecio) == 0 &&
					Passenger_setCodigoVuelo(pAuxiliar, auxCodigoVuelo) == 0 &&
					Passenger_setTipoPasajero(pAuxiliar, auxTipoPasajero) == 0 &&
					Passenger_setEstadoVuelo(pAuxiliar, auxEstadoVuelo) == 0)
				{
					ll_add(pArrayListPassenger, pAuxiliar);
					idIncremental++;
					retorno = 1;
				}
			}
		}
	}
	free(pAuxiliar);

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
	int opcionModificacion;
	int idMinimo;
	int idMaximo;

	if(pArrayListPassenger != NULL)
	{
		Passenger_obtenerIDMaximo(pArrayListPassenger, &idMinimo, &idMaximo);
		Passenger_listarPasajeros(pArrayListPassenger);
		if(utn_getNumeroEntero(&idModificacion, "\nIngrese el ID a modificar: ","\nEl ID ingresado no es valido\n",idMinimo,idMaximo,3) == 1)
		{
			indicePasajero = Passenger_buscarIndicePorID(pArrayListPassenger,idModificacion);
			if(indicePasajero >= 0)
			{
				pAuxModificacion = ll_get(pArrayListPassenger, indicePasajero);
				if(pAuxModificacion != NULL)
				{
					do
					{
						printf("\n\n-----------------------------------------------------------------------------------------\n");
						printf("******************************** DATOS DEL PASAJERO  ***********************************");
						printf("\n------------------------------------------------------------------------------------------\n");
						printf(" ID    NOMBRE            APELLIDO         PRECIO      CODIGO       TIPO           ESTADO ");
						printf("\n------------------------------------------------------------------------------------------\n");
						Passenger_imprimirUno(pAuxModificacion);
						if(utn_getNumeroEntero(&opcionModificacion, "\n\n*** MENU DE MODIFICACION ***"
																	"\n1.Modificar Nombre"
																	"\n2.Modificar Apellido"
																	"\n3.Modificar Precio de Vuelo"
																	"\n4.Modificar Codigo de Vuelo"
																	"\n5.Modificar Tipo de Pasajero"
																	"\n6.Modificar Estado de Vuelo"
																	"\n7.Salir"
																	"\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,7,3) == 1)
						{
							retorno = Passenger_editarUno(pAuxModificacion,opcionModificacion);
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
	int confirmacionBaja;
	int idMinimo;
	int idMaximo;

	if(pArrayListPassenger != NULL)
	{
		Passenger_obtenerIDMaximo(pArrayListPassenger, &idMinimo, &idMaximo);
		Passenger_listarPasajeros(pArrayListPassenger);
		printf("\nmin: %d   max: %d ", idMinimo,idMaximo);
		if(utn_getNumeroEntero(&idBaja, "\n\nIngrese el ID a dar de baja: ","\nEl ID ingresado no es valido\n",idMinimo,idMaximo,3) == 1)
		{
			indicePasajero = Passenger_buscarIndicePorID(pArrayListPassenger, idBaja);
			if(indicePasajero >= 0)
			{
				pAuxBaja = ll_get(pArrayListPassenger, indicePasajero);
				if(pAuxBaja != NULL)
				{
					printf("\n\n-----------------------------------------------------------------------------------------\n");
					printf("******************************** DATOS DEL PASAJERO  ***********************************");
					printf("\n------------------------------------------------------------------------------------------\n");
					printf(" ID    NOMBRE            APELLIDO         PRECIO      CODIGO       TIPO           ESTADO ");
					printf("\n------------------------------------------------------------------------------------------\n");
					Passenger_imprimirUno(pAuxBaja);
					if(utn_getNumeroEntero(&confirmacionBaja,"\n\nConfirma la baja del pasajero?\n1.SI\n2.NO\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,2,3) == 1
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
	int retorno = -1;
	int opcionOrden;
	int orden;
	int (*pFunc)(void* ,void*);

	if(pArrayListPassenger != NULL)
	{
		if(utn_getNumeroEntero(&opcionOrden,"\n*** MENU DE ORDENAMIENTO ***"
											"\n1. Ordenar por Nombre"
											"\n2. Ordenar por Precio"
											"\n3. Ordenar por Tipo de Pasajero"
											"\n4. Ordenar por Codigo de Vuelo"
											"\n5. Ordenar por Estado de Vuelo"
											"\nElija una opcion: ", "\nLa opcion elegida no es valida\n",1,5,3) == 1)
		{
			if(utn_getNumeroEntero(&orden,  "\n0. Ordenar de forma descendente"
											"\n1. Ordenar de forma ascendente"
											"\nElija una opcion: ", "\nLa opcion elegida no es valida\n",0,1,3) == 1)
			{
				switch(opcionOrden)
				{
					case 1:
						pFunc = Passenger_compararPorNombre;
						ll_sort(pArrayListPassenger, pFunc, orden);
						break;
					case 2:
						pFunc = Passenger_compararPorPrecio;
						ll_sort(pArrayListPassenger, pFunc, orden);
						break;
					case 3:
						pFunc = Passenger_compararPorTipoDePasajero;
						ll_sort(pArrayListPassenger, pFunc, orden);
						break;
					case 4:
						pFunc = Passenger_compararPorCodigoDeVuelo;
						ll_sort(pArrayListPassenger, pFunc, orden);
						break;
					case 5:
						pFunc = Passenger_compararPorEstadoDeVuelo;
						ll_sort(pArrayListPassenger, pFunc, orden);
						break;
					default:
						printf("\nLa opcion elegida no es valida\n");
						break;
				}
			}
			retorno = 1;
		}
	}

    return retorno;
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
			retorno = parser_PassengerToBinary(pArchivoBin, pArrayListPassenger);
		}
		fclose(pArchivoBin);
	}

	return retorno;
}

