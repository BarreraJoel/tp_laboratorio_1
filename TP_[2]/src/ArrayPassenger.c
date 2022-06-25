/*
 * ArrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: Joel Barrera
 */

#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			(*(list+i)).isEmpty = LIBRE;
		}
		retorno = 0;
	}
	return retorno;
}

void Passenger_obtenerTipo(int tipo,char tipoPasajeroStr[])
{
	typePassenger listaTipos[3] = {{1,"Adulto/a"},{2,"Ninio/a"},{3,"Adolescente"}};
	int i;

	if(tipo > 0 && tipo <= 3 && tipoPasajeroStr != NULL)
	{
		for(i = 0; i < 3; i++)
		{
			if(tipo == (*(listaTipos+i)).typePassenger)
			{
				strcpy(tipoPasajeroStr,(*(listaTipos+i)).descripcion);
				break;
			}
		}
	}
}

void Passenger_obtenerEstado(int estado,char statusFlightStr[])
{
	statusFlight listaEstados[2] = {{1,"Activo"},{2,"Cancelado"}};
	int i;

	if(estado > 0 && estado <= 2 && statusFlightStr != NULL)
	{
		for(i = 0; i < 3; i++)
		{
			if(estado == (*(listaEstados+i)).statusFlight)
			{
				strcpy(statusFlightStr,(*(listaEstados+i)).descripcion);
				break;
			}
		}
	}
}

void printPassenger(Passenger elemento)
{
	char typePassenger[10];
	char statusFlight[10];

	Passenger_obtenerTipo(elemento.typePassenger,typePassenger);
	Passenger_obtenerEstado(elemento.statusFlight,statusFlight);

	printf("\n%-10d %-10s  %-13s %.2f %9s %13s %15s\n",elemento.id,elemento.name,elemento.lastName,elemento.price,elemento.flycode,typePassenger,statusFlight);
}

int printPassengers(Passenger* list, int length)
{
	int retorno = -1;
	int i;

	if(list != NULL && length > 0)
	{
		printf("\n\n---------------------------------------------------------------------------------------\n");
		printf("******************************** DATOS DE LOS PASAJEROS *******************************");
		printf("\n---------------------------------------------------------------------------------------");
		printf("\nID        NOMBRE       APELLIDO       PRECIO      CODIGO        TIPO          ESTADO");
		printf("\n---------------------------------------------------------------------------------------");
		for(i = 0; i < length; i++)
		{
			if((*(list+i)).isEmpty == OCUPADO)
			{
				printPassenger((*(list+i)));
			}
		}
		retorno = 0;
	}
	return retorno;
}

int buscarEspacioLibrePassenger(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char* name,char* lastName,float price,int typePassenger, char* flycode, int statusFlight)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id >= 1000 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL && statusFlight > 0)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).isEmpty == LIBRE)
			{
				(*(list+i)).id = id;
				strcpy((*(list+i)).name, name);
				strcpy((*(list+i)).lastName, lastName);
				(*(list+i)).price = price;
				(*(list+i)).typePassenger = typePassenger;
				strcpy((*(list+i)).flycode, flycode);
				(*(list+i)).statusFlight = statusFlight;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int altaPassengers(Passenger* list, int len, int* id, int* ultimoId)
{
	int retorno = -1;
	int indiceLibre;
	Passenger auxiliar;

	if(list != NULL && len > 0 && id != NULL)
	{
		indiceLibre = buscarEspacioLibrePassenger(list, len);

		if(indiceLibre >= 0)
		{
			if( utn_getNombre(auxiliar.name,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",3, MAX_TEXTO,3) == 1 &&
				utn_getNombre(auxiliar.lastName,"\nIngrese el apellido: ","\nEl apellido ingresado no es valido\n",4,MAX_TEXTO,3) == 1 &&
				utn_getNumeroFlotante(&auxiliar.price,"\nIngrese el precio de vuelo (entre 100000 y 500000): ","\nEl precio de vuelo ingresado no es valido\n",100000,500000,3) == 1 &&
				utn_getTexto(auxiliar.flycode,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",3,MAX_CODIGO,3) == 1 &&
				utn_getNumeroEntero(&auxiliar.typePassenger,"\nTipo de pasajero\n1.Adulto/a\n2.Ninio/a\n3.Adolescente\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,3,3) &&
				utn_getNumeroEntero(&auxiliar.statusFlight,"\nEstado de vuelo\n1.Activo\n2.Cancelado\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,2,3) == 1)
			{
				auxiliar.id = *id;
				*ultimoId = auxiliar.id;
				if(addPassenger(list, len, auxiliar.id, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.typePassenger, auxiliar.flycode, auxiliar.statusFlight) == 0)
				{
					auxiliar.isEmpty = OCUPADO;
					(*(list+indiceLibre)) = auxiliar;
					(*id)++;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id >= 1000)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).isEmpty == OCUPADO && (*(list+i)).id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void buscarMinimoMaximo(Passenger* list, int* idMinimo,int* idMaximo, int ultimoId)
{
	int i;
	int minimo;
	int maximo;
	int banderaMinimo = 0;
	int banderaMaximo = 0;

	if(list != NULL && idMinimo != NULL && idMaximo != NULL && ultimoId >= 1000)
	{
		for(i = 0; i <= ultimoId-1000; i++)
		{
			if((*(list+i)).isEmpty == OCUPADO)
			{
				if((*(list+i)).id < minimo || banderaMinimo == 0)
				{
					minimo = (*(list+i)).id;
					banderaMinimo = 1;
				}
				if((*(list+i)).id > maximo || banderaMaximo  == 0)
				{
					maximo = (*(list+i)).id;
					banderaMaximo = 1;
				}
			}
		}
		*idMinimo = minimo;
		*idMaximo = maximo;
	}
}

int modificarPassenger(Passenger* pPasajero, int opcionMenu)
{
	int retorno = -1;
	Passenger auxiliar;

	if(pPasajero != NULL && opcionMenu > 0)
	{
		switch(opcionMenu)
		{
			case 1:
				if(utn_getNombre(auxiliar.name,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",3,MAX_TEXTO,3) == 1)
				{
					strcpy(pPasajero->name,auxiliar.name);
					retorno = 1;
				}
				break;
			case 2:
				if(utn_getNombre(auxiliar.lastName,"\nIngrese el apellido: ","\nEl apellido ingresado no es valido\n",4,MAX_TEXTO,3) == 1)
				{
					strcpy(pPasajero->lastName,auxiliar.lastName);
					retorno = 1;
				}
				break;
			case 3:
				if(utn_getNumeroFlotante(&auxiliar.price,"\nIngrese el precio de vuelo: ","\nEl precio de vuelo ingresado no es valido\n",100000,300000,3) == 1)
				{
					pPasajero->price = auxiliar.price;
					retorno = 1;
				}
				break;
			case 4:
				if(utn_getNumeroEntero(&auxiliar.typePassenger,"\nTipo de pasajero\n1.Adulto/a\n2.Ninio/a\n3.Adolescente\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,3,3) == 1)
				{
					pPasajero->typePassenger = auxiliar.typePassenger;
					retorno = 1;
				}
				break;
			case 5:
				if(utn_getTexto(auxiliar.flycode,"\nIngrese el codigo de vuelo: ","\nEl codigo ingresado no es valido\n",3,MAX_CODIGO,3) == 1)
				{
					strcpy(pPasajero->flycode,auxiliar.flycode);
					retorno = 1;
				}
				break;
			case 6:
				break;
			default:
				break;
		}
	}
	return retorno;
}

int modificarPassengers(Passenger* list, int len, int ultimoId)
{
	int retorno = -1;
	int idModificacion;
	int indiceId;
	int opcionMenu;
	int idMinimo;
	int idMaximo;

	if(list != NULL && len > 0 && ultimoId >= 1000)
	{
		buscarMinimoMaximo(list,&idMinimo,&idMaximo, ultimoId);
		printPassengers(list, len);

		if(utn_getNumeroEntero(&idModificacion,"\nIngrese el numero de ID del pasajero a modificar: ","\nEl ID ingresado no es valido\n",idMinimo,idMaximo,3) == 1)
		{
			indiceId = findPassengerById(list, len, idModificacion);
			if(indiceId >= 0)
			{
				do
				{
					printf("\n\n---------------------------------------------------------------------------------------\n");
					printf("*********************************** DATOS DEL PASAJERO *********************************");
					printf("\n---------------------------------------------------------------------------------------");
					printf("\nID        NOMBRE       APELLIDO       PRECIO      CODIGO        TIPO          ESTADO");
					printf("\n---------------------------------------------------------------------------------------");
					printPassenger((*(list+indiceId)));
					if(utn_getNumeroEntero(&opcionMenu, "\n\n*** MENU DE MODIFICACION ***"
														"\n\n1.Modificar Nombre"
														"\n2.Modificar Apellido"
														"\n3.Modificar Precio de vuelo"
														"\n4.Modificar Tipo de pasajero"
														"\n5.Modificar Codigo de vuelo"
														"\n6.Salir\nIngrese una opcion: ", "\nLa opcion ingresado no es valida\n",1,6,3) == 1)
					{
						if(modificarPassenger((list+indiceId),opcionMenu) == 1)
						{
							retorno = 1;
						}
					}
				}while(opcionMenu != 6);
			}
			else
			{
				printf("\nEl ID ingresado no es valido\n");
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;
	int confirmacion;

	if(list != NULL && len > 0 && id >= 1000)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).isEmpty == OCUPADO && (*(list+i)).id == id)
			{
				if(utn_getNumeroEntero(&confirmacion,"\nConfirma la baja del pasajero/a?"
													 "\n1.SI"
													 "\n2.NO"
													 "\nElija una opcion: ","\nLa opcion ingresada no es valida\n",1,2,3) == 1)
				{
					if(confirmacion == 1)
					{
						(*(list+i)).isEmpty = LIBRE;
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

int bajaPassengers(Passenger* list, int len, int ultimoId)
{
	int retorno = -1;
	int idBaja;
	int indiceId;
	int idMinimo;
	int idMaximo;

	if(list != NULL && len > 0 && ultimoId >= 1000)
	{
		buscarMinimoMaximo(list,&idMinimo,&idMaximo,ultimoId);
		printPassengers(list, len);
		if(utn_getNumeroEntero(&idBaja, "\nIngrese el numero de ID del pasajero a dar de baja: ","\nEl ID ingresado no es valido\n",idMinimo,idMaximo,3) == 1)
		{
			indiceId = findPassengerById(list, len, idBaja);
			if(indiceId >= 0)
			{
				printf("\n\n---------------------------------------------------------------------------------------\n");
				printf("*********************************** DATOS DEL PASAJERO *********************************");
				printf("\n---------------------------------------------------------------------------------------");
				printf("\nID        NOMBRE       APELLIDO       PRECIO      CODIGO        TIPO          ESTADO");
				printf("\n---------------------------------------------------------------------------------------");
				printPassenger((*(list+indiceId)));
				if(removePassenger(list, len, idBaja) == 0)
				{
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int sortPassengersByName(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	Passenger auxiliar;

	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if( ((strcmp((*(list+i)).lastName,(*(list+j)).lastName) > 0) && order == 0) ||
					((strcmp((*(list+i)).lastName,(*(list+j)).lastName) < 0) && order == 1))
				{
					auxiliar = *(list+i);
					*(list+i) = *(list+j);
					*(list+j) = auxiliar;
				}
				else
				{
					if( (((*(list+i)).typePassenger > (*(list+j)).typePassenger) && order == 0) ||
						(((*(list+i)).typePassenger < (*(list+j)).typePassenger) && order == 1))
					{
						auxiliar = *(list+i);
						*(list+i) = *(list+j);
						*(list+j) = auxiliar;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	Passenger auxiliar;

	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(i = 0; i < len-1; i++)
		{
			for(j = i+1; j < len; j++)
			{
				if((*(list+i)).statusFlight == 1 && (*(list+j)).statusFlight == 1)
				{
					if( ((strcmp((*(list+i)).flycode, (*(list+j)).flycode) > 0) && order == 0) ||
						((strcmp((*(list+i)).flycode, (*(list+j)).flycode) < 0) && order == 1))
					{
						auxiliar = (*(list+i));
						(*(list+i)) = (*(list+j));
						(*(list+j)) = auxiliar;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int sumarPasajes(Passenger* list,int len, float* pResultado)
{
	int retorno = -1;
	int i;
	float acumSuma = 0;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).isEmpty == OCUPADO)
			{
				acumSuma += (*(list+i)).price;
			}
		}
		*pResultado = acumSuma;
		retorno = 1;
	}
	return retorno;
}

int promediarPasajes(float sumaTotal, int contadorAltas, float* pResultado)
{
	int retorno = -1;
	float promedioPasajes;

	if(pResultado != NULL && contadorAltas > 0 && sumaTotal > 0)
	{
		promedioPasajes = sumaTotal / contadorAltas;

		*pResultado = promedioPasajes;
		retorno = 1;
	}
	return retorno;
}

int buscarPasajesPromedio(Passenger* list, int len, int* contPasajeros, float promedio)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && contPasajeros != NULL && promedio > 0)
	{
		for(i = 0; i < len; i++)
		{
			if((*(list+i)).price > promedio)
			{
				(*contPasajeros)++;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int informarPassengers(Passenger* list, int len, int contadorAltas)
{
	int retorno = -1;
	int opcionMenu;
	int opcionOrden;
	float sumaTotal;
	float promedio;
	int contPasajeros = 0;

	if(list != NULL && len > 0 && contadorAltas > 0)
	{
		if(utn_getNumeroEntero(&opcionMenu, "\n***** MENU DE OPCIONES *****"
											"\n1.Listar pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
											"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
											"\n3.Listar pasajeros por Código de vuelo y estados de vuelos ACTIVO"
											"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",1,3,3) == 1)
		{
			switch(opcionMenu)
			{
				case 1:
					if(utn_getNumeroEntero(&opcionOrden,"\n\n0.De manera ascendente"
														"\n1.De manera descendente"
														"\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n",0,1,3) == 1)
					{
						if(sortPassengersByName(list, len, opcionOrden) == 0)
						{
							printPassengers(list, len);
							retorno = 1;
						}
					}
					break;
				case 2:
					sumarPasajes(list, len, &sumaTotal);
					promediarPasajes(sumaTotal, contadorAltas, &promedio);
					buscarPasajesPromedio(list, len, &contPasajeros, promedio);
					printf( "\nSuma de pasajes: %.2f"
							"\nPromedio de pasajes: %.2f"
							"\nLa cantidad de pasajeros que superan el precio promedio es: %d", sumaTotal,promedio,contPasajeros);
					retorno = 1;

					break;
				case 3:
					if(utn_getNumeroEntero(&opcionOrden,"\n\n0.De manera ascendente"
														"\n1.De manera descendente"
														"\nIngrese una opcion: ","\nLa opcion ingresada no es valida\n",0,1,3) == 1)
					{
						if(sortPassengersByCode(list, len, opcionOrden) == 0)
						{
							printPassengers(list, len);
							retorno = 1;
						}
					}
					break;
				default:
					break;
			}
		}
	}

	return retorno;
}

void altaForzadaPassenger()
{
	Passenger listaPasajeros[5] = {{1000,"Juan","Rodriguez",254000,"S32915",1,1,1},
								   {1001,"Jimena","Gimenez",110000,"F32915",2,2,1},
								   {1002,"Laura","Fernandez",205200,"E32915",3,2,1},
								   {1003,"Lucas","Castro",342450,"D32915",2,1,1},
								   {1004,"Matias","Pereyra",109000,"A32915",1,2,1}};
	printPassengers(listaPasajeros, 5);
}

















