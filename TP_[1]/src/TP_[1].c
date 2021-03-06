/*
 ============================================================================
 *	Name     : TP_[1].c
 *	Author   : Joel Barrera
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "getNumero.h"
#include "calcularCostos.h"
#include "informarResultados.h"
#include "imprimirDatosForzados.h"
#include "confirmarDatos.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcionMenu;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	int primerOpcion;
	int segundaOpcion;
	int tercerOpcion;
	char confirmacionKm;
	char confirmacionAerolineas;
	char confirmacionLatam;
	float precioDebitoAero;
	float precioCreditoAero;
	float precioConBitcoinAero;
	float precioUnitarioAero;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioConBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;

	do
	{
		system("cls");
		printf("\nMENU DE OPCIONES\n");
		printf("\n1. Ingresar Kilometros: (km = %.2f)", kilometros);
		printf("\n2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)", precioAerolineas, precioLatam);
		printf("\n3. Calcular todos los costos:");
		printf("\n4. Informar Resultados");
		printf("\n5. Carga forzada de datos");
		printf("\n6. Salir\n");
		printf("\nElija una opcion: ");
		scanf("%d", &opcionMenu);

		switch(opcionMenu)
		{
			case 1:
				system("cls");
				if(confirmacionKm == 's')
				{
					printf("\nYa ingreso los kilometros\n");
				}
				else
				{
					do
					{
						getNumeroFlotante(&kilometros, "\nIngrese los kilometros: ", "\nLa cantidad ingresada no es valida\n", 1, 1000000, 3);
						if(kilometros >= 1)
						{
							confirmar(&confirmacionKm);
						}
					}while(confirmacionKm == 'n');
					primerOpcion = 1;
				}
				break;
			case 2:
				system("cls");
				if(confirmacionAerolineas == 's' && confirmacionLatam == 's')
				{
					printf("\nYa ingreso los precios de vuelos\n");
				}
				else
				{
					system("cls");
					do
					{
						getNumeroFlotante(&precioAerolineas, "\nIngrese el precio de vuelo para Aerolineas Argentinas: ", "\nEl precio ingresado no es valido\n", 1, 10000000, 3);
						if(precioAerolineas >= 1)
						{
							confirmar(&confirmacionAerolineas);
						}
					}while(confirmacionAerolineas == 'n');
					do
					{
						getNumeroFlotante(&precioLatam, "\nIngrese el precio de vuelo para Latam: ", "\nEl precio ingresado no es valido\n", 1, 10000000, 3);
						if(precioAerolineas >= 1)
						{
							confirmar(&confirmacionLatam);
						}
					}while(confirmacionLatam == 'n');
					segundaOpcion = 1;
				}
				break;
			case 3:
				system("cls");
				if(tercerOpcion == 1)
				{
					printf("\nYa se calcularon los costos\n");
				}
				else if(primerOpcion == 1 && segundaOpcion == 1)
				{
					calcularPrecioDebito(&precioDebitoAero, &precioDebitoLatam, precioAerolineas, precioLatam);
					calcularPrecioCredito(&precioCreditoAero, &precioCreditoLatam, precioAerolineas, precioLatam);
					calcularPrecioConBitcoin(&precioConBitcoinAero, &precioConBitcoinLatam, precioAerolineas, precioLatam);
					calcularPrecioUnitario(&precioUnitarioAero, &precioUnitarioLatam , kilometros, precioAerolineas, precioLatam);
					calcularDiferenciaPrecio(&diferenciaPrecio, precioAerolineas, precioLatam);
					tercerOpcion = 1;
				}
				else
				{
					printf("\nLe falta ingresar datos para poder calcular los costos\n");
				}
				break;
			case 4:
				system("cls");
				if(tercerOpcion == 1)
				{
					informarResultados(kilometros, precioAerolineas, precioLatam, precioDebitoAero, precioCreditoAero, precioConBitcoinAero, precioUnitarioAero, precioDebitoLatam, precioCreditoLatam, precioConBitcoinLatam, precioUnitarioLatam, diferenciaPrecio);
				}
				else
				{
					printf("\nLe falta ingresar datos para poder informar los resultados\n");
				}
				break;
			case 5:
				system("cls");
				cargarDatosForzados();
				break;
			case 6:
				break;
			default:
				printf("\nLa opcion ingresada no es valida\n");
				break;
		}
	}while(opcionMenu != 6);

	system("pause");

	return EXIT_SUCCESS;
}
