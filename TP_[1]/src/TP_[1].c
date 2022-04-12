/*
 ============================================================================
 Name        : TP_.c
 Author      : Joel Barrera
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void ingresarKilometros(float* p_Km);
void ingresarPrecios(float* precioAerolineas, float* precioLatam);

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	//1
	float kilometros;
	int primerOp = 0;
	int segundaOp = 0;
	int tercerOp = 0;
	//2
	float precioAerolineas;
	float precioLatam;
	//3

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
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				system("cls");

				if(kilometros != 0 && primerOp == 1)
				{
					printf("\nYa ingreso los kilometros\n");
					system("pause");
				}
				else
				{
					ingresarKilometros(&kilometros);
					primerOp = 1;
				}
				break;
			case 2:
				system("cls");

				if(segundaOp == 1)
				{
					printf("\nYa ingreso datos de vuelos\n");
				}
				else
				{
					system("cls");
					ingresarPrecios(&precioAerolineas, &precioLatam);
					segundaOp = 1;
				}
				break;
			case 3:
				system("cls");

				if(tercerOp == 1)
				{
					printf("\nYa se calcularon los costos");
				}
				else if(primerOp == 1 && segundaOp == 1)
				{
					//calcularCostos(km, precioAerolineas, precioLatam);
					tercerOp = 1;
				}
				else
				{
					printf("\nLe falta ingresar datos para poder calcular los costos");
				}
				break;
			case 4:
				system("cls");
				if(tercerOp == 1)
				{
					//comentario
				}
				else
				{
					printf("\nLe falta ingresar datos para poder informar los resultados");
				}
				break;
			case 5:
				//cargarDatosForzados();
				//carga forzada de datos
				//Km: 7090
				//Aerolineas Argentinas: $162965
				//Latam: $ 159339
				break;
			case 6:
				break;
			default:
				printf("\nLa opcion ingresada no es valida");
				break;
		}

	}while(opcion != 6);

	system("pause");

	return EXIT_SUCCESS;
}

void ingresarKilometros(float* p_Kilometros)
{
	printf("\nIngrese los kilometros: ");
	scanf("%f", p_Kilometros);
	while(*p_Kilometros < 1)
	{
		printf("\nIngrese una cantidad de kilometros valida: ");
		scanf("%f", p_Kilometros);
	}
}

void ingresarPrecios(float* p_PrecioAerolineas, float* p_PrecioLatam)
{
	printf("\nIngrese el precio de vuelo de Aerolineas: ");
	scanf("%f", p_PrecioAerolineas);
	while(*p_PrecioAerolineas < 1)
	{
		printf("\nIngrese un precio de vuelo valido para Aerolineas: ");
		scanf("%f", p_PrecioAerolineas);
	}

	printf("Ingrese el precio de vuelo de Latam: ");
	scanf("%f", p_PrecioLatam);
	while(*p_PrecioLatam < 1)
	{
		printf("Ingrese un precio de vuelo valido para Latam: ");
		scanf("%f", p_PrecioLatam);
	}
}







/*
void calcularCostos(float km, float precioAerolineas, float precioLatam)
{
	float precioDebitoAero;
	float precioCreditoAero;
	float precioConBitcoinAero;
	float precioPorKmAero;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioConBitcoinLatam;
	float precioPorKmLatam;
	float diferenciaPrecio;
	float precioBitcoin;

	precioBitcoin = 4606954.55;

	precioDebitoAero = precioAerolineas - precioAerolineas * 10/100;
	precioCreditoAero = precioAerolineas + precioAerolineas * 25/100;
	precioConBitcoinAero = precioAerolineas / precioBitcoin;
	precioPorKmAero = precioAerolineas / km;

	precioDebitoLatam = precioLatam - precioLatam * 10/100;
	precioCreditoLatam = precioLatam + precioLatam * 25/100;
	precioConBitcoinLatam = precioLatam / precioBitcoin;
	precioPorKmLatam = precioLatam / km;

	diferenciaPrecio = precioAerolineas - precioLatam;

	imprimirResultados(precioAerolineas, precioDebitoAero, precioCreditoAero, precioConBitcoinAero, precioPorKmAero, precioLatam, precioDebitoLatam, precioCreditoLatam, precioConBitcoinLatam, precioPorKmLatam, diferenciaPrecio);
}



void imprimirResultados(float precioAerolineas, float precioDebitoAero, float precioCreditoAero, float precioConBitcoinAero, float precioPorKmAero, float precioLatam, float precioDebitoLatam, float precioCreditoLatam, float precioConBitcoinLatam, float precioPorKmLatam, float diferenciaPrecio)
{
	printf("\nKilometros ingresados: %.2f", km);
	printf("\nPrecio Aerolineas: %.2f", precioAerolineas);
	printf("\na)Precio con tarjeta de debito: $ %.2f", precioDebitoAero);
	printf("\nb)Precio con tarjeta de credito: $ %.2f", precioCreditoAero);
	printf("\nc)Precio pagando con bitcoin: %.2f BTC", precioConBitcoinAero);
	printf("\nd)Precio unitario: $ %.2f", precioPorKmAero);
	printf("\n\nPrecio Latam: %.2f", precioLatam);
	printf("\na)Precio con tarjeta de debito: $ %.2f", precioDebitoLatam);
	printf("\nb)Precio con tarjeta de credito: $ %.2f", precioCreditoLatam);
	printf("\nc)Precio pagando con bitcoin: %.2f BTC", precioConBitcoinLatam);
	printf("\nd)Precio unitario: $ %.2f", precioPorKmLatam);
	printf("\n\nLa diferencia de precio es: $ %.2f", diferenciaPrecio);
}

void cargarDatosForzados()
{
	float km;
	float precioAerolineas;
	float precioLatam;

	km = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;

	calcularCostos(km, precioAerolineas, precioLatam);
}

*/
