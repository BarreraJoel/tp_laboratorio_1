/*
 ============================================================================
 Name        : Trabajo Practico 2
 Author      : Joel Barrera
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input-UTN.h"
#include "ArrayPassenger.h"

#define MAX_PASAJEROS 10

int main(void)
{
	setbuf(stdout, NULL);
	Passenger listaPasajeros[MAX_PASAJEROS];
	int opcionMenu;
	int flagOpcionUno = 0;
	int contadorAltas = 0;
	int id = 1000;
	int ultimoId;

	initPassengers(listaPasajeros, MAX_PASAJEROS);

	do
	{
		if(utn_getNumeroEntero(&opcionMenu, "\n\n*** MENU DE OPCIONES ***\n"
											"\n1.ALTAS"
											"\n2.MODIFICAR"
											"\n3.BAJA"
											"\n4.INFORMAR"
											"\n5.CARGA FORZADA"
											"\n6.SALIR"
											"\nElija una opcion: ","\n*** La opcion ingresada no es valida ***\n",1,6,3) == 1)
		{
			switch(opcionMenu)
			{
				case 1:
					if(contadorAltas < MAX_PASAJEROS)
					{
						if(altaPassengers(listaPasajeros, MAX_PASAJEROS, &id, &ultimoId) == 0)
						{
							printf("\n*** La carga se realizo con exito ***\n");
							contadorAltas++;
							flagOpcionUno = 1;
						}
					}
					else
					{
						printf("\n*** No hay mas espacio para guardar datos ***\n");
					}
					break;
				case 2:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						if(modificarPassengers(listaPasajeros, MAX_PASAJEROS, ultimoId) == 1)
						{
							printf("\n*** Las modificaciones se realizaron con exito ***\n");
						}
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos un pasajero ***\n");
					}
					break;
				case 3:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						if(bajaPassengers(listaPasajeros, MAX_PASAJEROS, ultimoId) == 1)
						{
							printf("\n*** La baja se realizo con exito ***\n");
							contadorAltas--;
						}
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos un pasajero ***\n");
					}
					break;
				case 4:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						informarPassengers(listaPasajeros, MAX_PASAJEROS, contadorAltas);
					}
					else
					{
						printf("\n*** Debe ingresar por lo menos un pasajero ***\n");
					}
					break;
				case 5:
					altaForzadaPassenger();
					break;
				case 6:
					break;
				default:
					break;
			}
		}
	}while(opcionMenu != 6);

	return EXIT_SUCCESS;
}



