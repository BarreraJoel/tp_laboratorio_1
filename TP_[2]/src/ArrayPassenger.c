/*
 * ArrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: Joel Barrera
 */

#include "ArrayPassenger.h"

static int idIncremental = 1000;
static int incrementarId();
static int incrementarId()
{
	return idIncremental++;
}

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}
		retorno = 0;
	}

	return retorno;
}

int printPassenger(Passenger* list, int length, int id)
{
	int retorno = -1;
	int i;
	int j;
	int k;
	typePassenger listaTipos[3] = {{1,"Adulto/a"},{2,"Ninio/a"},{3,"Adolescente"}};
	statusFlight listaEstados[3] = {{1,"ACTIVO"},{2,"CANCELADO"}};

	if(list != NULL && length > 0 && id >= 1000)
	{
		printf("\n\nDATOS DEL PASAJERO\n\nID      NOMBRE     APELLIDO     PRECIO    CODIGO     TIPO     ESTADO\n");
		printf("----------------------------------------------------------------------------------------------------");
		for(i = 0; i < length; i++)
		{
			for(j = 0; j < length; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].id == id)
				{
					if(list[i].typePassenger == listaTipos[j].typePassenger)
					{
						for(k = 0; k < length; k++)
						{
							if(list[i].statusFlight == listaEstados[k].statusFlight)
							{
								printf("\n%d"
										"%10s"
										"%12s"
										"    %.2f"
										"%9s"
										"%10s"
										"%10s\n", list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,listaTipos[j].descripcion,listaEstados[k].descripcion);
								retorno = 0;
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
	return retorno;
}

int printPassengers(Passenger* list, int length)
{
	int retorno = -1;
	int i;
	int j;
	int k;
	typePassenger listaTipos[3] = {{1,"Adulto/a"},{2,"Ninio/a"},{3,"Adolescente"}};
	statusFlight listaEstados[2] = {{1,"ACTIVO"},{2,"CANCELADO"}};

	if(list != NULL && length > 0)
	{
		printf("\n\nDATOS DE LOS PASAJEROS\n\nID      NOMBRE     APELLIDO     PRECIO    CODIGO     TIPO     ESTADO\n");
		printf("----------------------------------------------------------------------------------------------------");
		for(i = 0; i < length; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				for(j = 0; j < length; j++)
				{
					if(list[i].typePassenger == listaTipos[j].typePassenger)
					{
						for(k = 0; k < length; k++)
						{
							if(list[i].statusFlight == listaEstados[k].statusFlight)
							{
								printf("\n%d"
										"%10s"
										"%12s"
										"    %.2f"
										"%9s"
										"%10s"
										"%10s\n", list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,listaTipos[j].descripcion,listaEstados[k].descripcion);
								break;
							}
						}
						break;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int buscarEspacioLibrePassenger(Passenger list[], int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id >= 1000 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode, flycode);
				list[i].statusFlight = statusFlight;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int altaPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int indiceLibre;
	int id;
	Passenger auxiliar;

	if(list != NULL && len > 0)
	{
		indiceLibre = buscarEspacioLibrePassenger(list, len);

		if(indiceLibre >= 0)
		{
			if(utn_getNombre(auxiliar.name,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",3, MAX_TEXTO, 3) == 1)
			{
				if(utn_getNombre(auxiliar.lastName,"\nIngrese el apellido: ", "\nEl apellido ingresado no es valido\n",4,MAX_TEXTO,3) == 1)
				{
					if(utn_getNumeroFlotante(&auxiliar.price, "\nIngrese el precio de vuelo: ", "\nEl precio de vuelo ingresado no es valido\n", 100000, 300000, 3) == 1)
					{
						if(utn_getTexto(auxiliar.flycode,"\nIngrese el codigo de vuelo: ", "\nEl codigo ingresado no es valido\n",3,10,3) == 1)
						{
							if(utn_getNumeroEntero(&auxiliar.typePassenger,"\nTipo de pasajero\n1.Adulto/a\n2.Ninio/a\n3.Adolescente\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n",1,3,3) == 1)
							{
								if(utn_getNumeroEntero(&auxiliar.statusFlight,"\nEstado de vuelo\n1.Activo\n2.Cancelado\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n",1,2,3) == 1)
								{
									id = incrementarId();
									if(addPassenger(list, len, id, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.typePassenger, auxiliar.flycode, auxiliar.statusFlight) == 0)
									{
										list[indiceLibre].isEmpty = OCUPADO;
										printf("\nLa carga se realizo con exito\n");
										retorno = 0;
									}
								}
							}
						}
					}
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
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
		printf("\nEl ID ingresado no existe\n");
	}
	return retorno;
}

int modificarPassenger(Passenger list[], int len, int opcionMenu, int indiceId)
{
	int retorno = -1;

	if(list != NULL && len > 0 && opcionMenu > 0 && indiceId >= 0)
	{
		switch(opcionMenu)
		{
			case 1:
				if(utn_getNombre(list[indiceId].name,"\nIngrese el nombre: ","\nEl nombre ingresado no es valido\n",3, MAX_TEXTO, 3) == 1)
				{
					retorno = 1;
				}
				break;
			case 2:
				if(utn_getNombre(list[indiceId].lastName,"\nIngrese el apellido: ", "\nEl apellido ingresado no es valido\n",4,MAX_TEXTO,3) == 1)
				{
					retorno = 1;
				}
				break;
			case 3:
				if(utn_getNumeroFlotante(&list[indiceId].price, "\nIngrese el precio de vuelo: ", "\nEl precio de vuelo ingresado no es valido\n", 100000, 300000, 3) == 1)
				{
					retorno = 1;
				}
				break;
			case 4:
				if(utn_getNumeroEntero(&list[indiceId].typePassenger,"\nTipo de pasajero\n1.Adulto/a\n2.Ninio/a\n3.Adolescente\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n",1,3,3) == 1)
				{
					retorno = 1;
				}
				break;
			case 5:
				if(utn_getTexto(list[indiceId].flycode,"\nIngrese el codigo de vuelo: ", "\nEl codigo ingresado no es valido\n",3,10,3) == 1)
				{
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

int modificarPassengers(Passenger list[], int len, int contador)
{
	int retorno = -1;
	int id;
	int indiceId;
	int opcionMenu;

	if(list != NULL && len > 0 && contador > 0)
	{
		printPassengers(list, len);

		if(utn_getNumeroEntero(&id, "\nIngrese el numero de ID del pasajero a modificar: ", "\nEl ID ingresado no es valido\n", 1000, 1000+contador, 3) == 1)
		{
			indiceId = findPassengerById(list, len, id);
			if(indiceId >= 0)
			{
				do
				{
					printPassenger(list, len, id);
					if(utn_getNumeroEntero(&opcionMenu, "\n\nMENU DE MODIFICACION\n\n1.Modificar Nombre\n2.Modificar Apellido\n3.Modificar Precio de vuelo\n4.Modificar Tipo de pasajero\n5.Modificar Codigo de vuelo\n6.Salir\nIngrese una opcion: ", "\nLa opcion ingresado no es valida\n", 1, 6, 3) == 1)
					{
						if(modificarPassenger(list, len, opcionMenu, indiceId)==1)
						{
							retorno = 1;
						}
					}
				}while(opcionMenu != 6);
			}
		}
	}

	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id >= 1000)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				list[i].isEmpty = LIBRE;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int bajaPassengers(Passenger* list, int len, int contador)
{
	int retorno = -1;
	int id;

	if(list != NULL && len > 0 && contador > 0)
	{
		printPassengers(list, len);
		if(utn_getNumeroEntero(&id, "\nIngrese el numero de ID del pasajero a dar de baja: ", "\nEl ID ingresado no es valido\n", 1000, 1000+contador, 3) == 1)
		{
			if(findPassengerById(list, len, id) >= 0)
			{
				printPassenger(list, len, id);
				if(removePassenger(list, len, id) == 0)
				{
					printf("\nLa baja se realizo con exito\n");
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
	typePassenger listaTipos[3] = {{1,"Adulto/a"},{2,"Ninio/a"},{3,"Adolescente"}};

	if(list != NULL && len > 0 && order >= 0)
	{
		switch(order)
		{
			case 0:
				//descendente
				for(i = 0; i < len-1; i++)
				{
					for(j = i+1; j < len; j++)
					{
						if(list[i].typePassenger == listaTipos[i].typePassenger)
						{
							if(strcmp(list[i].lastName, list[j].lastName) >= 0)
							{
								if(strcmp(listaTipos[i].descripcion, listaTipos[j].descripcion) >= 0)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
									printPassengers(list, len);
								}
							}
						}
					}
				}
				break;
			case 1:
				//ascendente
				for(i = 0; i < len-1; i++)
				{
					for(j = i+1; j < len; j++)
					{
						if(list[i].typePassenger == listaTipos[i].typePassenger)
						{
							if(strcmp(list[i].lastName, list[j].lastName) < 0)
							{
								if(strcmp(listaTipos[i].descripcion, listaTipos[j].descripcion) < 0)
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
									printPassengers(list, len);
								}
							}
						}
					}
				}
				break;
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

	if(list != NULL && len > 0 && order >= 0)
	{
		switch(order)
		{
			case 0:
				//descendente
				for(i = 0; i < len-1; i++)
				{
					for(j = i+1; j < len; j++)
					{
						if(strcmp(list[i].flycode, list[j].flycode) < 0)
						{
							if(list[i].statusFlight > list[j].statusFlight)
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
				break;
			case 1:
				for(i = 0; i < len-1; i++)
				{
					for(j = i+1; j < len; j++)
					{
						if(strcmp(list[i].flycode, list[j].flycode) > 0)
						{
							if(list[i].statusFlight == 1)
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
				break;
		}
		retorno = 0;
	}

	return retorno;
}

int sumarPasajes(Passenger list[],int len, float* pResultado)
{
	int retorno = -1;
	int i;
	float acumSuma = 0;

	if(list != NULL && len > 0 && pResultado != NULL)
	{
		for(i = 0; i< len; i++)
		{
			acumSuma += list[i].price;
		}

		*pResultado = acumSuma;
		retorno = 1;
	}
	return retorno;
}

int ordenarPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int opcionMenu;
	int opcionOrden;
	float sumaTotal;

	if(list != NULL && len > 0)
	{
		if(utn_getNumeroEntero(&opcionMenu, "\nMENU DE OPCIONES"
				"\n1.Listar pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero"
				"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
				"\n3.Listar pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO"
				"\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n", 1, 3, 3) == 1)
		{
			switch(opcionMenu)
			{
				case 1:
					if(utn_getNumeroEntero(&opcionOrden, "\n\n0.Ordenar de manera ascendente\n1.Ordenar de manera descendente\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n", 0, 1, 3) == 1)
					{
						if(sortPassengersByName(list, len, opcionOrden) == 0)
						{
							printPassengers(list, len);
							retorno = 1;
						}
					}
					break;
				case 2:
					if(sumarPasajes(list,len, &sumaTotal) == 1)
					{
						retorno = 1;
						printf("\nSuma de pasajes: %.2f", sumaTotal);
					}
					break;
				case 3:
					if(utn_getNumeroEntero(&opcionOrden, "\n\n0.Ordenar de manera ascendente\n1.Ordenar de manera descendente\nIngrese una opcion: ", "\nLa opcion ingresada no es valida\n", 0, 1, 3) == 1)
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
	Passenger listaPasajeros[5] = {{1000,"Juan","Perez",250000,"S32915",1,2,1},
									{1001,"Jimena","Gimenez",100000,"F32915",2,1,1},
									{1002,"Laura","Fernandez",200000,"E32915",1,1,1},
									{1003,"Lucas","Castro",50000,"D32915",2,2,1},
									{1004,"Matias","Pereyra",109000,"A32915",1,2,1}};
	printPassengers(listaPasajeros, 5);
}




