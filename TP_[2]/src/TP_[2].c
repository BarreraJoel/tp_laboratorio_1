/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Joel Barrera
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"

#define MAX_PASAJEROS 10

int main(void)
{
	setbuf(stdout, NULL);

	Passenger listaPasajeros[MAX_PASAJEROS];
	int opcionMenu;
	int flagOpcionUno = 0;
	int i = 0;
	int contadorAltas = 0;
	int contadorMaximo = 0;

	initPassengers(listaPasajeros, MAX_PASAJEROS);
	do
	{
		if(utn_getNumeroEntero(&opcionMenu, "\nMENU DE OPCIONES\n\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.CARGA FORZADA\nElija una opcion: ", "\nLa opcion elegida no es valida\n",1,6,3) == 1)
		{
			switch(opcionMenu)
			{
				case 1:
					if(i < MAX_PASAJEROS)
					{
						if(altaPassengers(listaPasajeros, MAX_PASAJEROS) == 0)
						{
							i++;
							contadorAltas++;
							contadorMaximo++;
							flagOpcionUno = 1;
						}
					}
					else
					{
						printf("\nNo hay mas espacio para guardar datos\n");
					}
					break;
				case 2:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						if(modificarPassengers(listaPasajeros, MAX_PASAJEROS, contadorMaximo) == 1)
						{
							printf("\nLa modificacion se realizo con exito\n");
						}
					}
					else
					{
						printf("\nDebe ingresar por lo menos un pasajero\n");
					}
					break;
				case 3:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						if(bajaPassengers(listaPasajeros, MAX_PASAJEROS, contadorMaximo) == 1)
						{
							contadorAltas--;
						}
					}
					else
					{
						printf("\nDebe ingresar por lo menos un pasajero\n");
					}
					break;
				case 4:
					if(flagOpcionUno == 1 && contadorAltas > 0)
					{
						ordenarPassengers(listaPasajeros, MAX_PASAJEROS);
					}
					else
					{
						printf("\nDebe ingresar por lo menos un pasajero\n");
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



