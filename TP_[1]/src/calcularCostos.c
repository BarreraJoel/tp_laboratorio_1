/*
 * calcularCostos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Joel Barrera
 */

#include <stdio.h>

#define DESCUENTO 10
#define INTERES 25

int calcularPrecioDebito(float* precioDebitoAero, float* precioDebitoLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(precioDebitoAero != NULL && precioDebitoLatam != NULL)
	{
		*precioDebitoAero = precioAerolineas - precioAerolineas * DESCUENTO/100;
		*precioDebitoLatam = precioLatam - precioLatam * DESCUENTO/100;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioCredito(float* precioCreditoAero, float* precioCreditoLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(precioCreditoAero != NULL && precioCreditoLatam != NULL)
	{
		*precioCreditoAero = precioAerolineas + precioAerolineas * INTERES / 100;
		*precioCreditoLatam = precioLatam + precioLatam * INTERES / 100;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioConBitcoin(float* precioConBitcoinAero, float* precioConBitcoinLatam, float precioAerolineas, float precioLatam)
{
	int retorno;
	float precioBitcoin;

	retorno = -1;
	precioBitcoin = 4606954.55;

	if(precioConBitcoinAero != NULL && precioConBitcoinLatam != NULL)
	{
		*precioConBitcoinAero = precioAerolineas / precioBitcoin;
		*precioConBitcoinLatam = precioLatam / precioBitcoin;
		retorno = 1;
	}

	return retorno;
}

int calcularPrecioUnitario(float* precioUnitarioAero, float* precioUnitarioLatam , float km, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(precioUnitarioAero != NULL && precioUnitarioLatam != NULL)
	{
		*precioUnitarioAero = precioAerolineas / km;
		*precioUnitarioLatam = precioLatam / km;
		retorno = 1;
	}

	return retorno;
}

int calcularDiferenciaPrecio(float* diferenciaPrecio, float precioAerolineas, float precioLatam)
{
	int retorno;
	retorno = -1;

	if(diferenciaPrecio != NULL)
	{
		if(precioLatam > precioAerolineas)
		{
			*diferenciaPrecio = precioLatam - precioAerolineas;
		}
		else
		{
			*diferenciaPrecio = precioAerolineas - precioLatam;
		}
		retorno = 1;
	}

	return retorno;
}
